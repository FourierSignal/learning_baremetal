.section ".text.boot"

_start:
    mrs    x0, mpidr_el1        
    and    x0, x0,#0xFF        // Check processor id
    cbz    x0, main_cpu        // Hang for all non-primary CPU  ( if processor ID is 0)
    b    processor_hang


processor_hang: 
    b processor_hang


main_cpu:
    mov   sp, #0x8000
    bl    main

