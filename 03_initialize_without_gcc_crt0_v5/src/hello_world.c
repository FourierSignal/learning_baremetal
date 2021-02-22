#include "uart.h"

#include "rpi-gpio.h"

volatile unsigned int time_delay;

int
main (void)
{

  unsigned int loop_times;

  init_uart ();

  uart_puts ("Hi SudheerV! Hello world!\n");



  for(loop_times = 0; loop_times < 50; loop_times++)
  {

  /* Set the LED GPIO pin low ( Turn OK LED on for original Pi, and off
           for plus models )*/
    gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);

    for(time_delay = 0; time_delay < 500000; time_delay++)
      ;

  /* Set the LED GPIO pin high ( Turn OK LED off for original Pi, and on
           for plus models )*/
    gpio[LED_GPSET] = (1 << LED_GPIO_BIT);
  
  }

/* Never exit as there is no OS to exit to! */
  while(1);
  
  return 0;
}

void exit(int code)
{
    while(1)
        ;
}


