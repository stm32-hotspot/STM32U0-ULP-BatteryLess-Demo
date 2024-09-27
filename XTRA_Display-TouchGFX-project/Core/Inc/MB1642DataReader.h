#ifndef DataReader_H
#define DataReader_H

#include <stdint.h>

uint32_t DataReader_IsReceivingData(void);
void     DataReader_WaitForReceiveDone(void);
void     DataReader_Init(void);
void     DataReader_ReadData(uint32_t address24, uint8_t* buffer, uint32_t length);
void     DataReader_StartDMAReadData(uint32_t address24, uint8_t* buffer, uint32_t length);
void     DataReader_DMACallback(void);

#endif //DataReader_H
