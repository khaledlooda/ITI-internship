

void main() {
GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIOE_ODR,_GPIO_PINMASK_ALL);
GPIOA_ODR = 0xFFFF;
GPIOB_ODR = 0xFFFF;
GPIOC_ODR = 0xFFFF;
GPIOD_ODR = 0xFFFF;
GPIOE_ODR = 0xFFFF;
while(1)
{
GPIOA_ODR = ~GPIOA_ODR;
GPIOB_ODR = ~GPIOB_ODR;
GPIOC_ODR = ~GPIOC_ODR;
GPIOD_ODR = ~GPIOD_ODR;
GPIOE_ODR = ~GPIOE_ODR;
   Delay_ms(500);
}
 //GPIOD_ODR = 1;
//while(1){
  // GPIOD_ODR <<= 1;
  // if(GPIOD_ODR ==0)
  // {
  // GPIOD_ODR =1;
  // }
  // Delay_ms(500);
      //   }
}