#include "uart.h"

#include "stdio.h"

extern void init_uart (void);

extern void uart_putc (char c);

extern void uart_puts (const char *s);

extern void run_counters(void);