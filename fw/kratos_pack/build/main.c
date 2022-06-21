ARM GAS  /tmp/ccitkYpi.s 			page 1


   1              		.cpu cortex-m0plus
   2              		.eabi_attribute 20, 1
   3              		.eabi_attribute 21, 1
   4              		.eabi_attribute 23, 3
   5              		.eabi_attribute 24, 1
   6              		.eabi_attribute 25, 1
   7              		.eabi_attribute 26, 1
   8              		.eabi_attribute 30, 1
   9              		.eabi_attribute 34, 0
  10              		.eabi_attribute 18, 4
  11              		.file	"main.c"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.section	.text._ZL12MX_GPIO_Initv,"ax",%progbits
  16              		.align	1
  17              		.arch armv6s-m
  18              		.syntax unified
  19              		.code	16
  20              		.thumb_func
  21              		.fpu softvfp
  23              	_ZL12MX_GPIO_Initv:
  24              	.LFB3860:
  25              		.file 1 "Src/main.c"
   1:Src/main.c    **** /* USER CODE BEGIN Header */
   2:Src/main.c    **** 
   3:Src/main.c    **** /**
   4:Src/main.c    ****   ******************************************************************************
   5:Src/main.c    ****   * @file           : main.c
   6:Src/main.c    ****   * @brief          : Main program body
   7:Src/main.c    ****   ******************************************************************************
   8:Src/main.c    ****   * @attention
   9:Src/main.c    ****   *
  10:Src/main.c    ****   * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  11:Src/main.c    ****   * All rights reserved.</center></h2>
  12:Src/main.c    ****   *
  13:Src/main.c    ****   * This software component is licensed by ST under BSD 3-Clause license,
  14:Src/main.c    ****   * the "License"; You may not use this file except in compliance with the
  15:Src/main.c    ****   * License. You may obtain a copy of the License at:
  16:Src/main.c    ****   *                        opensource.org/licenses/BSD-3-Clause
  17:Src/main.c    ****   *
  18:Src/main.c    ****   ******************************************************************************
  19:Src/main.c    ****   */
  20:Src/main.c    **** /* USER CODE END Header */
  21:Src/main.c    **** /* Includes ------------------------------------------------------------------*/
  22:Src/main.c    **** #include "main.h"
  23:Src/main.c    **** 
  24:Src/main.c    **** /* Private includes ----------------------------------------------------------*/
  25:Src/main.c    **** /* USER CODE BEGIN Includes */
  26:Src/main.c    **** #include "stm32g0xx_hal.h"
  27:Src/main.c    **** 
  28:Src/main.c    **** #include "device/device.hpp"
  29:Src/main.c    **** #include "led/KTD2026.hpp"
  30:Src/main.c    **** #include "apps/i2c_scanner.hpp"
  31:Src/main.c    **** /* USER CODE END Includes */
  32:Src/main.c    **** 
  33:Src/main.c    **** /* Private typedef -----------------------------------------------------------*/
ARM GAS  /tmp/ccitkYpi.s 			page 2


  34:Src/main.c    **** /* USER CODE BEGIN PTD */
  35:Src/main.c    **** 
  36:Src/main.c    **** /* USER CODE END PTD */
  37:Src/main.c    **** 
  38:Src/main.c    **** /* Private define ------------------------------------------------------------*/
  39:Src/main.c    **** /* USER CODE BEGIN PD */
  40:Src/main.c    **** /* USER CODE END PD */
  41:Src/main.c    **** 
  42:Src/main.c    **** /* Private macro -------------------------------------------------------------*/
  43:Src/main.c    **** /* USER CODE BEGIN PM */
  44:Src/main.c    **** 
  45:Src/main.c    **** /* USER CODE END PM */
  46:Src/main.c    **** 
  47:Src/main.c    **** /* Private variables ---------------------------------------------------------*/
  48:Src/main.c    **** ADC_HandleTypeDef hadc1;
  49:Src/main.c    **** 
  50:Src/main.c    **** I2C_HandleTypeDef hi2c1;
  51:Src/main.c    **** 
  52:Src/main.c    **** TIM_HandleTypeDef htim2;
  53:Src/main.c    **** 
  54:Src/main.c    **** UART_HandleTypeDef huart2;
  55:Src/main.c    **** UART_HandleTypeDef huart3;
  56:Src/main.c    **** 
  57:Src/main.c    **** /* USER CODE BEGIN PV */
  58:Src/main.c    **** 
  59:Src/main.c    **** /* USER CODE END PV */
  60:Src/main.c    **** 
  61:Src/main.c    **** /* Private function prototypes -----------------------------------------------*/
  62:Src/main.c    **** void SystemClock_Config(void);
  63:Src/main.c    **** static void MX_GPIO_Init(void);
  64:Src/main.c    **** static void MX_I2C1_Init(void);
  65:Src/main.c    **** static void MX_USART2_UART_Init(void);
  66:Src/main.c    **** static void MX_USART3_UART_Init(void);
  67:Src/main.c    **** static void MX_ADC1_Init(void);
  68:Src/main.c    **** static void MX_TIM2_Init(void);
  69:Src/main.c    **** /* USER CODE BEGIN PFP */
  70:Src/main.c    **** 
  71:Src/main.c    **** /* USER CODE END PFP */
  72:Src/main.c    **** 
  73:Src/main.c    **** /* Private user code ---------------------------------------------------------*/
  74:Src/main.c    **** /* USER CODE BEGIN 0 */
  75:Src/main.c    **** 
  76:Src/main.c    **** /* USER CODE END 0 */
  77:Src/main.c    **** 
  78:Src/main.c    **** /**
  79:Src/main.c    ****   * @brief  The application entry point.
  80:Src/main.c    ****   * @retval int
  81:Src/main.c    ****   */
  82:Src/main.c    **** int main(void){
  83:Src/main.c    ****     /* USER CODE BEGIN 1 */
  84:Src/main.c    **** 
  85:Src/main.c    ****     /* USER CODE END 1 */
  86:Src/main.c    **** 
  87:Src/main.c    ****     /* MCU Configuration--------------------------------------------------------*/
  88:Src/main.c    **** 
  89:Src/main.c    ****     /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  90:Src/main.c    ****     HAL_Init();
ARM GAS  /tmp/ccitkYpi.s 			page 3


  91:Src/main.c    **** 
  92:Src/main.c    ****     /* USER CODE BEGIN Init */
  93:Src/main.c    **** 
  94:Src/main.c    ****     /* USER CODE END Init */
  95:Src/main.c    **** 
  96:Src/main.c    ****     /* Configure the system clock */
  97:Src/main.c    ****     SystemClock_Config();
  98:Src/main.c    **** 
  99:Src/main.c    ****     /* USER CODE BEGIN SysInit */
 100:Src/main.c    **** 
 101:Src/main.c    ****     /* USER CODE END SysInit */
 102:Src/main.c    **** 
 103:Src/main.c    ****     /* Initialize all configured peripherals */
 104:Src/main.c    ****     MX_GPIO_Init();
 105:Src/main.c    ****     MX_I2C1_Init();
 106:Src/main.c    ****     MX_USART2_UART_Init();
 107:Src/main.c    ****     MX_USART3_UART_Init();
 108:Src/main.c    ****     MX_ADC1_Init();
 109:Src/main.c    ****     MX_TIM2_Init();
 110:Src/main.c    ****     /* USER CODE BEGIN 2 */
 111:Src/main.c    ****     HAL_Delay(1);
 112:Src/main.c    **** 
 113:Src/main.c    **** 
 114:Src/main.c    **** 
 115:Src/main.c    ****     device()->mcu->UART_2->Send("Hello world\r\n");
 116:Src/main.c    **** 
 117:Src/main.c    ****     device()->Enable_CLI(device()->mcu->UART_2);
 118:Src/main.c    ****     device()->Enable_Filesystem();
 119:Src/main.c    ****     device()->cli->Enable_filesystem_executable(device()->fs);
 120:Src/main.c    **** 
 121:Src/main.c    ****     auto app = new I2C_scanner(device()->mcu->I2C_1);
 122:Src/main.c    **** 
 123:Src/main.c    ****     auto led_enable = new Pin('C', 14);
 124:Src/main.c    ****     led_enable->Set(true);
 125:Src/main.c    **** 
 126:Src/main.c    ****     auto led = new KTD2026(*(device()->mcu->I2C_1), 0b01100010);
 127:Src/main.c    ****     led->Test();
 128:Src/main.c    **** 
 129:Src/main.c    ****     /* USER CODE END 2 */
 130:Src/main.c    **** 
 131:Src/main.c    ****     /* Infinite loop */
 132:Src/main.c    ****     /* USER CODE BEGIN WHILE */
 133:Src/main.c    ****     while (1) {
 134:Src/main.c    ****         /* USER CODE END WHILE */
 135:Src/main.c    **** 
 136:Src/main.c    ****         /* USER CODE BEGIN 3 */
 137:Src/main.c    ****     }
 138:Src/main.c    ****     /* USER CODE END 3 */
 139:Src/main.c    **** } // main
 140:Src/main.c    **** 
 141:Src/main.c    **** /**
 142:Src/main.c    ****   * @brief System Clock Configuration
 143:Src/main.c    ****   * @retval None
 144:Src/main.c    ****   */
 145:Src/main.c    **** void SystemClock_Config(void){
 146:Src/main.c    ****     RCC_OscInitTypeDef RCC_OscInitStruct   = { 0 };
 147:Src/main.c    ****     RCC_ClkInitTypeDef RCC_ClkInitStruct   = { 0 };
ARM GAS  /tmp/ccitkYpi.s 			page 4


 148:Src/main.c    ****     RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };
 149:Src/main.c    **** 
 150:Src/main.c    ****     /** Configure the main internal regulator output voltage
 151:Src/main.c    ****     */
 152:Src/main.c    ****     HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);
 153:Src/main.c    **** 
 154:Src/main.c    ****     /** Initializes the RCC Oscillators according to the specified parameters
 155:Src/main.c    ****     * in the RCC_OscInitTypeDef structure.
 156:Src/main.c    ****     */
 157:Src/main.c    ****     RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
 158:Src/main.c    ****     RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
 159:Src/main.c    ****     RCC_OscInitStruct.HSIDiv              = RCC_HSI_DIV1;
 160:Src/main.c    ****     RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
 161:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
 162:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
 163:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLM            = RCC_PLLM_DIV1;
 164:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLN            = 8;
 165:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLP            = RCC_PLLP_DIV2;
 166:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLQ            = RCC_PLLQ_DIV2;
 167:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLR            = RCC_PLLR_DIV2;
 168:Src/main.c    ****     if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
 169:Src/main.c    ****         Error_Handler();
 170:Src/main.c    ****     }
 171:Src/main.c    **** 
 172:Src/main.c    ****     /** Initializes the CPU, AHB and APB buses clocks
 173:Src/main.c    ****     */
 174:Src/main.c    ****     RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
 175:Src/main.c    ****       | RCC_CLOCKTYPE_PCLK1;
 176:Src/main.c    ****     RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
 177:Src/main.c    ****     RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
 178:Src/main.c    ****     RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
 179:Src/main.c    **** 
 180:Src/main.c    ****     if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
 181:Src/main.c    ****         Error_Handler();
 182:Src/main.c    ****     }
 183:Src/main.c    **** 
 184:Src/main.c    ****     /** Initializes the peripherals clocks
 185:Src/main.c    ****     */
 186:Src/main.c    ****     PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_I2C1
 187:Src/main.c    ****       | RCC_PERIPHCLK_ADC;
 188:Src/main.c    ****     PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
 189:Src/main.c    ****     PeriphClkInit.I2c1ClockSelection   = RCC_I2C1CLKSOURCE_PCLK1;
 190:Src/main.c    ****     PeriphClkInit.AdcClockSelection    = RCC_ADCCLKSOURCE_SYSCLK;
 191:Src/main.c    ****     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
 192:Src/main.c    ****         Error_Handler();
 193:Src/main.c    ****     }
 194:Src/main.c    **** } // SystemClock_Config
 195:Src/main.c    **** 
 196:Src/main.c    **** /**
 197:Src/main.c    ****   * @brief ADC1 Initialization Function
 198:Src/main.c    ****   * @param None
 199:Src/main.c    ****   * @retval None
 200:Src/main.c    ****   */
 201:Src/main.c    **** static void MX_ADC1_Init(void){
 202:Src/main.c    ****     /* USER CODE BEGIN ADC1_Init 0 */
 203:Src/main.c    **** 
 204:Src/main.c    ****     /* USER CODE END ADC1_Init 0 */
ARM GAS  /tmp/ccitkYpi.s 			page 5


 205:Src/main.c    **** 
 206:Src/main.c    ****     ADC_ChannelConfTypeDef sConfig = { 0 };
 207:Src/main.c    **** 
 208:Src/main.c    ****     /* USER CODE BEGIN ADC1_Init 1 */
 209:Src/main.c    **** 
 210:Src/main.c    ****     /* USER CODE END ADC1_Init 1 */
 211:Src/main.c    **** 
 212:Src/main.c    ****     /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of c
 213:Src/main.c    ****     */
 214:Src/main.c    ****     hadc1.Instance = ADC1;
 215:Src/main.c    ****     hadc1.Init.ClockPrescaler        = ADC_CLOCK_SYNC_PCLK_DIV4;
 216:Src/main.c    ****     hadc1.Init.Resolution            = ADC_RESOLUTION_12B;
 217:Src/main.c    ****     hadc1.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
 218:Src/main.c    ****     hadc1.Init.ScanConvMode          = ADC_SCAN_DISABLE;
 219:Src/main.c    ****     hadc1.Init.EOCSelection          = ADC_EOC_SINGLE_CONV;
 220:Src/main.c    ****     hadc1.Init.LowPowerAutoWait      = DISABLE;
 221:Src/main.c    ****     hadc1.Init.LowPowerAutoPowerOff  = DISABLE;
 222:Src/main.c    ****     hadc1.Init.ContinuousConvMode    = DISABLE;
 223:Src/main.c    ****     hadc1.Init.NbrOfConversion       = 1;
 224:Src/main.c    ****     hadc1.Init.DiscontinuousConvMode = DISABLE;
 225:Src/main.c    ****     hadc1.Init.ExternalTrigConv      = ADC_SOFTWARE_START;
 226:Src/main.c    ****     hadc1.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
 227:Src/main.c    ****     hadc1.Init.DMAContinuousRequests = DISABLE;
 228:Src/main.c    ****     hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
 229:Src/main.c    ****     hadc1.Init.SamplingTimeCommon1  = ADC_SAMPLETIME_1CYCLE_5;
 230:Src/main.c    ****     hadc1.Init.SamplingTimeCommon2  = ADC_SAMPLETIME_1CYCLE_5;
 231:Src/main.c    ****     hadc1.Init.OversamplingMode     = DISABLE;
 232:Src/main.c    ****     hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
 233:Src/main.c    ****     if (HAL_ADC_Init(&hadc1) != HAL_OK) {
 234:Src/main.c    ****         Error_Handler();
 235:Src/main.c    ****     }
 236:Src/main.c    **** 
 237:Src/main.c    ****     /** Configure Regular Channel
 238:Src/main.c    ****     */
 239:Src/main.c    ****     sConfig.Channel      = ADC_CHANNEL_6;
 240:Src/main.c    ****     sConfig.Rank         = ADC_REGULAR_RANK_1;
 241:Src/main.c    ****     sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
 242:Src/main.c    ****     if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
 243:Src/main.c    ****         Error_Handler();
 244:Src/main.c    ****     }
 245:Src/main.c    ****     /* USER CODE BEGIN ADC1_Init 2 */
 246:Src/main.c    **** 
 247:Src/main.c    ****     /* USER CODE END ADC1_Init 2 */
 248:Src/main.c    **** } // MX_ADC1_Init
 249:Src/main.c    **** 
 250:Src/main.c    **** /**
 251:Src/main.c    ****   * @brief I2C1 Initialization Function
 252:Src/main.c    ****   * @param None
 253:Src/main.c    ****   * @retval None
 254:Src/main.c    ****   */
 255:Src/main.c    **** static void MX_I2C1_Init(void){
 256:Src/main.c    ****     /* USER CODE BEGIN I2C1_Init 0 */
 257:Src/main.c    **** 
 258:Src/main.c    ****     /* USER CODE END I2C1_Init 0 */
 259:Src/main.c    **** 
 260:Src/main.c    ****     /* USER CODE BEGIN I2C1_Init 1 */
 261:Src/main.c    **** 
ARM GAS  /tmp/ccitkYpi.s 			page 6


 262:Src/main.c    ****     /* USER CODE END I2C1_Init 1 */
 263:Src/main.c    ****     hi2c1.Instance              = I2C1;
 264:Src/main.c    ****     hi2c1.Init.Timing           = 0x10707DBC;
 265:Src/main.c    ****     hi2c1.Init.OwnAddress1      = 0;
 266:Src/main.c    ****     hi2c1.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
 267:Src/main.c    ****     hi2c1.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
 268:Src/main.c    ****     hi2c1.Init.OwnAddress2      = 0;
 269:Src/main.c    ****     hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
 270:Src/main.c    ****     hi2c1.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
 271:Src/main.c    ****     hi2c1.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;
 272:Src/main.c    ****     if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
 273:Src/main.c    ****         Error_Handler();
 274:Src/main.c    ****     }
 275:Src/main.c    **** 
 276:Src/main.c    ****     /** Configure Analogue filter
 277:Src/main.c    ****     */
 278:Src/main.c    ****     if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK) {
 279:Src/main.c    ****         Error_Handler();
 280:Src/main.c    ****     }
 281:Src/main.c    **** 
 282:Src/main.c    ****     /** Configure Digital filter
 283:Src/main.c    ****     */
 284:Src/main.c    ****     if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK) {
 285:Src/main.c    ****         Error_Handler();
 286:Src/main.c    ****     }
 287:Src/main.c    ****     /* USER CODE BEGIN I2C1_Init 2 */
 288:Src/main.c    **** 
 289:Src/main.c    ****     /* USER CODE END I2C1_Init 2 */
 290:Src/main.c    **** } // MX_I2C1_Init
 291:Src/main.c    **** 
 292:Src/main.c    **** /**
 293:Src/main.c    ****   * @brief TIM2 Initialization Function
 294:Src/main.c    ****   * @param None
 295:Src/main.c    ****   * @retval None
 296:Src/main.c    ****   */
 297:Src/main.c    **** static void MX_TIM2_Init(void){
 298:Src/main.c    ****     /* USER CODE BEGIN TIM2_Init 0 */
 299:Src/main.c    **** 
 300:Src/main.c    ****     /* USER CODE END TIM2_Init 0 */
 301:Src/main.c    **** 
 302:Src/main.c    ****     TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
 303:Src/main.c    ****     TIM_MasterConfigTypeDef sMasterConfig     = { 0 };
 304:Src/main.c    **** 
 305:Src/main.c    ****     /* USER CODE BEGIN TIM2_Init 1 */
 306:Src/main.c    **** 
 307:Src/main.c    ****     /* USER CODE END TIM2_Init 1 */
 308:Src/main.c    ****     htim2.Instance               = TIM2;
 309:Src/main.c    ****     htim2.Init.Prescaler         = 0;
 310:Src/main.c    ****     htim2.Init.CounterMode       = TIM_COUNTERMODE_UP;
 311:Src/main.c    ****     htim2.Init.Period            = 4294967295;
 312:Src/main.c    ****     htim2.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
 313:Src/main.c    ****     htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
 314:Src/main.c    ****     if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
 315:Src/main.c    ****         Error_Handler();
 316:Src/main.c    ****     }
 317:Src/main.c    ****     sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
 318:Src/main.c    ****     if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
