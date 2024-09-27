#include "MB1642DataReader.h"
#include "stm32u0xx_hal.h"
#include "main.h"

#define CMD_RDID 0x9F
#define CMD_READ 0x03
#define CMD_WREN 0x06
#define CMD_PP   0x02
#define CMD_RDSR 0x05
#define CMD_SE   0xD8
#define STATUS_WIP 0x01

extern SPI_HandleTypeDef hspi2;

//private variables
//DMA handles for reading pixels from SPI peripheral
extern DMA_HandleTypeDef hdma_spi2_rx;
extern DMA_HandleTypeDef hdma_spi2_tx;

//Status flag. Non-zero when receiving data
static volatile uint8_t isReceivingData = 0;

void readData(uint32_t address24, uint8_t* buffer, uint32_t length)
{
    FLASH_CS_GPIO_Port->BRR = FLASH_CS_Pin;
    *((__IO uint8_t*)&SPI2->DR) = CMD_READ;

    //clock out address
    *((__IO uint8_t*)&hspi2.Instance->DR) = (address24 >> 16) & 0xFF;

    while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
    *((__IO uint8_t*)&hspi2.Instance->DR) = (address24 >> 8) & 0xFF;

    while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
    *((__IO uint8_t*)&hspi2.Instance->DR) = address24 & 0xFF;

    switch (length)
    {
        default:
            while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
            *((__IO uint8_t*)&hspi2.Instance->DR);
            *((__IO uint8_t*)&hspi2.Instance->DR) = 0 ;
        case 3:
            while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
            *((__IO uint8_t*)&hspi2.Instance->DR);
            *((__IO uint8_t*)&hspi2.Instance->DR) = 0;
        case 2:
            while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
            *((__IO uint8_t*)&hspi2.Instance->DR);
            *((__IO uint8_t*)&hspi2.Instance->DR) = 0;
        case 1:
            while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
            *((__IO uint8_t*)&hspi2.Instance->DR);
            *((__IO uint8_t*)&hspi2.Instance->DR) = 0;
        case 0:
            break;
    }
    switch (length)
    {
        case 1:
        *((__IO uint8_t*)&hspi2.Instance->DR);
        case 2:
        *((__IO uint8_t*)&hspi2.Instance->DR);
        case 3:
        *((__IO uint8_t*)&hspi2.Instance->DR);
        default:
            break;
    }

    uint8_t* const buf_end = buffer + length - 4;

    while ((buf_end - buffer) > 3)
    {
        while(((SPI2->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
        *buffer++ = *((__IO uint8_t*)&SPI2->DR);
				*((__IO uint8_t*)&SPI2->DR) = 0;
				while(((SPI2->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
				*buffer++ = *((__IO uint8_t*)&SPI2->DR);
				*((__IO uint8_t*)&SPI2->DR) = 0;
				while(((SPI2->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
				*buffer++ = *((__IO uint8_t*)&SPI2->DR);
				*((__IO uint8_t*)&SPI2->DR) = 0;
				while(((SPI2->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
				*buffer++ = *((__IO uint8_t*)&SPI2->DR);
				*((__IO uint8_t*)&SPI2->DR) = 0;
    }

    while (buffer < buf_end)
    {
        while(((SPI2->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
        *buffer++ = *((__IO uint8_t*)&SPI2->DR);
				*((__IO uint8_t*)&SPI2->DR) = 0;
    }

    /* Wait until the bus is ready before releasing Chip select */
    while(((hspi2.Instance->SR) & SPI_FLAG_BSY) != RESET) { }

    FLASH_CS_GPIO_Port->BSRR = FLASH_CS_Pin;
    const int rest = length < 4 ? length : 4;
    for (int i = 0; i<rest; i++)
    {
        *buffer++ = *((__IO uint8_t*)&SPI2->DR);
    }
}

void readDataDMA(uint32_t address24, uint8_t* buffer, uint32_t length)
{
    // Pull Flash CS pin low
    isReceivingData = 1;
    FLASH_CS_GPIO_Port->BRR = FLASH_CS_Pin;

    *((__IO uint8_t*)&hspi2.Instance->DR) = CMD_READ;

    //clock out address
    while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
    *((__IO uint8_t*)&hspi2.Instance->DR) = (address24 >> 16) & 0xFF;

    while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
    *((__IO uint8_t*)&hspi2.Instance->DR) = (address24 >> 8) & 0xFF;

    while(((hspi2.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE) { }
    *((__IO uint8_t*)&hspi2.Instance->DR) = address24 & 0xFF;

    /* Wait until the bus is ready before reading 4 dummy bytes */
    while(((hspi2.Instance->SR) & SPI_FLAG_BSY) != RESET) { }
    *((__IO uint8_t*)&hspi2.Instance->DR);
    *((__IO uint8_t*)&hspi2.Instance->DR);
    *((__IO uint8_t*)&hspi2.Instance->DR);
    *((__IO uint8_t*)&hspi2.Instance->DR);

    /* Reset the threshold bit */
    CLEAR_BIT(hspi2.Instance->CR2, SPI_CR2_LDMATX | SPI_CR2_LDMARX);

    /* Set RX Fifo threshold according the reception data length: 8bit */
    SET_BIT(hspi2.Instance->CR2, SPI_RXFIFO_THRESHOLD);

    /******** RX ****************/
    /* Disable the peripheral */
    __HAL_DMA_DISABLE(&hdma_spi2_rx);

    /* Clear all flags */
    __HAL_DMA_CLEAR_FLAG(&hdma_spi2_rx, (DMA_FLAG_GI1 << (hdma_spi2_rx.ChannelIndex & 0x1cU)));

    /* Configure DMA Channel data length */
    hdma_spi2_rx.Instance->CNDTR = length;

    /* Configure DMA Channel destination address */
    hdma_spi2_rx.Instance->CPAR = (uint32_t)&hspi2.Instance->DR;

    /* Configure DMA Channel source address */
    hdma_spi2_rx.Instance->CMAR = (uint32_t)buffer;

    __HAL_DMA_DISABLE_IT(&hdma_spi2_rx, DMA_IT_HT | DMA_IT_TE);
    __HAL_DMA_ENABLE_IT(&hdma_spi2_rx, (DMA_IT_TC));

    /* Enable the Peripheral */
    __HAL_DMA_ENABLE(&hdma_spi2_rx);

    /* Enable Rx DMA Request */
    SET_BIT(hspi2.Instance->CR2, SPI_CR2_RXDMAEN);

    /******** TX ****************/
    /* Disable the peripheral */
    __HAL_DMA_DISABLE(&hdma_spi2_tx);

    /* Clear all flags */
    __HAL_DMA_CLEAR_FLAG(&hdma_spi2_tx, (DMA_FLAG_GI1 << (hdma_spi2_tx.ChannelIndex & 0x1cU)));

    /* Configure DMA Channel data length */
    hdma_spi2_tx.Instance->CNDTR = length;

    /* Configure DMA Channel destination address */
    hdma_spi2_tx.Instance->CPAR = (uint32_t)&hspi2.Instance->DR;

    /* Configure DMA Channel source address */
    hdma_spi2_tx.Instance->CMAR = (uint32_t)buffer;

    /* Enable the Peripheral */
    __HAL_DMA_ENABLE(&hdma_spi2_tx);

    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(&hspi2);

    /* Enable Tx DMA Request */
    SET_BIT(hspi2.Instance->CR2, SPI_CR2_TXDMAEN);
}

void DataReader_DMACallback()
{
    /* Transfer Complete Interrupt management ***********************************/
    if ((0U != (DMA1->ISR & (DMA_FLAG_TC1 << (hdma_spi2_rx.ChannelIndex & 0x1cU)))) && (0U != (hdma_spi2_rx.Instance->CCR & DMA_IT_TC)))
    {
        /* Disable the transfer complete and error interrupt */
        __HAL_DMA_DISABLE_IT(&hdma_spi2_rx, DMA_IT_TE | DMA_IT_TC);
        /* Clear the transfer complete flag */
        __HAL_DMA_CLEAR_FLAG(&hdma_spi2_rx, (DMA_FLAG_TC1 << (hdma_spi2_rx.ChannelIndex & 0x1cU)));


        // Wait until the bus is not busy before changing configuration
        // SPI is busy in communication or Tx buffer is not empty
        while(((hspi2.Instance->SR) & SPI_FLAG_BSY) != RESET) { }

        FLASH_CS_GPIO_Port->BSRR = FLASH_CS_Pin;

        isReceivingData = 0;
    }
}

void DataReader_ReadData(uint32_t address24, uint8_t* buffer, uint32_t length)
{
    readData(address24, buffer, length);
}

void DataReader_StartDMAReadData(uint32_t address24, uint8_t* buffer, uint32_t length)
{
    readDataDMA(address24, buffer, length);
}

uint32_t DataReader_IsReceivingData(void)
{
    return isReceivingData;
}

void DataReader_WaitForReceiveDone(void)
{
    while (isReceivingData) { }
}

void DataReader_Init(void)
{
    __HAL_SPI_ENABLE(&hspi2);
}
