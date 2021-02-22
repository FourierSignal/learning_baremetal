
#include "uart.h"

void
init_uart (void)
{
  int i;

  AUX_ENB |= 1;		/* Enable mini-uart */
  MU_LCR = 3;		/* 8 bit.  */
  MU_BAUD = 270;	/* 115200 baud.  */
  GPFSEL1 &= ~((7 << 12) | (7 << 15));	/* GPIO14 & 15: alt5  */
  GPFSEL1 |= (2 << 12) | (2 << 15);

  /* Disable pull-up/down.  */
  GPPUD = 0;

  for (i = 0; i < 150; i++)
    asm volatile ("nop");

  GPPUDCLK0 = (2 << 14) | (2 << 15);

  for (i = 0; i < 150; i++)
    asm volatile ("nop");

  GPPUDCLK0 = 0;

  MU_CNTL = 3;		/* Enable Tx and Rx.  */
}


void
raw_putc (char c)
{
  while (!(MU_LSR & 0x20))
    ;
  MU_IO = c;
}

void
uart_putc (char c)
{
  if (c == '\n')
    raw_putc ('\r');
  raw_putc (c);
}

void
uart_puts (const char *s)
{
  while (*s)
    uart_putc (*s++);
}

