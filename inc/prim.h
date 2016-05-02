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

#include <macro/all.h>

#include <sys/types.h>



//==============================================================================
// Enumerations
//==============================================================================
enum prim_type {
	PRIM_U1 = 0,
	PRIM_U2,
	PRIM_U4,
	PRIM_U8,
	PRIM_U16,
	PRIM_S1,
	PRIM_S2,
	PRIM_S4,
	PRIM_S8,
	PRIM_S16,
	_PRIM_COUNT
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

