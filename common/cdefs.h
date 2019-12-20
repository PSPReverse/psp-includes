#ifndef __include_cdefs_h
#define __include_cdefs_h

#define UNUSED(a_Expr) do { (void)(a_Expr); } while (0)

/** Returns the number of elements from a static array. */
#define ELEMENTS(a_Array) (sizeof(a_Array)/sizeof(a_Array[0]))
/** Returns the maximum of two numbers. */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
/** Returns the minimum of two numbers. */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
/** Clamps the given value to remain in the given window. */
#define CLAMP(a_Val, a_Min, a_Max) (MAX(MIN((a_Val), (a_Max)), (a_Min)))

/** Return the absolute value of a given number .*/
#define ABS(a) ((a) < 0 ? -(a) : (a))

/** Sets the given bit. */
#define BIT(a) (1 << (a))

/** Number of milliseconds in one second. */
#define MS_PER_1SEC  (1000)
/** Number of microseconds in one millisecond. */
#define US_PER_1MSEC (1000)
/** Number of nanoseconds in one microsecond. */
#define NS_PER_1USEC (1000)

#define SEC_TO_MSEC(a_sec) ((a_sec) * 1000)

#define MSEC_TO_SEC(a_msec) ((a_msec) / 1000)
#define MSEC_TO_SEC_REMAINDER(a_msec) ((a_msec) % 1000)

#define SEC_TO_MIN(a_sec) ((a_sec) / 60)
#define SEC_TO_MIN_REMAINDER(a_sec) ((a_sec) % 60)

#define MIN_TO_HOUR(a_min) ((a_min) / 60)
#define MIN_TO_HOUR_REMAINDER(a_min) ((a_min) % 60)

#define MIN_TO_MSEC(a_min) SEC_TO_MSEC((a_min) * 60)
#define HOUR_TO_MSEC(a_Hour) MIN_TO_MSEC((a_Hour) * 60)


static inline void busy_wait(unsigned int iter) {

  unsigned int i;
  unsigned int volatile tmp;
  unsigned int volatile* hdr = (unsigned int*)0x15000;

  for (i = iter; i > 0; i--) {
    tmp = *hdr;
    UNUSED(tmp);
  }

}

static inline void flush_tlb(void) {
  /* The cortex-A8 has a 32 entry data/instruction TLB
   * The for loop should access 32 sections to fill the TLB */

  unsigned int i;
  unsigned int volatile tmp = 0x0;

  for(i = 0; i < 32; i++) {
    tmp = *((unsigned int* volatile)0x1000000 + i * 0x100000);
  }

}

#endif