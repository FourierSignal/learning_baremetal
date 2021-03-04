
ENTRY(_start)

 /* 1GB DDR in RPI3   GPU-ARM memory devide gpu_mem = 512M in config.txt   */

_estack = 0x8000;  /* end of RAM */

/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0x200;;      /* required amount of heap  */
_Min_Stack_Size = 0x400;; /* required amount of stack */



MEMORY
{
    SRAM(rwx) : ORIGIN = 0, LENGTH = 512M
}

/*   */

SECTIONS
{

    . =  0x0;              

  .isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
  } 


    .text :
    {
        *(.text.boot)
        *(.text)
        *(.rodata)

    }


  .data :
    {

    }


        .bss :
    {
  /*  . = ALIGN(16); */

    __bss_start = . ;

    *(.bss)

  /*  . = ALIGN(16);  */
    
    __bss_end = . ;


    }



  
  /* User_heap_stack section, used to check that there is enough RAM left */
  ._user_heap_stack :
  {
    . = ALIGN(4);
    /*
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    */
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(4);
  } >SRAM

    _end = .;

}


