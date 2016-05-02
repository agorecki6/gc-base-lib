#pragma once

#include <macro/all.h>

#include <sys/types.h>



//==============================================================================
// Enumerations
//==============================================================================
enum pt_type {
	PT_U1 = 0,
	PT_U2,
	PT_U4,
	PT_U8,
	PT_U16,
	PT_S1,
	PT_S2,
	PT_S4,
	PT_S8,
	PT_S16,
	_PT_COUNT
};



//==============================================================================
// Type definitions
//==============================================================================
typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

typedef int8_t s1;
typedef int16_t s2;
typedef int32_t s4;
typedef int64_t s8;

#if defined(HAVE_INT128)
	typedef __uint128 u16;
	typedef __int128 s16;
#endif

typedef off_t off;
typedef size_t us;
typedef ssize_t ss;

