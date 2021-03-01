#include "hello_world.h"




int
main (void)
{

  

  init_uart ();

  while(1)
  uart_puts ("Hi SudheerV! Hello world!\n");

  run_counters();

/* Never exit as there is no OS to exit to! */
  //while(1);
  
  return 0;
}

void exit(int code)
{
    while(1)
        ;
}


