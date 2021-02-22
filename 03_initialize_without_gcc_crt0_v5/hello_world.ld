
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

    __bss_start = ALIGN(0x10);

    *(.bss)

    __bss_end = ALIGN(0x10);


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

}


