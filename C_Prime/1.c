// 读取引脚函数
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);// (端口号,引脚)


// 引脚写函数
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx,
                       uint16_t GPIO_Pin,
                       GPIO_PinState PinState);
// 引脚翻转函数
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
