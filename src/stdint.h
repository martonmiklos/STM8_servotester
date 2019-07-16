/*	C99 STANDARD INTEGER HEADER
 *	Copyright (c) 2012 by COSMIC Software
 */
#ifndef __STDINT__
#define __STDINT__	1

/*	standard types
 */
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
#if __LGLG__
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
#endif

/*	minimum types
 */
typedef signed char int_least8_t;
typedef signed short int_least16_t;
typedef signed long int_least32_t;
typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned long uint_least32_t;
#if __LGLG__
typedef signed long long int_least64_t;
typedef unsigned long long uint_least64_t;
#endif

/*	fastest types
 */
typedef signed char int_fast8_t;
typedef signed short int_fast16_t;
typedef signed long int_fast32_t;
typedef unsigned char uint_fast8_t;
typedef unsigned short uint_fast16_t;
typedef unsigned long uint_fast32_t;
#if __LGLG__
typedef signed long long int_fast64_t;
typedef unsigned long long uint_fast64_t;
#endif

/*	pointer types
 */
typedef signed long intptr_t;
typedef unsigned long uintptr_t;

/*	greatest types
 */
#if __LGLG__
typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#else
typedef signed long intmax_t;
typedef unsigned long uintmax_t;
#endif

/*	limit macros
 */
#define INT8_MIN	(-128)
#define INT16_MIN	(-32768)
#define INT32_MIN	(-2147483648)
#define INT8_MAX	127
#define INT16_MAX	32767
#define INT32_MAX	2147483647
#define uint8_t_MAX	255
#define UINT16_MAX	0xffff
#define UINT32_MAX	0xffffffff
#if __LGLG__
#define INT64_MIN       (-9223372036854775808)
#define INT64_MAX         9223372036854775807
#define UINT64_MAX        0xffffffffffffffff
#endif

/*	minimum limit macros
 */
#define INT_LEAST8_MIN	(-128)
#define INT_LEAST16_MIN	(-32768)
#define INT_LEAST32_MIN	(-2147483648)
#define INT_LEAST8_MAX	  127
#define INT_LEAST16_MAX	  32767
#define INT_LEAST32_MAX	  2147483647
#define UINT_LEAST8_MAX	  255
#define UINT_LEAST16_MAX  0xffff
#define UINT_LEAST32_MAX  0xffffffff
#if __LGLG__
#define INT_LEAST64_MIN (-9223372036854775808)
#define INT_LEAST64_MAX   9223372036854775807
#define UINT_LEAST64_MAX  0xffffffffffffffff
#endif

/*	fastest limit macros
 */
#define INT_FAST8_MIN	(-128)
#define INT_FAST16_MIN	(-32768)
#define INT_FAST32_MIN	(-2147483648)
#define INT_FAST8_MAX	  127
#define INT_FAST16_MAX	  32767
#define INT_FAST32_MAX	  2147483647
#define UINT_FAST8_MAX	  255
#define UINT_FAST16_MAX	  0xffff
#define UINT_FAST32_MAX	  0xffffffff
#if __LGLG__
#define INT_FAST64_MIN  (-9223372036854775808)
#define INT_FAST64_MAX    9223372036854775807
#define UINT_FAST64_MAX  0xffffffffffffffff
#endif

/*	pointer limit macros
 */
#define INTPTR_MIN	(-2147483648)
#define INTPTR_MAX	2147483647
#define UINTPTR_MAX	0xffffffff
#define PTRDIFF_MIN	(-2147483648)
#define PTRDIFF_MAX	2147483647

/*	greatest limit macros
 */
#if __LGLG__
#define INTMAX_MIN      (-9223372036854775808)
#define INTMAX_MAX        9223372036854775807
#define UINTMAX_MAX       0xffffffffffffffff
#else
#define INTMAX_MIN	(-2147483648)
#define INTMAX_MAX	2147483647
#define UINTMAX_MAX	0xffffffff
#endif

/*	integer constants macros
 */
#define INT8_C(n)	((int8_t)n)
#define INT16_C(n)	((int16_t)n)
#define INT32_C(n)	(n ## L)

#define uint8_t_C(n)	((uint8_t)n)
#define UINT16_C(n)	((uint16_t)n)
#define UINT32_C(n)	(n ## UL)

#if __LGLG__
#define INT64_C(n)      (n ## LL)
#define UINT64_C(n)     (n ## ULL)
#define INTMAX_C(n)     (n ## LL)
#define UINTMAX_C(n)    (n ## ULL)
#else
#define INTMAX_C(n)	(n ## L)
#define UINTMAX_C(n)	(n ## UL)
#endif

#endif
