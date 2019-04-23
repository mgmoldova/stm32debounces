int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	int state = 0;
  while (1)
  {
    /* USER CODE END WHILE */
		if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == 0 )
		{
			HAL_Delay(50);
			state ^= 1;
			while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == 0 )
			{
				if(state == 1)
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
				else
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			}						
		}
		

		//HAL_Delay(3000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