ARM GAS  /tmp/ccitkYpi.s 			page 7


 319:Src/main.c    ****         Error_Handler();
 320:Src/main.c    ****     }
 321:Src/main.c    ****     sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
 322:Src/main.c    ****     sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
 323:Src/main.c    ****     if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK) {
 324:Src/main.c    ****         Error_Handler();
 325:Src/main.c    ****     }
 326:Src/main.c    ****     /* USER CODE BEGIN TIM2_Init 2 */
 327:Src/main.c    **** 
 328:Src/main.c    ****     /* USER CODE END TIM2_Init 2 */
 329:Src/main.c    **** } // MX_TIM2_Init
 330:Src/main.c    **** 
 331:Src/main.c    **** /**
 332:Src/main.c    ****   * @brief USART2 Initialization Function
 333:Src/main.c    ****   * @param None
 334:Src/main.c    ****   * @retval None
 335:Src/main.c    ****   */
 336:Src/main.c    **** static void MX_USART2_UART_Init(void){
 337:Src/main.c    ****     /* USER CODE BEGIN USART2_Init 0 */
 338:Src/main.c    **** 
 339:Src/main.c    ****     /* USER CODE END USART2_Init 0 */
 340:Src/main.c    **** 
 341:Src/main.c    ****     /* USER CODE BEGIN USART2_Init 1 */
 342:Src/main.c    **** 
 343:Src/main.c    ****     /* USER CODE END USART2_Init 1 */
 344:Src/main.c    ****     huart2.Instance                    = USART2;
 345:Src/main.c    ****     huart2.Init.BaudRate               = 115200;
 346:Src/main.c    ****     huart2.Init.WordLength             = UART_WORDLENGTH_8B;
 347:Src/main.c    ****     huart2.Init.StopBits               = UART_STOPBITS_1;
 348:Src/main.c    ****     huart2.Init.Parity                 = UART_PARITY_NONE;
 349:Src/main.c    ****     huart2.Init.Mode                   = UART_MODE_TX_RX;
 350:Src/main.c    ****     huart2.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
 351:Src/main.c    ****     huart2.Init.OverSampling           = UART_OVERSAMPLING_16;
 352:Src/main.c    ****     huart2.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
 353:Src/main.c    ****     huart2.Init.ClockPrescaler         = UART_PRESCALER_DIV1;
 354:Src/main.c    ****     huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 355:Src/main.c    ****     if (HAL_UART_Init(&huart2) != HAL_OK) {
 356:Src/main.c    ****         Error_Handler();
 357:Src/main.c    ****     }
 358:Src/main.c    ****     if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK) {
 359:Src/main.c    ****         Error_Handler();
 360:Src/main.c    ****     }
 361:Src/main.c    ****     if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK) {
 362:Src/main.c    ****         Error_Handler();
 363:Src/main.c    ****     }
 364:Src/main.c    ****     if (HAL_UARTEx_DisableFifoMode(&huart2) != HAL_OK) {
 365:Src/main.c    ****         Error_Handler();
 366:Src/main.c    ****     }
 367:Src/main.c    ****     /* USER CODE BEGIN USART2_Init 2 */
 368:Src/main.c    **** 
 369:Src/main.c    ****     /* USER CODE END USART2_Init 2 */
 370:Src/main.c    **** } // MX_USART2_UART_Init
 371:Src/main.c    **** 
 372:Src/main.c    **** /**
 373:Src/main.c    ****   * @brief USART3 Initialization Function
 374:Src/main.c    ****   * @param None
 375:Src/main.c    ****   * @retval None
ARM GAS  /tmp/ccitkYpi.s 			page 8


 376:Src/main.c    ****   */
 377:Src/main.c    **** static void MX_USART3_UART_Init(void){
 378:Src/main.c    ****     /* USER CODE BEGIN USART3_Init 0 */
 379:Src/main.c    **** 
 380:Src/main.c    ****     /* USER CODE END USART3_Init 0 */
 381:Src/main.c    **** 
 382:Src/main.c    ****     /* USER CODE BEGIN USART3_Init 1 */
 383:Src/main.c    **** 
 384:Src/main.c    ****     /* USER CODE END USART3_Init 1 */
 385:Src/main.c    ****     huart3.Instance                    = USART3;
 386:Src/main.c    ****     huart3.Init.BaudRate               = 115200;
 387:Src/main.c    ****     huart3.Init.WordLength             = UART_WORDLENGTH_8B;
 388:Src/main.c    ****     huart3.Init.StopBits               = UART_STOPBITS_1;
 389:Src/main.c    ****     huart3.Init.Parity                 = UART_PARITY_NONE;
 390:Src/main.c    ****     huart3.Init.Mode                   = UART_MODE_TX_RX;
 391:Src/main.c    ****     huart3.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
 392:Src/main.c    ****     huart3.Init.OverSampling           = UART_OVERSAMPLING_16;
 393:Src/main.c    ****     huart3.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
 394:Src/main.c    ****     huart3.Init.ClockPrescaler         = UART_PRESCALER_DIV1;
 395:Src/main.c    ****     huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 396:Src/main.c    ****     if (HAL_UART_Init(&huart3) != HAL_OK) {
 397:Src/main.c    ****         Error_Handler();
 398:Src/main.c    ****     }
 399:Src/main.c    ****     /* USER CODE BEGIN USART3_Init 2 */
 400:Src/main.c    **** 
 401:Src/main.c    ****     /* USER CODE END USART3_Init 2 */
 402:Src/main.c    **** }
 403:Src/main.c    **** 
 404:Src/main.c    **** /**
 405:Src/main.c    ****   * @brief GPIO Initialization Function
 406:Src/main.c    ****   * @param None
 407:Src/main.c    ****   * @retval None
 408:Src/main.c    ****   */
 409:Src/main.c    **** static void MX_GPIO_Init(void){
  26              		.loc 1 409 31 view -0
  27              		.cfi_startproc
  28              		@ args = 0, pretend = 0, frame = 32
  29              		@ frame_needed = 0, uses_anonymous_args = 0
  30 0000 F0B5     		push	{r4, r5, r6, r7, lr}
  31              	.LCFI0:
  32              		.cfi_def_cfa_offset 20
  33              		.cfi_offset 4, -20
  34              		.cfi_offset 5, -16
  35              		.cfi_offset 6, -12
  36              		.cfi_offset 7, -8
  37              		.cfi_offset 14, -4
  38 0002 CE46     		mov	lr, r9
  39 0004 4746     		mov	r7, r8
  40 0006 80B5     		push	{r7, lr}
  41              	.LCFI1:
  42              		.cfi_def_cfa_offset 28
  43              		.cfi_offset 8, -28
  44              		.cfi_offset 9, -24
  45 0008 89B0     		sub	sp, sp, #36
  46              	.LCFI2:
  47              		.cfi_def_cfa_offset 64
 410:Src/main.c    ****     GPIO_InitTypeDef GPIO_InitStruct = { 0 };
ARM GAS  /tmp/ccitkYpi.s 			page 9


  48              		.loc 1 410 5 view .LVU1
  49              		.loc 1 410 22 is_stmt 0 view .LVU2
  50 000a 1422     		movs	r2, #20
  51 000c 0021     		movs	r1, #0
  52 000e 03A8     		add	r0, sp, #12
  53 0010 FFF7FEFF 		bl	memset
  54              	.LVL0:
 411:Src/main.c    **** 
 412:Src/main.c    ****     /* GPIO Ports Clock Enable */
 413:Src/main.c    ****     __HAL_RCC_GPIOC_CLK_ENABLE();
  55              		.loc 1 413 5 is_stmt 1 view .LVU3
  56              	.LBB174:
  57              		.loc 1 413 5 view .LVU4
  58              		.loc 1 413 5 view .LVU5
  59 0014 2D4B     		ldr	r3, .L2
  60 0016 596B     		ldr	r1, [r3, #52]
  61 0018 0422     		movs	r2, #4
  62 001a 1143     		orrs	r1, r2
  63 001c 5963     		str	r1, [r3, #52]
  64              		.loc 1 413 5 view .LVU6
  65 001e 596B     		ldr	r1, [r3, #52]
  66 0020 0A40     		ands	r2, r1
  67 0022 0092     		str	r2, [sp]
  68              		.loc 1 413 5 view .LVU7
  69 0024 009A     		ldr	r2, [sp]
  70              	.LBE174:
 414:Src/main.c    ****     __HAL_RCC_GPIOA_CLK_ENABLE();
  71              		.loc 1 414 5 view .LVU8
  72              	.LBB175:
  73              		.loc 1 414 5 view .LVU9
  74              		.loc 1 414 5 view .LVU10
  75 0026 5A6B     		ldr	r2, [r3, #52]
  76 0028 0125     		movs	r5, #1
  77 002a 2A43     		orrs	r2, r5
  78 002c 5A63     		str	r2, [r3, #52]
  79              		.loc 1 414 5 view .LVU11
  80 002e 5A6B     		ldr	r2, [r3, #52]
  81 0030 2A40     		ands	r2, r5
  82 0032 0192     		str	r2, [sp, #4]
  83              		.loc 1 414 5 view .LVU12
  84 0034 019A     		ldr	r2, [sp, #4]
  85              	.LBE175:
 415:Src/main.c    ****     __HAL_RCC_GPIOB_CLK_ENABLE();
  86              		.loc 1 415 5 view .LVU13
  87              	.LBB176:
  88              		.loc 1 415 5 view .LVU14
  89              		.loc 1 415 5 view .LVU15
  90 0036 596B     		ldr	r1, [r3, #52]
  91 0038 0222     		movs	r2, #2
  92 003a 1143     		orrs	r1, r2
  93 003c 5963     		str	r1, [r3, #52]
  94              		.loc 1 415 5 view .LVU16
  95 003e 5B6B     		ldr	r3, [r3, #52]
  96 0040 1A40     		ands	r2, r3
  97 0042 0292     		str	r2, [sp, #8]
  98              		.loc 1 415 5 view .LVU17
  99 0044 029B     		ldr	r3, [sp, #8]
ARM GAS  /tmp/ccitkYpi.s 			page 10


 100              	.LBE176:
 416:Src/main.c    **** 
 417:Src/main.c    ****     /*Configure GPIO pin Output Level */
 418:Src/main.c    ****     HAL_GPIO_WritePin(GPIOC, LED_EN_Pin | CD_Pin, GPIO_PIN_RESET);
 101              		.loc 1 418 5 view .LVU18
 102              		.loc 1 418 22 is_stmt 0 view .LVU19
 103 0046 C024     		movs	r4, #192
 104 0048 2402     		lsls	r4, r4, #8
 105 004a 214B     		ldr	r3, .L2+4
 106 004c 9946     		mov	r9, r3
 107 004e 0022     		movs	r2, #0
 108 0050 2100     		movs	r1, r4
 109 0052 1800     		movs	r0, r3
 110 0054 FFF7FEFF 		bl	HAL_GPIO_WritePin
 111              	.LVL1:
 419:Src/main.c    **** 
 420:Src/main.c    ****     /*Configure GPIO pin Output Level */
 421:Src/main.c    ****     HAL_GPIO_WritePin(GPIOA, ME_EN_Pin | CS_EN_Pin, GPIO_PIN_RESET);
 112              		.loc 1 421 5 is_stmt 1 view .LVU20
 113              		.loc 1 421 22 is_stmt 0 view .LVU21
 114 0058 9023     		movs	r3, #144
 115 005a 1B01     		lsls	r3, r3, #4
 116 005c 9846     		mov	r8, r3
 117 005e A027     		movs	r7, #160
 118 0060 FF05     		lsls	r7, r7, #23
 119 0062 0022     		movs	r2, #0
 120 0064 1900     		movs	r1, r3
 121 0066 3800     		movs	r0, r7
 122 0068 FFF7FEFF 		bl	HAL_GPIO_WritePin
 123              	.LVL2:
 422:Src/main.c    **** 
 423:Src/main.c    ****     /*Configure GPIO pin Output Level */
 424:Src/main.c    ****     HAL_GPIO_WritePin(PSEL_GPIO_Port, PSEL_Pin, GPIO_PIN_RESET);
 124              		.loc 1 424 5 is_stmt 1 view .LVU22
 125              		.loc 1 424 22 is_stmt 0 view .LVU23
 126 006c 194E     		ldr	r6, .L2+8
 127 006e 0022     		movs	r2, #0
 128 0070 0821     		movs	r1, #8
 129 0072 3000     		movs	r0, r6
 130 0074 FFF7FEFF 		bl	HAL_GPIO_WritePin
 131              	.LVL3:
 425:Src/main.c    **** 
 426:Src/main.c    ****     /*Configure GPIO pins : LED_EN_Pin CD_Pin */
 427:Src/main.c    ****     GPIO_InitStruct.Pin   = LED_EN_Pin | CD_Pin;
 132              		.loc 1 427 5 is_stmt 1 view .LVU24
 133              		.loc 1 427 27 is_stmt 0 view .LVU25
 134 0078 0394     		str	r4, [sp, #12]
 428:Src/main.c    ****     GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
 135              		.loc 1 428 5 is_stmt 1 view .LVU26
 136              		.loc 1 428 27 is_stmt 0 view .LVU27
 137 007a 0495     		str	r5, [sp, #16]
 429:Src/main.c    ****     GPIO_InitStruct.Pull  = GPIO_NOPULL;
 138              		.loc 1 429 5 is_stmt 1 view .LVU28
 139              		.loc 1 429 27 is_stmt 0 view .LVU29
 140 007c 0024     		movs	r4, #0
 141 007e 0594     		str	r4, [sp, #20]
 430:Src/main.c    ****     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
ARM GAS  /tmp/ccitkYpi.s 			page 11


 142              		.loc 1 430 5 is_stmt 1 view .LVU30
 143              		.loc 1 430 27 is_stmt 0 view .LVU31
 144 0080 0694     		str	r4, [sp, #24]
 431:Src/main.c    ****     HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
 145              		.loc 1 431 5 is_stmt 1 view .LVU32
 146              		.loc 1 431 18 is_stmt 0 view .LVU33
 147 0082 03A9     		add	r1, sp, #12
 148 0084 4846     		mov	r0, r9
 149 0086 FFF7FEFF 		bl	HAL_GPIO_Init
 150              	.LVL4:
 432:Src/main.c    **** 
 433:Src/main.c    ****     /*Configure GPIO pins : ME_EN_Pin CS_EN_Pin */
 434:Src/main.c    ****     GPIO_InitStruct.Pin   = ME_EN_Pin | CS_EN_Pin;
 151              		.loc 1 434 5 is_stmt 1 view .LVU34
 152              		.loc 1 434 27 is_stmt 0 view .LVU35
 153 008a 4346     		mov	r3, r8
 154 008c 0393     		str	r3, [sp, #12]
 435:Src/main.c    ****     GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
 155              		.loc 1 435 5 is_stmt 1 view .LVU36
 156              		.loc 1 435 27 is_stmt 0 view .LVU37
 157 008e 0495     		str	r5, [sp, #16]
 436:Src/main.c    ****     GPIO_InitStruct.Pull  = GPIO_NOPULL;
 158              		.loc 1 436 5 is_stmt 1 view .LVU38
 159              		.loc 1 436 27 is_stmt 0 view .LVU39
 160 0090 0594     		str	r4, [sp, #20]
 437:Src/main.c    ****     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 161              		.loc 1 437 5 is_stmt 1 view .LVU40
 162              		.loc 1 437 27 is_stmt 0 view .LVU41
 163 0092 0694     		str	r4, [sp, #24]
 438:Src/main.c    ****     HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
 164              		.loc 1 438 5 is_stmt 1 view .LVU42
 165              		.loc 1 438 18 is_stmt 0 view .LVU43
 166 0094 03A9     		add	r1, sp, #12
 167 0096 3800     		movs	r0, r7
 168 0098 FFF7FEFF 		bl	HAL_GPIO_Init
 169              	.LVL5:
 439:Src/main.c    **** 
 440:Src/main.c    ****     /*Configure GPIO pin : PSEL_Pin */
 441:Src/main.c    ****     GPIO_InitStruct.Pin   = PSEL_Pin;
 170              		.loc 1 441 5 is_stmt 1 view .LVU44
 171              		.loc 1 441 27 is_stmt 0 view .LVU45
 172 009c 0823     		movs	r3, #8
 173 009e 0393     		str	r3, [sp, #12]
 442:Src/main.c    ****     GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
 174              		.loc 1 442 5 is_stmt 1 view .LVU46
 175              		.loc 1 442 27 is_stmt 0 view .LVU47
 176 00a0 0495     		str	r5, [sp, #16]
 443:Src/main.c    ****     GPIO_InitStruct.Pull  = GPIO_NOPULL;
 177              		.loc 1 443 5 is_stmt 1 view .LVU48
 178              		.loc 1 443 27 is_stmt 0 view .LVU49
 179 00a2 0594     		str	r4, [sp, #20]
 444:Src/main.c    ****     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
 180              		.loc 1 444 5 is_stmt 1 view .LVU50
 181              		.loc 1 444 27 is_stmt 0 view .LVU51
 182 00a4 0694     		str	r4, [sp, #24]
 445:Src/main.c    ****     HAL_GPIO_Init(PSEL_GPIO_Port, &GPIO_InitStruct);
 183              		.loc 1 445 5 is_stmt 1 view .LVU52
ARM GAS  /tmp/ccitkYpi.s 			page 12


 184              		.loc 1 445 18 is_stmt 0 view .LVU53
 185 00a6 03A9     		add	r1, sp, #12
 186 00a8 3000     		movs	r0, r6
 187 00aa FFF7FEFF 		bl	HAL_GPIO_Init
 188              	.LVL6:
 446:Src/main.c    **** 
 447:Src/main.c    ****     /*Configure GPIO pin : CH_INT_Pin */
 448:Src/main.c    ****     GPIO_InitStruct.Pin  = CH_INT_Pin;
 189              		.loc 1 448 5 is_stmt 1 view .LVU54
 190              		.loc 1 448 26 is_stmt 0 view .LVU55
 191 00ae 8023     		movs	r3, #128
 192 00b0 5B00     		lsls	r3, r3, #1
 193 00b2 0393     		str	r3, [sp, #12]
 449:Src/main.c    ****     GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
 194              		.loc 1 449 5 is_stmt 1 view .LVU56
 195              		.loc 1 449 26 is_stmt 0 view .LVU57
 196 00b4 084B     		ldr	r3, .L2+12
 197 00b6 0493     		str	r3, [sp, #16]
 450:Src/main.c    ****     GPIO_InitStruct.Pull = GPIO_NOPULL;
 198              		.loc 1 450 5 is_stmt 1 view .LVU58
 199              		.loc 1 450 26 is_stmt 0 view .LVU59
 200 00b8 0594     		str	r4, [sp, #20]
 451:Src/main.c    ****     HAL_GPIO_Init(CH_INT_GPIO_Port, &GPIO_InitStruct);
 201              		.loc 1 451 5 is_stmt 1 view .LVU60
 202              		.loc 1 451 18 is_stmt 0 view .LVU61
 203 00ba 03A9     		add	r1, sp, #12
 204 00bc 3000     		movs	r0, r6
 205 00be FFF7FEFF 		bl	HAL_GPIO_Init
 206              	.LVL7:
 452:Src/main.c    **** } // MX_GPIO_Init
 207              		.loc 1 452 1 view .LVU62
 208 00c2 09B0     		add	sp, sp, #36
 209              		@ sp needed
 210 00c4 C0BC     		pop	{r6, r7}
 211 00c6 B946     		mov	r9, r7
 212 00c8 B046     		mov	r8, r6
 213 00ca F0BD     		pop	{r4, r5, r6, r7, pc}
 214              	.L3:
 215              		.align	2
 216              	.L2:
 217 00cc 00100240 		.word	1073876992
 218 00d0 00080050 		.word	1342179328
 219 00d4 00040050 		.word	1342178304
 220 00d8 00001110 		.word	269549568
 221              		.cfi_endproc
 222              	.LFE3860:
 224              		.section	.text.Error_Handler,"ax",%progbits
 225              		.align	1
 226              		.global	Error_Handler
 227              		.syntax unified
 228              		.code	16
 229              		.thumb_func
 230              		.fpu softvfp
 232              	Error_Handler:
 233              	.LFB3861:
 453:Src/main.c    **** 
 454:Src/main.c    **** /* USER CODE BEGIN 4 */
ARM GAS  /tmp/ccitkYpi.s 			page 13


 455:Src/main.c    **** 
 456:Src/main.c    **** /* USER CODE END 4 */
 457:Src/main.c    **** 
 458:Src/main.c    **** /**
 459:Src/main.c    ****   * @brief  This function is executed in case of error occurrence.
 460:Src/main.c    ****   * @retval None
 461:Src/main.c    ****   */
 462:Src/main.c    **** void Error_Handler(void){
 234              		.loc 1 462 25 is_stmt 1 view -0
 235              		.cfi_startproc
 236              		@ Volatile: function does not return.
 237              		@ args = 0, pretend = 0, frame = 0
 238              		@ frame_needed = 0, uses_anonymous_args = 0
 239              		@ link register save eliminated.
 463:Src/main.c    ****     /* USER CODE BEGIN Error_Handler_Debug */
 464:Src/main.c    ****     /* User can add his own implementation to report the HAL error return state */
 465:Src/main.c    ****     __disable_irq();
 240              		.loc 1 465 5 view .LVU64
 241              	.LBB177:
 242              	.LBI177:
 243              		.file 2 "Drivers/CMSIS/Include/cmsis_gcc.h"
   1:Drivers/CMSIS/Include/cmsis_gcc.h **** /**************************************************************************//**
   2:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @file     cmsis_gcc.h
   3:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @brief    CMSIS compiler GCC header file
   4:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @version  V5.2.0
   5:Drivers/CMSIS/Include/cmsis_gcc.h ****  * @date     08. May 2019
   6:Drivers/CMSIS/Include/cmsis_gcc.h ****  ******************************************************************************/
   7:Drivers/CMSIS/Include/cmsis_gcc.h **** /*
   8:Drivers/CMSIS/Include/cmsis_gcc.h ****  * Copyright (c) 2009-2019 Arm Limited. All rights reserved.
   9:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  10:Drivers/CMSIS/Include/cmsis_gcc.h ****  * SPDX-License-Identifier: Apache-2.0
  11:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  12:Drivers/CMSIS/Include/cmsis_gcc.h ****  * Licensed under the Apache License, Version 2.0 (the License); you may
  13:Drivers/CMSIS/Include/cmsis_gcc.h ****  * not use this file except in compliance with the License.
  14:Drivers/CMSIS/Include/cmsis_gcc.h ****  * You may obtain a copy of the License at
  15:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  16:Drivers/CMSIS/Include/cmsis_gcc.h ****  * www.apache.org/licenses/LICENSE-2.0
  17:Drivers/CMSIS/Include/cmsis_gcc.h ****  *
  18:Drivers/CMSIS/Include/cmsis_gcc.h ****  * Unless required by applicable law or agreed to in writing, software
  19:Drivers/CMSIS/Include/cmsis_gcc.h ****  * distributed under the License is distributed on an AS IS BASIS, WITHOUT
  20:Drivers/CMSIS/Include/cmsis_gcc.h ****  * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  21:Drivers/CMSIS/Include/cmsis_gcc.h ****  * See the License for the specific language governing permissions and
  22:Drivers/CMSIS/Include/cmsis_gcc.h ****  * limitations under the License.
  23:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
  24:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  25:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __CMSIS_GCC_H
  26:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __CMSIS_GCC_H
  27:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  28:Drivers/CMSIS/Include/cmsis_gcc.h **** /* ignore some GCC warnings */
  29:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic push
  30:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic ignored "-Wsign-conversion"
  31:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic ignored "-Wconversion"
  32:Drivers/CMSIS/Include/cmsis_gcc.h **** #pragma GCC diagnostic ignored "-Wunused-parameter"
  33:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  34:Drivers/CMSIS/Include/cmsis_gcc.h **** /* Fallback for __has_builtin */
  35:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __has_builtin
  36:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __has_builtin(x) (0)
ARM GAS  /tmp/ccitkYpi.s 			page 14


  37:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  38:Drivers/CMSIS/Include/cmsis_gcc.h **** 
  39:Drivers/CMSIS/Include/cmsis_gcc.h **** /* CMSIS compiler specific defines */
  40:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __ASM
  41:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __ASM                                  __asm
  42:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  43:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __INLINE
  44:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __INLINE                               inline
  45:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  46:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __STATIC_INLINE
  47:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __STATIC_INLINE                        static inline
  48:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  49:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __STATIC_FORCEINLINE                 
  50:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
  51:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif                                           
  52:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __NO_RETURN
  53:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __NO_RETURN                            __attribute__((__noreturn__))
  54:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  55:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __USED
  56:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __USED                                 __attribute__((used))
  57:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  58:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __WEAK
  59:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __WEAK                                 __attribute__((weak))
  60:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  61:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __PACKED
  62:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __PACKED                               __attribute__((packed, aligned(1)))
  63:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  64:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __PACKED_STRUCT
  65:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __PACKED_STRUCT                        struct __attribute__((packed, aligned(1)))
  66:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  67:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __PACKED_UNION
  68:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __PACKED_UNION                         union __attribute__((packed, aligned(1)))
  69:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  70:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT32        /* deprecated */
  71:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  72:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  73:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  74:Drivers/CMSIS/Include/cmsis_gcc.h ****   struct __attribute__((packed)) T_UINT32 { uint32_t v; };
  75:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
  76:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT32(x)                  (((struct T_UINT32 *)(x))->v)
  77:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  78:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT16_WRITE
  79:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  80:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  81:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  82:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT16_WRITE { uint16_t v; };
  83:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
  84:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT16_WRITE(addr, val)    (void)((((struct T_UINT16_WRITE *)(void *)(addr))-
  85:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
  86:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT16_READ
  87:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  88:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  89:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  90:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT16_READ { uint16_t v; };
  91:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
  92:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT16_READ(addr)          (((const struct T_UINT16_READ *)(const void *)(add
  93:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
ARM GAS  /tmp/ccitkYpi.s 			page 15


  94:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT32_WRITE
  95:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
  96:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
  97:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
  98:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT32_WRITE { uint32_t v; };
  99:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
 100:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT32_WRITE(addr, val)    (void)((((struct T_UINT32_WRITE *)(void *)(addr))-
 101:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 102:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __UNALIGNED_UINT32_READ
 103:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic push
 104:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wpacked"
 105:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic ignored "-Wattributes"
 106:Drivers/CMSIS/Include/cmsis_gcc.h ****   __PACKED_STRUCT T_UINT32_READ { uint32_t v; };
 107:Drivers/CMSIS/Include/cmsis_gcc.h ****   #pragma GCC diagnostic pop
 108:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __UNALIGNED_UINT32_READ(addr)          (((const struct T_UINT32_READ *)(const void *)(add
 109:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 110:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __ALIGNED
 111:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __ALIGNED(x)                           __attribute__((aligned(x)))
 112:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 113:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __RESTRICT
 114:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __RESTRICT                             __restrict
 115:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 116:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef   __COMPILER_BARRIER
 117:Drivers/CMSIS/Include/cmsis_gcc.h ****   #define __COMPILER_BARRIER()                   __ASM volatile("":::"memory")
 118:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 119:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 120:Drivers/CMSIS/Include/cmsis_gcc.h **** /* #########################  Startup and Lowlevel Init  ######################## */
 121:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 122:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __PROGRAM_START
 123:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 124:Drivers/CMSIS/Include/cmsis_gcc.h **** /**
 125:Drivers/CMSIS/Include/cmsis_gcc.h ****   \brief   Initializes data and bss sections
 126:Drivers/CMSIS/Include/cmsis_gcc.h ****   \details This default implementations initialized all data and additional bss
 127:Drivers/CMSIS/Include/cmsis_gcc.h ****            sections relying on .copy.table and .zero.table specified properly
 128:Drivers/CMSIS/Include/cmsis_gcc.h ****            in the used linker script.
 129:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 130:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 131:Drivers/CMSIS/Include/cmsis_gcc.h **** __STATIC_FORCEINLINE __NO_RETURN void __cmsis_start(void)
 132:Drivers/CMSIS/Include/cmsis_gcc.h **** {
 133:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern void _start(void) __NO_RETURN;
 134:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 135:Drivers/CMSIS/Include/cmsis_gcc.h ****   typedef struct {
 136:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t const* src;
 137:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t* dest;
 138:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t  wlen;
 139:Drivers/CMSIS/Include/cmsis_gcc.h ****   } __copy_table_t;
 140:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 141:Drivers/CMSIS/Include/cmsis_gcc.h ****   typedef struct {
 142:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t* dest;
 143:Drivers/CMSIS/Include/cmsis_gcc.h ****     uint32_t  wlen;
 144:Drivers/CMSIS/Include/cmsis_gcc.h ****   } __zero_table_t;
 145:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 146:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __copy_table_t __copy_table_start__;
 147:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __copy_table_t __copy_table_end__;
 148:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __zero_table_t __zero_table_start__;
 149:Drivers/CMSIS/Include/cmsis_gcc.h ****   extern const __zero_table_t __zero_table_end__;
 150:Drivers/CMSIS/Include/cmsis_gcc.h **** 
ARM GAS  /tmp/ccitkYpi.s 			page 16


 151:Drivers/CMSIS/Include/cmsis_gcc.h ****   for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable
 152:Drivers/CMSIS/Include/cmsis_gcc.h ****     for(uint32_t i=0u; i<pTable->wlen; ++i) {
 153:Drivers/CMSIS/Include/cmsis_gcc.h ****       pTable->dest[i] = pTable->src[i];
 154:Drivers/CMSIS/Include/cmsis_gcc.h ****     }
 155:Drivers/CMSIS/Include/cmsis_gcc.h ****   }
 156:Drivers/CMSIS/Include/cmsis_gcc.h ****  
 157:Drivers/CMSIS/Include/cmsis_gcc.h ****   for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable
 158:Drivers/CMSIS/Include/cmsis_gcc.h ****     for(uint32_t i=0u; i<pTable->wlen; ++i) {
 159:Drivers/CMSIS/Include/cmsis_gcc.h ****       pTable->dest[i] = 0u;
 160:Drivers/CMSIS/Include/cmsis_gcc.h ****     }
 161:Drivers/CMSIS/Include/cmsis_gcc.h ****   }
 162:Drivers/CMSIS/Include/cmsis_gcc.h ****  
 163:Drivers/CMSIS/Include/cmsis_gcc.h ****   _start();
 164:Drivers/CMSIS/Include/cmsis_gcc.h **** }
 165:Drivers/CMSIS/Include/cmsis_gcc.h ****   
 166:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __PROGRAM_START           __cmsis_start
 167:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 168:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 169:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __INITIAL_SP
 170:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __INITIAL_SP              __StackTop
 171:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 172:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 173:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __STACK_LIMIT
 174:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __STACK_LIMIT             __StackLimit
 175:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 176:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 177:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __VECTOR_TABLE
 178:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __VECTOR_TABLE            __Vectors
 179:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 180:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 181:Drivers/CMSIS/Include/cmsis_gcc.h **** #ifndef __VECTOR_TABLE_ATTRIBUTE
 182:Drivers/CMSIS/Include/cmsis_gcc.h **** #define __VECTOR_TABLE_ATTRIBUTE  __attribute((used, section(".vectors")))
 183:Drivers/CMSIS/Include/cmsis_gcc.h **** #endif
 184:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 185:Drivers/CMSIS/Include/cmsis_gcc.h **** /* ###########################  Core Function Access  ########################### */
 186:Drivers/CMSIS/Include/cmsis_gcc.h **** /** \ingroup  CMSIS_Core_FunctionInterface
 187:Drivers/CMSIS/Include/cmsis_gcc.h ****     \defgroup CMSIS_Core_RegAccFunctions CMSIS Core Register Access Functions
 188:Drivers/CMSIS/Include/cmsis_gcc.h ****   @{
 189:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 190:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 191:Drivers/CMSIS/Include/cmsis_gcc.h **** /**
 192:Drivers/CMSIS/Include/cmsis_gcc.h ****   \brief   Enable IRQ Interrupts
 193:Drivers/CMSIS/Include/cmsis_gcc.h ****   \details Enables IRQ interrupts by clearing the I-bit in the CPSR.
 194:Drivers/CMSIS/Include/cmsis_gcc.h ****            Can only be executed in Privileged modes.
 195:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 196:Drivers/CMSIS/Include/cmsis_gcc.h **** __STATIC_FORCEINLINE void __enable_irq(void)
 197:Drivers/CMSIS/Include/cmsis_gcc.h **** {
 198:Drivers/CMSIS/Include/cmsis_gcc.h ****   __ASM volatile ("cpsie i" : : : "memory");
 199:Drivers/CMSIS/Include/cmsis_gcc.h **** }
 200:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 201:Drivers/CMSIS/Include/cmsis_gcc.h **** 
 202:Drivers/CMSIS/Include/cmsis_gcc.h **** /**
 203:Drivers/CMSIS/Include/cmsis_gcc.h ****   \brief   Disable IRQ Interrupts
 204:Drivers/CMSIS/Include/cmsis_gcc.h ****   \details Disables IRQ interrupts by setting the I-bit in the CPSR.
 205:Drivers/CMSIS/Include/cmsis_gcc.h ****            Can only be executed in Privileged modes.
 206:Drivers/CMSIS/Include/cmsis_gcc.h ****  */
 207:Drivers/CMSIS/Include/cmsis_gcc.h **** __STATIC_FORCEINLINE void __disable_irq(void)
ARM GAS  /tmp/ccitkYpi.s 			page 17


 244              		.loc 2 207 27 view .LVU65
 245              	.LBB178:
 208:Drivers/CMSIS/Include/cmsis_gcc.h **** {
 209:Drivers/CMSIS/Include/cmsis_gcc.h ****   __ASM volatile ("cpsid i" : : : "memory");
 246              		.loc 2 209 3 view .LVU66
 247              		.loc 2 209 44 is_stmt 0 view .LVU67
 248              		.syntax divided
 249              	@ 209 "Drivers/CMSIS/Include/cmsis_gcc.h" 1
 250 0000 72B6     		cpsid i
 251              	@ 0 "" 2
 252              		.thumb
 253              		.syntax unified
 254              	.L5:
 255              	.LBE178:
 256              	.LBE177:
 466:Src/main.c    ****     while (1) { }
 257              		.loc 1 466 5 is_stmt 1 discriminator 1 view .LVU68
 258              		.loc 1 466 5 discriminator 1 view .LVU69
 259 0002 FEE7     		b	.L5
 260              		.cfi_endproc
 261              	.LFE3861:
 263              		.section	.text._ZL12MX_I2C1_Initv,"ax",%progbits
 264              		.align	1
 265              		.syntax unified
 266              		.code	16
 267              		.thumb_func
 268              		.fpu softvfp
 270              	_ZL12MX_I2C1_Initv:
 271              	.LFB3856:
 255:Src/main.c    ****     /* USER CODE BEGIN I2C1_Init 0 */
 272              		.loc 1 255 31 view -0
 273              		.cfi_startproc
 274              		@ args = 0, pretend = 0, frame = 0
 275              		@ frame_needed = 0, uses_anonymous_args = 0
 276 0000 10B5     		push	{r4, lr}
 277              	.LCFI3:
 278              		.cfi_def_cfa_offset 8
 279              		.cfi_offset 4, -8
 280              		.cfi_offset 14, -4
 263:Src/main.c    ****     hi2c1.Init.Timing           = 0x10707DBC;
 281              		.loc 1 263 5 view .LVU71
 263:Src/main.c    ****     hi2c1.Init.Timing           = 0x10707DBC;
 282              		.loc 1 263 33 is_stmt 0 view .LVU72
 283 0002 1248     		ldr	r0, .L13
 284 0004 124B     		ldr	r3, .L13+4
 285 0006 0360     		str	r3, [r0]
 264:Src/main.c    ****     hi2c1.Init.OwnAddress1      = 0;
 286              		.loc 1 264 5 is_stmt 1 view .LVU73
 264:Src/main.c    ****     hi2c1.Init.OwnAddress1      = 0;
 287              		.loc 1 264 33 is_stmt 0 view .LVU74
 288 0008 124B     		ldr	r3, .L13+8
 289 000a 4360     		str	r3, [r0, #4]
 265:Src/main.c    ****     hi2c1.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
 290              		.loc 1 265 5 is_stmt 1 view .LVU75
 265:Src/main.c    ****     hi2c1.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
 291              		.loc 1 265 33 is_stmt 0 view .LVU76
 292 000c 0023     		movs	r3, #0
ARM GAS  /tmp/ccitkYpi.s 			page 18


 293 000e 8360     		str	r3, [r0, #8]
 266:Src/main.c    ****     hi2c1.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
 294              		.loc 1 266 5 is_stmt 1 view .LVU77
 266:Src/main.c    ****     hi2c1.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
 295              		.loc 1 266 33 is_stmt 0 view .LVU78
 296 0010 0122     		movs	r2, #1
 297 0012 C260     		str	r2, [r0, #12]
 267:Src/main.c    ****     hi2c1.Init.OwnAddress2      = 0;
 298              		.loc 1 267 5 is_stmt 1 view .LVU79
 267:Src/main.c    ****     hi2c1.Init.OwnAddress2      = 0;
 299              		.loc 1 267 33 is_stmt 0 view .LVU80
 300 0014 0361     		str	r3, [r0, #16]
 268:Src/main.c    ****     hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
 301              		.loc 1 268 5 is_stmt 1 view .LVU81
 268:Src/main.c    ****     hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
 302              		.loc 1 268 33 is_stmt 0 view .LVU82
 303 0016 4361     		str	r3, [r0, #20]
 269:Src/main.c    ****     hi2c1.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
 304              		.loc 1 269 5 is_stmt 1 view .LVU83
 269:Src/main.c    ****     hi2c1.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
 305              		.loc 1 269 33 is_stmt 0 view .LVU84
 306 0018 8361     		str	r3, [r0, #24]
 270:Src/main.c    ****     hi2c1.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;
 307              		.loc 1 270 5 is_stmt 1 view .LVU85
 270:Src/main.c    ****     hi2c1.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;
 308              		.loc 1 270 33 is_stmt 0 view .LVU86
 309 001a C361     		str	r3, [r0, #28]
 271:Src/main.c    ****     if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
 310              		.loc 1 271 5 is_stmt 1 view .LVU87
 271:Src/main.c    ****     if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
 311              		.loc 1 271 33 is_stmt 0 view .LVU88
 312 001c 0362     		str	r3, [r0, #32]
 272:Src/main.c    ****         Error_Handler();
 313              		.loc 1 272 5 is_stmt 1 view .LVU89
 272:Src/main.c    ****         Error_Handler();
 314              		.loc 1 272 21 is_stmt 0 view .LVU90
 315 001e FFF7FEFF 		bl	HAL_I2C_Init
 316              	.LVL8:
 272:Src/main.c    ****         Error_Handler();
 317              		.loc 1 272 5 view .LVU91
 318 0022 0028     		cmp	r0, #0
 319 0024 0CD1     		bne	.L10
 278:Src/main.c    ****         Error_Handler();
 320              		.loc 1 278 5 is_stmt 1 view .LVU92
 278:Src/main.c    ****         Error_Handler();
 321              		.loc 1 278 37 is_stmt 0 view .LVU93
 322 0026 0021     		movs	r1, #0
 323 0028 0848     		ldr	r0, .L13
 324 002a FFF7FEFF 		bl	HAL_I2CEx_ConfigAnalogFilter
 325              	.LVL9:
 278:Src/main.c    ****         Error_Handler();
 326              		.loc 1 278 5 view .LVU94
 327 002e 0028     		cmp	r0, #0
 328 0030 08D1     		bne	.L11
 284:Src/main.c    ****         Error_Handler();
 329              		.loc 1 284 5 is_stmt 1 view .LVU95
 284:Src/main.c    ****         Error_Handler();
ARM GAS  /tmp/ccitkYpi.s 			page 19


 330              		.loc 1 284 38 is_stmt 0 view .LVU96
 331 0032 0021     		movs	r1, #0
 332 0034 0548     		ldr	r0, .L13
 333 0036 FFF7FEFF 		bl	HAL_I2CEx_ConfigDigitalFilter
 334              	.LVL10:
 284:Src/main.c    ****         Error_Handler();
 335              		.loc 1 284 5 view .LVU97
 336 003a 0028     		cmp	r0, #0
 337 003c 04D1     		bne	.L12
 290:Src/main.c    **** 
 338              		.loc 1 290 1 view .LVU98
 339              		@ sp needed
 340 003e 10BD     		pop	{r4, pc}
 341              	.L10:
 273:Src/main.c    ****     }
 342              		.loc 1 273 9 is_stmt 1 view .LVU99
 273:Src/main.c    ****     }
 343              		.loc 1 273 22 is_stmt 0 view .LVU100
 344 0040 FFF7FEFF 		bl	Error_Handler
 345              	.LVL11:
 346              	.L11:
 279:Src/main.c    ****     }
 347              		.loc 1 279 9 is_stmt 1 view .LVU101
 279:Src/main.c    ****     }
 348              		.loc 1 279 22 is_stmt 0 view .LVU102
 349 0044 FFF7FEFF 		bl	Error_Handler
 350              	.LVL12:
 351              	.L12:
 285:Src/main.c    ****     }
 352              		.loc 1 285 9 is_stmt 1 view .LVU103
 285:Src/main.c    ****     }
 353              		.loc 1 285 22 is_stmt 0 view .LVU104
 354 0048 FFF7FEFF 		bl	Error_Handler
 355              	.LVL13:
 356              	.L14:
 357              		.align	2
 358              	.L13:
 359 004c 00000000 		.word	.LANCHOR0
 360 0050 00540040 		.word	1073763328
 361 0054 BC7D7010 		.word	275807676
 362              		.cfi_endproc
 363              	.LFE3856:
 365              		.section	.text._ZL19MX_USART2_UART_Initv,"ax",%progbits
 366              		.align	1
 367              		.syntax unified
 368              		.code	16
 369              		.thumb_func
 370              		.fpu softvfp
 372              	_ZL19MX_USART2_UART_Initv:
 373              	.LFB3858:
 336:Src/main.c    ****     /* USER CODE BEGIN USART2_Init 0 */
 374              		.loc 1 336 38 is_stmt 1 view -0
 375              		.cfi_startproc
 376              		@ args = 0, pretend = 0, frame = 0
 377              		@ frame_needed = 0, uses_anonymous_args = 0
 378 0000 10B5     		push	{r4, lr}
 379              	.LCFI4:
ARM GAS  /tmp/ccitkYpi.s 			page 20


 380              		.cfi_def_cfa_offset 8
 381              		.cfi_offset 4, -8
 382              		.cfi_offset 14, -4
 344:Src/main.c    ****     huart2.Init.BaudRate               = 115200;
 383              		.loc 1 344 5 view .LVU106
 344:Src/main.c    ****     huart2.Init.BaudRate               = 115200;
 384              		.loc 1 344 40 is_stmt 0 view .LVU107
 385 0002 1748     		ldr	r0, .L24
 386 0004 174B     		ldr	r3, .L24+4
 387 0006 0360     		str	r3, [r0]
 345:Src/main.c    ****     huart2.Init.WordLength             = UART_WORDLENGTH_8B;
 388              		.loc 1 345 5 is_stmt 1 view .LVU108
 345:Src/main.c    ****     huart2.Init.WordLength             = UART_WORDLENGTH_8B;
 389              		.loc 1 345 40 is_stmt 0 view .LVU109
 390 0008 E123     		movs	r3, #225
 391 000a 5B02     		lsls	r3, r3, #9
 392 000c 4360     		str	r3, [r0, #4]
 346:Src/main.c    ****     huart2.Init.StopBits               = UART_STOPBITS_1;
 393              		.loc 1 346 5 is_stmt 1 view .LVU110
 346:Src/main.c    ****     huart2.Init.StopBits               = UART_STOPBITS_1;
 394              		.loc 1 346 40 is_stmt 0 view .LVU111
 395 000e 0023     		movs	r3, #0
 396 0010 8360     		str	r3, [r0, #8]
 347:Src/main.c    ****     huart2.Init.Parity                 = UART_PARITY_NONE;
 397              		.loc 1 347 5 is_stmt 1 view .LVU112
 347:Src/main.c    ****     huart2.Init.Parity                 = UART_PARITY_NONE;
 398              		.loc 1 347 40 is_stmt 0 view .LVU113
 399 0012 C360     		str	r3, [r0, #12]
 348:Src/main.c    ****     huart2.Init.Mode                   = UART_MODE_TX_RX;
 400              		.loc 1 348 5 is_stmt 1 view .LVU114
 348:Src/main.c    ****     huart2.Init.Mode                   = UART_MODE_TX_RX;
 401              		.loc 1 348 40 is_stmt 0 view .LVU115
 402 0014 0361     		str	r3, [r0, #16]
 349:Src/main.c    ****     huart2.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
 403              		.loc 1 349 5 is_stmt 1 view .LVU116
 349:Src/main.c    ****     huart2.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
 404              		.loc 1 349 40 is_stmt 0 view .LVU117
 405 0016 0C22     		movs	r2, #12
 406 0018 4261     		str	r2, [r0, #20]
 350:Src/main.c    ****     huart2.Init.OverSampling           = UART_OVERSAMPLING_16;
 407              		.loc 1 350 5 is_stmt 1 view .LVU118
 350:Src/main.c    ****     huart2.Init.OverSampling           = UART_OVERSAMPLING_16;
 408              		.loc 1 350 40 is_stmt 0 view .LVU119
 409 001a 8361     		str	r3, [r0, #24]
 351:Src/main.c    ****     huart2.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
 410              		.loc 1 351 5 is_stmt 1 view .LVU120
 351:Src/main.c    ****     huart2.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
 411              		.loc 1 351 40 is_stmt 0 view .LVU121
 412 001c C361     		str	r3, [r0, #28]
 352:Src/main.c    ****     huart2.Init.ClockPrescaler         = UART_PRESCALER_DIV1;
 413              		.loc 1 352 5 is_stmt 1 view .LVU122
 352:Src/main.c    ****     huart2.Init.ClockPrescaler         = UART_PRESCALER_DIV1;
 414              		.loc 1 352 40 is_stmt 0 view .LVU123
 415 001e 0362     		str	r3, [r0, #32]
 353:Src/main.c    ****     huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 416              		.loc 1 353 5 is_stmt 1 view .LVU124
 353:Src/main.c    ****     huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
ARM GAS  /tmp/ccitkYpi.s 			page 21


 417              		.loc 1 353 40 is_stmt 0 view .LVU125
 418 0020 4362     		str	r3, [r0, #36]
 354:Src/main.c    ****     if (HAL_UART_Init(&huart2) != HAL_OK) {
 419              		.loc 1 354 5 is_stmt 1 view .LVU126
 354:Src/main.c    ****     if (HAL_UART_Init(&huart2) != HAL_OK) {
 420              		.loc 1 354 40 is_stmt 0 view .LVU127
 421 0022 8362     		str	r3, [r0, #40]
 355:Src/main.c    ****         Error_Handler();
 422              		.loc 1 355 5 is_stmt 1 view .LVU128
 355:Src/main.c    ****         Error_Handler();
 423              		.loc 1 355 22 is_stmt 0 view .LVU129
 424 0024 FFF7FEFF 		bl	HAL_UART_Init
 425              	.LVL14:
 355:Src/main.c    ****         Error_Handler();
 426              		.loc 1 355 5 view .LVU130
 427 0028 0028     		cmp	r0, #0
 428 002a 11D1     		bne	.L20
 358:Src/main.c    ****         Error_Handler();
 429              		.loc 1 358 5 is_stmt 1 view .LVU131
 358:Src/main.c    ****         Error_Handler();
 430              		.loc 1 358 38 is_stmt 0 view .LVU132
 431 002c 0021     		movs	r1, #0
 432 002e 0C48     		ldr	r0, .L24
 433 0030 FFF7FEFF 		bl	HAL_UARTEx_SetTxFifoThreshold
 434              	.LVL15:
 358:Src/main.c    ****         Error_Handler();
 435              		.loc 1 358 5 view .LVU133
 436 0034 0028     		cmp	r0, #0
 437 0036 0DD1     		bne	.L21
 361:Src/main.c    ****         Error_Handler();
 438              		.loc 1 361 5 is_stmt 1 view .LVU134
 361:Src/main.c    ****         Error_Handler();
 439              		.loc 1 361 38 is_stmt 0 view .LVU135
 440 0038 0021     		movs	r1, #0
 441 003a 0948     		ldr	r0, .L24
 442 003c FFF7FEFF 		bl	HAL_UARTEx_SetRxFifoThreshold
 443              	.LVL16:
 361:Src/main.c    ****         Error_Handler();
 444              		.loc 1 361 5 view .LVU136
 445 0040 0028     		cmp	r0, #0
 446 0042 09D1     		bne	.L22
 364:Src/main.c    ****         Error_Handler();
 447              		.loc 1 364 5 is_stmt 1 view .LVU137
 364:Src/main.c    ****         Error_Handler();
 448              		.loc 1 364 35 is_stmt 0 view .LVU138
 449 0044 0648     		ldr	r0, .L24
 450 0046 FFF7FEFF 		bl	HAL_UARTEx_DisableFifoMode
 451              	.LVL17:
 364:Src/main.c    ****         Error_Handler();
 452              		.loc 1 364 5 view .LVU139
 453 004a 0028     		cmp	r0, #0
 454 004c 06D1     		bne	.L23
 370:Src/main.c    **** 
 455              		.loc 1 370 1 view .LVU140
 456              		@ sp needed
 457 004e 10BD     		pop	{r4, pc}
 458              	.L20:
ARM GAS  /tmp/ccitkYpi.s 			page 22


 356:Src/main.c    ****     }
 459              		.loc 1 356 9 is_stmt 1 view .LVU141
 356:Src/main.c    ****     }
 460              		.loc 1 356 22 is_stmt 0 view .LVU142
 461 0050 FFF7FEFF 		bl	Error_Handler
 462              	.LVL18:
 463              	.L21:
 359:Src/main.c    ****     }
 464              		.loc 1 359 9 is_stmt 1 view .LVU143
 359:Src/main.c    ****     }
 465              		.loc 1 359 22 is_stmt 0 view .LVU144
 466 0054 FFF7FEFF 		bl	Error_Handler
 467              	.LVL19:
 468              	.L22:
 362:Src/main.c    ****     }
 469              		.loc 1 362 9 is_stmt 1 view .LVU145
 362:Src/main.c    ****     }
 470              		.loc 1 362 22 is_stmt 0 view .LVU146
 471 0058 FFF7FEFF 		bl	Error_Handler
 472              	.LVL20:
 473              	.L23:
 365:Src/main.c    ****     }
 474              		.loc 1 365 9 is_stmt 1 view .LVU147
 365:Src/main.c    ****     }
 475              		.loc 1 365 22 is_stmt 0 view .LVU148
 476 005c FFF7FEFF 		bl	Error_Handler
 477              	.LVL21:
 478              	.L25:
 479              		.align	2
 480              	.L24:
 481 0060 00000000 		.word	huart2
 482 0064 00440040 		.word	1073759232
 483              		.cfi_endproc
 484              	.LFE3858:
 486              		.section	.text._ZL19MX_USART3_UART_Initv,"ax",%progbits
 487              		.align	1
 488              		.syntax unified
 489              		.code	16
 490              		.thumb_func
 491              		.fpu softvfp
 493              	_ZL19MX_USART3_UART_Initv:
 494              	.LFB3859:
 377:Src/main.c    ****     /* USER CODE BEGIN USART3_Init 0 */
 495              		.loc 1 377 38 is_stmt 1 view -0
 496              		.cfi_startproc
 497              		@ args = 0, pretend = 0, frame = 0
 498              		@ frame_needed = 0, uses_anonymous_args = 0
 499 0000 10B5     		push	{r4, lr}
 500              	.LCFI5:
 501              		.cfi_def_cfa_offset 8
 502              		.cfi_offset 4, -8
 503              		.cfi_offset 14, -4
 385:Src/main.c    ****     huart3.Init.BaudRate               = 115200;
 504              		.loc 1 385 5 view .LVU150
 385:Src/main.c    ****     huart3.Init.BaudRate               = 115200;
 505              		.loc 1 385 40 is_stmt 0 view .LVU151
 506 0002 0C48     		ldr	r0, .L29
ARM GAS  /tmp/ccitkYpi.s 			page 23


 507 0004 0C4B     		ldr	r3, .L29+4
 508 0006 0360     		str	r3, [r0]
 386:Src/main.c    ****     huart3.Init.WordLength             = UART_WORDLENGTH_8B;
 509              		.loc 1 386 5 is_stmt 1 view .LVU152
 386:Src/main.c    ****     huart3.Init.WordLength             = UART_WORDLENGTH_8B;
 510              		.loc 1 386 40 is_stmt 0 view .LVU153
 511 0008 E123     		movs	r3, #225
 512 000a 5B02     		lsls	r3, r3, #9
 513 000c 4360     		str	r3, [r0, #4]
 387:Src/main.c    ****     huart3.Init.StopBits               = UART_STOPBITS_1;
 514              		.loc 1 387 5 is_stmt 1 view .LVU154
 387:Src/main.c    ****     huart3.Init.StopBits               = UART_STOPBITS_1;
 515              		.loc 1 387 40 is_stmt 0 view .LVU155
 516 000e 0023     		movs	r3, #0
 517 0010 8360     		str	r3, [r0, #8]
 388:Src/main.c    ****     huart3.Init.Parity                 = UART_PARITY_NONE;
 518              		.loc 1 388 5 is_stmt 1 view .LVU156
 388:Src/main.c    ****     huart3.Init.Parity                 = UART_PARITY_NONE;
 519              		.loc 1 388 40 is_stmt 0 view .LVU157
 520 0012 C360     		str	r3, [r0, #12]
 389:Src/main.c    ****     huart3.Init.Mode                   = UART_MODE_TX_RX;
 521              		.loc 1 389 5 is_stmt 1 view .LVU158
 389:Src/main.c    ****     huart3.Init.Mode                   = UART_MODE_TX_RX;
 522              		.loc 1 389 40 is_stmt 0 view .LVU159
 523 0014 0361     		str	r3, [r0, #16]
 390:Src/main.c    ****     huart3.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
 524              		.loc 1 390 5 is_stmt 1 view .LVU160
 390:Src/main.c    ****     huart3.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
 525              		.loc 1 390 40 is_stmt 0 view .LVU161
 526 0016 0C22     		movs	r2, #12
 527 0018 4261     		str	r2, [r0, #20]
 391:Src/main.c    ****     huart3.Init.OverSampling           = UART_OVERSAMPLING_16;
 528              		.loc 1 391 5 is_stmt 1 view .LVU162
 391:Src/main.c    ****     huart3.Init.OverSampling           = UART_OVERSAMPLING_16;
 529              		.loc 1 391 40 is_stmt 0 view .LVU163
 530 001a 8361     		str	r3, [r0, #24]
 392:Src/main.c    ****     huart3.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
 531              		.loc 1 392 5 is_stmt 1 view .LVU164
 392:Src/main.c    ****     huart3.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
 532              		.loc 1 392 40 is_stmt 0 view .LVU165
 533 001c C361     		str	r3, [r0, #28]
 393:Src/main.c    ****     huart3.Init.ClockPrescaler         = UART_PRESCALER_DIV1;
 534              		.loc 1 393 5 is_stmt 1 view .LVU166
 393:Src/main.c    ****     huart3.Init.ClockPrescaler         = UART_PRESCALER_DIV1;
 535              		.loc 1 393 40 is_stmt 0 view .LVU167
 536 001e 0362     		str	r3, [r0, #32]
 394:Src/main.c    ****     huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 537              		.loc 1 394 5 is_stmt 1 view .LVU168
 394:Src/main.c    ****     huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
 538              		.loc 1 394 40 is_stmt 0 view .LVU169
 539 0020 4362     		str	r3, [r0, #36]
 395:Src/main.c    ****     if (HAL_UART_Init(&huart3) != HAL_OK) {
 540              		.loc 1 395 5 is_stmt 1 view .LVU170
 395:Src/main.c    ****     if (HAL_UART_Init(&huart3) != HAL_OK) {
 541              		.loc 1 395 40 is_stmt 0 view .LVU171
 542 0022 8362     		str	r3, [r0, #40]
 396:Src/main.c    ****         Error_Handler();
ARM GAS  /tmp/ccitkYpi.s 			page 24


 543              		.loc 1 396 5 is_stmt 1 view .LVU172
 396:Src/main.c    ****         Error_Handler();
 544              		.loc 1 396 22 is_stmt 0 view .LVU173
 545 0024 FFF7FEFF 		bl	HAL_UART_Init
 546              	.LVL22:
 396:Src/main.c    ****         Error_Handler();
 547              		.loc 1 396 5 view .LVU174
 548 0028 0028     		cmp	r0, #0
 549 002a 00D1     		bne	.L28
 402:Src/main.c    **** 
 550              		.loc 1 402 1 view .LVU175
 551              		@ sp needed
 552 002c 10BD     		pop	{r4, pc}
 553              	.L28:
 397:Src/main.c    ****     }
 554              		.loc 1 397 9 is_stmt 1 view .LVU176
 397:Src/main.c    ****     }
 555              		.loc 1 397 22 is_stmt 0 view .LVU177
 556 002e FFF7FEFF 		bl	Error_Handler
 557              	.LVL23:
 558              	.L30:
 559 0032 C046     		.align	2
 560              	.L29:
 561 0034 00000000 		.word	huart3
 562 0038 00480040 		.word	1073760256
 563              		.cfi_endproc
 564              	.LFE3859:
 566              		.section	.text._ZL12MX_ADC1_Initv,"ax",%progbits
 567              		.align	1
 568              		.syntax unified
 569              		.code	16
 570              		.thumb_func
 571              		.fpu softvfp
 573              	_ZL12MX_ADC1_Initv:
 574              	.LFB3855:
 201:Src/main.c    ****     /* USER CODE BEGIN ADC1_Init 0 */
 575              		.loc 1 201 31 is_stmt 1 view -0
 576              		.cfi_startproc
 577              		@ args = 0, pretend = 0, frame = 16
 578              		@ frame_needed = 0, uses_anonymous_args = 0
 579 0000 00B5     		push	{lr}
 580              	.LCFI6:
 581              		.cfi_def_cfa_offset 4
 582              		.cfi_offset 14, -4
 583 0002 85B0     		sub	sp, sp, #20
 584              	.LCFI7:
 585              		.cfi_def_cfa_offset 24
 206:Src/main.c    **** 
 586              		.loc 1 206 5 view .LVU179
 206:Src/main.c    **** 
 587              		.loc 1 206 28 is_stmt 0 view .LVU180
 588 0004 0C22     		movs	r2, #12
 589 0006 0021     		movs	r1, #0
 590 0008 01A8     		add	r0, sp, #4
 591 000a FFF7FEFF 		bl	memset
 592              	.LVL24:
 214:Src/main.c    ****     hadc1.Init.ClockPrescaler        = ADC_CLOCK_SYNC_PCLK_DIV4;
ARM GAS  /tmp/ccitkYpi.s 			page 25


 593              		.loc 1 214 5 is_stmt 1 view .LVU181
 214:Src/main.c    ****     hadc1.Init.ClockPrescaler        = ADC_CLOCK_SYNC_PCLK_DIV4;
 594              		.loc 1 214 20 is_stmt 0 view .LVU182
 595 000e 1948     		ldr	r0, .L36
 596 0010 194B     		ldr	r3, .L36+4
 597 0012 0360     		str	r3, [r0]
 215:Src/main.c    ****     hadc1.Init.Resolution            = ADC_RESOLUTION_12B;
 598              		.loc 1 215 5 is_stmt 1 view .LVU183
 215:Src/main.c    ****     hadc1.Init.Resolution            = ADC_RESOLUTION_12B;
 599              		.loc 1 215 38 is_stmt 0 view .LVU184
 600 0014 8023     		movs	r3, #128
 601 0016 1B06     		lsls	r3, r3, #24
 602 0018 4360     		str	r3, [r0, #4]
 216:Src/main.c    ****     hadc1.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
 603              		.loc 1 216 5 is_stmt 1 view .LVU185
 216:Src/main.c    ****     hadc1.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
 604              		.loc 1 216 38 is_stmt 0 view .LVU186
 605 001a 0023     		movs	r3, #0
 606 001c 8360     		str	r3, [r0, #8]
 217:Src/main.c    ****     hadc1.Init.ScanConvMode          = ADC_SCAN_DISABLE;
 607              		.loc 1 217 5 is_stmt 1 view .LVU187
 217:Src/main.c    ****     hadc1.Init.ScanConvMode          = ADC_SCAN_DISABLE;
 608              		.loc 1 217 38 is_stmt 0 view .LVU188
 609 001e C360     		str	r3, [r0, #12]
 218:Src/main.c    ****     hadc1.Init.EOCSelection          = ADC_EOC_SINGLE_CONV;
 610              		.loc 1 218 5 is_stmt 1 view .LVU189
 218:Src/main.c    ****     hadc1.Init.EOCSelection          = ADC_EOC_SINGLE_CONV;
 611              		.loc 1 218 38 is_stmt 0 view .LVU190
 612 0020 0361     		str	r3, [r0, #16]
 219:Src/main.c    ****     hadc1.Init.LowPowerAutoWait      = DISABLE;
 613              		.loc 1 219 5 is_stmt 1 view .LVU191
 219:Src/main.c    ****     hadc1.Init.LowPowerAutoWait      = DISABLE;
 614              		.loc 1 219 38 is_stmt 0 view .LVU192
 615 0022 0422     		movs	r2, #4
 616 0024 4261     		str	r2, [r0, #20]
 220:Src/main.c    ****     hadc1.Init.LowPowerAutoPowerOff  = DISABLE;
 617              		.loc 1 220 5 is_stmt 1 view .LVU193
 220:Src/main.c    ****     hadc1.Init.LowPowerAutoPowerOff  = DISABLE;
 618              		.loc 1 220 38 is_stmt 0 view .LVU194
 619 0026 0376     		strb	r3, [r0, #24]
 221:Src/main.c    ****     hadc1.Init.ContinuousConvMode    = DISABLE;
 620              		.loc 1 221 5 is_stmt 1 view .LVU195
 221:Src/main.c    ****     hadc1.Init.ContinuousConvMode    = DISABLE;
 621              		.loc 1 221 38 is_stmt 0 view .LVU196
 622 0028 4376     		strb	r3, [r0, #25]
 222:Src/main.c    ****     hadc1.Init.NbrOfConversion       = 1;
 623              		.loc 1 222 5 is_stmt 1 view .LVU197
 222:Src/main.c    ****     hadc1.Init.NbrOfConversion       = 1;
 624              		.loc 1 222 38 is_stmt 0 view .LVU198
 625 002a 8376     		strb	r3, [r0, #26]
 223:Src/main.c    ****     hadc1.Init.DiscontinuousConvMode = DISABLE;
 626              		.loc 1 223 5 is_stmt 1 view .LVU199
 223:Src/main.c    ****     hadc1.Init.DiscontinuousConvMode = DISABLE;
 627              		.loc 1 223 38 is_stmt 0 view .LVU200
 628 002c 033A     		subs	r2, r2, #3
 629 002e C261     		str	r2, [r0, #28]
 224:Src/main.c    ****     hadc1.Init.ExternalTrigConv      = ADC_SOFTWARE_START;
ARM GAS  /tmp/ccitkYpi.s 			page 26


 630              		.loc 1 224 5 is_stmt 1 view .LVU201
 224:Src/main.c    ****     hadc1.Init.ExternalTrigConv      = ADC_SOFTWARE_START;
 631              		.loc 1 224 38 is_stmt 0 view .LVU202
 632 0030 1F32     		adds	r2, r2, #31
 633 0032 8354     		strb	r3, [r0, r2]
 225:Src/main.c    ****     hadc1.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
 634              		.loc 1 225 5 is_stmt 1 view .LVU203
 225:Src/main.c    ****     hadc1.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
 635              		.loc 1 225 38 is_stmt 0 view .LVU204
 636 0034 4362     		str	r3, [r0, #36]
 226:Src/main.c    ****     hadc1.Init.DMAContinuousRequests = DISABLE;
 637              		.loc 1 226 5 is_stmt 1 view .LVU205
 226:Src/main.c    ****     hadc1.Init.DMAContinuousRequests = DISABLE;
 638              		.loc 1 226 38 is_stmt 0 view .LVU206
 639 0036 8362     		str	r3, [r0, #40]
 227:Src/main.c    ****     hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
 640              		.loc 1 227 5 is_stmt 1 view .LVU207
 227:Src/main.c    ****     hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
 641              		.loc 1 227 38 is_stmt 0 view .LVU208
 642 0038 0C32     		adds	r2, r2, #12
 643 003a 8354     		strb	r3, [r0, r2]
 228:Src/main.c    ****     hadc1.Init.SamplingTimeCommon1  = ADC_SAMPLETIME_1CYCLE_5;
 644              		.loc 1 228 5 is_stmt 1 view .LVU209
 228:Src/main.c    ****     hadc1.Init.SamplingTimeCommon1  = ADC_SAMPLETIME_1CYCLE_5;
 645              		.loc 1 228 24 is_stmt 0 view .LVU210
 646 003c 0363     		str	r3, [r0, #48]
 229:Src/main.c    ****     hadc1.Init.SamplingTimeCommon2  = ADC_SAMPLETIME_1CYCLE_5;
 647              		.loc 1 229 5 is_stmt 1 view .LVU211
 229:Src/main.c    ****     hadc1.Init.SamplingTimeCommon2  = ADC_SAMPLETIME_1CYCLE_5;
 648              		.loc 1 229 37 is_stmt 0 view .LVU212
 649 003e 4363     		str	r3, [r0, #52]
 230:Src/main.c    ****     hadc1.Init.OversamplingMode     = DISABLE;
 650              		.loc 1 230 5 is_stmt 1 view .LVU213
 230:Src/main.c    ****     hadc1.Init.OversamplingMode     = DISABLE;
 651              		.loc 1 230 37 is_stmt 0 view .LVU214
 652 0040 8363     		str	r3, [r0, #56]
 231:Src/main.c    ****     hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
 653              		.loc 1 231 5 is_stmt 1 view .LVU215
 231:Src/main.c    ****     hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
 654              		.loc 1 231 37 is_stmt 0 view .LVU216
 655 0042 1032     		adds	r2, r2, #16
 656 0044 8354     		strb	r3, [r0, r2]
 232:Src/main.c    ****     if (HAL_ADC_Init(&hadc1) != HAL_OK) {
 657              		.loc 1 232 5 is_stmt 1 view .LVU217
 232:Src/main.c    ****     if (HAL_ADC_Init(&hadc1) != HAL_OK) {
 658              		.loc 1 232 37 is_stmt 0 view .LVU218
 659 0046 C364     		str	r3, [r0, #76]
 233:Src/main.c    ****         Error_Handler();
 660              		.loc 1 233 5 is_stmt 1 view .LVU219
 233:Src/main.c    ****         Error_Handler();
 661              		.loc 1 233 21 is_stmt 0 view .LVU220
 662 0048 FFF7FEFF 		bl	HAL_ADC_Init
 663              	.LVL25:
 233:Src/main.c    ****         Error_Handler();
 664              		.loc 1 233 5 view .LVU221
 665 004c 0028     		cmp	r0, #0
 666 004e 0CD1     		bne	.L34
ARM GAS  /tmp/ccitkYpi.s 			page 27


 239:Src/main.c    ****     sConfig.Rank         = ADC_REGULAR_RANK_1;
 667              		.loc 1 239 5 is_stmt 1 view .LVU222
 239:Src/main.c    ****     sConfig.Rank         = ADC_REGULAR_RANK_1;
 668              		.loc 1 239 26 is_stmt 0 view .LVU223
 669 0050 0A4B     		ldr	r3, .L36+8
 670 0052 0193     		str	r3, [sp, #4]
 240:Src/main.c    ****     sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
 671              		.loc 1 240 5 is_stmt 1 view .LVU224
 240:Src/main.c    ****     sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
 672              		.loc 1 240 26 is_stmt 0 view .LVU225
 673 0054 0023     		movs	r3, #0
 674 0056 0293     		str	r3, [sp, #8]
 241:Src/main.c    ****     if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
 675              		.loc 1 241 5 is_stmt 1 view .LVU226
 241:Src/main.c    ****     if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
 676              		.loc 1 241 26 is_stmt 0 view .LVU227
 677 0058 0393     		str	r3, [sp, #12]
 242:Src/main.c    ****         Error_Handler();
 678              		.loc 1 242 5 is_stmt 1 view .LVU228
 242:Src/main.c    ****         Error_Handler();
 679              		.loc 1 242 30 is_stmt 0 view .LVU229
 680 005a 01A9     		add	r1, sp, #4
 681 005c 0548     		ldr	r0, .L36
 682 005e FFF7FEFF 		bl	HAL_ADC_ConfigChannel
 683              	.LVL26:
 242:Src/main.c    ****         Error_Handler();
 684              		.loc 1 242 5 view .LVU230
 685 0062 0028     		cmp	r0, #0
 686 0064 03D1     		bne	.L35
 248:Src/main.c    **** 
 687              		.loc 1 248 1 view .LVU231
 688 0066 05B0     		add	sp, sp, #20
 689              		@ sp needed
 690 0068 00BD     		pop	{pc}
 691              	.L34:
 234:Src/main.c    ****     }
 692              		.loc 1 234 9 is_stmt 1 view .LVU232
 234:Src/main.c    ****     }
 693              		.loc 1 234 22 is_stmt 0 view .LVU233
 694 006a FFF7FEFF 		bl	Error_Handler
 695              	.LVL27:
 696              	.L35:
 243:Src/main.c    ****     }
 697              		.loc 1 243 9 is_stmt 1 view .LVU234
 243:Src/main.c    ****     }
 698              		.loc 1 243 22 is_stmt 0 view .LVU235
 699 006e FFF7FEFF 		bl	Error_Handler
 700              	.LVL28:
 701              	.L37:
 702 0072 C046     		.align	2
 703              	.L36:
 704 0074 00000000 		.word	.LANCHOR1
 705 0078 00240140 		.word	1073816576
 706 007c 40000018 		.word	402653248
 707              		.cfi_endproc
 708              	.LFE3855:
 710              		.section	.text._ZL12MX_TIM2_Initv,"ax",%progbits
ARM GAS  /tmp/ccitkYpi.s 			page 28


 711              		.align	1
 712              		.syntax unified
 713              		.code	16
 714              		.thumb_func
 715              		.fpu softvfp
 717              	_ZL12MX_TIM2_Initv:
 718              	.LFB3857:
 297:Src/main.c    ****     /* USER CODE BEGIN TIM2_Init 0 */
 719              		.loc 1 297 31 is_stmt 1 view -0
 720              		.cfi_startproc
 721              		@ args = 0, pretend = 0, frame = 32
 722              		@ frame_needed = 0, uses_anonymous_args = 0
 723 0000 00B5     		push	{lr}
 724              	.LCFI8:
 725              		.cfi_def_cfa_offset 4
 726              		.cfi_offset 14, -4
 727 0002 89B0     		sub	sp, sp, #36
 728              	.LCFI9:
 729              		.cfi_def_cfa_offset 40
 302:Src/main.c    ****     TIM_MasterConfigTypeDef sMasterConfig     = { 0 };
 730              		.loc 1 302 5 view .LVU237
 302:Src/main.c    ****     TIM_MasterConfigTypeDef sMasterConfig     = { 0 };
 731              		.loc 1 302 28 is_stmt 0 view .LVU238
 732 0004 1022     		movs	r2, #16
 733 0006 0021     		movs	r1, #0
 734 0008 04A8     		add	r0, sp, #16
 735 000a FFF7FEFF 		bl	memset
 736              	.LVL29:
 303:Src/main.c    **** 
 737              		.loc 1 303 5 is_stmt 1 view .LVU239
 303:Src/main.c    **** 
 738              		.loc 1 303 29 is_stmt 0 view .LVU240
 739 000e 0C22     		movs	r2, #12
 740 0010 0021     		movs	r1, #0
 741 0012 01A8     		add	r0, sp, #4
 742 0014 FFF7FEFF 		bl	memset
 743              	.LVL30:
 308:Src/main.c    ****     htim2.Init.Prescaler         = 0;
 744              		.loc 1 308 5 is_stmt 1 view .LVU241
 308:Src/main.c    ****     htim2.Init.Prescaler         = 0;
 745              		.loc 1 308 34 is_stmt 0 view .LVU242
 746 0018 1448     		ldr	r0, .L45
 747 001a 8023     		movs	r3, #128
 748 001c DB05     		lsls	r3, r3, #23
 749 001e 0360     		str	r3, [r0]
 309:Src/main.c    ****     htim2.Init.CounterMode       = TIM_COUNTERMODE_UP;
 750              		.loc 1 309 5 is_stmt 1 view .LVU243
 309:Src/main.c    ****     htim2.Init.CounterMode       = TIM_COUNTERMODE_UP;
 751              		.loc 1 309 34 is_stmt 0 view .LVU244
 752 0020 0023     		movs	r3, #0
 753 0022 4360     		str	r3, [r0, #4]
 310:Src/main.c    ****     htim2.Init.Period            = 4294967295;
 754              		.loc 1 310 5 is_stmt 1 view .LVU245
 310:Src/main.c    ****     htim2.Init.Period            = 4294967295;
 755              		.loc 1 310 34 is_stmt 0 view .LVU246
 756 0024 8360     		str	r3, [r0, #8]
 311:Src/main.c    ****     htim2.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
ARM GAS  /tmp/ccitkYpi.s 			page 29


 757              		.loc 1 311 5 is_stmt 1 view .LVU247
 311:Src/main.c    ****     htim2.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
 758              		.loc 1 311 34 is_stmt 0 view .LVU248
 759 0026 0122     		movs	r2, #1
 760 0028 5242     		rsbs	r2, r2, #0
 761 002a C260     		str	r2, [r0, #12]
 312:Src/main.c    ****     htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
 762              		.loc 1 312 5 is_stmt 1 view .LVU249
 312:Src/main.c    ****     htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
 763              		.loc 1 312 34 is_stmt 0 view .LVU250
 764 002c 0361     		str	r3, [r0, #16]
 313:Src/main.c    ****     if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
 765              		.loc 1 313 5 is_stmt 1 view .LVU251
 313:Src/main.c    ****     if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
 766              		.loc 1 313 34 is_stmt 0 view .LVU252
 767 002e 8361     		str	r3, [r0, #24]
 314:Src/main.c    ****         Error_Handler();
 768              		.loc 1 314 5 is_stmt 1 view .LVU253
 314:Src/main.c    ****         Error_Handler();
 769              		.loc 1 314 26 is_stmt 0 view .LVU254
 770 0030 FFF7FEFF 		bl	HAL_TIM_Base_Init
 771              	.LVL31:
 314:Src/main.c    ****         Error_Handler();
 772              		.loc 1 314 5 view .LVU255
 773 0034 0028     		cmp	r0, #0
 774 0036 13D1     		bne	.L42
 317:Src/main.c    ****     if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
 775              		.loc 1 317 5 is_stmt 1 view .LVU256
 317:Src/main.c    ****     if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
 776              		.loc 1 317 36 is_stmt 0 view .LVU257
 777 0038 8023     		movs	r3, #128
 778 003a 5B01     		lsls	r3, r3, #5
 779 003c 0493     		str	r3, [sp, #16]
 318:Src/main.c    ****         Error_Handler();
 780              		.loc 1 318 5 is_stmt 1 view .LVU258
 318:Src/main.c    ****         Error_Handler();
 781              		.loc 1 318 34 is_stmt 0 view .LVU259
 782 003e 04A9     		add	r1, sp, #16
 783 0040 0A48     		ldr	r0, .L45
 784 0042 FFF7FEFF 		bl	HAL_TIM_ConfigClockSource
 785              	.LVL32:
 318:Src/main.c    ****         Error_Handler();
 786              		.loc 1 318 5 view .LVU260
 787 0046 0028     		cmp	r0, #0
 788 0048 0CD1     		bne	.L43
 321:Src/main.c    ****     sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
 789              		.loc 1 321 5 is_stmt 1 view .LVU261
 321:Src/main.c    ****     sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
 790              		.loc 1 321 39 is_stmt 0 view .LVU262
 791 004a 0023     		movs	r3, #0
 792 004c 0193     		str	r3, [sp, #4]
 322:Src/main.c    ****     if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK) {
 793              		.loc 1 322 5 is_stmt 1 view .LVU263
 322:Src/main.c    ****     if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK) {
 794              		.loc 1 322 39 is_stmt 0 view .LVU264
 795 004e 0393     		str	r3, [sp, #12]
 323:Src/main.c    ****         Error_Handler();
ARM GAS  /tmp/ccitkYpi.s 			page 30


 796              		.loc 1 323 5 is_stmt 1 view .LVU265
 323:Src/main.c    ****         Error_Handler();
 797              		.loc 1 323 46 is_stmt 0 view .LVU266
 798 0050 01A9     		add	r1, sp, #4
 799 0052 0648     		ldr	r0, .L45
 800 0054 FFF7FEFF 		bl	HAL_TIMEx_MasterConfigSynchronization
 801              	.LVL33:
 323:Src/main.c    ****         Error_Handler();
 802              		.loc 1 323 5 view .LVU267
 803 0058 0028     		cmp	r0, #0
 804 005a 05D1     		bne	.L44
 329:Src/main.c    **** 
 805              		.loc 1 329 1 view .LVU268
 806 005c 09B0     		add	sp, sp, #36
 807              		@ sp needed
 808 005e 00BD     		pop	{pc}
 809              	.L42:
 315:Src/main.c    ****     }
 810              		.loc 1 315 9 is_stmt 1 view .LVU269
 315:Src/main.c    ****     }
 811              		.loc 1 315 22 is_stmt 0 view .LVU270
 812 0060 FFF7FEFF 		bl	Error_Handler
 813              	.LVL34:
 814              	.L43:
 319:Src/main.c    ****     }
 815              		.loc 1 319 9 is_stmt 1 view .LVU271
 319:Src/main.c    ****     }
 816              		.loc 1 319 22 is_stmt 0 view .LVU272
 817 0064 FFF7FEFF 		bl	Error_Handler
 818              	.LVL35:
 819              	.L44:
 324:Src/main.c    ****     }
 820              		.loc 1 324 9 is_stmt 1 view .LVU273
 324:Src/main.c    ****     }
 821              		.loc 1 324 22 is_stmt 0 view .LVU274
 822 0068 FFF7FEFF 		bl	Error_Handler
 823              	.LVL36:
 824              	.L46:
 825              		.align	2
 826              	.L45:
 827 006c 00000000 		.word	.LANCHOR2
 828              		.cfi_endproc
 829              	.LFE3857:
 831              		.section	.text._Z18SystemClock_Configv,"ax",%progbits
 832              		.align	1
 833              		.global	_Z18SystemClock_Configv
 834              		.syntax unified
 835              		.code	16
 836              		.thumb_func
 837              		.fpu softvfp
 839              	_Z18SystemClock_Configv:
 840              	.LFB3854:
 145:Src/main.c    ****     RCC_OscInitTypeDef RCC_OscInitStruct   = { 0 };
 841              		.loc 1 145 30 is_stmt 1 view -0
 842              		.cfi_startproc
 843              		@ args = 0, pretend = 0, frame = 128
 844              		@ frame_needed = 0, uses_anonymous_args = 0
ARM GAS  /tmp/ccitkYpi.s 			page 31


 845 0000 00B5     		push	{lr}
 846              	.LCFI10:
 847              		.cfi_def_cfa_offset 4
 848              		.cfi_offset 14, -4
 849 0002 A1B0     		sub	sp, sp, #132
 850              	.LCFI11:
 851              		.cfi_def_cfa_offset 136
 146:Src/main.c    ****     RCC_ClkInitTypeDef RCC_ClkInitStruct   = { 0 };
 852              		.loc 1 146 5 view .LVU276
 146:Src/main.c    ****     RCC_ClkInitTypeDef RCC_ClkInitStruct   = { 0 };
 853              		.loc 1 146 24 is_stmt 0 view .LVU277
 854 0004 3822     		movs	r2, #56
 855 0006 0021     		movs	r1, #0
 856 0008 12A8     		add	r0, sp, #72
 857 000a FFF7FEFF 		bl	memset
 858              	.LVL37:
 147:Src/main.c    ****     RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };
 859              		.loc 1 147 5 is_stmt 1 view .LVU278
 147:Src/main.c    ****     RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };
 860              		.loc 1 147 24 is_stmt 0 view .LVU279
 861 000e 1022     		movs	r2, #16
 862 0010 0021     		movs	r1, #0
 863 0012 0EA8     		add	r0, sp, #56
 864 0014 FFF7FEFF 		bl	memset
 865              	.LVL38:
 148:Src/main.c    **** 
 866              		.loc 1 148 5 is_stmt 1 view .LVU280
 148:Src/main.c    **** 
 867              		.loc 1 148 30 is_stmt 0 view .LVU281
 868 0018 3422     		movs	r2, #52
 869 001a 0021     		movs	r1, #0
 870 001c 01A8     		add	r0, sp, #4
 871 001e FFF7FEFF 		bl	memset
 872              	.LVL39:
 152:Src/main.c    **** 
 873              		.loc 1 152 5 is_stmt 1 view .LVU282
 152:Src/main.c    **** 
 874              		.loc 1 152 36 is_stmt 0 view .LVU283
 875 0022 8020     		movs	r0, #128
 876 0024 8000     		lsls	r0, r0, #2
 877 0026 FFF7FEFF 		bl	HAL_PWREx_ControlVoltageScaling
 878              	.LVL40:
 157:Src/main.c    ****     RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
 879              		.loc 1 157 5 is_stmt 1 view .LVU284
 157:Src/main.c    ****     RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
 880              		.loc 1 157 43 is_stmt 0 view .LVU285
 881 002a 0223     		movs	r3, #2
 882 002c 1293     		str	r3, [sp, #72]
 158:Src/main.c    ****     RCC_OscInitStruct.HSIDiv              = RCC_HSI_DIV1;
 883              		.loc 1 158 5 is_stmt 1 view .LVU286
 158:Src/main.c    ****     RCC_OscInitStruct.HSIDiv              = RCC_HSI_DIV1;
 884              		.loc 1 158 43 is_stmt 0 view .LVU287
 885 002e 8022     		movs	r2, #128
 886 0030 5200     		lsls	r2, r2, #1
 887 0032 1592     		str	r2, [sp, #84]
 159:Src/main.c    ****     RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
 888              		.loc 1 159 5 is_stmt 1 view .LVU288
ARM GAS  /tmp/ccitkYpi.s 			page 32


 159:Src/main.c    ****     RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
 889              		.loc 1 159 43 is_stmt 0 view .LVU289
 890 0034 0022     		movs	r2, #0
 891 0036 1692     		str	r2, [sp, #88]
 160:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
 892              		.loc 1 160 5 is_stmt 1 view .LVU290
 160:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
 893              		.loc 1 160 43 is_stmt 0 view .LVU291
 894 0038 4021     		movs	r1, #64
 895 003a 1791     		str	r1, [sp, #92]
 161:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
 896              		.loc 1 161 5 is_stmt 1 view .LVU292
 161:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
 897              		.loc 1 161 43 is_stmt 0 view .LVU293
 898 003c 1993     		str	r3, [sp, #100]
 162:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLM            = RCC_PLLM_DIV1;
 899              		.loc 1 162 5 is_stmt 1 view .LVU294
 162:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLM            = RCC_PLLM_DIV1;
 900              		.loc 1 162 43 is_stmt 0 view .LVU295
 901 003e 1A93     		str	r3, [sp, #104]
 163:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLN            = 8;
 902              		.loc 1 163 5 is_stmt 1 view .LVU296
 163:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLN            = 8;
 903              		.loc 1 163 43 is_stmt 0 view .LVU297
 904 0040 1B92     		str	r2, [sp, #108]
 164:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLP            = RCC_PLLP_DIV2;
 905              		.loc 1 164 5 is_stmt 1 view .LVU298
 164:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLP            = RCC_PLLP_DIV2;
 906              		.loc 1 164 43 is_stmt 0 view .LVU299
 907 0042 0633     		adds	r3, r3, #6
 908 0044 1C93     		str	r3, [sp, #112]
 165:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLQ            = RCC_PLLQ_DIV2;
 909              		.loc 1 165 5 is_stmt 1 view .LVU300
 165:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLQ            = RCC_PLLQ_DIV2;
 910              		.loc 1 165 43 is_stmt 0 view .LVU301
 911 0046 8023     		movs	r3, #128
 912 0048 9B02     		lsls	r3, r3, #10
 913 004a 1D93     		str	r3, [sp, #116]
 166:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLR            = RCC_PLLR_DIV2;
 914              		.loc 1 166 5 is_stmt 1 view .LVU302
 166:Src/main.c    ****     RCC_OscInitStruct.PLL.PLLR            = RCC_PLLR_DIV2;
 915              		.loc 1 166 43 is_stmt 0 view .LVU303
 916 004c 8023     		movs	r3, #128
 917 004e 9B04     		lsls	r3, r3, #18
 918 0050 1E93     		str	r3, [sp, #120]
 167:Src/main.c    ****     if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
 919              		.loc 1 167 5 is_stmt 1 view .LVU304
 167:Src/main.c    ****     if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
 920              		.loc 1 167 43 is_stmt 0 view .LVU305
 921 0052 8023     		movs	r3, #128
 922 0054 9B05     		lsls	r3, r3, #22
 923 0056 1F93     		str	r3, [sp, #124]
 168:Src/main.c    ****         Error_Handler();
 924              		.loc 1 168 5 is_stmt 1 view .LVU306
 168:Src/main.c    ****         Error_Handler();
 925              		.loc 1 168 26 is_stmt 0 view .LVU307
 926 0058 12A8     		add	r0, sp, #72
ARM GAS  /tmp/ccitkYpi.s 			page 33


 927 005a FFF7FEFF 		bl	HAL_RCC_OscConfig
 928              	.LVL41:
 168:Src/main.c    ****         Error_Handler();
 929              		.loc 1 168 5 view .LVU308
 930 005e 0028     		cmp	r0, #0
 931 0060 19D1     		bne	.L51
 174:Src/main.c    ****       | RCC_CLOCKTYPE_PCLK1;
 932              		.loc 1 174 5 is_stmt 1 view .LVU309
 174:Src/main.c    ****       | RCC_CLOCKTYPE_PCLK1;
 933              		.loc 1 174 33 is_stmt 0 view .LVU310
 934 0062 0723     		movs	r3, #7
 935 0064 0E93     		str	r3, [sp, #56]
 176:Src/main.c    ****     RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
 936              		.loc 1 176 5 is_stmt 1 view .LVU311
 176:Src/main.c    ****     RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
 937              		.loc 1 176 38 is_stmt 0 view .LVU312
 938 0066 053B     		subs	r3, r3, #5
 939 0068 0F93     		str	r3, [sp, #60]
 177:Src/main.c    ****     RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
 940              		.loc 1 177 5 is_stmt 1 view .LVU313
 177:Src/main.c    ****     RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
 941              		.loc 1 177 38 is_stmt 0 view .LVU314
 942 006a 0023     		movs	r3, #0
 943 006c 1093     		str	r3, [sp, #64]
 178:Src/main.c    **** 
 944              		.loc 1 178 5 is_stmt 1 view .LVU315
 178:Src/main.c    **** 
 945              		.loc 1 178 38 is_stmt 0 view .LVU316
 946 006e 1193     		str	r3, [sp, #68]
 180:Src/main.c    ****         Error_Handler();
 947              		.loc 1 180 5 is_stmt 1 view .LVU317
 180:Src/main.c    ****         Error_Handler();
 948              		.loc 1 180 28 is_stmt 0 view .LVU318
 949 0070 0221     		movs	r1, #2
 950 0072 0EA8     		add	r0, sp, #56
 951 0074 FFF7FEFF 		bl	HAL_RCC_ClockConfig
 952              	.LVL42:
 180:Src/main.c    ****         Error_Handler();
 953              		.loc 1 180 5 view .LVU319
 954 0078 0028     		cmp	r0, #0
 955 007a 0ED1     		bne	.L52
 186:Src/main.c    ****       | RCC_PERIPHCLK_ADC;
 956              		.loc 1 186 5 is_stmt 1 view .LVU320
 186:Src/main.c    ****       | RCC_PERIPHCLK_ADC;
 957              		.loc 1 186 40 is_stmt 0 view .LVU321
 958 007c 094B     		ldr	r3, .L54
 959 007e 0193     		str	r3, [sp, #4]
 188:Src/main.c    ****     PeriphClkInit.I2c1ClockSelection   = RCC_I2C1CLKSOURCE_PCLK1;
 960              		.loc 1 188 5 is_stmt 1 view .LVU322
 188:Src/main.c    ****     PeriphClkInit.I2c1ClockSelection   = RCC_I2C1CLKSOURCE_PCLK1;
 961              		.loc 1 188 40 is_stmt 0 view .LVU323
 962 0080 0023     		movs	r3, #0
 963 0082 0393     		str	r3, [sp, #12]
 189:Src/main.c    ****     PeriphClkInit.AdcClockSelection    = RCC_ADCCLKSOURCE_SYSCLK;
 964              		.loc 1 189 5 is_stmt 1 view .LVU324
 189:Src/main.c    ****     PeriphClkInit.AdcClockSelection    = RCC_ADCCLKSOURCE_SYSCLK;
 965              		.loc 1 189 40 is_stmt 0 view .LVU325
ARM GAS  /tmp/ccitkYpi.s 			page 34


 966 0084 0593     		str	r3, [sp, #20]
 190:Src/main.c    ****     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
 967              		.loc 1 190 5 is_stmt 1 view .LVU326
 190:Src/main.c    ****     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
 968              		.loc 1 190 40 is_stmt 0 view .LVU327
 969 0086 0993     		str	r3, [sp, #36]
 191:Src/main.c    ****         Error_Handler();
 970              		.loc 1 191 5 is_stmt 1 view .LVU328
 191:Src/main.c    ****         Error_Handler();
 971              		.loc 1 191 34 is_stmt 0 view .LVU329
 972 0088 01A8     		add	r0, sp, #4
 973 008a FFF7FEFF 		bl	HAL_RCCEx_PeriphCLKConfig
 974              	.LVL43:
 191:Src/main.c    ****         Error_Handler();
 975              		.loc 1 191 5 view .LVU330
 976 008e 0028     		cmp	r0, #0
 977 0090 05D1     		bne	.L53
 194:Src/main.c    **** 
 978              		.loc 1 194 1 view .LVU331
 979 0092 21B0     		add	sp, sp, #132
 980              		@ sp needed
 981 0094 00BD     		pop	{pc}
 982              	.L51:
 169:Src/main.c    ****     }
 983              		.loc 1 169 9 is_stmt 1 view .LVU332
 169:Src/main.c    ****     }
 984              		.loc 1 169 22 is_stmt 0 view .LVU333
 985 0096 FFF7FEFF 		bl	Error_Handler
 986              	.LVL44:
 987              	.L52:
 181:Src/main.c    ****     }
 988              		.loc 1 181 9 is_stmt 1 view .LVU334
 181:Src/main.c    ****     }
 989              		.loc 1 181 22 is_stmt 0 view .LVU335
 990 009a FFF7FEFF 		bl	Error_Handler
 991              	.LVL45:
 992              	.L53:
 192:Src/main.c    ****     }
 993              		.loc 1 192 9 is_stmt 1 view .LVU336
 192:Src/main.c    ****     }
 994              		.loc 1 192 22 is_stmt 0 view .LVU337
 995 009e FFF7FEFF 		bl	Error_Handler
 996              	.LVL46:
 997              	.L55:
 998 00a2 C046     		.align	2
 999              	.L54:
 1000 00a4 22400000 		.word	16418
 1001              		.cfi_endproc
 1002              	.LFE3854:
 1004              		.section	.rodata._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St
 1005              		.align	2
 1006              	.LC5:
 1007 0000 62617369 		.ascii	"basic_string::_M_construct null not valid\000"
 1007      635F7374 
 1007      72696E67 
 1007      3A3A5F4D 
 1007      5F636F6E 
ARM GAS  /tmp/ccitkYpi.s 			page 35


 1008              		.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20
 1009              		.align	1
 1010              		.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_i
 1011              		.syntax unified
 1012              		.code	16
 1013              		.thumb_func
 1014              		.fpu softvfp
 1016              	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator
 1017              	.LVL47:
 1018              	.LFB4407:
 1019              		.file 3 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc"
   1:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // Components for manipulating sequences of characters -*- C++ -*-
   2:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
   3:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // Copyright (C) 1997-2019 Free Software Foundation, Inc.
   4:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** //
   5:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // software; you can redistribute it and/or modify it under the
   7:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // terms of the GNU General Public License as published by the
   8:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // Free Software Foundation; either version 3, or (at your option)
   9:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // any later version.
  10:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  11:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // This library is distributed in the hope that it will be useful,
  12:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // GNU General Public License for more details.
  15:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  16:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // Under Section 7 of GPL version 3, you are granted additional
  17:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // permissions described in the GCC Runtime Library Exception, version
  18:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // 3.1, as published by the Free Software Foundation.
  19:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  20:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // You should have received a copy of the GNU General Public License and
  21:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // <http://www.gnu.org/licenses/>.
  24:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  25:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** /** @file bits/basic_string.tcc
  26:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****  *  This is an internal header file, included by other library headers.
  27:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****  *  Do not attempt to use it directly. @headername{string}
  28:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****  */
  29:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  30:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** //
  31:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // ISO C++ 14882: 21  Strings library
  32:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** //
  33:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  34:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // Written by Jason Merrill based upon the specification by Takanori Adachi
  35:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // in ANSI X3J16/94-0013R2.  Rewritten by Nathan Myers to ISO-14882.
  36:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // Non-reference-counted implementation written by Paolo Carlini and
  37:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** // updated by Jonathan Wakely for ISO-14882-2011.
  38:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  39:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** #ifndef _BASIC_STRING_TCC
  40:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** #define _BASIC_STRING_TCC 1
  41:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  42:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** #pragma GCC system_header
  43:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  44:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** #include <bits/cxxabi_forced.h>
  45:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  46:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** namespace std _GLIBCXX_VISIBILITY(default)
ARM GAS  /tmp/ccitkYpi.s 			page 36


  47:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** {
  48:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  49:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  50:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** #if _GLIBCXX_USE_CXX11_ABI
  51:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  52:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   template<typename _CharT, typename _Traits, typename _Alloc>
  53:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     const typename basic_string<_CharT, _Traits, _Alloc>::size_type
  54:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     basic_string<_CharT, _Traits, _Alloc>::npos;
  55:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  56:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   template<typename _CharT, typename _Traits, typename _Alloc>
  57:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     void
  58:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     basic_string<_CharT, _Traits, _Alloc>::
  59:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     swap(basic_string& __s) _GLIBCXX_NOEXCEPT
  60:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     {
  61:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       if (this == &__s)
  62:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	return;
  63:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  64:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       _Alloc_traits::_S_on_swap(_M_get_allocator(), __s._M_get_allocator());
  65:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
  66:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       if (_M_is_local())
  67:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	if (__s._M_is_local())
  68:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  {
  69:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    if (length() && __s.length())
  70:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      {
  71:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		_CharT __tmp_data[_S_local_capacity + 1];
  72:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		traits_type::copy(__tmp_data, __s._M_local_buf,
  73:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				  _S_local_capacity + 1);
  74:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		traits_type::copy(__s._M_local_buf, _M_local_buf,
  75:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				  _S_local_capacity + 1);
  76:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		traits_type::copy(_M_local_buf, __tmp_data,
  77:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				  _S_local_capacity + 1);
  78:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      }
  79:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    else if (__s.length())
  80:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      {
  81:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		traits_type::copy(_M_local_buf, __s._M_local_buf,
  82:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				  _S_local_capacity + 1);
  83:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		_M_length(__s.length());
  84:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		__s._M_set_length(0);
  85:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		return;
  86:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      }
  87:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    else if (length())
  88:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      {
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		traits_type::copy(__s._M_local_buf, _M_local_buf,
  90:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				  _S_local_capacity + 1);
  91:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		__s._M_length(length());
  92:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		_M_set_length(0);
  93:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		return;
  94:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      }
  95:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  }
  96:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	else
  97:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  {
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    const size_type __tmp_capacity = __s._M_allocated_capacity;
  99:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    traits_type::copy(__s._M_local_buf, _M_local_buf,
 100:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 			      _S_local_capacity + 1);
 101:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    _M_data(__s._M_data());
 102:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    __s._M_data(__s._M_local_buf);
 103:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    _M_capacity(__tmp_capacity);
ARM GAS  /tmp/ccitkYpi.s 			page 37


 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  }
 105:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       else
 106:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	{
 107:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  const size_type __tmp_capacity = _M_allocated_capacity;
 108:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  if (__s._M_is_local())
 109:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    {
 110:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      traits_type::copy(_M_local_buf, __s._M_local_buf,
 111:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				_S_local_capacity + 1);
 112:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      __s._M_data(_M_data());
 113:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      _M_data(_M_local_buf);
 114:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    }
 115:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  else
 116:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    {
 117:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      pointer __tmp_ptr = _M_data();
 118:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      _M_data(__s._M_data());
 119:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      __s._M_data(__tmp_ptr);
 120:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      _M_capacity(__s._M_allocated_capacity);
 121:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    }
 122:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  __s._M_capacity(__tmp_capacity);
 123:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	}
 124:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 125:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       const size_type __tmp_length = length();
 126:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       _M_length(__s.length());
 127:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       __s._M_length(__tmp_length);
 128:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     }
 129:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 130:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   template<typename _CharT, typename _Traits, typename _Alloc>
 131:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     typename basic_string<_CharT, _Traits, _Alloc>::pointer
 132:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     basic_string<_CharT, _Traits, _Alloc>::
 133:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     _M_create(size_type& __capacity, size_type __old_capacity)
 134:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     {
 135:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
 136:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       // 83.  String::npos vs. string::max_size()
 137:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       if (__capacity > max_size())
 138:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	std::__throw_length_error(__N("basic_string::_M_create"));
 139:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 140:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       // The below implements an exponential growth policy, necessary to
 141:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       // meet amortized linear time requirements of the library: see
 142:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       // http://gcc.gnu.org/ml/libstdc++/2001-07/msg00085.html.
 143:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       if (__capacity > __old_capacity && __capacity < 2 * __old_capacity)
 144:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	{
 145:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  __capacity = 2 * __old_capacity;
 146:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  // Never allocate a string bigger than max_size.
 147:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  if (__capacity > max_size())
 148:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    __capacity = max_size();
 149:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	}
 150:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 151:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       // NB: Need an array of char_type[__capacity], plus a terminating
 152:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       // null char_type() element.
 153:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       return _Alloc_traits::allocate(_M_get_allocator(), __capacity + 1);
 154:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     }
 155:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 156:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   // NB: This is the special case for Input Iterators, used in
 157:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   // istreambuf_iterators, etc.
 158:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   // Input Iterators have a cost structure very different from
 159:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   // pointers, calling for a different coding style.
 160:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   template<typename _CharT, typename _Traits, typename _Alloc>
ARM GAS  /tmp/ccitkYpi.s 			page 38


 161:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     template<typename _InIterator>
 162:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       void
 163:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       basic_string<_CharT, _Traits, _Alloc>::
 164:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       _M_construct(_InIterator __beg, _InIterator __end,
 165:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		   std::input_iterator_tag)
 166:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       {
 167:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	size_type __len = 0;
 168:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	size_type __capacity = size_type(_S_local_capacity);
 169:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 170:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	while (__beg != __end && __len < __capacity)
 171:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  {
 172:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    _M_data()[__len++] = *__beg;
 173:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    ++__beg;
 174:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  }
 175:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 176:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	__try
 177:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  {
 178:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    while (__beg != __end)
 179:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      {
 180:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		if (__len == __capacity)
 181:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		  {
 182:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		    // Allocate more space.
 183:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		    __capacity = __len + 1;
 184:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		    pointer __another = _M_create(__capacity, __len);
 185:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		    this->_S_copy(__another, _M_data(), __len);
 186:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		    _M_dispose();
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		    _M_data(__another);
 188:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		    _M_capacity(__capacity);
 189:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		  }
 190:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		_M_data()[__len++] = *__beg;
 191:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		++__beg;
 192:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	      }
 193:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  }
 194:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	__catch(...)
 195:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  {
 196:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    _M_dispose();
 197:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    __throw_exception_again;
 198:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  }
 199:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 200:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	_M_set_length(__len);
 201:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       }
 202:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 203:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****   template<typename _CharT, typename _Traits, typename _Alloc>
 204:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****     template<typename _InIterator>
 205:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       void
 206:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       basic_string<_CharT, _Traits, _Alloc>::
 1020              		.loc 3 206 7 is_stmt 1 view -0
 1021              		.cfi_startproc
 1022              		@ args = 0, pretend = 0, frame = 8
 1023              		@ frame_needed = 0, uses_anonymous_args = 0
 1024              		.loc 3 206 7 is_stmt 0 view .LVU339
 1025 0000 70B5     		push	{r4, r5, r6, lr}
 1026              	.LCFI12:
 1027              		.cfi_def_cfa_offset 16
 1028              		.cfi_offset 4, -16
 1029              		.cfi_offset 5, -12
 1030              		.cfi_offset 6, -8
ARM GAS  /tmp/ccitkYpi.s 			page 39


 1031              		.cfi_offset 14, -4
 1032 0002 82B0     		sub	sp, sp, #8
 1033              	.LCFI13:
 1034              		.cfi_def_cfa_offset 24
 1035 0004 0500     		movs	r5, r0
 1036 0006 0E1E     		subs	r6, r1, #0
 207:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       _M_construct(_InIterator __beg, _InIterator __end,
 208:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 		   std::forward_iterator_tag)
 209:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       {
 210:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	// NB: Not required, but considered best practice.
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	if (__gnu_cxx::__is_null_pointer(__beg) && __beg != __end)
 1037              		.loc 3 211 42 view .LVU340
 1038 0008 0DD0     		beq	.L61
 1039              	.L57:
 1040              	.LVL48:
 1041              	.LBB179:
 1042              	.LBI179:
 1043              		.file 4 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_f
   1:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // Functions used by iterators -*- C++ -*-
   2:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
   3:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // Copyright (C) 2001-2019 Free Software Foundation, Inc.
   4:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** //
   5:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // software; you can redistribute it and/or modify it under the
   7:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // terms of the GNU General Public License as published by the
   8:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // Free Software Foundation; either version 3, or (at your option)
   9:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // any later version.
  10:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  11:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // This library is distributed in the hope that it will be useful,
  12:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // GNU General Public License for more details.
  15:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  16:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // permissions described in the GCC Runtime Library Exception, version
  18:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // 3.1, as published by the Free Software Foundation.
  19:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  20:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // You should have received a copy of the GNU General Public License and
  21:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** // <http://www.gnu.org/licenses/>.
  24:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  25:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** /*
  26:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *
  27:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * Copyright (c) 1994
  28:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * Hewlett-Packard Company
  29:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *
  30:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * Permission to use, copy, modify, distribute and sell this software
  31:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * and its documentation for any purpose is hereby granted without fee,
  32:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * provided that the above copyright notice appear in all copies and
  33:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * that both that copyright notice and this permission notice appear
  34:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * in supporting documentation.  Hewlett-Packard Company makes no
  35:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * representations about the suitability of this software for any
  36:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * purpose.  It is provided "as is" without express or implied warranty.
  37:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *
  38:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *
  39:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * Copyright (c) 1996-1998
ARM GAS  /tmp/ccitkYpi.s 			page 40


  40:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * Silicon Graphics Computer Systems, Inc.
  41:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *
  42:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * Permission to use, copy, modify, distribute and sell this software
  43:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * and its documentation for any purpose is hereby granted without fee,
  44:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * provided that the above copyright notice appear in all copies and
  45:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * that both that copyright notice and this permission notice appear
  46:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * in supporting documentation.  Silicon Graphics makes no
  47:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * representations about the suitability of this software for any
  48:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  * purpose.  It is provided "as is" without express or implied warranty.
  49:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  */
  50:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  51:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** /** @file bits/stl_iterator_base_funcs.h
  52:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *  This is an internal header file, included by other library headers.
  53:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *  Do not attempt to use it directly. @headername{iterator}
  54:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *
  55:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *  This file contains all of the general iterator-related utility
  56:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  *  functions, such as distance() and advance().
  57:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****  */
  58:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  59:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** #ifndef _STL_ITERATOR_BASE_FUNCS_H
  60:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** #define _STL_ITERATOR_BASE_FUNCS_H 1
  61:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  62:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** #pragma GCC system_header
  63:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  64:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** #include <bits/concept_check.h>
  65:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** #include <debug/assertions.h>
  66:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  67:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** namespace std _GLIBCXX_VISIBILITY(default)
  68:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** {
  69:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  70:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  71:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** _GLIBCXX_BEGIN_NAMESPACE_CONTAINER
  72:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   // Forward declaration for the overloads of __distance.
  73:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   template <typename> struct _List_iterator;
  74:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   template <typename> struct _List_const_iterator;
  75:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** _GLIBCXX_END_NAMESPACE_CONTAINER
  76:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  77:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   template<typename _InputIterator>
  78:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     inline _GLIBCXX14_CONSTEXPR
  79:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     typename iterator_traits<_InputIterator>::difference_type
  80:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     __distance(_InputIterator __first, _InputIterator __last,
  81:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****                input_iterator_tag)
  82:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     {
  83:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       // concept requirements
  84:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
  85:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  86:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       typename iterator_traits<_InputIterator>::difference_type __n = 0;
  87:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       while (__first != __last)
  88:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	{
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	  ++__first;
  90:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	  ++__n;
  91:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	}
  92:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       return __n;
  93:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     }
  94:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
  95:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   template<typename _RandomAccessIterator>
  96:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     inline _GLIBCXX14_CONSTEXPR
ARM GAS  /tmp/ccitkYpi.s 			page 41


  97:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     typename iterator_traits<_RandomAccessIterator>::difference_type
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
  99:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****                random_access_iterator_tag)
 100:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     {
 101:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       // concept requirements
 102:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       __glibcxx_function_requires(_RandomAccessIteratorConcept<
 103:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 				  _RandomAccessIterator>)
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****       return __last - __first;
 105:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     }
 106:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
 107:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** #if _GLIBCXX_USE_CXX11_ABI
 108:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   // Forward declaration because of the qualified call in distance.
 109:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   template<typename _Tp>
 110:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     ptrdiff_t
 111:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     __distance(_GLIBCXX_STD_C::_List_iterator<_Tp>,
 112:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	       _GLIBCXX_STD_C::_List_iterator<_Tp>,
 113:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	       input_iterator_tag);
 114:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
 115:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   template<typename _Tp>
 116:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     ptrdiff_t
 117:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     __distance(_GLIBCXX_STD_C::_List_const_iterator<_Tp>,
 118:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	       _GLIBCXX_STD_C::_List_const_iterator<_Tp>,
 119:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 	       input_iterator_tag);
 120:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** #endif
 121:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h **** 
 122:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   /**
 123:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  @brief A generalization of pointer arithmetic.
 124:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  @param  __first  An input iterator.
 125:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  @param  __last  An input iterator.
 126:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  @return  The distance between them.
 127:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *
 128:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  Returns @c n such that __first + n == __last.  This requires
 129:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  that @p __last must be reachable from @p __first.  Note that @c
 130:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  n may be negative.
 131:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *
 132:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  For random access iterators, this uses their @c + and @c - operations
 133:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****    *  and are constant time.  For other %iterator classes they are linear time.
 134:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   */
 135:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****   template<typename _InputIterator>
 136:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     inline _GLIBCXX17_CONSTEXPR
 137:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     typename iterator_traits<_InputIterator>::difference_type
 138:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     distance(_InputIterator __first, _InputIterator __last)
 1044              		.loc 4 138 5 is_stmt 1 view .LVU341
 1045              	.LBB180:
 1046              	.LBI180:
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****                random_access_iterator_tag)
 1047              		.loc 4 98 5 view .LVU342
 1048              	.LBB181:
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     }
 1049              		.loc 4 104 23 is_stmt 0 view .LVU343
 1050 000a 941B     		subs	r4, r2, r6
 1051              	.LVL49:
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_funcs.h ****     }
 1052              		.loc 4 104 23 view .LVU344
 1053              	.LBE181:
 1054              	.LBE180:
 1055              	.LBE179:
ARM GAS  /tmp/ccitkYpi.s 			page 42


 212:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  std::__throw_logic_error(__N("basic_string::"
 213:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				       "_M_construct null not valid"));
 214:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 215:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	size_type __dnew = static_cast<size_type>(std::distance(__beg, __end));
 1056              		.loc 3 215 12 view .LVU345
 1057 000c 0194     		str	r4, [sp, #4]
 216:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 217:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	if (__dnew > size_type(_S_local_capacity))
 1058              		.loc 3 217 2 view .LVU346
 1059 000e 0F2C     		cmp	r4, #15
 1060 0010 0ED8     		bhi	.L62
 1061              	.LVL50:
 1062              	.L58:
 1063              	.LBB182:
 1064              	.LBI182:
 1065              		.file 5 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h"
   1:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // Components for manipulating sequences of characters -*- C++ -*-
   2:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
   3:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // Copyright (C) 1997-2019 Free Software Foundation, Inc.
   4:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** //
   5:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // software; you can redistribute it and/or modify it under the
   7:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // terms of the GNU General Public License as published by the
   8:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // Free Software Foundation; either version 3, or (at your option)
   9:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // any later version.
  10:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  11:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // This library is distributed in the hope that it will be useful,
  12:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // GNU General Public License for more details.
  15:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  16:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // permissions described in the GCC Runtime Library Exception, version
  18:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // 3.1, as published by the Free Software Foundation.
  19:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  20:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // You should have received a copy of the GNU General Public License and
  21:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // <http://www.gnu.org/licenses/>.
  24:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  25:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** /** @file bits/basic_string.h
  26:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****  *  This is an internal header file, included by other library headers.
  27:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****  *  Do not attempt to use it directly. @headername{string}
  28:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****  */
  29:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  30:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** //
  31:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** // ISO C++ 14882: 21 Strings library
  32:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** //
  33:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  34:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #ifndef _BASIC_STRING_H
  35:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #define _BASIC_STRING_H 1
  36:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  37:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #pragma GCC system_header
  38:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  39:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #include <ext/atomicity.h>
  40:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #include <ext/alloc_traits.h>
  41:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #include <debug/debug.h>
ARM GAS  /tmp/ccitkYpi.s 			page 43


  42:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  43:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201103L
  44:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #include <initializer_list>
  45:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
  46:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  47:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201703L
  48:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** # include <string_view>
  49:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
  50:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  51:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  52:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** namespace std _GLIBCXX_VISIBILITY(default)
  53:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** {
  54:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  55:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  56:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if _GLIBCXX_USE_CXX11_ABI
  57:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** _GLIBCXX_BEGIN_NAMESPACE_CXX11
  58:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****   /**
  59:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @class basic_string basic_string.h <string>
  60:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @brief  Managing sequences of characters and character-like objects.
  61:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *
  62:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @ingroup strings
  63:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @ingroup sequences
  64:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *
  65:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @tparam _CharT  Type of character
  66:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @tparam _Traits  Traits for character type, defaults to
  67:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *                   char_traits<_CharT>.
  68:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @tparam _Alloc  Allocator type, defaults to allocator<_CharT>.
  69:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *
  70:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  Meets the requirements of a <a href="tables.html#65">container</a>, a
  71:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  <a href="tables.html#66">reversible container</a>, and a
  72:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  <a href="tables.html#67">sequence</a>.  Of the
  73:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  <a href="tables.html#68">optional sequence requirements</a>, only
  74:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    *  @c push_back, @c at, and @c %array access are supported.
  75:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****    */
  76:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****   template<typename _CharT, typename _Traits, typename _Alloc>
  77:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****     class basic_string
  78:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****     {
  79:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
  80:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	rebind<_CharT>::other _Char_alloc_type;
  81:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef __gnu_cxx::__alloc_traits<_Char_alloc_type> _Alloc_traits;
  82:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
  83:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // Types:
  84:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****     public:
  85:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef _Traits					traits_type;
  86:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename _Traits::char_type		value_type;
  87:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef _Char_alloc_type				allocator_type;
  88:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename _Alloc_traits::size_type		size_type;
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename _Alloc_traits::difference_type	difference_type;
  90:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename _Alloc_traits::reference		reference;
  91:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename _Alloc_traits::const_reference	const_reference;
  92:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename _Alloc_traits::pointer		pointer;
  93:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef typename _Alloc_traits::const_pointer	const_pointer;
  94:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef __gnu_cxx::__normal_iterator<pointer, basic_string>  iterator;
  95:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef __gnu_cxx::__normal_iterator<const_pointer, basic_string>
  96:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 							const_iterator;
  97:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef std::reverse_iterator<iterator>		reverse_iterator;
ARM GAS  /tmp/ccitkYpi.s 			page 44


  99:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 100:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       ///  Value returned by various member functions when they fail.
 101:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static const size_type	npos = static_cast<size_type>(-1);
 102:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 103:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****     protected:
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // type used for positions in insert, erase etc.
 105:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus < 201103L
 106:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef iterator __const_iterator;
 107:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #else
 108:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef const_iterator __const_iterator;
 109:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 110:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 111:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****     private:
 112:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201703L
 113:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // A helper type for avoiding boiler-plate.
 114:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       typedef basic_string_view<_CharT, _Traits> __sv_type;
 115:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 116:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _Tp, typename _Res>
 117:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	using _If_sv = enable_if_t<
 118:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  __and_<is_convertible<const _Tp&, __sv_type>,
 119:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		 __not_<is_convertible<const _Tp*, const basic_string*>>,
 120:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		 __not_<is_convertible<const _Tp&, const _CharT*>>>::value,
 121:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  _Res>;
 122:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 123:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // Allows an implicit conversion to __sv_type.
 124:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static __sv_type
 125:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_to_string_view(__sv_type __svt) noexcept
 126:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return __svt; }
 127:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 128:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // Wraps a string_view by explicit conversion and thus
 129:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // allows to add an internal constructor that does not
 130:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // participate in overload resolution when a string_view
 131:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // is provided.
 132:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       struct __sv_wrapper
 133:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 134:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	explicit __sv_wrapper(__sv_type __sv) noexcept : _M_sv(__sv) { }
 135:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	__sv_type _M_sv;
 136:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       };
 137:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 138:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 139:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Only internally used: Construct string from a string view
 140:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *          wrapper.
 141:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __svw  string view wrapper.
 142:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use.
 143:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 144:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       explicit
 145:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(__sv_wrapper __svw, const _Alloc& __a)
 146:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : basic_string(__svw._M_sv.data(), __svw._M_sv.size(), __a) { }
 147:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 148:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 149:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // Use empty-base optimization: http://www.cantrip.org/emptyopt.html
 150:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       struct _Alloc_hider : allocator_type // TODO check __is_final
 151:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 152:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus < 201103L
 153:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_Alloc_hider(pointer __dat, const _Alloc& __a = _Alloc())
 154:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	: allocator_type(__a), _M_p(__dat) { }
 155:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #else
ARM GAS  /tmp/ccitkYpi.s 			page 45


 156:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_Alloc_hider(pointer __dat, const _Alloc& __a)
 157:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	: allocator_type(__a), _M_p(__dat) { }
 158:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 159:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_Alloc_hider(pointer __dat, _Alloc&& __a = _Alloc())
 160:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	: allocator_type(std::move(__a)), _M_p(__dat) { }
 161:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 162:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 163:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	pointer _M_p; // The actual data.
 164:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       };
 165:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 166:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _Alloc_hider	_M_dataplus;
 167:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       size_type		_M_string_length;
 168:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 169:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       enum { _S_local_capacity = 15 / sizeof(_CharT) };
 170:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 171:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       union
 172:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 173:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_CharT           _M_local_buf[_S_local_capacity + 1];
 174:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	size_type        _M_allocated_capacity;
 175:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       };
 176:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 177:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 178:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_data(pointer __p)
 179:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_dataplus._M_p = __p; }
 180:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 181:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 182:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_length(size_type __length)
 183:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_string_length = __length; }
 184:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 185:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       pointer
 186:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_data() const
 1066              		.loc 5 186 7 is_stmt 1 view .LVU347
 1067              	.LBB183:
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return _M_dataplus._M_p; }
 1068              		.loc 5 187 28 is_stmt 0 view .LVU348
 1069 0012 2868     		ldr	r0, [r5]
 1070              	.LVL51:
 1071              		.loc 5 187 28 view .LVU349
 1072              	.LBE183:
 1073              	.LBE182:
 1074              	.LBB184:
 1075              	.LBI184:
 188:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 189:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       pointer
 190:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_local_data()
 191:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 192:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201103L
 193:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	return std::pointer_traits<pointer>::pointer_to(*_M_local_buf);
 194:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #else
 195:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	return pointer(_M_local_buf);
 196:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 197:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 198:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 199:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       const_pointer
 200:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_local_data() const
 201:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 202:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201103L
ARM GAS  /tmp/ccitkYpi.s 			page 46


 203:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	return std::pointer_traits<const_pointer>::pointer_to(*_M_local_buf);
 204:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #else
 205:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	return const_pointer(_M_local_buf);
 206:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 207:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 208:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 209:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 210:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_capacity(size_type __capacity)
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_allocated_capacity = __capacity; }
 212:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 213:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 214:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_set_length(size_type __n)
 215:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 216:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_M_length(__n);
 217:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	traits_type::assign(_M_data()[__n], _CharT());
 218:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 219:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 220:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       bool
 221:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_is_local() const
 222:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return _M_data() == _M_local_data(); }
 223:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 224:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // Create & Destroy
 225:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       pointer
 226:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_create(size_type&, size_type);
 227:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 228:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 229:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_dispose()
 230:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 231:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (!_M_is_local())
 232:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  _M_destroy(_M_allocated_capacity);
 233:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 234:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 235:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 236:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_destroy(size_type __size) throw()
 237:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
 238:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 239:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // _M_construct_aux is used to implement the 21.3.1 para 15 which
 240:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // requires special behaviour if _InIterator is an integral type
 241:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _InIterator>
 242:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         void
 243:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         _M_construct_aux(_InIterator __beg, _InIterator __end,
 244:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 			 std::__false_type)
 245:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	{
 246:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****           typedef typename iterator_traits<_InIterator>::iterator_category _Tag;
 247:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****           _M_construct(__beg, __end, _Tag());
 248:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	}
 249:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 250:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
 251:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // 438. Ambiguity in the "do the right thing" clause
 252:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _Integer>
 253:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         void
 254:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         _M_construct_aux(_Integer __beg, _Integer __end, std::__true_type)
 255:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	{ _M_construct_aux_2(static_cast<size_type>(__beg), __end); }
 256:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 257:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 258:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_construct_aux_2(size_type __req, _CharT __c)
 259:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_construct(__req, __c); }
ARM GAS  /tmp/ccitkYpi.s 			page 47


 260:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 261:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _InIterator>
 262:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         void
 263:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         _M_construct(_InIterator __beg, _InIterator __end)
 264:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	{
 265:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  typedef typename std::__is_integer<_InIterator>::__type _Integral;
 266:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  _M_construct_aux(__beg, __end, _Integral());
 267:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         }
 268:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 269:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // For Input Iterators, used in istreambuf_iterators, etc.
 270:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _InIterator>
 271:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         void
 272:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         _M_construct(_InIterator __beg, _InIterator __end,
 273:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		     std::input_iterator_tag);
 274:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 275:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // For forward_iterators up to random_access_iterators, used for
 276:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // string::iterator, _CharT*, etc.
 277:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _FwdIterator>
 278:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         void
 279:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         _M_construct(_FwdIterator __beg, _FwdIterator __end,
 280:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		     std::forward_iterator_tag);
 281:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 282:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 283:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_construct(size_type __req, _CharT __c);
 284:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 285:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       allocator_type&
 286:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_get_allocator()
 287:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return _M_dataplus; }
 288:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 289:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       const allocator_type&
 290:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_get_allocator() const
 291:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return _M_dataplus; }
 292:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 293:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****     private:
 294:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 295:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #ifdef _GLIBCXX_DISAMBIGUATE_REPLACE_INST
 296:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // The explicit instantiations in misc-inst.cc require this due to
 297:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=64063
 298:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _Tp, bool _Requires =
 299:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	       !__are_same<_Tp, _CharT*>::__value
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	       && !__are_same<_Tp, const _CharT*>::__value
 301:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	       && !__are_same<_Tp, iterator>::__value
 302:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	       && !__are_same<_Tp, const_iterator>::__value>
 303:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	struct __enable_if_not_native_iterator
 304:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	{ typedef basic_string& __type; };
 305:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _Tp>
 306:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	struct __enable_if_not_native_iterator<_Tp, false> { };
 307:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 308:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 309:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       size_type
 310:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_check(size_type __pos, const char* __s) const
 311:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 312:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (__pos > this->size())
 313:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  __throw_out_of_range_fmt(__N("%s: __pos (which is %zu) > "
 314:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 				       "this->size() (which is %zu)"),
 315:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 				   __s, __pos, this->size());
 316:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	return __pos;
ARM GAS  /tmp/ccitkYpi.s 			page 48


 317:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 318:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 319:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 320:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_check_length(size_type __n1, size_type __n2, const char* __s) const
 321:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 322:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (this->max_size() - (this->size() - __n1) < __n2)
 323:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  __throw_length_error(__N(__s));
 324:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 325:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 326:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 327:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // NB: _M_limit doesn't check for a bad __pos value.
 328:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       size_type
 329:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_limit(size_type __pos, size_type __off) const _GLIBCXX_NOEXCEPT
 330:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 331:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	const bool __testoff =  __off < this->size() - __pos;
 332:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	return __testoff ? __off : this->size() - __pos;
 333:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 334:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 335:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // True if _Rep and source do not overlap.
 336:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       bool
 337:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_disjunct(const _CharT* __s) const _GLIBCXX_NOEXCEPT
 338:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 339:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	return (less<const _CharT*>()(__s, _M_data())
 340:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		|| less<const _CharT*>()(_M_data() + this->size(), __s));
 341:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 342:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 343:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // When __n = 1 way faster than the general multichar
 344:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // traits_type::copy/move/assign.
 345:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static void
 346:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_copy(_CharT* __d, const _CharT* __s, size_type __n)
 347:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 348:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (__n == 1)
 349:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  traits_type::assign(*__d, *__s);
 350:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else
 351:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  traits_type::copy(__d, __s, __n);
 352:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 353:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 354:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static void
 355:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_move(_CharT* __d, const _CharT* __s, size_type __n)
 356:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 357:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (__n == 1)
 358:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  traits_type::assign(*__d, *__s);
 359:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else
 360:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  traits_type::move(__d, __s, __n);
 361:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 362:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 363:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static void
 364:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_assign(_CharT* __d, size_type __n, _CharT __c)
 365:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 366:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (__n == 1)
 367:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  traits_type::assign(*__d, __c);
 368:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else
 369:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  traits_type::assign(__d, __n, __c);
 370:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 371:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 372:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // _S_copy_chars is a separate template to permit specialization
 373:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // to optimize for the common case of pointers as iterators.
ARM GAS  /tmp/ccitkYpi.s 			page 49


 374:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<class _Iterator>
 375:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         static void
 376:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         _S_copy_chars(_CharT* __p, _Iterator __k1, _Iterator __k2)
 377:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         {
 378:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  for (; __k1 != __k2; ++__k1, (void)++__p)
 379:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    traits_type::assign(*__p, *__k1); // These types are off.
 380:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	}
 381:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 382:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static void
 383:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_copy_chars(_CharT* __p, iterator __k1, iterator __k2) _GLIBCXX_NOEXCEPT
 384:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _S_copy_chars(__p, __k1.base(), __k2.base()); }
 385:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 386:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static void
 387:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_copy_chars(_CharT* __p, const_iterator __k1, const_iterator __k2)
 388:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _GLIBCXX_NOEXCEPT
 389:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _S_copy_chars(__p, __k1.base(), __k2.base()); }
 390:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 391:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static void
 392:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_copy_chars(_CharT* __p, _CharT* __k1, _CharT* __k2) _GLIBCXX_NOEXCEPT
 393:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _S_copy(__p, __k1, __k2 - __k1); }
 394:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 395:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static void
 396:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_copy_chars(_CharT* __p, const _CharT* __k1, const _CharT* __k2)
 1076              		.loc 5 396 7 is_stmt 1 view .LVU350
 1077              	.LBB185:
 1078              	.LBI185:
 346:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1079              		.loc 5 346 7 view .LVU351
 1080              	.LBB186:
 348:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  traits_type::assign(*__d, *__s);
 1081              		.loc 5 348 2 is_stmt 0 view .LVU352
 1082 0014 012C     		cmp	r4, #1
 1083 0016 14D0     		beq	.L63
 1084              	.LVL52:
 1085              	.LBB187:
 1086              	.LBI187:
 1087              		.file 6 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h"
   1:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // Character Traits for use by standard string and iostream -*- C++ -*-
   2:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
   3:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // Copyright (C) 1997-2019 Free Software Foundation, Inc.
   4:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** //
   5:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // software; you can redistribute it and/or modify it under the
   7:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // terms of the GNU General Public License as published by the
   8:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // Free Software Foundation; either version 3, or (at your option)
   9:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // any later version.
  10:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  11:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // This library is distributed in the hope that it will be useful,
  12:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // GNU General Public License for more details.
  15:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  16:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // permissions described in the GCC Runtime Library Exception, version
  18:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // 3.1, as published by the Free Software Foundation.
  19:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  20:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // You should have received a copy of the GNU General Public License and
ARM GAS  /tmp/ccitkYpi.s 			page 50


  21:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // <http://www.gnu.org/licenses/>.
  24:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  25:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** /** @file bits/char_traits.h
  26:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****  *  This is an internal header file, included by other library headers.
  27:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****  *  Do not attempt to use it directly. @headername{string}
  28:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****  */
  29:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  30:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** //
  31:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** // ISO C++ 14882: 21  Strings library
  32:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** //
  33:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  34:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #ifndef _CHAR_TRAITS_H
  35:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #define _CHAR_TRAITS_H 1
  36:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  37:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #pragma GCC system_header
  38:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  39:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #include <bits/stl_algobase.h>  // std::copy, std::fill_n
  40:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #include <bits/postypes.h>      // For streampos
  41:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #include <cwchar>               // For WEOF, wmemmove, wmemset, etc.
  42:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  43:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #ifndef _GLIBCXX_ALWAYS_INLINE
  44:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** # define _GLIBCXX_ALWAYS_INLINE inline __attribute__((__always_inline__))
  45:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #endif
  46:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  47:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
  48:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** {
  49:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  50:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  51:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   /**
  52:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @brief  Mapping from character type to associated types.
  53:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *
  54:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @note This is an implementation class for the generic version
  55:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  of char_traits.  It defines int_type, off_type, pos_type, and
  56:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  state_type.  By default these are unsigned long, streamoff,
  57:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  streampos, and mbstate_t.  Users who need a different set of
  58:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  types, but who don't need to change the definitions of any function
  59:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  defined in char_traits, can specialize __gnu_cxx::_Char_types
  60:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  while leaving __gnu_cxx::char_traits alone. */
  61:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
  62:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     struct _Char_types
  63:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
  64:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef unsigned long   int_type;
  65:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef std::streampos  pos_type;
  66:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef std::streamoff  off_type;
  67:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef std::mbstate_t  state_type;
  68:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     };
  69:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  70:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  71:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   /**
  72:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @brief  Base class used to implement std::char_traits.
  73:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *
  74:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @note For any given actual character type, this definition is
  75:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  probably wrong.  (Most of the member functions are likely to be
  76:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  right, but the int_type and state_type typedefs, and the eof()
  77:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  member function, are likely to be wrong.)  The reason this class
ARM GAS  /tmp/ccitkYpi.s 			page 51


  78:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  exists is so users can specialize it.  Classes in namespace std
  79:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  may not be specialized for fundamental types, but classes in
  80:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  namespace __gnu_cxx may be.
  81:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *
  82:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  See https://gcc.gnu.org/onlinedocs/libstdc++/manual/strings.html#strings.string.character_typ
  83:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  for advice on how to make use of this class for @a unusual character
  84:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  types. Also, check out include/ext/pod_char_traits.h.  
  85:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    */
  86:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
  87:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     struct char_traits
  88:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef _CharT                                    char_type;
  90:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef typename _Char_types<_CharT>::int_type    int_type;
  91:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef typename _Char_types<_CharT>::pos_type    pos_type;
  92:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef typename _Char_types<_CharT>::off_type    off_type;
  93:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef typename _Char_types<_CharT>::state_type  state_type;
  94:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  95:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX14_CONSTEXPR void
  96:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       assign(char_type& __c1, const char_type& __c2)
  97:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { __c1 = __c2; }
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
  99:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR bool
 100:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       eq(const char_type& __c1, const char_type& __c2)
 101:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return __c1 == __c2; }
 102:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 103:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR bool
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       lt(const char_type& __c1, const char_type& __c2)
 105:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return __c1 < __c2; }
 106:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 107:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX14_CONSTEXPR int
 108:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       compare(const char_type* __s1, const char_type* __s2, std::size_t __n);
 109:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 110:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX14_CONSTEXPR std::size_t
 111:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       length(const char_type* __s);
 112:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 113:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX14_CONSTEXPR const char_type*
 114:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       find(const char_type* __s, std::size_t __n, const char_type& __a);
 115:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 116:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static char_type*
 117:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       move(char_type* __s1, const char_type* __s2, std::size_t __n);
 118:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 119:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static char_type*
 120:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       copy(char_type* __s1, const char_type* __s2, std::size_t __n);
 121:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 122:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static char_type*
 123:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       assign(char_type* __s, std::size_t __n, char_type __a);
 124:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 125:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR char_type
 126:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       to_char_type(const int_type& __c)
 127:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return static_cast<char_type>(__c); }
 128:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 129:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR int_type
 130:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       to_int_type(const char_type& __c)
 131:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return static_cast<int_type>(__c); }
 132:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 133:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR bool
 134:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       eq_int_type(const int_type& __c1, const int_type& __c2)
ARM GAS  /tmp/ccitkYpi.s 			page 52


 135:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return __c1 == __c2; }
 136:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 137:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR int_type
 138:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       eof()
 139:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return static_cast<int_type>(_GLIBCXX_STDIO_EOF); }
 140:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 141:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR int_type
 142:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       not_eof(const int_type& __c)
 143:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return !eq_int_type(__c, eof()) ? __c : to_int_type(char_type()); }
 144:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     };
 145:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 146:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 147:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     _GLIBCXX14_CONSTEXPR int
 148:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     char_traits<_CharT>::
 149:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     compare(const char_type* __s1, const char_type* __s2, std::size_t __n)
 150:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 151:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       for (std::size_t __i = 0; __i < __n; ++__i)
 152:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (lt(__s1[__i], __s2[__i]))
 153:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return -1;
 154:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	else if (lt(__s2[__i], __s1[__i]))
 155:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return 1;
 156:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return 0;
 157:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 158:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 159:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 160:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     _GLIBCXX14_CONSTEXPR std::size_t
 161:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     char_traits<_CharT>::
 162:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     length(const char_type* __p)
 163:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 164:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       std::size_t __i = 0;
 165:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       while (!eq(__p[__i], char_type()))
 166:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****         ++__i;
 167:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return __i;
 168:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 169:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 170:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 171:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     _GLIBCXX14_CONSTEXPR const typename char_traits<_CharT>::char_type*
 172:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     char_traits<_CharT>::
 173:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     find(const char_type* __s, std::size_t __n, const char_type& __a)
 174:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 175:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       for (std::size_t __i = 0; __i < __n; ++__i)
 176:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****         if (eq(__s[__i], __a))
 177:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****           return __s + __i;
 178:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return 0;
 179:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 180:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 181:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 182:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     typename char_traits<_CharT>::char_type*
 183:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     char_traits<_CharT>::
 184:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     move(char_type* __s1, const char_type* __s2, std::size_t __n)
 185:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 186:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       if (__n == 0)
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	return __s1;
 188:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return static_cast<_CharT*>(__builtin_memmove(__s1, __s2,
 189:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 						    __n * sizeof(char_type)));
 190:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 191:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
ARM GAS  /tmp/ccitkYpi.s 			page 53


 192:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 193:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     typename char_traits<_CharT>::char_type*
 194:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     char_traits<_CharT>::
 195:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     copy(char_type* __s1, const char_type* __s2, std::size_t __n)
 196:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 197:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       // NB: Inline std::copy so no recursive dependencies.
 198:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       std::copy(__s2, __s2 + __n, __s1);
 199:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return __s1;
 200:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 201:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 202:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 203:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     typename char_traits<_CharT>::char_type*
 204:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     char_traits<_CharT>::
 205:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     assign(char_type* __s, std::size_t __n, char_type __a)
 206:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 207:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       // NB: Inline std::fill_n so no recursive dependencies.
 208:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       std::fill_n(__s, __n, __a);
 209:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return __s;
 210:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 212:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** _GLIBCXX_END_NAMESPACE_VERSION
 213:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** } // namespace
 214:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 215:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** namespace std _GLIBCXX_VISIBILITY(default)
 216:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** {
 217:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
 218:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 219:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #if __cplusplus >= 201703L
 220:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #define __cpp_lib_constexpr_char_traits 201611
 221:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 222:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   /**
 223:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @brief Determine whether the characters of a NULL-terminated
 224:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  string are known at compile time.
 225:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @param  __s  The string.
 226:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *
 227:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  Assumes that _CharT is a built-in character type.
 228:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    */
 229:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 230:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     static _GLIBCXX_ALWAYS_INLINE constexpr bool
 231:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     __constant_string_p(const _CharT* __s)
 232:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 233:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #ifdef _GLIBCXX_HAVE_BUILTIN_IS_CONSTANT_EVALUATED
 234:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       (void) __s;
 235:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       // In constexpr contexts all strings should be constant.
 236:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return __builtin_is_constant_evaluated();
 237:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #else
 238:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       while (__builtin_constant_p(*__s) && *__s)
 239:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	__s++;
 240:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return __builtin_constant_p(*__s);
 241:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #endif
 242:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 243:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 244:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   /**
 245:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @brief Determine whether the characters of a character array are
 246:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  known at compile time.
 247:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @param  __a  The character array.
 248:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @param  __n  Number of characters.
ARM GAS  /tmp/ccitkYpi.s 			page 54


 249:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *
 250:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  Assumes that _CharT is a built-in character type.
 251:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    */
 252:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<typename _CharT>
 253:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     static _GLIBCXX_ALWAYS_INLINE constexpr bool
 254:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     __constant_char_array_p(const _CharT* __a, size_t __n)
 255:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 256:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #ifdef _GLIBCXX_HAVE_BUILTIN_IS_CONSTANT_EVALUATED
 257:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       (void) __a;
 258:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       (void) __n;
 259:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       // In constexpr contexts all character arrays should be constant.
 260:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return __builtin_is_constant_evaluated();
 261:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #else
 262:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       size_t __i = 0;
 263:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       while (__i < __n && __builtin_constant_p(__a[__i]))
 264:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	__i++;
 265:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       return __i == __n;
 266:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #endif
 267:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     }
 268:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #endif
 269:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 270:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   // 21.1
 271:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   /**
 272:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @brief  Basis for explicit traits specializations.
 273:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *
 274:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  @note  For any given actual character type, this definition is
 275:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  probably wrong.  Since this is just a thin wrapper around
 276:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  __gnu_cxx::char_traits, it is possible to achieve a more
 277:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  appropriate definition by specializing __gnu_cxx::char_traits.
 278:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *
 279:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  See https://gcc.gnu.org/onlinedocs/libstdc++/manual/strings.html#strings.string.character_typ
 280:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  for advice on how to make use of this class for @a unusual character
 281:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****    *  types. Also, check out include/ext/pod_char_traits.h.
 282:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   */
 283:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<class _CharT>
 284:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     struct char_traits : public __gnu_cxx::char_traits<_CharT>
 285:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     { };
 286:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 287:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 288:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   /// 21.1.3.1  char_traits specializations
 289:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****   template<>
 290:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     struct char_traits<char>
 291:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****     {
 292:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef char              char_type;
 293:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef int               int_type;
 294:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef streampos         pos_type;
 295:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef streamoff         off_type;
 296:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       typedef mbstate_t         state_type;
 297:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 298:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX17_CONSTEXPR void
 299:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       assign(char_type& __c1, const char_type& __c2) _GLIBCXX_NOEXCEPT
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { __c1 = __c2; }
 301:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 302:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR bool
 303:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       eq(const char_type& __c1, const char_type& __c2) _GLIBCXX_NOEXCEPT
 304:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { return __c1 == __c2; }
 305:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
ARM GAS  /tmp/ccitkYpi.s 			page 55


 306:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX_CONSTEXPR bool
 307:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       lt(const char_type& __c1, const char_type& __c2) _GLIBCXX_NOEXCEPT
 308:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       {
 309:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	// LWG 467.
 310:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	return (static_cast<unsigned char>(__c1)
 311:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 		< static_cast<unsigned char>(__c2));
 312:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       }
 313:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 314:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX17_CONSTEXPR int
 315:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       compare(const char_type* __s1, const char_type* __s2, size_t __n)
 316:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       {
 317:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (__n == 0)
 318:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return 0;
 319:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #if __cplusplus >= 201703L
 320:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (__builtin_constant_p(__n)
 321:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	    && __constant_char_array_p(__s1, __n)
 322:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	    && __constant_char_array_p(__s2, __n))
 323:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return __gnu_cxx::char_traits<char_type>::compare(__s1, __s2, __n);
 324:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #endif
 325:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	return __builtin_memcmp(__s1, __s2, __n);
 326:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       }
 327:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 328:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX17_CONSTEXPR size_t
 329:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       length(const char_type* __s)
 330:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       {
 331:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #if __cplusplus >= 201703L
 332:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (__constant_string_p(__s))
 333:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return __gnu_cxx::char_traits<char_type>::length(__s);
 334:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #endif
 335:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	return __builtin_strlen(__s);
 336:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       }
 337:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 338:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static _GLIBCXX17_CONSTEXPR const char_type*
 339:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       find(const char_type* __s, size_t __n, const char_type& __a)
 340:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       {
 341:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (__n == 0)
 342:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return 0;
 343:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #if __cplusplus >= 201703L
 344:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (__builtin_constant_p(__n)
 345:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	    && __builtin_constant_p(__a)
 346:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	    && __constant_char_array_p(__s, __n))
 347:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return __gnu_cxx::char_traits<char_type>::find(__s, __n, __a);
 348:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** #endif
 349:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	return static_cast<const char_type*>(__builtin_memchr(__s, __a, __n));
 350:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       }
 351:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 352:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static char_type*
 353:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       move(char_type* __s1, const char_type* __s2, size_t __n)
 354:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       {
 355:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (__n == 0)
 356:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return __s1;
 357:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	return static_cast<char_type*>(__builtin_memmove(__s1, __s2, __n));
 358:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       }
 359:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 360:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       static char_type*
 361:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       copy(char_type* __s1, const char_type* __s2, size_t __n)
 1088              		.loc 6 361 7 is_stmt 1 view .LVU353
ARM GAS  /tmp/ccitkYpi.s 			page 56


 1089              	.LBB188:
 362:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       {
 363:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	if (__n == 0)
 1090              		.loc 6 363 2 view .LVU354
 1091 0018 002C     		cmp	r4, #0
 1092 001a 14D0     		beq	.L60
 364:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return __s1;
 365:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
 1093              		.loc 6 365 2 view .LVU355
 1094              		.loc 6 365 49 is_stmt 0 view .LVU356
 1095 001c 2200     		movs	r2, r4
 1096 001e 3100     		movs	r1, r6
 1097 0020 FFF7FEFF 		bl	memcpy
 1098              	.LVL53:
 1099              		.loc 6 365 66 view .LVU357
 1100 0024 0FE0     		b	.L60
 1101              	.LVL54:
 1102              	.L61:
 1103              		.loc 6 365 66 view .LVU358
 1104              	.LBE188:
 1105              	.LBE187:
 1106              	.LBE186:
 1107              	.LBE185:
 1108              	.LBE184:
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  std::__throw_logic_error(__N("basic_string::"
 1109              		.loc 3 211 42 discriminator 1 view .LVU359
 1110 0026 9142     		cmp	r1, r2
 1111 0028 EFD0     		beq	.L57
 212:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				       "_M_construct null not valid"));
 1112              		.loc 3 212 28 view .LVU360
 1113 002a 0B48     		ldr	r0, .L64
 1114              	.LVL55:
 212:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 				       "_M_construct null not valid"));
 1115              		.loc 3 212 28 view .LVU361
 1116 002c FFF7FEFF 		bl	_ZSt19__throw_logic_errorPKc
 1117              	.LVL56:
 1118              	.L62:
 218:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  {
 219:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    _M_data(_M_create(__dnew, size_type(0)));
 1119              		.loc 3 219 6 view .LVU362
 1120 0030 0022     		movs	r2, #0
 1121              	.LVL57:
 1122              		.loc 3 219 6 view .LVU363
 1123 0032 01A9     		add	r1, sp, #4
 1124              	.LVL58:
 1125              		.loc 3 219 6 view .LVU364
 1126 0034 2800     		movs	r0, r5
 1127              	.LVL59:
 1128              		.loc 3 219 6 view .LVU365
 1129 0036 FFF7FEFF 		bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj
 1130              	.LVL60:
 1131              	.LBB193:
 1132              	.LBI193:
 178:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_dataplus._M_p = __p; }
 1133              		.loc 5 178 7 is_stmt 1 view .LVU366
 1134              	.LBB194:
 179:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
ARM GAS  /tmp/ccitkYpi.s 			page 57


 1135              		.loc 5 179 9 is_stmt 0 view .LVU367
 1136 003a 2860     		str	r0, [r5]
 1137              	.LVL61:
 179:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1138              		.loc 5 179 9 view .LVU368
 1139              	.LBE194:
 1140              	.LBE193:
 1141              	.LBB195:
 1142              	.LBI195:
 210:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_allocated_capacity = __capacity; }
 1143              		.loc 5 210 7 is_stmt 1 view .LVU369
 1144              	.LBB196:
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1145              		.loc 5 211 9 is_stmt 0 view .LVU370
 1146 003c 019B     		ldr	r3, [sp, #4]
 1147 003e AB60     		str	r3, [r5, #8]
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1148              		.loc 5 211 45 view .LVU371
 1149 0040 E7E7     		b	.L58
 1150              	.LVL62:
 1151              	.L63:
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1152              		.loc 5 211 45 view .LVU372
 1153              	.LBE196:
 1154              	.LBE195:
 1155              	.LBB197:
 1156              	.LBB192:
 1157              	.LBB191:
 1158              	.LBB189:
 1159              	.LBI189:
 299:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { __c1 = __c2; }
 1160              		.loc 6 299 7 is_stmt 1 view .LVU373
 1161              	.LBB190:
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1162              		.loc 6 300 9 view .LVU374
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1163              		.loc 6 300 16 is_stmt 0 view .LVU375
 1164 0042 3378     		ldrb	r3, [r6]
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1165              		.loc 6 300 14 view .LVU376
 1166 0044 0370     		strb	r3, [r0]
 1167              	.LVL63:
 1168              	.L60:
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1169              		.loc 6 300 14 view .LVU377
 1170              	.LBE190:
 1171              	.LBE189:
 1172              	.LBE191:
 1173              	.LBE192:
 1174              	.LBE197:
 220:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    _M_capacity(__dnew);
 221:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  }
 222:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 223:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	// Check for out_of_range and length_error exceptions.
 224:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	__try
 225:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  { this->_S_copy_chars(_M_data(), __beg, __end); }
 226:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	__catch(...)
ARM GAS  /tmp/ccitkYpi.s 			page 58


 227:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  {
 228:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    _M_dispose();
 229:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	    __throw_exception_again;
 230:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	  }
 231:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 
 232:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc **** 	_M_set_length(__dnew);
 1175              		.loc 3 232 2 view .LVU378
 1176 0046 019A     		ldr	r2, [sp, #4]
 1177              	.LVL64:
 1178              	.LBB198:
 1179              	.LBI198:
 214:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1180              		.loc 5 214 7 is_stmt 1 view .LVU379
 1181              	.LBB199:
 1182              	.LBB200:
 1183              	.LBI200:
 182:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_string_length = __length; }
 1184              		.loc 5 182 7 view .LVU380
 1185              	.LBB201:
 183:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1186              		.loc 5 183 9 is_stmt 0 view .LVU381
 1187 0048 6A60     		str	r2, [r5, #4]
 1188              	.LVL65:
 183:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1189              		.loc 5 183 9 view .LVU382
 1190              	.LBE201:
 1191              	.LBE200:
 1192              	.LBB202:
 1193              	.LBI202:
 186:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return _M_dataplus._M_p; }
 1194              		.loc 5 186 7 is_stmt 1 view .LVU383
 1195              	.LBB203:
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1196              		.loc 5 187 28 is_stmt 0 view .LVU384
 1197 004a 2B68     		ldr	r3, [r5]
 1198              	.LVL66:
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1199              		.loc 5 187 28 view .LVU385
 1200              	.LBE203:
 1201              	.LBE202:
 217:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 1202              		.loc 5 217 31 view .LVU386
 1203 004c 9B18     		adds	r3, r3, r2
 1204              	.LVL67:
 1205              	.LBB204:
 1206              	.LBI204:
 299:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       { __c1 = __c2; }
 1207              		.loc 6 299 7 is_stmt 1 view .LVU387
 1208              	.LBB205:
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1209              		.loc 6 300 9 view .LVU388
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1210              		.loc 6 300 14 is_stmt 0 view .LVU389
 1211 004e 0022     		movs	r2, #0
 1212              	.LVL68:
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1213              		.loc 6 300 14 view .LVU390
ARM GAS  /tmp/ccitkYpi.s 			page 59


 1214 0050 1A70     		strb	r2, [r3]
 1215              	.LVL69:
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 
 1216              		.loc 6 300 14 view .LVU391
 1217              	.LBE205:
 1218              	.LBE204:
 1219              	.LBE199:
 1220              	.LBE198:
 233:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.tcc ****       }
 1221              		.loc 3 233 7 view .LVU392
 1222 0052 02B0     		add	sp, sp, #8
 1223              		@ sp needed
 1224              	.LVL70:
 1225              	.LVL71:
 1226              		.loc 3 233 7 view .LVU393
 1227 0054 70BD     		pop	{r4, r5, r6, pc}
 1228              	.L65:
 1229 0056 C046     		.align	2
 1230              	.L64:
 1231 0058 00000000 		.word	.LC5
 1232              		.cfi_endproc
 1233              	.LFE4407:
 1235              		.section	.rodata.main.str1.4,"aMS",%progbits,1
 1236              		.align	2
 1237              	.LC7:
 1238 0000 48656C6C 		.ascii	"Hello world\015\012\000"
 1238      6F20776F 
 1238      726C640D 
 1238      0A00
 1239              		.section	.text.main,"ax",%progbits
 1240              		.align	1
 1241              		.global	main
 1242              		.syntax unified
 1243              		.code	16
 1244              		.thumb_func
 1245              		.fpu softvfp
 1247              	main:
 1248              	.LFB3853:
  82:Src/main.c    ****     /* USER CODE BEGIN 1 */
 1249              		.loc 1 82 15 is_stmt 1 view -0
 1250              		.cfi_startproc
 1251              		@ args = 0, pretend = 0, frame = 32
 1252              		@ frame_needed = 0, uses_anonymous_args = 0
 1253 0000 30B5     		push	{r4, r5, lr}
 1254              	.LCFI14:
 1255              		.cfi_def_cfa_offset 12
 1256              		.cfi_offset 4, -12
 1257              		.cfi_offset 5, -8
 1258              		.cfi_offset 14, -4
 1259 0002 89B0     		sub	sp, sp, #36
 1260              	.LCFI15:
 1261              		.cfi_def_cfa_offset 48
  90:Src/main.c    **** 
 1262              		.loc 1 90 5 view .LVU395
  90:Src/main.c    **** 
 1263              		.loc 1 90 13 is_stmt 0 view .LVU396
 1264 0004 FFF7FEFF 		bl	HAL_Init
ARM GAS  /tmp/ccitkYpi.s 			page 60


 1265              	.LVL72:
  97:Src/main.c    **** 
 1266              		.loc 1 97 5 is_stmt 1 view .LVU397
  97:Src/main.c    **** 
 1267              		.loc 1 97 23 is_stmt 0 view .LVU398
 1268 0008 FFF7FEFF 		bl	_Z18SystemClock_Configv
 1269              	.LVL73:
 104:Src/main.c    ****     MX_I2C1_Init();
 1270              		.loc 1 104 5 is_stmt 1 view .LVU399
 104:Src/main.c    ****     MX_I2C1_Init();
 1271              		.loc 1 104 17 is_stmt 0 view .LVU400
 1272 000c FFF7FEFF 		bl	_ZL12MX_GPIO_Initv
 1273              	.LVL74:
 105:Src/main.c    ****     MX_USART2_UART_Init();
 1274              		.loc 1 105 5 is_stmt 1 view .LVU401
 105:Src/main.c    ****     MX_USART2_UART_Init();
 1275              		.loc 1 105 17 is_stmt 0 view .LVU402
 1276 0010 FFF7FEFF 		bl	_ZL12MX_I2C1_Initv
 1277              	.LVL75:
 106:Src/main.c    ****     MX_USART3_UART_Init();
 1278              		.loc 1 106 5 is_stmt 1 view .LVU403
 106:Src/main.c    ****     MX_USART3_UART_Init();
 1279              		.loc 1 106 24 is_stmt 0 view .LVU404
 1280 0014 FFF7FEFF 		bl	_ZL19MX_USART2_UART_Initv
 1281              	.LVL76:
 107:Src/main.c    ****     MX_ADC1_Init();
 1282              		.loc 1 107 5 is_stmt 1 view .LVU405
 107:Src/main.c    ****     MX_ADC1_Init();
 1283              		.loc 1 107 24 is_stmt 0 view .LVU406
 1284 0018 FFF7FEFF 		bl	_ZL19MX_USART3_UART_Initv
 1285              	.LVL77:
 108:Src/main.c    ****     MX_TIM2_Init();
 1286              		.loc 1 108 5 is_stmt 1 view .LVU407
 108:Src/main.c    ****     MX_TIM2_Init();
 1287              		.loc 1 108 17 is_stmt 0 view .LVU408
 1288 001c FFF7FEFF 		bl	_ZL12MX_ADC1_Initv
 1289              	.LVL78:
 109:Src/main.c    ****     /* USER CODE BEGIN 2 */
 1290              		.loc 1 109 5 is_stmt 1 view .LVU409
 109:Src/main.c    ****     /* USER CODE BEGIN 2 */
 1291              		.loc 1 109 17 is_stmt 0 view .LVU410
 1292 0020 FFF7FEFF 		bl	_ZL12MX_TIM2_Initv
 1293              	.LVL79:
 111:Src/main.c    **** 
 1294              		.loc 1 111 5 is_stmt 1 view .LVU411
 111:Src/main.c    **** 
 1295              		.loc 1 111 14 is_stmt 0 view .LVU412
 1296 0024 0120     		movs	r0, #1
 1297 0026 FFF7FEFF 		bl	HAL_Delay
 1298              	.LVL80:
 115:Src/main.c    **** 
 1299              		.loc 1 115 5 is_stmt 1 view .LVU413
 115:Src/main.c    **** 
 1300              		.loc 1 115 11 is_stmt 0 view .LVU414
 1301 002a FFF7FEFF 		bl	_Z6devicev
 1302              	.LVL81:
 115:Src/main.c    **** 
ARM GAS  /tmp/ccitkYpi.s 			page 61


 1303              		.loc 1 115 15 view .LVU415
 1304 002e 0368     		ldr	r3, [r0]
 115:Src/main.c    **** 
 1305              		.loc 1 115 20 view .LVU416
 1306 0030 DD69     		ldr	r5, [r3, #28]
 1307              	.LVL82:
 1308              	.LBB241:
 1309              	.LBI241:
 1310              		.file 7 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h"
   1:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // Allocators -*- C++ -*-
   2:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
   3:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // Copyright (C) 2001-2019 Free Software Foundation, Inc.
   4:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** //
   5:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // software; you can redistribute it and/or modify it under the
   7:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // terms of the GNU General Public License as published by the
   8:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // Free Software Foundation; either version 3, or (at your option)
   9:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // any later version.
  10:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  11:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // This library is distributed in the hope that it will be useful,
  12:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // GNU General Public License for more details.
  15:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  16:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // permissions described in the GCC Runtime Library Exception, version
  18:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // 3.1, as published by the Free Software Foundation.
  19:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  20:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // You should have received a copy of the GNU General Public License and
  21:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** // <http://www.gnu.org/licenses/>.
  24:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  25:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** /*
  26:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * Copyright (c) 1996-1997
  27:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * Silicon Graphics Computer Systems, Inc.
  28:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  *
  29:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * Permission to use, copy, modify, distribute and sell this software
  30:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * and its documentation for any purpose is hereby granted without fee,
  31:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * provided that the above copyright notice appear in all copies and
  32:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * that both that copyright notice and this permission notice appear
  33:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * in supporting documentation.  Silicon Graphics makes no
  34:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * representations about the suitability of this software for any
  35:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  * purpose.  It is provided "as is" without express or implied warranty.
  36:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  */
  37:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  38:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** /** @file bits/allocator.h
  39:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  *  This is an internal header file, included by other library headers.
  40:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  *  Do not attempt to use it directly. @headername{memory}
  41:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****  */
  42:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  43:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #ifndef _ALLOCATOR_H
  44:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #define _ALLOCATOR_H 1
  45:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  46:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #include <bits/c++allocator.h> // Define the base class to std::allocator.
  47:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #include <bits/memoryfwd.h>
  48:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #if __cplusplus >= 201103L
ARM GAS  /tmp/ccitkYpi.s 			page 62


  49:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #include <type_traits>
  50:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #endif
  51:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  52:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #define __cpp_lib_incomplete_container_elements 201505
  53:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #if __cplusplus >= 201103L
  54:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** # define __cpp_lib_allocator_is_always_equal 201411
  55:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #endif
  56:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  57:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** namespace std _GLIBCXX_VISIBILITY(default)
  58:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** {
  59:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  60:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  61:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****   /**
  62:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    *  @addtogroup allocators
  63:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    *  @{
  64:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    */
  65:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  66:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****   /// allocator<void> specialization.
  67:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****   template<>
  68:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****     class allocator<void>
  69:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****     {
  70:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****     public:
  71:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef size_t      size_type;
  72:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef ptrdiff_t   difference_type;
  73:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef void*       pointer;
  74:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef const void* const_pointer;
  75:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef void        value_type;
  76:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  77:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       template<typename _Tp1>
  78:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	struct rebind
  79:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	{ typedef allocator<_Tp1> other; };
  80:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  81:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #if __cplusplus >= 201103L
  82:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
  83:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       // 2103. std::allocator propagate_on_container_move_assignment
  84:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef true_type propagate_on_container_move_assignment;
  85:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  86:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef true_type is_always_equal;
  87:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  88:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       template<typename _Up, typename... _Args>
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	void
  90:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	construct(_Up* __p, _Args&&... __args)
  91:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	noexcept(noexcept(::new((void *)__p)
  92:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 			    _Up(std::forward<_Args>(__args)...)))
  93:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
  94:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
  95:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       template<typename _Up>
  96:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	void
  97:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	destroy(_Up* __p)
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	noexcept(noexcept(__p->~_Up()))
  99:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	{ __p->~_Up(); }
 100:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #endif
 101:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****     };
 102:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 103:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****   /**
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    * @brief  The @a standard allocator, as per [20.4].
 105:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    *
ARM GAS  /tmp/ccitkYpi.s 			page 63


 106:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    *  See https://gcc.gnu.org/onlinedocs/libstdc++/manual/memory.html#std.util.memory.allocator
 107:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    *  for further details.
 108:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    *
 109:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    *  @tparam  _Tp  Type of allocated object.
 110:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    */
 111:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****   template<typename _Tp>
 112:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****     class allocator : public __allocator_base<_Tp>
 113:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****     {
 114:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****    public:
 115:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef size_t     size_type;
 116:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef ptrdiff_t  difference_type;
 117:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef _Tp*       pointer;
 118:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef const _Tp* const_pointer;
 119:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef _Tp&       reference;
 120:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef const _Tp& const_reference;
 121:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef _Tp        value_type;
 122:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 123:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       template<typename _Tp1>
 124:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	struct rebind
 125:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	{ typedef allocator<_Tp1> other; };
 126:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 127:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #if __cplusplus >= 201103L
 128:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
 129:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       // 2103. std::allocator propagate_on_container_move_assignment
 130:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef true_type propagate_on_container_move_assignment;
 131:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 132:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       typedef true_type is_always_equal;
 133:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #endif
 134:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 135:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
 136:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       // 3035. std::allocator's constructors should be constexpr
 137:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       _GLIBCXX20_CONSTEXPR
 138:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       allocator() _GLIBCXX_NOTHROW { }
 1311              		.loc 7 138 7 is_stmt 1 view .LVU417
 1312              	.LBB242:
 1313              	.LBI242:
 1314              		.file 8 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h"
   1:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // Allocator that wraps operator new -*- C++ -*-
   2:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
   3:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // Copyright (C) 2001-2019 Free Software Foundation, Inc.
   4:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** //
   5:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // software; you can redistribute it and/or modify it under the
   7:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // terms of the GNU General Public License as published by the
   8:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // Free Software Foundation; either version 3, or (at your option)
   9:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // any later version.
  10:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  11:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // This library is distributed in the hope that it will be useful,
  12:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // GNU General Public License for more details.
  15:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  16:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // permissions described in the GCC Runtime Library Exception, version
  18:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // 3.1, as published by the Free Software Foundation.
  19:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  20:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // You should have received a copy of the GNU General Public License and
ARM GAS  /tmp/ccitkYpi.s 			page 64


  21:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** // <http://www.gnu.org/licenses/>.
  24:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  25:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** /** @file ext/new_allocator.h
  26:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****  *  This file is a GNU extension to the Standard C++ Library.
  27:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****  */
  28:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  29:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #ifndef _NEW_ALLOCATOR_H
  30:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #define _NEW_ALLOCATOR_H 1
  31:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  32:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #include <bits/c++config.h>
  33:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #include <new>
  34:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #include <bits/functexcept.h>
  35:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #include <bits/move.h>
  36:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #if __cplusplus >= 201103L
  37:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #include <type_traits>
  38:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #endif
  39:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  40:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** namespace __gnu_cxx _GLIBCXX_VISIBILITY(default)
  41:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** {
  42:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  43:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  44:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****   using std::size_t;
  45:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****   using std::ptrdiff_t;
  46:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  47:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****   /**
  48:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *  @brief  An allocator that uses global new, as per [20.4].
  49:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *  @ingroup allocators
  50:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *
  51:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *  This is precisely the allocator defined in the C++ Standard.
  52:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *    - all allocation calls operator new
  53:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *    - all deallocation calls operator delete
  54:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *
  55:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    *  @tparam  _Tp  Type of allocated object.
  56:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****    */
  57:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****   template<typename _Tp>
  58:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****     class new_allocator
  59:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****     {
  60:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****     public:
  61:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef size_t     size_type;
  62:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef ptrdiff_t  difference_type;
  63:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef _Tp*       pointer;
  64:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef const _Tp* const_pointer;
  65:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef _Tp&       reference;
  66:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef const _Tp& const_reference;
  67:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef _Tp        value_type;
  68:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  69:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       template<typename _Tp1>
  70:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	struct rebind
  71:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	{ typedef new_allocator<_Tp1> other; };
  72:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  73:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #if __cplusplus >= 201103L
  74:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
  75:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       // 2103. propagate_on_container_move_assignment
  76:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       typedef std::true_type propagate_on_container_move_assignment;
  77:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #endif
ARM GAS  /tmp/ccitkYpi.s 			page 65


  78:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  79:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       _GLIBCXX20_CONSTEXPR
  80:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       new_allocator() _GLIBCXX_USE_NOEXCEPT { }
 1315              		.loc 8 80 7 view .LVU418
 1316              		.loc 8 80 7 is_stmt 0 view .LVU419
 1317              	.LBE242:
 1318              	.LBE241:
 1319              	.LBB243:
 1320              	.LBI243:
 397:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _GLIBCXX_NOEXCEPT
 398:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _S_copy(__p, __k1, __k2 - __k1); }
 399:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 400:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       static int
 401:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _S_compare(size_type __n1, size_type __n2) _GLIBCXX_NOEXCEPT
 402:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 403:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	const difference_type __d = difference_type(__n1 - __n2);
 404:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 405:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (__d > __gnu_cxx::__numeric_traits<int>::__max)
 406:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  return __gnu_cxx::__numeric_traits<int>::__max;
 407:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else if (__d < __gnu_cxx::__numeric_traits<int>::__min)
 408:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  return __gnu_cxx::__numeric_traits<int>::__min;
 409:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else
 410:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  return int(__d);
 411:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 412:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 413:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 414:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_assign(const basic_string&);
 415:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 416:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 417:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_mutate(size_type __pos, size_type __len1, const _CharT* __s,
 418:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		size_type __len2);
 419:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 420:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       void
 421:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _M_erase(size_type __pos, size_type __n);
 422:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 423:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****     public:
 424:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // Construct/copy/destroy:
 425:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // NB: We overload ctors in some cases instead of using default
 426:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // arguments, per 17.4.4.4 para. 2 item 2.
 427:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 428:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 429:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Default constructor creates an empty string.
 430:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 431:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string()
 432:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       _GLIBCXX_NOEXCEPT_IF(is_nothrow_default_constructible<_Alloc>::value)
 433:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data())
 434:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_set_length(0); }
 435:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 436:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 437:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct an empty string using allocator @a a.
 438:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 439:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       explicit
 440:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const _Alloc& __a) _GLIBCXX_NOEXCEPT
 441:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 442:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_set_length(0); }
 443:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 444:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
ARM GAS  /tmp/ccitkYpi.s 			page 66


 445:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string with copy of value of @a __str.
 446:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __str  Source string.
 447:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 448:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const basic_string& __str)
 449:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(),
 450:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		    _Alloc_traits::_S_select_on_copy(__str._M_get_allocator()))
 451:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_construct(__str._M_data(), __str._M_data() + __str.length()); }
 452:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 453:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
 454:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // 2583. no way to supply an allocator for basic_string(str, pos)
 455:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 456:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string as copy of a substring.
 457:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __str  Source string.
 458:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __pos  Index of first character to copy from.
 459:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use.
 460:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 461:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const basic_string& __str, size_type __pos,
 462:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		   const _Alloc& __a = _Alloc())
 463:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 464:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 465:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	const _CharT* __start = __str._M_data()
 466:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  + __str._M_check(__pos, "basic_string::basic_string");
 467:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_M_construct(__start, __start + __str._M_limit(__pos, npos));
 468:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 469:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 470:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 471:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string as copy of a substring.
 472:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __str  Source string.
 473:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __pos  Index of first character to copy from.
 474:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __n  Number of characters to copy.
 475:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 476:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const basic_string& __str, size_type __pos,
 477:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		   size_type __n)
 478:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data())
 479:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 480:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	const _CharT* __start = __str._M_data()
 481:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  + __str._M_check(__pos, "basic_string::basic_string");
 482:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_M_construct(__start, __start + __str._M_limit(__pos, __n));
 483:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 484:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 485:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 486:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string as copy of a substring.
 487:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __str  Source string.
 488:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __pos  Index of first character to copy from.
 489:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __n  Number of characters to copy.
 490:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use.
 491:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 492:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const basic_string& __str, size_type __pos,
 493:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		   size_type __n, const _Alloc& __a)
 494:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 495:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 496:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	const _CharT* __start
 497:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  = __str._M_data() + __str._M_check(__pos, "string::string");
 498:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_M_construct(__start, __start + __str._M_limit(__pos, __n));
 499:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 500:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 501:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
ARM GAS  /tmp/ccitkYpi.s 			page 67


 502:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string initialized by a character %array.
 503:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __s  Source character %array.
 504:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __n  Number of characters to copy.
 505:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use (default is default allocator).
 506:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *
 507:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  NB: @a __s must have at least @a __n characters, &apos;\\0&apos;
 508:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  has no special meaning.
 509:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 510:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const _CharT* __s, size_type __n,
 511:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		   const _Alloc& __a = _Alloc())
 512:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 513:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_construct(__s, __s + __n); }
 514:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 515:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 516:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string as copy of a C string.
 517:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __s  Source C string.
 518:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use (default is default allocator).
 519:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 520:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cpp_deduction_guides && ! defined _GLIBCXX_DEFINING_STRING_INSTANTIATIONS
 521:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
 522:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // 3076. basic_string CTAD ambiguity
 523:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename = _RequireAllocator<_Alloc>>
 524:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 525:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const _CharT* __s, const _Alloc& __a = _Alloc())
 1321              		.loc 5 525 7 is_stmt 1 view .LVU420
 1322              	.LBB244:
 1323              	.LBB245:
 1324              	.LBB246:
 1325              	.LBI246:
 190:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1326              		.loc 5 190 7 view .LVU421
 190:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1327              		.loc 5 190 7 is_stmt 0 view .LVU422
 1328              	.LBE246:
 1329              	.LBB247:
 1330              	.LBI247:
 156:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	: allocator_type(__a), _M_p(__dat) { }
 1331              		.loc 5 156 2 is_stmt 1 view .LVU423
 1332              	.LBB248:
 1333              	.LBB249:
 1334              	.LBB250:
 1335              	.LBI250:
 139:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 140:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       _GLIBCXX20_CONSTEXPR
 141:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       allocator(const allocator& __a) _GLIBCXX_NOTHROW
 1336              		.loc 7 141 7 view .LVU424
 1337              	.LBB251:
 1338              	.LBI251:
  81:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  82:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       _GLIBCXX20_CONSTEXPR
  83:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       new_allocator(const new_allocator&) _GLIBCXX_USE_NOEXCEPT { }
 1339              		.loc 8 83 7 view .LVU425
 1340              		.loc 8 83 7 is_stmt 0 view .LVU426
 1341              	.LBE251:
 1342              	.LBE250:
 157:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1343              		.loc 5 157 35 view .LVU427
ARM GAS  /tmp/ccitkYpi.s 			page 68


 1344 0032 02AC     		add	r4, sp, #8
 1345              	.LVL83:
 157:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1346              		.loc 5 157 35 view .LVU428
 1347 0034 0094     		str	r4, [sp]
 1348              	.LVL84:
 157:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1349              		.loc 5 157 35 view .LVU429
 1350              	.LBE249:
 1351              	.LBE248:
 1352              	.LBE247:
 1353              	.LBB252:
 1354              	.LBI252:
 329:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       {
 1355              		.loc 6 329 7 is_stmt 1 view .LVU430
 1356              	.LBE252:
 1357              	.LBE245:
 1358              	.LBE244:
 1359              	.LBE243:
 332:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h **** 	  return __gnu_cxx::char_traits<char_type>::length(__s);
 1360              		.loc 6 332 2 view .LVU431
 335:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/char_traits.h ****       }
 1361              		.loc 6 335 2 view .LVU432
 1362              	.LBB259:
 1363              	.LBB258:
 1364              	.LBB257:
 1365              	.LBB253:
 1366              	.LBI253:
 263:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	{
 1367              		.loc 5 263 9 view .LVU433
 1368              	.LBB254:
 1369              	.LBB255:
 1370              	.LBI255:
 243:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 			 std::__false_type)
 1371              		.loc 5 243 9 view .LVU434
 1372              	.LBB256:
 247:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	}
 1373              		.loc 5 247 11 is_stmt 0 view .LVU435
 1374 0036 294A     		ldr	r2, .L69
 1375              	.LVL85:
 247:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	}
 1376              		.loc 5 247 11 view .LVU436
 1377 0038 1100     		movs	r1, r2
 1378 003a 0D39     		subs	r1, r1, #13
 1379 003c 0023     		movs	r3, #0
 1380 003e 6846     		mov	r0, sp
 1381 0040 FFF7FEFF 		bl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iter
 1382              	.LVL86:
 247:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	}
 1383              		.loc 5 247 11 view .LVU437
 1384              	.LBE256:
 1385              	.LBE255:
 1386              	.LBE254:
 1387              	.LBE253:
 1388              	.LBE257:
 1389              	.LBE258:
 1390              	.LBE259:
ARM GAS  /tmp/ccitkYpi.s 			page 69


 115:Src/main.c    **** 
 1391              		.loc 1 115 32 view .LVU438
 1392 0044 6946     		mov	r1, sp
 1393 0046 2800     		movs	r0, r5
 1394 0048 FFF7FEFF 		bl	_ZN4UART4SendENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
 1395              	.LVL87:
 1396              	.LBB260:
 1397              	.LBI260:
 526:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 527:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_construct(__s, __s ? __s + traits_type::length(__s) : __s+npos); }
 528:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 529:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 530:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string as multiple characters.
 531:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __n  Number of characters.
 532:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __c  Character to use.
 533:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use (default is default allocator).
 534:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 535:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cpp_deduction_guides && ! defined _GLIBCXX_DEFINING_STRING_INSTANTIATIONS
 536:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // _GLIBCXX_RESOLVE_LIB_DEFECTS
 537:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       // 3076. basic_string CTAD ambiguity
 538:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename = _RequireAllocator<_Alloc>>
 539:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 540:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(size_type __n, _CharT __c, const _Alloc& __a = _Alloc())
 541:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 542:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_construct(__n, __c); }
 543:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 544:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201103L
 545:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 546:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Move construct string.
 547:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __str  Source string.
 548:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *
 549:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  The newly-created string contains the exact contents of @a __str.
 550:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @a __str is a valid, but unspecified string.
 551:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        **/
 552:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(basic_string&& __str) noexcept
 553:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), std::move(__str._M_get_allocator()))
 554:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 555:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (__str._M_is_local())
 556:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  {
 557:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    traits_type::copy(_M_local_buf, __str._M_local_buf,
 558:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 			      _S_local_capacity + 1);
 559:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  }
 560:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else
 561:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  {
 562:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    _M_data(__str._M_data());
 563:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    _M_capacity(__str._M_allocated_capacity);
 564:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  }
 565:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 566:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	// Must use _M_length() here not _M_set_length() because
 567:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	// basic_stringbuf relies on writing into unallocated capacity so
 568:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	// we mess up the contents if we put a '\0' in the string.
 569:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	_M_length(__str.length());
 570:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	__str._M_data(__str._M_local_data());
 571:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	__str._M_set_length(0);
 572:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 573:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 574:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
ARM GAS  /tmp/ccitkYpi.s 			page 70


 575:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string from an initializer %list.
 576:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __l  std::initializer_list of characters.
 577:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use (default is default allocator).
 578:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 579:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(initializer_list<_CharT> __l, const _Alloc& __a = _Alloc())
 580:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 581:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_construct(__l.begin(), __l.end()); }
 582:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 583:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(const basic_string& __str, const _Alloc& __a)
 584:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 585:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _M_construct(__str.begin(), __str.end()); }
 586:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 587:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       basic_string(basic_string&& __str, const _Alloc& __a)
 588:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       noexcept(_Alloc_traits::_S_always_equal())
 589:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       : _M_dataplus(_M_local_data(), __a)
 590:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 591:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	if (__str._M_is_local())
 592:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  {
 593:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    traits_type::copy(_M_local_buf, __str._M_local_buf,
 594:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 			      _S_local_capacity + 1);
 595:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    _M_length(__str.length());
 596:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    __str._M_set_length(0);
 597:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  }
 598:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else if (_Alloc_traits::_S_always_equal()
 599:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    || __str.get_allocator() == __a)
 600:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  {
 601:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    _M_data(__str._M_data());
 602:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    _M_length(__str.length());
 603:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    _M_capacity(__str._M_allocated_capacity);
 604:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    __str._M_data(__str._M_local_buf);
 605:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	    __str._M_set_length(0);
 606:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  }
 607:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	else
 608:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  _M_construct(__str.begin(), __str.end());
 609:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       }
 610:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 611:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif // C++11
 612:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 613:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 614:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string as copy of a range.
 615:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __beg  Start of range.
 616:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __end  End of range.
 617:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use (default is default allocator).
 618:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 619:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201103L
 620:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _InputIterator,
 621:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	       typename = std::_RequireInputIter<_InputIterator>>
 622:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #else
 623:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _InputIterator>
 624:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif
 625:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****         basic_string(_InputIterator __beg, _InputIterator __end,
 626:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		     const _Alloc& __a = _Alloc())
 627:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	: _M_dataplus(_M_local_data(), __a)
 628:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	{ _M_construct(__beg, __end); }
 629:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 630:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #if __cplusplus >= 201703L
 631:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
ARM GAS  /tmp/ccitkYpi.s 			page 71


 632:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string from a substring of a string_view.
 633:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __t   Source object convertible to string view.
 634:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __pos The index of the first character to copy from __t.
 635:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __n   The number of characters to copy from __t.
 636:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a   Allocator to use.
 637:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 638:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _Tp, typename = _If_sv<_Tp, void>>
 639:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	basic_string(const _Tp& __t, size_type __pos, size_type __n,
 640:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 		     const _Alloc& __a = _Alloc())
 641:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	: basic_string(_S_to_string_view(__t).substr(__pos, __n), __a) { }
 642:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 643:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 644:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Construct string from a string_view.
 645:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __t  Source object convertible to string view.
 646:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @param  __a  Allocator to use (default is default allocator).
 647:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 648:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       template<typename _Tp, typename = _If_sv<_Tp, void>>
 649:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	explicit
 650:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	basic_string(const _Tp& __t, const _Alloc& __a = _Alloc())
 651:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	: basic_string(__sv_wrapper(_S_to_string_view(__t)), __a) { }
 652:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** #endif // C++17
 653:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 654:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       /**
 655:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        *  @brief  Destroy the string instance.
 656:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****        */
 657:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       ~basic_string()
 1398              		.loc 5 657 7 is_stmt 1 view .LVU439
 1399              	.LBB261:
 1400              	.LBI261:
 229:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1401              		.loc 5 229 7 view .LVU440
 1402              	.LBB262:
 1403              	.LBB263:
 1404              	.LBI263:
 221:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return _M_data() == _M_local_data(); }
 1405              		.loc 5 221 7 view .LVU441
 1406              	.LBB264:
 1407              	.LBI264:
 186:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { return _M_dataplus._M_p; }
 1408              		.loc 5 186 7 view .LVU442
 1409              	.LBB265:
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1410              		.loc 5 187 28 is_stmt 0 view .LVU443
 1411 004c 0098     		ldr	r0, [sp]
 1412              	.LVL88:
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 
 1413              		.loc 5 187 28 view .LVU444
 1414              	.LBE265:
 1415              	.LBE264:
 1416              	.LBB266:
 1417              	.LBI266:
 200:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1418              		.loc 5 200 7 is_stmt 1 view .LVU445
 200:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1419              		.loc 5 200 7 is_stmt 0 view .LVU446
 1420              	.LBE266:
 1421              	.LBE263:
ARM GAS  /tmp/ccitkYpi.s 			page 72


 231:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h **** 	  _M_destroy(_M_allocated_capacity);
 1422              		.loc 5 231 2 view .LVU447
 1423 004e A042     		cmp	r0, r4
 1424 0050 01D0     		beq	.L67
 1425              	.LVL89:
 1426              	.LBB267:
 1427              	.LBI267:
 236:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
 1428              		.loc 5 236 7 is_stmt 1 view .LVU448
 1429              	.LBB268:
 1430              	.LBB269:
 1431              	.LBI269:
 1432              		.file 9 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h"
   1:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // Allocator traits -*- C++ -*-
   2:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
   3:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // Copyright (C) 2011-2019 Free Software Foundation, Inc.
   4:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** //
   5:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // software; you can redistribute it and/or modify it under the
   7:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // terms of the GNU General Public License as published by the
   8:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // Free Software Foundation; either version 3, or (at your option)
   9:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // any later version.
  10:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  11:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // This library is distributed in the hope that it will be useful,
  12:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // GNU General Public License for more details.
  15:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  16:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // permissions described in the GCC Runtime Library Exception, version
  18:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // 3.1, as published by the Free Software Foundation.
  19:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  20:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // You should have received a copy of the GNU General Public License and
  21:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** // <http://www.gnu.org/licenses/>.
  24:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  25:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** /** @file bits/alloc_traits.h
  26:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****  *  This is an internal header file, included by other library headers.
  27:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****  *  Do not attempt to use it directly. @headername{memory}
  28:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****  */
  29:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  30:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** #ifndef _ALLOC_TRAITS_H
  31:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** #define _ALLOC_TRAITS_H 1
  32:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  33:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** #if __cplusplus >= 201103L
  34:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  35:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** #include <bits/memoryfwd.h>
  36:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** #include <bits/ptr_traits.h>
  37:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** #include <ext/numeric_traits.h>
  38:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  39:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** #define __cpp_lib_allocator_traits_is_always_equal 201411
  40:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  41:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** namespace std _GLIBCXX_VISIBILITY(default)
  42:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** {
  43:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  44:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
ARM GAS  /tmp/ccitkYpi.s 			page 73


  45:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   struct __allocator_traits_base
  46:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   {
  47:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp, typename _Up, typename = void>
  48:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       struct __rebind : __replace_first_arg<_Tp, _Up> { };
  49:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  50:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp, typename _Up>
  51:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       struct __rebind<_Tp, _Up,
  52:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 		      __void_t<typename _Tp::template rebind<_Up>::other>>
  53:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { using type = typename _Tp::template rebind<_Up>::other; };
  54:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  55:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   protected:
  56:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  57:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __pointer = typename _Tp::pointer;
  58:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  59:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __c_pointer = typename _Tp::const_pointer;
  60:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  61:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __v_pointer = typename _Tp::void_pointer;
  62:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  63:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __cv_pointer = typename _Tp::const_void_pointer;
  64:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  65:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __pocca = typename _Tp::propagate_on_container_copy_assignment;
  66:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  67:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __pocma = typename _Tp::propagate_on_container_move_assignment;
  68:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  69:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __pocs = typename _Tp::propagate_on_container_swap;
  70:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     template<typename _Tp>
  71:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using __equal = typename _Tp::is_always_equal;
  72:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   };
  73:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  74:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   template<typename _Alloc, typename _Up>
  75:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     using __alloc_rebind
  76:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       = typename __allocator_traits_base::template __rebind<_Alloc, _Up>::type;
  77:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  78:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   /**
  79:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****    * @brief  Uniform interface to all allocator types.
  80:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****    * @ingroup allocators
  81:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   */
  82:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   template<typename _Alloc>
  83:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     struct allocator_traits : __allocator_traits_base
  84:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     {
  85:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator type
  86:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       typedef _Alloc allocator_type;
  87:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocated type
  88:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       typedef typename _Alloc::value_type value_type;
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  90:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
  91:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   The allocator's pointer type.
  92:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
  93:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::pointer if that type exists, otherwise @c value_type*
  94:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
  95:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using pointer = __detected_or_t<value_type*, __pointer, _Alloc>;
  96:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
  97:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     private:
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       // Select _Func<_Alloc> or pointer_traits<pointer>::rebind<_Tp>
  99:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<template<typename> class _Func, typename _Tp, typename = void>
 100:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	struct _Ptr
 101:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{
ARM GAS  /tmp/ccitkYpi.s 			page 74


 102:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  using type = typename pointer_traits<pointer>::template rebind<_Tp>;
 103:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	};
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 105:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<template<typename> class _Func, typename _Tp>
 106:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	struct _Ptr<_Func, _Tp, __void_t<_Func<_Alloc>>>
 107:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{
 108:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  using type = _Func<_Alloc>;
 109:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	};
 110:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 111:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       // Select _A2::difference_type or pointer_traits<_Ptr>::difference_type
 112:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _A2, typename _PtrT, typename = void>
 113:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	struct _Diff
 114:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ using type = typename pointer_traits<_PtrT>::difference_type; };
 115:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 116:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _A2, typename _PtrT>
 117:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	struct _Diff<_A2, _PtrT, __void_t<typename _A2::difference_type>>
 118:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ using type = typename _A2::difference_type; };
 119:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 120:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       // Select _A2::size_type or make_unsigned<_DiffT>::type
 121:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _A2, typename _DiffT, typename = void>
 122:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	struct _Size : make_unsigned<_DiffT> { };
 123:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 124:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _A2, typename _DiffT>
 125:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	struct _Size<_A2, _DiffT, __void_t<typename _A2::size_type>>
 126:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ using type = typename _A2::size_type; };
 127:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 128:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     public:
 129:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 130:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   The allocator's const pointer type.
 131:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 132:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::const_pointer if that type exists, otherwise
 133:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * <tt> pointer_traits<pointer>::rebind<const value_type> </tt>
 134:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 135:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using const_pointer = typename _Ptr<__c_pointer, const value_type>::type;
 136:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 137:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 138:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   The allocator's void pointer type.
 139:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 140:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::void_pointer if that type exists, otherwise
 141:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * <tt> pointer_traits<pointer>::rebind<void> </tt>
 142:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 143:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using void_pointer = typename _Ptr<__v_pointer, void>::type;
 144:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 145:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 146:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   The allocator's const void pointer type.
 147:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 148:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::const_void_pointer if that type exists, otherwise
 149:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * <tt> pointer_traits<pointer>::rebind<const void> </tt>
 150:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 151:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using const_void_pointer = typename _Ptr<__cv_pointer, const void>::type;
 152:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 153:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 154:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   The allocator's difference type
 155:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 156:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::difference_type if that type exists, otherwise
 157:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * <tt> pointer_traits<pointer>::difference_type </tt>
 158:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
ARM GAS  /tmp/ccitkYpi.s 			page 75


 159:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using difference_type = typename _Diff<_Alloc, pointer>::type;
 160:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 161:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 162:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   The allocator's size type
 163:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 164:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::size_type if that type exists, otherwise
 165:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * <tt> make_unsigned<difference_type>::type </tt>
 166:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 167:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using size_type = typename _Size<_Alloc, difference_type>::type;
 168:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 169:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 170:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   How the allocator is propagated on copy assignment
 171:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 172:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::propagate_on_container_copy_assignment if that type exists,
 173:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * otherwise @c false_type
 174:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 175:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using propagate_on_container_copy_assignment
 176:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	= __detected_or_t<false_type, __pocca, _Alloc>;
 177:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 178:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 179:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   How the allocator is propagated on move assignment
 180:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 181:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::propagate_on_container_move_assignment if that type exists,
 182:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * otherwise @c false_type
 183:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 184:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using propagate_on_container_move_assignment
 185:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	= __detected_or_t<false_type, __pocma, _Alloc>;
 186:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 187:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 188:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   How the allocator is propagated on swap
 189:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 190:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::propagate_on_container_swap if that type exists,
 191:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * otherwise @c false_type
 192:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 193:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using propagate_on_container_swap
 194:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	= __detected_or_t<false_type, __pocs, _Alloc>;
 195:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 196:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 197:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @brief   Whether all instances of the allocator type compare equal.
 198:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 199:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * @c Alloc::is_always_equal if that type exists,
 200:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        * otherwise @c is_empty<Alloc>::type
 201:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 202:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using is_always_equal
 203:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	= __detected_or_t<typename is_empty<_Alloc>::type, __equal, _Alloc>;
 204:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 205:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp>
 206:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	using rebind_alloc = __alloc_rebind<_Alloc, _Tp>;
 207:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp>
 208:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	using rebind_traits = allocator_traits<rebind_alloc<_Tp>>;
 209:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 210:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     private:
 211:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2>
 212:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static auto
 213:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_allocate(_Alloc2& __a, size_type __n, const_void_pointer __hint, int)
 214:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	-> decltype(__a.allocate(__n, __hint))
 215:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ return __a.allocate(__n, __hint); }
ARM GAS  /tmp/ccitkYpi.s 			page 76


 216:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 217:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2>
 218:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static pointer
 219:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_allocate(_Alloc2& __a, size_type __n, const_void_pointer, ...)
 220:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ return __a.allocate(__n); }
 221:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 222:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp, typename... _Args>
 223:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	struct __construct_helper
 224:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{
 225:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  template<typename _Alloc2,
 226:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	    typename = decltype(std::declval<_Alloc2*>()->construct(
 227:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 		  std::declval<_Tp*>(), std::declval<_Args>()...))>
 228:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	    static true_type __test(int);
 229:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 230:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  template<typename>
 231:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	    static false_type __test(...);
 232:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 233:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  using type = decltype(__test<_Alloc>(0));
 234:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	};
 235:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 236:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp, typename... _Args>
 237:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	using __has_construct
 238:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  = typename __construct_helper<_Tp, _Args...>::type;
 239:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 240:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp, typename... _Args>
 241:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static _Require<__has_construct<_Tp, _Args...>>
 242:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_construct(_Alloc& __a, _Tp* __p, _Args&&... __args)
 243:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	noexcept(noexcept(__a.construct(__p, std::forward<_Args>(__args)...)))
 244:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ __a.construct(__p, std::forward<_Args>(__args)...); }
 245:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 246:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp, typename... _Args>
 247:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static
 248:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_Require<__and_<__not_<__has_construct<_Tp, _Args...>>,
 249:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 			       is_constructible<_Tp, _Args...>>>
 250:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_construct(_Alloc&, _Tp* __p, _Args&&... __args)
 251:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	noexcept(noexcept(::new((void*)__p)
 252:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 			  _Tp(std::forward<_Args>(__args)...)))
 253:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ ::new((void*)__p) _Tp(std::forward<_Args>(__args)...); }
 254:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 255:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2, typename _Tp>
 256:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static auto
 257:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_destroy(_Alloc2& __a, _Tp* __p, int)
 258:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	noexcept(noexcept(__a.destroy(__p)))
 259:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	-> decltype(__a.destroy(__p))
 260:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ __a.destroy(__p); }
 261:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 262:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2, typename _Tp>
 263:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static void
 264:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_destroy(_Alloc2&, _Tp* __p, ...)
 265:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	noexcept(noexcept(__p->~_Tp()))
 266:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ __p->~_Tp(); }
 267:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 268:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2>
 269:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static auto
 270:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_max_size(_Alloc2& __a, int)
 271:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	-> decltype(__a.max_size())
 272:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ return __a.max_size(); }
ARM GAS  /tmp/ccitkYpi.s 			page 77


 273:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 274:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2>
 275:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static size_type
 276:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_max_size(_Alloc2&, ...)
 277:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{
 278:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  // _GLIBCXX_RESOLVE_LIB_DEFECTS
 279:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  // 2466. allocator_traits::max_size() default behavior is incorrect
 280:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	  return __gnu_cxx::__numeric_traits<size_type>::__max
 281:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	    / sizeof(value_type);
 282:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	}
 283:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 284:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2>
 285:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static auto
 286:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_select(_Alloc2& __a, int)
 287:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	-> decltype(__a.select_on_container_copy_construction())
 288:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ return __a.select_on_container_copy_construction(); }
 289:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 290:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Alloc2>
 291:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static _Alloc2
 292:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	_S_select(_Alloc2& __a, ...)
 293:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ return __a; }
 294:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 295:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     public:
 296:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 297:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 298:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Allocate memory.
 299:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 300:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __n  The number of objects to allocate space for.
 301:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 302:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Calls @c a.allocate(n)
 303:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 304:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       _GLIBCXX_NODISCARD static pointer
 305:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       allocate(_Alloc& __a, size_type __n)
 306:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { return __a.allocate(__n); }
 307:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 308:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 309:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Allocate memory.
 310:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 311:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __n  The number of objects to allocate space for.
 312:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __hint Aid to locality.
 313:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @return Memory of suitable size and alignment for @a n objects
 314:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *          of type @c value_type
 315:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 316:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Returns <tt> a.allocate(n, hint) </tt> if that expression is
 317:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  well-formed, otherwise returns @c a.allocate(n)
 318:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 319:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       _GLIBCXX_NODISCARD static pointer
 320:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       allocate(_Alloc& __a, size_type __n, const_void_pointer __hint)
 321:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { return _S_allocate(__a, __n, __hint, 0); }
 322:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 323:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 324:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Deallocate memory.
 325:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 326:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __p  Pointer to the memory to deallocate.
 327:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __n  The number of objects space was allocated for.
 328:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 329:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Calls <tt> a.deallocate(p, n) </tt>
ARM GAS  /tmp/ccitkYpi.s 			page 78


 330:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 331:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       static void
 332:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       deallocate(_Alloc& __a, pointer __p, size_type __n)
 333:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { __a.deallocate(__p, __n); }
 334:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 335:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 336:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Construct an object of type @a _Tp
 337:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 338:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __p  Pointer to memory of suitable size and alignment for Tp
 339:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __args Constructor arguments.
 340:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 341:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Calls <tt> __a.construct(__p, std::forward<Args>(__args)...) </tt>
 342:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  if that expression is well-formed, otherwise uses placement-new
 343:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  to construct an object of type @a _Tp at location @a __p from the
 344:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  arguments @a __args...
 345:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 346:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp, typename... _Args>
 347:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static auto construct(_Alloc& __a, _Tp* __p, _Args&&... __args)
 348:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	noexcept(noexcept(_S_construct(__a, __p,
 349:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 				       std::forward<_Args>(__args)...)))
 350:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	-> decltype(_S_construct(__a, __p, std::forward<_Args>(__args)...))
 351:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ _S_construct(__a, __p, std::forward<_Args>(__args)...); }
 352:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 353:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 354:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Destroy an object of type @a _Tp
 355:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 356:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __p  Pointer to the object to destroy
 357:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 358:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Calls @c __a.destroy(__p) if that expression is well-formed,
 359:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  otherwise calls @c __p->~_Tp()
 360:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 361:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Tp>
 362:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	static void destroy(_Alloc& __a, _Tp* __p)
 363:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	noexcept(noexcept(_S_destroy(__a, __p, 0)))
 364:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	{ _S_destroy(__a, __p, 0); }
 365:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 366:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 367:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  The maximum supported allocation size
 368:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 369:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @return @c __a.max_size() or @c numeric_limits<size_type>::max()
 370:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 371:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Returns @c __a.max_size() if that expression is well-formed,
 372:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  otherwise returns @c numeric_limits<size_type>::max()
 373:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 374:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       static size_type max_size(const _Alloc& __a) noexcept
 375:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { return _S_max_size(__a, 0); }
 376:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 377:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 378:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Obtain an allocator to use when copying a container.
 379:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __rhs  An allocator.
 380:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @return @c __rhs.select_on_container_copy_construction() or @a __rhs
 381:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 382:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Returns @c __rhs.select_on_container_copy_construction() if that
 383:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  expression is well-formed, otherwise returns @a __rhs
 384:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 385:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       static _Alloc
 386:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       select_on_container_copy_construction(const _Alloc& __rhs)
ARM GAS  /tmp/ccitkYpi.s 			page 79


 387:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { return _S_select(__rhs, 0); }
 388:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     };
 389:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 390:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   /// Partial specialization for std::allocator.
 391:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****   template<typename _Tp>
 392:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     struct allocator_traits<allocator<_Tp>>
 393:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****     {
 394:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator type
 395:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using allocator_type = allocator<_Tp>;
 396:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocated type
 397:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using value_type = _Tp;
 398:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 399:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator's pointer type.
 400:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using pointer = _Tp*;
 401:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 402:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator's const pointer type.
 403:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using const_pointer = const _Tp*;
 404:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 405:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator's void pointer type.
 406:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using void_pointer = void*;
 407:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 408:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator's const void pointer type.
 409:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using const_void_pointer = const void*;
 410:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 411:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator's difference type
 412:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using difference_type = std::ptrdiff_t;
 413:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 414:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// The allocator's size type
 415:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using size_type = std::size_t;
 416:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 417:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// How the allocator is propagated on copy assignment
 418:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using propagate_on_container_copy_assignment = false_type;
 419:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 420:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// How the allocator is propagated on move assignment
 421:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using propagate_on_container_move_assignment = true_type;
 422:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 423:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// How the allocator is propagated on swap
 424:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using propagate_on_container_swap = false_type;
 425:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 426:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /// Whether all instances of the allocator type compare equal.
 427:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       using is_always_equal = true_type;
 428:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 429:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Up>
 430:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	using rebind_alloc = allocator<_Up>;
 431:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 432:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       template<typename _Up>
 433:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 	using rebind_traits = allocator_traits<allocator<_Up>>;
 434:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 435:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 436:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Allocate memory.
 437:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 438:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __n  The number of objects to allocate space for.
 439:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 440:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Calls @c a.allocate(n)
 441:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 442:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       _GLIBCXX_NODISCARD static pointer
 443:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       allocate(allocator_type& __a, size_type __n)
ARM GAS  /tmp/ccitkYpi.s 			page 80


 444:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { return __a.allocate(__n); }
 445:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 446:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 447:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Allocate memory.
 448:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 449:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __n  The number of objects to allocate space for.
 450:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __hint Aid to locality.
 451:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @return Memory of suitable size and alignment for @a n objects
 452:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *          of type @c value_type
 453:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 454:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Returns <tt> a.allocate(n, hint) </tt>
 455:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 456:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       _GLIBCXX_NODISCARD static pointer
 457:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       allocate(allocator_type& __a, size_type __n, const_void_pointer __hint)
 458:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       { return __a.allocate(__n, __hint); }
 459:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h **** 
 460:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       /**
 461:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @brief  Deallocate memory.
 462:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __a  An allocator.
 463:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __p  Pointer to the memory to deallocate.
 464:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  @param  __n  The number of objects space was allocated for.
 465:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *
 466:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****        *  Calls <tt> a.deallocate(p, n) </tt>
 467:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       */
 468:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       static void
 469:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/alloc_traits.h ****       deallocate(allocator_type& __a, pointer __p, size_type __n)
 1433              		.loc 9 469 7 view .LVU449
 1434              	.LBB270:
 1435              	.LBI270:
  84:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  85:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       template<typename _Tp1>
  86:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	_GLIBCXX20_CONSTEXPR
  87:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	new_allocator(const new_allocator<_Tp1>&) _GLIBCXX_USE_NOEXCEPT { }
  88:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       ~new_allocator() _GLIBCXX_USE_NOEXCEPT { }
  90:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  91:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       pointer
  92:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       address(reference __x) const _GLIBCXX_NOEXCEPT
  93:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       { return std::__addressof(__x); }
  94:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  95:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       const_pointer
  96:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       address(const_reference __x) const _GLIBCXX_NOEXCEPT
  97:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       { return std::__addressof(__x); }
  98:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
  99:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       // NB: __n is permitted to be 0.  The C++ standard says nothing
 100:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       // about what the return value is when __n == 0.
 101:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       _GLIBCXX_NODISCARD pointer
 102:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       allocate(size_type __n, const void* = static_cast<const void*>(0))
 103:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       {
 104:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	if (__n > this->max_size())
 105:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	  std::__throw_bad_alloc();
 106:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
 107:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #if __cpp_aligned_new
 108:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	if (alignof(_Tp) > __STDCPP_DEFAULT_NEW_ALIGNMENT__)
 109:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	  {
 110:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	    std::align_val_t __al = std::align_val_t(alignof(_Tp));
 111:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	    return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp), __al));
ARM GAS  /tmp/ccitkYpi.s 			page 81


 112:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	  }
 113:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #endif
 114:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
 115:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       }
 116:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
 117:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       // __p is not permitted to be a null pointer.
 118:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       void
 119:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       deallocate(pointer __p, size_type)
 1436              		.loc 8 119 7 view .LVU450
 1437              	.LBB271:
 120:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h ****       {
 121:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #if __cpp_aligned_new
 122:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	if (alignof(_Tp) > __STDCPP_DEFAULT_NEW_ALIGNMENT__)
 123:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	  {
 124:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	    ::operator delete(__p, std::align_val_t(alignof(_Tp)));
 125:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	    return;
 126:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	  }
 127:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** #endif
 128:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 	::operator delete(__p);
 1438              		.loc 8 128 19 is_stmt 0 view .LVU451
 1439 0052 FFF7FEFF 		bl	_ZdlPv
 1440              	.LVL90:
 1441              	.L67:
 1442              		.loc 8 128 19 view .LVU452
 1443              	.LBE271:
 1444              	.LBE270:
 1445              	.LBE269:
 1446              	.LBE268:
 1447              	.LBE267:
 1448              	.LBE262:
 1449              	.LBE261:
 1450              	.LBB272:
 1451              	.LBI272:
 150:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/basic_string.h ****       {
 1452              		.loc 5 150 14 is_stmt 1 view .LVU453
 1453              	.LBB273:
 1454              	.LBI273:
 142:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       : __allocator_base<_Tp>(__a) { }
 143:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 144:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #if __cplusplus >= 201103L
 145:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       // Avoid implicit deprecation.
 146:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       allocator& operator=(const allocator&) = default;
 147:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** #endif
 148:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 149:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       template<typename _Tp1>
 150:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	_GLIBCXX20_CONSTEXPR
 151:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 	allocator(const allocator<_Tp1>&) _GLIBCXX_NOTHROW { }
 152:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h **** 
 153:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/allocator.h ****       ~allocator() _GLIBCXX_NOTHROW { }
 1455              		.loc 7 153 7 view .LVU454
 1456              	.LBB274:
 1457              	.LBI274:
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
 1458              		.loc 8 89 7 view .LVU455
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
 1459              		.loc 8 89 7 is_stmt 0 view .LVU456
 1460              	.LBE274:
ARM GAS  /tmp/ccitkYpi.s 			page 82


 1461              	.LBE273:
 1462              	.LBE272:
 1463              	.LBE260:
 1464              	.LBB275:
 1465              	.LBI275:
 1466              		.loc 7 153 7 is_stmt 1 view .LVU457
 1467              	.LBB276:
 1468              	.LBI276:
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
 1469              		.loc 8 89 7 view .LVU458
  89:/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/new_allocator.h **** 
 1470              		.loc 8 89 7 is_stmt 0 view .LVU459
 1471              	.LBE276:
 1472              	.LBE275:
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1473              		.loc 1 117 5 is_stmt 1 view .LVU460
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1474              		.loc 1 117 25 is_stmt 0 view .LVU461
 1475 0056 FFF7FEFF 		bl	_Z6devicev
 1476              	.LVL91:
 1477 005a 0400     		movs	r4, r0
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1478              		.loc 1 117 32 view .LVU462
 1479 005c FFF7FEFF 		bl	_Z6devicev
 1480              	.LVL92:
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1481              		.loc 1 117 36 view .LVU463
 1482 0060 0368     		ldr	r3, [r0]
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1483              		.loc 1 117 41 view .LVU464
 1484 0062 D969     		ldr	r1, [r3, #28]
 117:Src/main.c    ****     device()->Enable_Filesystem();
 1485              		.loc 1 117 25 view .LVU465
 1486 0064 2000     		movs	r0, r4
 1487 0066 FFF7FEFF 		bl	_ZN6Device10Enable_CLIEP11Serial_line
 1488              	.LVL93:
 118:Src/main.c    ****     device()->cli->Enable_filesystem_executable(device()->fs);
 1489              		.loc 1 118 5 is_stmt 1 view .LVU466
 118:Src/main.c    ****     device()->cli->Enable_filesystem_executable(device()->fs);
 1490              		.loc 1 118 32 is_stmt 0 view .LVU467
 1491 006a FFF7FEFF 		bl	_Z6devicev
 1492              	.LVL94:
 1493 006e FFF7FEFF 		bl	_ZN6Device17Enable_FilesystemEv
 1494              	.LVL95:
 119:Src/main.c    **** 
 1495              		.loc 1 119 5 is_stmt 1 view .LVU468
 119:Src/main.c    **** 
 1496              		.loc 1 119 11 is_stmt 0 view .LVU469
 1497 0072 FFF7FEFF 		bl	_Z6devicev
 1498              	.LVL96:
 119:Src/main.c    **** 
 1499              		.loc 1 119 15 view .LVU470
 1500 0076 4468     		ldr	r4, [r0, #4]
 119:Src/main.c    **** 
 1501              		.loc 1 119 55 view .LVU471
 1502 0078 FFF7FEFF 		bl	_Z6devicev
 1503              	.LVL97:
ARM GAS  /tmp/ccitkYpi.s 			page 83


 119:Src/main.c    **** 
 1504              		.loc 1 119 48 view .LVU472
 1505 007c 8168     		ldr	r1, [r0, #8]
 1506 007e 2000     		movs	r0, r4
 1507 0080 FFF7FEFF 		bl	_ZN3CLI28Enable_filesystem_executableEP10Filesystem
 1508              	.LVL98:
 121:Src/main.c    **** 
 1509              		.loc 1 121 5 is_stmt 1 view .LVU473
 121:Src/main.c    **** 
 1510              		.loc 1 121 38 is_stmt 0 view .LVU474
 1511 0084 FFF7FEFF 		bl	_Z6devicev
 1512              	.LVL99:
 121:Src/main.c    **** 
 1513              		.loc 1 121 42 view .LVU475
 1514 0088 0368     		ldr	r3, [r0]
 121:Src/main.c    **** 
 1515              		.loc 1 121 47 view .LVU476
 1516 008a 5C6A     		ldr	r4, [r3, #36]
 121:Src/main.c    **** 
 1517              		.loc 1 121 52 view .LVU477
 1518 008c 2020     		movs	r0, #32
 1519 008e FFF7FEFF 		bl	_Znwj
 1520              	.LVL100:
 1521 0092 2100     		movs	r1, r4
 1522 0094 FFF7FEFF 		bl	_ZN11I2C_scannerC1EP10I2C_master
 1523              	.LVL101:
 123:Src/main.c    ****     led_enable->Set(true);
 1524              		.loc 1 123 5 is_stmt 1 view .LVU478
 123:Src/main.c    ****     led_enable->Set(true);
 1525              		.loc 1 123 38 is_stmt 0 view .LVU479
 1526 0098 0C20     		movs	r0, #12
 1527 009a FFF7FEFF 		bl	_Znwj
 1528              	.LVL102:
 1529 009e 0400     		movs	r4, r0
 1530 00a0 0E22     		movs	r2, #14
 1531 00a2 4321     		movs	r1, #67
 1532 00a4 FFF7FEFF 		bl	_ZN3PinC1Ech
 1533              	.LVL103:
 124:Src/main.c    **** 
 1534              		.loc 1 124 5 is_stmt 1 view .LVU480
 124:Src/main.c    **** 
 1535              		.loc 1 124 25 is_stmt 0 view .LVU481
 1536 00a8 2368     		ldr	r3, [r4]
 1537 00aa 5B68     		ldr	r3, [r3, #4]
 124:Src/main.c    **** 
 1538              		.loc 1 124 20 view .LVU482
 1539 00ac 0121     		movs	r1, #1
 1540 00ae 2000     		movs	r0, r4
 1541 00b0 9847     		blx	r3
 1542              	.LVL104:
 126:Src/main.c    ****     led->Test();
 1543              		.loc 1 126 5 is_stmt 1 view .LVU483
 126:Src/main.c    ****     led->Test();
 1544              		.loc 1 126 36 is_stmt 0 view .LVU484
 1545 00b2 FFF7FEFF 		bl	_Z6devicev
 1546              	.LVL105:
 126:Src/main.c    ****     led->Test();
ARM GAS  /tmp/ccitkYpi.s 			page 84


 1547              		.loc 1 126 40 view .LVU485
 1548 00b6 0368     		ldr	r3, [r0]
 126:Src/main.c    ****     led->Test();
 1549              		.loc 1 126 45 view .LVU486
 1550 00b8 5B6A     		ldr	r3, [r3, #36]
 126:Src/main.c    ****     led->Test();
 1551              		.loc 1 126 63 view .LVU487
 1552 00ba 06AD     		add	r5, sp, #24
 1553 00bc 2A00     		movs	r2, r5
 1554 00be 03CB     		ldmia	r3!, {r0, r1}
 1555 00c0 03C2     		stmia	r2!, {r0, r1}
 1556 00c2 2C20     		movs	r0, #44
 1557 00c4 FFF7FEFF 		bl	_Znwj
 1558              	.LVL106:
 1559 00c8 0400     		movs	r4, r0
 1560              	.LVL107:
 126:Src/main.c    ****     led->Test();
 1561              		.loc 1 126 63 view .LVU488
 1562 00ca 6223     		movs	r3, #98
 1563 00cc 0699     		ldr	r1, [sp, #24]
 1564 00ce 6A68     		ldr	r2, [r5, #4]
 1565 00d0 FFF7FEFF 		bl	_ZN7KTD2026C1E10I2C_masterh
 1566              	.LVL108:
 127:Src/main.c    **** 
 1567              		.loc 1 127 5 is_stmt 1 view .LVU489
 127:Src/main.c    **** 
 1568              		.loc 1 127 14 is_stmt 0 view .LVU490
 1569 00d4 2000     		movs	r0, r4
 1570 00d6 FFF7FEFF 		bl	_ZN7KTD20264TestEv
 1571              	.LVL109:
 1572              	.L68:
 133:Src/main.c    ****         /* USER CODE END WHILE */
 1573              		.loc 1 133 5 is_stmt 1 discriminator 1 view .LVU491
 133:Src/main.c    ****         /* USER CODE END WHILE */
 1574              		.loc 1 133 5 discriminator 1 view .LVU492
 1575 00da FEE7     		b	.L68
 1576              	.L70:
 1577              		.align	2
 1578              	.L69:
 1579 00dc 0D000000 		.word	.LC7+13
 1580              		.cfi_endproc
 1581              	.LFE3853:
 1583              		.global	huart3
 1584              		.global	huart2
 1585              		.global	htim2
 1586              		.global	hi2c1
 1587              		.global	hadc1
 1588              		.section	.bss.hadc1,"aw",%nobits
 1589              		.align	2
 1590              		.set	.LANCHOR1,. + 0
 1593              	hadc1:
 1594 0000 00000000 		.space	100
 1594      00000000 
 1594      00000000 
 1594      00000000 
 1594      00000000 
 1595              		.section	.bss.hi2c1,"aw",%nobits
ARM GAS  /tmp/ccitkYpi.s 			page 85


 1596              		.align	2
 1597              		.set	.LANCHOR0,. + 0
 1600              	hi2c1:
 1601 0000 00000000 		.space	76
 1601      00000000 
 1601      00000000 
 1601      00000000 
 1601      00000000 
 1602              		.section	.bss.htim2,"aw",%nobits
 1603              		.align	2
 1604              		.set	.LANCHOR2,. + 0
 1607              	htim2:
 1608 0000 00000000 		.space	76
 1608      00000000 
 1608      00000000 
 1608      00000000 
 1608      00000000 
 1609              		.section	.bss.huart2,"aw",%nobits
 1610              		.align	2
 1613              	huart2:
 1614 0000 00000000 		.space	144
 1614      00000000 
 1614      00000000 
 1614      00000000 
 1614      00000000 
 1615              		.section	.bss.huart3,"aw",%nobits
 1616              		.align	2
 1619              	huart3:
 1620 0000 00000000 		.space	144
 1620      00000000 
 1620      00000000 
 1620      00000000 
 1620      00000000 
 1621              		.text
 1622              	.Letext0:
 1623              		.file 10 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/machine/_default_types.h"
 1624              		.file 11 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/_stdint.h"
 1625              		.file 12 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/stdint.h"
 1626              		.file 13 "Drivers/CMSIS/Device/ST/STM32G0xx/Include/system_stm32g0xx.h"
 1627              		.file 14 "Drivers/CMSIS/Device/ST/STM32G0xx/Include/stm32g071xx.h"
 1628              		.file 15 "Drivers/CMSIS/Device/ST/STM32G0xx/Include/stm32g0xx.h"
 1629              		.file 16 "/opt/gcc-arm-none-eabi-9-2020-q2/lib/gcc/arm-none-eabi/9.3.1/include/stddef.h"
 1630              		.file 17 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_def.h"
 1631              		.file 18 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_rcc.h"
 1632              		.file 19 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_rcc_ex.h"
 1633              		.file 20 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_gpio.h"
 1634              		.file 21 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_dma.h"
 1635              		.file 22 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_adc.h"
 1636              		.file 23 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_flash.h"
 1637              		.file 24 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_i2c.h"
 1638              		.file 25 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_tim.h"
 1639              		.file 26 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_uart.h"
 1640              		.file 27 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal.h"
 1641              		.file 28 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/type_traits"
 1642              		.file 29 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/arm-none-eabi/thumb/v6-
 1643              		.file 30 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_pair.h"
 1644              		.file 31 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/cpp_type_traits.h"
ARM GAS  /tmp/ccitkYpi.s 			page 86


 1645              		.file 32 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator_base_
 1646              		.file 33 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/debug/debug.h"
 1647              		.file 34 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cwchar"
 1648              		.file 35 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cstdint"
 1649              		.file 36 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/exception_ptr.h"
 1650              		.file 37 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/new"
 1651              		.file 38 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/clocale"
 1652              		.file 39 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/limits"
 1653              		.file 40 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/string_view"
 1654              		.file 41 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cstdlib"
 1655              		.file 42 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/cstdio"
 1656              		.file 43 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/initializer_list"
 1657              		.file 44 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stringfwd.h"
 1658              		.file 45 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/utility"
 1659              		.file 46 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/algorithmfwd.h"
 1660              		.file 47 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/uses_allocator.h"
 1661              		.file 48 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/tuple"
 1662              		.file 49 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/optional"
 1663              		.file 50 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_function.h"
 1664              		.file 51 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/functional"
 1665              		.file 52 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_vector.h"
 1666              		.file 53 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/vector.tcc"
 1667              		.file 54 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_tree.h"
 1668              		.file 55 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_map.h"
 1669              		.file 56 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/ptr_traits.h"
 1670              		.file 57 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/move.h"
 1671              		.file 58 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/predefined_ops.h"
 1672              		.file 59 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/numeric_traits.h"
 1673              		.file 60 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/alloc_traits.h"
 1674              		.file 61 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/stl_iterator.h"
 1675              		.file 62 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/ext/type_traits.h"
 1676              		.file 63 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/_types.h"
 1677              		.file 64 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/reent.h"
 1678              		.file 65 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/lock.h"
 1679              		.file 66 "/opt/gcc-arm-none-eabi-9-2020-q2/lib/gcc/arm-none-eabi/9.3.1/include/stdarg.h"
 1680              		.file 67 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/wchar.h"
 1681              		.file 68 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/locale.h"
 1682              		.file 69 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/ctype.h"
 1683              		.file 70 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/stdlib.h"
 1684              		.file 71 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/stdio.h"
 1685              		.file 72 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/sys/errno.h"
 1686              		.file 73 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/pstl/execution_defs.h"
 1687              		.file 74 "alohal/globals.hpp"
 1688              		.file 75 "alohal/irq/irq_handler.hpp"
 1689              		.file 76 "alohal/irq/irq_observer.hpp"
 1690              		.file 77 "alohal/irq/irq_multi_handler.hpp"
 1691              		.file 78 "alohal/uart/serial_line.hpp"
 1692              		.file 79 "alohal/uart/uart.hpp"
 1693              		.file 80 "alohal/mcu/configuration/externs.hpp"
 1694              		.file 81 "alohal/timer/TIM_channel.hpp"
 1695              		.file 82 "alohal/timer/timer.hpp"
 1696              		.file 83 "alohal/i2c/i2c_master.hpp"
 1697              		.file 84 "alohal/mcu/mcu.hpp"
 1698              		.file 85 "/opt/gcc-arm-none-eabi-9-2020-q2/arm-none-eabi/include/c++/9.3.1/bits/functexcept.h"
 1699              		.file 86 "alohal/cli/command.hpp"
 1700              		.file 87 "alohal/cli/history.hpp"
 1701              		.file 88 "alohal/filesystem/entry.hpp"
ARM GAS  /tmp/ccitkYpi.s 			page 87


 1702              		.file 89 "alohal/filesystem/executable.hpp"
 1703              		.file 90 "alohal/cli/cli.hpp"
 1704              		.file 91 "alohal/filesystem/filesystem.hpp"
 1705              		.file 92 "alohal/filesystem/directory.hpp"
 1706              		.file 93 "alohal/filesystem/file.hpp"
 1707              		.file 94 "alohal/misc/text_transform.hpp"
 1708              		.file 95 "alohal/events/planner/planner_phase.hpp"
 1709              		.file 96 "alohal/events/planner/planner.hpp"
 1710              		.file 97 "alohal/device/device.hpp"
 1711              		.file 98 "alohal/device/component.hpp"
 1712              		.file 99 "alohal/bus/bus_device.hpp"
 1713              		.file 100 "alohal/led/KTD2026.hpp"
 1714              		.file 101 "alohal/device/application.hpp"
 1715              		.file 102 "alohal/apps/i2c_scanner.hpp"
 1716              		.file 103 "alohal/misc/invocation_wrapper.hpp"
 1717              		.file 104 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_ll_dma.h"
 1718              		.file 105 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_uart_ex.h"
 1719              		.file 106 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_tim_ex.h"
 1720              		.file 107 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_i2c_ex.h"
 1721              		.file 108 "Drivers/STM32G0xx_HAL_Driver/Inc/stm32g0xx_hal_pwr_ex.h"
 1722              		.file 109 "<built-in>"
ARM GAS  /tmp/ccitkYpi.s 			page 88


DEFINED SYMBOLS
                            *ABS*:0000000000000000 main.c
     /tmp/ccitkYpi.s:16     .text._ZL12MX_GPIO_Initv:0000000000000000 $t
     /tmp/ccitkYpi.s:23     .text._ZL12MX_GPIO_Initv:0000000000000000 _ZL12MX_GPIO_Initv
     /tmp/ccitkYpi.s:217    .text._ZL12MX_GPIO_Initv:00000000000000cc $d
     /tmp/ccitkYpi.s:225    .text.Error_Handler:0000000000000000 $t
     /tmp/ccitkYpi.s:232    .text.Error_Handler:0000000000000000 Error_Handler
     /tmp/ccitkYpi.s:264    .text._ZL12MX_I2C1_Initv:0000000000000000 $t
     /tmp/ccitkYpi.s:270    .text._ZL12MX_I2C1_Initv:0000000000000000 _ZL12MX_I2C1_Initv
     /tmp/ccitkYpi.s:359    .text._ZL12MX_I2C1_Initv:000000000000004c $d
     /tmp/ccitkYpi.s:366    .text._ZL19MX_USART2_UART_Initv:0000000000000000 $t
     /tmp/ccitkYpi.s:372    .text._ZL19MX_USART2_UART_Initv:0000000000000000 _ZL19MX_USART2_UART_Initv
     /tmp/ccitkYpi.s:481    .text._ZL19MX_USART2_UART_Initv:0000000000000060 $d
     /tmp/ccitkYpi.s:1613   .bss.huart2:0000000000000000 huart2
     /tmp/ccitkYpi.s:487    .text._ZL19MX_USART3_UART_Initv:0000000000000000 $t
     /tmp/ccitkYpi.s:493    .text._ZL19MX_USART3_UART_Initv:0000000000000000 _ZL19MX_USART3_UART_Initv
     /tmp/ccitkYpi.s:561    .text._ZL19MX_USART3_UART_Initv:0000000000000034 $d
     /tmp/ccitkYpi.s:1619   .bss.huart3:0000000000000000 huart3
     /tmp/ccitkYpi.s:567    .text._ZL12MX_ADC1_Initv:0000000000000000 $t
     /tmp/ccitkYpi.s:573    .text._ZL12MX_ADC1_Initv:0000000000000000 _ZL12MX_ADC1_Initv
     /tmp/ccitkYpi.s:704    .text._ZL12MX_ADC1_Initv:0000000000000074 $d
     /tmp/ccitkYpi.s:711    .text._ZL12MX_TIM2_Initv:0000000000000000 $t
     /tmp/ccitkYpi.s:717    .text._ZL12MX_TIM2_Initv:0000000000000000 _ZL12MX_TIM2_Initv
     /tmp/ccitkYpi.s:827    .text._ZL12MX_TIM2_Initv:000000000000006c $d
     /tmp/ccitkYpi.s:832    .text._Z18SystemClock_Configv:0000000000000000 $t
     /tmp/ccitkYpi.s:839    .text._Z18SystemClock_Configv:0000000000000000 _Z18SystemClock_Configv
     /tmp/ccitkYpi.s:1000   .text._Z18SystemClock_Configv:00000000000000a4 $d
     /tmp/ccitkYpi.s:1005   .rodata._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.str1.4:0000000000000000 $d
     /tmp/ccitkYpi.s:1009   .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag:0000000000000000 $t
     /tmp/ccitkYpi.s:1016   .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag:0000000000000000 _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag
     /tmp/ccitkYpi.s:1231   .text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag:0000000000000058 $d
     /tmp/ccitkYpi.s:1236   .rodata.main.str1.4:0000000000000000 $d
     /tmp/ccitkYpi.s:1237   .rodata.main.str1.4:0000000000000000 .LC7
     /tmp/ccitkYpi.s:1240   .text.main:0000000000000000 $t
     /tmp/ccitkYpi.s:1247   .text.main:0000000000000000 main
     /tmp/ccitkYpi.s:1579   .text.main:00000000000000dc $d
     /tmp/ccitkYpi.s:1607   .bss.htim2:0000000000000000 htim2
     /tmp/ccitkYpi.s:1600   .bss.hi2c1:0000000000000000 hi2c1
     /tmp/ccitkYpi.s:1593   .bss.hadc1:0000000000000000 hadc1
     /tmp/ccitkYpi.s:1589   .bss.hadc1:0000000000000000 $d
     /tmp/ccitkYpi.s:1596   .bss.hi2c1:0000000000000000 $d
     /tmp/ccitkYpi.s:1603   .bss.htim2:0000000000000000 $d
     /tmp/ccitkYpi.s:1610   .bss.huart2:0000000000000000 $d
     /tmp/ccitkYpi.s:1616   .bss.huart3:0000000000000000 $d

UNDEFINED SYMBOLS
memset
HAL_GPIO_WritePin
HAL_GPIO_Init
HAL_I2C_Init
HAL_I2CEx_ConfigAnalogFilter
HAL_I2CEx_ConfigDigitalFilter
HAL_UART_Init
HAL_UARTEx_SetTxFifoThreshold
HAL_UARTEx_SetRxFifoThreshold
HAL_UARTEx_DisableFifoMode
HAL_ADC_Init
ARM GAS  /tmp/ccitkYpi.s 			page 89


HAL_ADC_ConfigChannel
HAL_TIM_Base_Init
HAL_TIM_ConfigClockSource
HAL_TIMEx_MasterConfigSynchronization
HAL_PWREx_ControlVoltageScaling
HAL_RCC_OscConfig
HAL_RCC_ClockConfig
HAL_RCCEx_PeriphCLKConfig
memcpy
_ZSt19__throw_logic_errorPKc
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj
HAL_Init
HAL_Delay
_Z6devicev
_ZN4UART4SendENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
_ZdlPv
_ZN6Device10Enable_CLIEP11Serial_line
_ZN6Device17Enable_FilesystemEv
_ZN3CLI28Enable_filesystem_executableEP10Filesystem
_Znwj
_ZN11I2C_scannerC1EP10I2C_master
_ZN3PinC1Ech
_ZN7KTD2026C1E10I2C_masterh
_ZN7KTD20264TestEv
