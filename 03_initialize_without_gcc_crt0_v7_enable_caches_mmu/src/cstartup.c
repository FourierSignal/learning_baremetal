
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

#if 1
/*
The A64 instructions for accessing special-purpose registers are:
MSR <special-purpose register>, Xt ; Write to special-purpose register 
MRS Xt, <special-purpose register> ;Read from special-purpose register



D8.2.79  SCTLR_EL1, System Control Register (EL1)
(ARMv8-A_Architecture_Reference_Manual)
To access the SCTLR_EL1:
MRS <Xt>, SCTLR_EL1 ; Read SCTLR_EL1 into Xt
MSR SCTLR_EL1, <Xt> ; Write Xt to SCTLR_EL1

CurrentEL, Current Exception Level register: bits [3:2]--> EL
To access the CurrentEL:
MRS <Xt>, CurrentEL ; Read CurrentEL into Xt

https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html

The inline assembly can be used in following two formats:
asm("assembly code") or __asm__("assembly code")
asm asm-qualifiers ( AssemblerTemplate 
                      : OutputOperands
                    [ : InputOperands ]
                    [ : Clobbers      ]
                    [ : GotoLabels)   ]

Clobbers/scratch registers:
A comma-separated list of registers or other values changed by the AssemblerTemplate,
beyond those listed as outputs. An empty list is permitted.

Intel syntax “mov eax, edx” will look like “mov %edx, %eax” in AT&T assembly.
Register names are prefixed with %

int a=10, b;
        asm ("movl %1, %%eax; 
              movl %%eax, %0;"
             :"=r"(b)        // output
             :"r"(a)         // input 
             :"%eax"         // clobbered register
             );       

"b" is the output operand, referred to by %0 and "a" is the input operand, referred to by %1

constraint on the operands:
"r" says to GCC to use any register for storing the operands.
constraint modifier "=" --->says that it is the output operand and is write-only
% helps GCC to distinguish between the operands and registers.

"=m" says that my_var is an output and it is in memor
"ir" says operand is an integer
"cc" clobberlist. 

*/



{
    unsigned long r=0;
    unsigned int exception_level;

    r|=0xC00800;     // set mandatory reserved bits
    r&=~((1<<25) |   // clear EE, little endian translation tables
         (1<<24) |   // clear E0E
         (1<<19) |   // clear WXN
         (1<<12) |   // clear I, no instruction cache
         (1<<4) |    // clear SA0
         (1<<3) |    // clear SA

         (1<<1));    // clear A, no aligment check

    r|=  (1<<2);     // Enable caches.
    r|=  (1<<0);     // set M, enable MMU

    // are we currently in EL1?? -check
    asm volatile ("mrs %0,currentEL":"=r"(exception_level): );

    asm volatile ("msr sctlr_el1, %0; isb" : : "r" (r));
    
}

#endif

     /* We should never return from main ... */
    main();
    /* ... but if we return, safely trap here */
    while(1)
    {
        /* EMPTY! */
    }

}


