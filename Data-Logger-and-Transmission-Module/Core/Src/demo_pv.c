/* USER CODE BEGIN Header */
/**
 ******************************************************************************
  * @file 	 demo_pv.c
  * @author      Etienne Sesmat
  * @brief       This file contains the state-machine function
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed under terms that can be found in the LICENSE file
  * in the root derictory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "demo_pv.h"
#include "main.h"
#include "app_x-cube-subg2.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
typedef enum { 
  SM_DEMO_IDLE = 0,
  SM_DEMO_CHECK_VOLTAGE,  
  SM_DEMO_DO_MEASURE,    
  SM_DEMO_DISPLAY_MEASURE,
  SM_DEMO_SEND_DATA,    
  SM_DEMO_WAIT_FOR_SENDING_DONE,
  SM_DEMO_CHECK_PB_PUSHED,
  SM_DEMO_DISPLAY_CHANGE_MEASURE,
  SM_DEMO_WAKEUP,
  SM_DEMO_STOP2,
} SM_Demo_t;

typedef enum{
  TEMP = 0,
  LUX,
  TIME_ALIVE,
} BeingMeasured_t;

typedef struct{
  BeingMeasured_t BeingMeasured;
  uint16_t DataMeasured;
} Measure_t;

typedef struct{
  uint8_t *pTxBuff;
  uint8_t cTxlen;
  uint8_t* pRxBuff; 
  uint8_t cRxlen;
} RFcom_t;

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
SM_Demo_t SM_Demo = SM_DEMO_IDLE;
Measure_t pMeasure;
extern uint8_t PV_supplied;
extern uint8_t Is_RF_Module_Connected;

extern uint8_t Number_demos;
extern DemoTypedef list_demos[];
uint8_t Demo_index;
PWR_PVDTypeDef sConfigPVD;

static uint8_t pushed = 0;
static uint8_t change_display_in_process = 0;

extern ADC_HandleTypeDef hadc1;
__IO   uint16_t aADCxConvertedData[ADC_NUMBER_MEASURES]; /* ADC group regular conversion data (array of data) */
volatile uint16_t voltage_measured = 0;
volatile uint32_t calculated_current = 0;
volatile uint16_t calculated_illuminance = 0;
float Value_Temp;
uint16_t Value_Temp_u16 = 0;
uint16_t voltage_ascii[6];
uint16_t current_ascii[6];
uint16_t time_ascii[6];
uint16_t lux_ascii[6];
uint16_t temp_ascii[6];
uint16_t tab[6];

extern FlagStatus xTxDoneFlag;
extern uint8_t TxLengthTest;
extern uint8_t aTransmitBufferTest[4];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void PVD_Init(void);
void PVD_Set_High_V(void);
void PVD_Set_Low_V(void);
void Enter_Stop2(void);
uint8_t is_PV_supplied(void);

void Demo_do_measure();
uint32_t ADC_measuring(void);

void Demo_Display_LCD();
uint32_t Voltage_to_Current(uint32_t voltage_measured);
uint32_t Current_to_Lux(uint32_t calculated_current);
void Convert_IntegerIntoChar(float number, uint16_t *p_tab);
void Disp_Illuminance(uint32_t calculated_illuminance);
void Disp_Temp(uint16_t Value_Temp);

extern void send_Data(uint8_t *pTxBuff, uint8_t cTxlen);

