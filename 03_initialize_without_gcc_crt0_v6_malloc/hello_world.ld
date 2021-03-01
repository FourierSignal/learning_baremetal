
ENTRY(_start)

 /* 1GB DDR in RPI3   GPU-ARM memory devide gpu_mem = 512M in config.txt   */

 
MEMORY
{
    SRAM(rwx) : ORIGIN = 0, LENGTH = 512M
}

/*   */

SECTIONS
{

    . =  0x0;              

    .bss :
    {
  /*  . = ALIGN(16); */

    __bss_start = . ;

    *(.bss)

  /*  . = ALIGN(16);  */
    
    __bss_end = . ;


    }

    .data :
    {

    }

    .text :
    {
        *(.text.boot)
        *(.text)
        *(.rodata)

    }
    _end = . ; 
}


