#include "hello_world.h"




int
main (void)
{

  unsigned int loop_times;

  init_uart ();

  uart_puts ("Hi SudheerV! Hello world!\n");

  blink_led(loop_times);

/* Never exit as there is no OS to exit to! */
  while(1);
  
  return 0;
}

void exit(int code)
{
    while(1)
        ;
}


