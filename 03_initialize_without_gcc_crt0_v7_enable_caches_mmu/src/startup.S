.global _start
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

  // Enable MMU
  // -----------
  MOV      x0, #(1 << 0)                     // M=1           Enable the stage 1 MMU
  ORR      x0, x0, #(1 << 2)                 // C=1           Enable data and unified caches
  ORR      x0, x0, #(1 << 12)                // I=1           Enable instruction fetches to allocate into unified caches
                                             // A=0           Strict alignment checking disabled
                                             // SA=0          Stack alignment checking disabled
                                             // WXN=0         Write permission does not imply XN
                                             // EE=0          EL3 data accesses are little endian
  MSR      SCTLR_EL1, x0
  ISB

  bl    _cstartup 


