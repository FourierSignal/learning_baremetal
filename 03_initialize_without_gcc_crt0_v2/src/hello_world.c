#include "uart.h"

int
main (void)
{
  init_uart ();

  uart_puts ("Hi Sudheer! Hello world!\n");

  return 0;
}

/*
void exit(int code)
{
    while(1)
        ;
}
*/
