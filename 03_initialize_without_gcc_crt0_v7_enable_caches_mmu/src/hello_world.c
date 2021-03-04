#include "hello_world.h"




int
main (void)
{

  unsigned int exception_level;
  char message[50];
  init_uart ();

  
  uart_puts ("Hi SudheerV! Hello world!\n");
  asm volatile ("mrs %0, currentEL":"=r"(exception_level):);
  sprintf(message,"current exception level = %d",exception_level>>2);
  uart_puts(message);
//  run_counters();

/* Never exit as there is no OS to exit to! */
  while(1);
  
  return 0;
}

void exit(int code)
{
    while(1)
        ;
}


