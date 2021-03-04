#include <stdlib.h>
#include <stddef.h>

extern char _user_heap_stack;

void run_counters()
{

  unsigned int loop;
  unsigned int* counters;


/* Allocate a block of memory for counters */
//    counters = malloc( 1024 * sizeof( unsigned int ) );
//counters = & _user_heap_stack;
counters = (unsigned int *) 0x40000000;
    /* Failed to allocate memory! */
    if( counters == NULL )
        while(1) {   /* Trap here */ }

    for( loop=0; loop<1024; loop++ )
        counters[loop] = 0;

    /* Never exit as there is no OS to exit to! */
    while(1)
    {
 
        for(counters[0] = 0; counters[0] < 500000; counters[0]++)
            ;

        for(counters[1] = 0; counters[1] < 500000; counters[1]++)
            ;
    }

}