void Next_Demo(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void Start(void){
  PVD_Init();                           //PVD init
  PVD_Set_Low_V();
  HAL_PWREx_EnableUltraLowPowerMode();
  PV_supplied = is_PV_supplied()||PV_SUPPLIED;
  if(PV_supplied){
    PVD_Set_High_V();                     // PVD set to High Voltage
    HAL_DBGMCU_DisableDBGStopMode();
    HAL_PWREx_EnterSTOP2Mode(PWR_STOPENTRY_WFI); // Enter stop 2 mode
  }
}

void Process_Demo(){
  switch(SM_Demo)
  {
  case SM_DEMO_IDLE:
    {
      SM_Demo = SM_DEMO_CHECK_VOLTAGE;
    }
    break;
    
  case SM_DEMO_CHECK_VOLTAGE:
    {
      if((__HAL_PWR_GET_FLAG(PWR_FLAG_PVDO) == 0)){
        SM_Demo = SM_DEMO_DO_MEASURE;
      } else {
        SM_Demo = SM_DEMO_STOP2;
      }
    }
    break;
    
  case SM_DEMO_DO_MEASURE:    
    {
      Demo_do_measure();
      if(Is_RF_Module_Connected){
        Next_Demo();
        Demo_do_measure();
        Next_Demo();
      }
      
      if(USE_LCD){
        SM_Demo = SM_DEMO_DISPLAY_MEASURE;
      }else if(Is_RF_Module_Connected){
        SM_Demo = SM_DEMO_SEND_DATA;
      }else{
        SM_Demo = SM_DEMO_STOP2;
      }
    }
    break;
    
  case SM_DEMO_DISPLAY_MEASURE:    
    {
      Demo_Display_LCD();
      
      if(Is_RF_Module_Connected && calculated_illuminance > THRESHOLD_LUX_NO_SENDING){
        SM_Demo = SM_DEMO_SEND_DATA;
      }else {
        SM_Demo = SM_DEMO_CHECK_PB_PUSHED;
      }
    }
    break;     
    
  case SM_DEMO_SEND_DATA:    
    {
      S2LPCmdStrobeReady();
      send_Data(aTransmitBufferTest, TxLengthTest);
      
      SM_Demo = SM_DEMO_WAIT_FOR_SENDING_DONE;
    }
    break;    
    
  case SM_DEMO_WAIT_FOR_SENDING_DONE:    
    {
      Enter_Stop2();
      if(xTxDoneFlag){
          xTxDoneFlag = RESET;
          S2LPCmdStrobeSleep();
          
          SM_Demo = SM_DEMO_STOP2;
      }
    }
    break;    
    
  case SM_DEMO_CHECK_PB_PUSHED:
    {
      if(pushed & !change_display_in_process){
        SM_Demo = SM_DEMO_DISPLAY_CHANGE_MEASURE;
      }else{
        SM_Demo = SM_DEMO_STOP2;
      }
    }
    break;
    
    case SM_DEMO_DISPLAY_CHANGE_MEASURE:
    {
      if (Demo_index==1){
        BSP_LCD_GLASS_DisplayString("LIGHT ");
      }else{
        BSP_LCD_GLASS_DisplayString("TEMP  ");
      }
      Next_Demo();
      change_display_in_process=1;
      
      SM_Demo = SM_DEMO_STOP2;
    }
    break;   
    
  case SM_DEMO_WAKEUP:
    {
      if(pushed){
        if(!change_display_in_process){
          SM_Demo = SM_DEMO_DISPLAY_CHANGE_MEASURE;
        }else{
         SM_Demo = SM_DEMO_STOP2;
        }
      }else{
        SM_Demo = SM_DEMO_IDLE;
      }
    }
    break;
    
  case SM_DEMO_STOP2:    
    {
      Enter_Stop2();
      SM_Demo = SM_DEMO_WAKEUP;
    }
    break;     
  }
}

void Send_data_one_shot(void){
    send_Data(aTransmitBufferTest, TxLengthTest);
}

void  PVD_Init(void){
  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_NVIC_SetPriority(PVD_PVM_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(PVD_PVM_IRQn);
}


void PVD_Set_High_V(void){
  /* Configure the PVD Level to */
  SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_PVDL);
  sConfigPVD.PVDLevel = PWR_PVDLEVEL_6; 
  sConfigPVD.Mode = PWR_PVD_MODE_IT_FALLING;
  HAL_PWR_PVDConfig(&sConfigPVD);
  
  /* Enable the PVD Output */
  HAL_PWR_EnablePVD();
}


void PVD_Set_Low_V(void){
  /* Configure the PVD Level to */
  sConfigPVD.PVDLevel = PWR_PVDLEVEL_0;
  sConfigPVD.Mode = PWR_PVD_MODE_NORMAL;
  HAL_PWR_PVDConfig(&sConfigPVD);
  
  /* Enable the PVD Output */
  HAL_PWR_EnablePVD();
}

void Enter_Stop2(void){
#if (ENABLE_STOP2 > 0)
  HAL_SuspendTick();
  HAL_DBGMCU_DisableDBGStopMode();
  HAL_PWREx_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
  HAL_ResumeTick();
#endif
}
void Demo_do_measure(){
//#if (ENTER_DEMO > 0)
  switch(list_demos[Demo_index].Measure){
    case ID_MEASURE_CURRENTPV:
      voltage_measured = ADC_measuring();
      voltage_measured = __LL_ADC_CALC_DATA_TO_VOLTAGE(VDDA_APPLI, voltage_measured, LL_ADC_RESOLUTION_12B);
      calculated_current = Voltage_to_Current(voltage_measured);
      calculated_illuminance = Current_to_Lux(calculated_current);    
      aTransmitBufferTest[0] = (calculated_illuminance & 0xFF);
      aTransmitBufferTest[1] = (calculated_illuminance >> 8);
    break;
    
    case ID_MEASURE_TEMPERATURE_STTS22H:
      BSP_ENV_SENSOR_GetValue(ENV_SENSOR_STTS22H_0, ENV_TEMPERATURE, &Value_Temp);
      Value_Temp_u16 = (uint16_t)(Value_Temp*100);
      aTransmitBufferTest[2] = (Value_Temp_u16 & 0xFF);
      aTransmitBufferTest[3] = (Value_Temp_u16 >> 8);
      pMeasure.DataMeasured= (uint16_t)(Value_Temp*100);   
    break;
  }
//#endif
}

void Demo_Display_LCD(){
#if CLEAR_LCD > 0
    BSP_LCD_GLASS_Clear();    
#endif
     
//#if (ENTER_DEMO > 0) && (USE_LCD > 0)
//#if (ENTER_DEMO > 0) && (USE_LCD > 0)
  switch(list_demos[Demo_index].Display){
      
  case ID_DISPLAY_ILLUMINENCE:
    Disp_Illuminance(calculated_illuminance);
    break;
    
  case ID_DISPLAY_TEMPERATURE_STTS22H:
//    Disp_Temp((uint16_t)Value_Temp*100);
    Disp_Temp(pMeasure.DataMeasured);
    break;
//#endif
  }
}


uint32_t ADC_measuring(){
    uint32_t measure= 0;
    uint32_t tmp_index_adc_converted_data = 0;
    
    if (HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK)
    {
      /* Calibration Error */
      Error_Handler();
    }
    HAL_GPIO_WritePin(LUX_GPIO_PORT, LUX_GPIO_PIN, GPIO_PIN_RESET);
    
    for (tmp_index_adc_converted_data = 0; tmp_index_adc_converted_data < ADC_NUMBER_MEASURES; tmp_index_adc_converted_data++)
      {
        if (HAL_ADC_Start(&hadc1) != HAL_OK)
        {
          Error_Handler(); 
        }
        HAL_ADC_PollForConversion(&hadc1,1);
        aADCxConvertedData[tmp_index_adc_converted_data] = HAL_ADC_GetValue(&hadc1);
        if(tmp_index_adc_converted_data> (ADC_NUMBER_MEASURES - ADC_MESURES_TAKEN_INTO_ACCOUNT)-1){
            measure += aADCxConvertedData[tmp_index_adc_converted_data];
        }
      }
    HAL_GPIO_WritePin(LUX_GPIO_PORT, LUX_GPIO_PIN, GPIO_PIN_SET);
    measure = measure/(ADC_MESURES_TAKEN_INTO_ACCOUNT);  
    return(measure);
}


uint32_t Voltage_to_Current(uint32_t voltage_measured){
  return voltage_measured*1000/RESISTOR_VALUE_OHM;
}


uint32_t Current_to_Lux(uint32_t calculated_current){
  return calculated_current*COEF_CURRENT_TO_LUX;
}

void Disp_Voltage(uint32_t voltage_measured){
  Convert_IntegerIntoChar(voltage_measured*100, (uint16_t *)voltage_ascii);
  if(voltage_ascii[0]=='0'){
    if(voltage_ascii[1]=='0'){
      if(voltage_ascii[2]=='0'){
        voltage_ascii[2]=' ';
      }
      voltage_ascii[1]=' ';
    }
    voltage_ascii[0]=' ';
  }
  voltage_ascii[4]='m';
  voltage_ascii[5]='V';
  
  BSP_LCD_GLASS_DisplayStrDeci(voltage_ascii);
}

void Disp_Current(uint32_t calculated_current){
  Convert_IntegerIntoChar(calculated_current*100, (uint16_t *)current_ascii);
  if(current_ascii[0]=='0'){
    if(current_ascii[1]=='0'){
      if(current_ascii[2]=='0'){
        current_ascii[2]=' ';
      }
      current_ascii[1]=' ';
    }
    current_ascii[0]=' ';
  }
  current_ascii[4]='u';
  current_ascii[5]='A';
  
  BSP_LCD_GLASS_DisplayStrDeci(current_ascii);
}

void Disp_Illuminance(uint32_t calculated_illuminance){
  if(calculated_illuminance < 1000){
    Convert_IntegerIntoChar(calculated_illuminance*1000, (uint16_t *)lux_ascii);
    if(lux_ascii[0]=='0'){
      if(lux_ascii[1]=='0'){
        lux_ascii[1]=' ';
      }
      lux_ascii[0]=' ';
    }
  }else{
    Convert_IntegerIntoChar(calculated_illuminance*100, (uint16_t *)lux_ascii);
    lux_ascii[2]='k';
    lux_ascii[0]|=DOT;
  }
  lux_ascii[3]='l';
  lux_ascii[4]='u';
  lux_ascii[5]='x';
  
  BSP_LCD_GLASS_DisplayStrDeci(lux_ascii);
}

void Disp_Time_Alive(TimeTypedef time_alive){
  
  time_ascii[5] = time_alive.su + 0x30;
  time_ascii[4] = time_alive.sd + 0x30;
  time_ascii[3] = time_alive.mu + 0x30;
  time_ascii[2] = time_alive.md + 0x30;
  time_ascii[1] = time_alive.hu + 0x30;
  time_ascii[0] = time_alive.hd + 0x30;
  time_ascii[1]|= DOUBLE_DOT;
  time_ascii[3]|= DOUBLE_DOT;
  BSP_LCD_GLASS_DisplayStrDeci(time_ascii);
}

void Disp_Temp(uint16_t Value_Temp){
   Convert_IntegerIntoChar(Value_Temp*100, (uint16_t *)tab);
   tab[5] = 'C';
//   tab[4] = '°';
    tab[4] = 0xb0; // °
   /* Test the significant digit for displays 3 or 4 digits*/
   if (tab[0] != '0')
   {
     tab[1] |= DOT; /* To add decimal point */
   }
   else
   {
     /* To shift for suppress '0' before decimal */
     tab[0] = tab[1] ;
     tab[0] |= DOT ;
     tab[1] = tab[2] ;
     tab[2] = tab[3] ;
     tab[3] = ' ';
   }
  BSP_LCD_GLASS_DisplayStrDeci(tab);
}

/**
  * @brief converts a 32bit unsined int into ASCII 
  * @caller several callers for display values
  * @param number digit to displays
  * @param p_tab values in array in ASCII   
  * @retval None
  */ 
void Convert_IntegerIntoChar(float number, uint16_t *p_tab)
{
  uint16_t units=0, tens=0, hundreds=0, thousands=0, tenthousand=0, hundredthousand=0;
  
  uint32_t number1 = (uint32_t) number;
  
  units = ((((number1%100000)%10000)%1000)%100)%10;
  tens = (((((number1-units)/10)%10000)%1000)%100)%10;
  hundreds = ((((number1-tens-units)/100)%1000)%100)%10;
  thousands = (((number1-hundreds-tens-units)/1000)%100)%10;
  tenthousand = ((number1-thousands-hundreds-tens-units)/10000)%10;
  hundredthousand = ((number1-tenthousand-thousands-hundreds-tens-units)/100000);
  
  *(p_tab+5) = units + 0x30;
  *(p_tab+4) = tens + 0x30;
  *(p_tab+3) = hundreds + 0x30;
  *(p_tab+2) = thousands + 0x30;
  *(p_tab+1) = tenthousand + 0x30;
  *(p_tab+0) = hundredthousand + 0x30;
}

void Next_Demo(void){
  if(Demo_index >= Number_demos-1){
    Demo_index = 0;
  }else{
    Demo_index++;
  } 
}
uint8_t is_PV_supplied(void){
  uint8_t temp = READ_BIT(PWR->SR2, PWR_SR2_PVDO) != 0U;
  return(temp);
}
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
    pushed = 1;
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
    pushed=0;
    change_display_in_process=0;
}

/* USER CODE END EV */