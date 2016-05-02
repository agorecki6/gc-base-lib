//==============================================================================
// This file is part of Gc-Base-Lib.
// Copyright (C) 2018 Anthony Gorecki <agorecki3@gmail.com>
//
// Gc-Base-Lib is free software: you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// Gc-Base-Lib is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Gc-Base-Lib. If not, see <http://www.gnu.org/licenses/>.
//==============================================================================
#pragma once

#define _GNU_SOURCE

#include <sys/types.h>



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



//==============================================================================
// Macros
//==============================================================================
#define typeof(VAR) __typeof__((VAR))

#define likely(EXPR) __builtin_expect((EXPR), 1)
#define unlikely(EXPR) __builtin_expect((EXPR), 0)

#define __dll_import __declspec(dllimport)
#define __dll_export __declspec(dllexport)

#define __stmt_expr __extension__



//==============================================================================
// Statement expressions
//==============================================================================
#define containerof(PTR, N_TYPE, N_MEMB) \
__stmt_expr ({ \
	const typeof(((N_TYPE *)0)->N_MEMB) *_memb = (PTR); \
	(N_TYPE *)((u1 *)_memb - offsetof(N_TYPE, N_MEMB)); \
})
