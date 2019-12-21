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

#define _1K          (1024)
#define _4K          (4096)
#define _256K        (256 * _1K)
#define _1M          (1024 * _1K)
#define _16M         (16 * _1M)
#define _32M         (32 * _1M)
#define _64M         (64 * _1M)

#define PAGE_SIZE    _4K

#endif
