
#include "rpi-gpio.h"

/** GPIO Register set */
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

volatile unsigned int time_delay;

void blink_led(unsigned int loop_times)
{
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

}