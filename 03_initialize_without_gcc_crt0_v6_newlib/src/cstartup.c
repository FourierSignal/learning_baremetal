
//here __bss_end__ , __bss_start__ are addresses
//when you are using a linker script defined symbol in source code you should always take the address of the symbol, and never attempt to use its value.
extern char __bss_start;
extern char __bss_end;

extern int main(void);

void _cstartup( unsigned int r0, unsigned int r1, unsigned int r2 )
{
    /*__bss_start__ and __bss_end__ are defined in the linker script */
    register  char* bss = &__bss_start;
    register  char* bss_end = &__bss_end;

    /*
        Clear the BSS section

        See http://en.wikipedia.org/wiki/.bss for further information on the
            BSS section

        See https://sourceware.org/newlib/libc.html#Stubs for further
            information on the c-library stubs
    */
    while( bss < bss_end )
        *bss++ = 0;

     /* We should never return from main ... */
    main();
    /* ... but if we return, safely trap here */
    while(1)
    {
        /* EMPTY! */
    }

}


