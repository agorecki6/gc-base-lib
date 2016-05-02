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

#include <prim.h>

#include <lib/base.h>



//==============================================================================
// Definitions
//==============================================================================
#define COMP_CONF_EXTR 1
#define COMP_SER_CSTM  2



//==============================================================================
// Predeclarations
//==============================================================================
struct comp_arr_info;



//==============================================================================
// Type definitions
//==============================================================================
typedef u1 (comp_fp_init)(void*, void*);
typedef void (comp_fp_deinit)(void*);

typedef u1 (comp_fp_conf)(void*, void*);



//==============================================================================
// Structures
//==============================================================================
struct comp_info {
	u1 flag;
	u2 s_inst;
	u2 s_conf;
	struct comp_arr_info a_prim;
	struct comp_arr_info a_comp;
	comp_fp_init *fp_init;
	comp_fp_deinit *fp_deinit;
};

struct comp_info_extr {
	struct comp_info gen;
	struct comp_arr_info a_comp_conf;
	comp_fp_conf *fp_conf_g;
	comp_fp_conf *fp_conf_s;
};



//==============================================================================
// Function prototypes
//==============================================================================
__dllexp u1 comp_init(struct comp_info*, void*, void*);
__dllexp void comp_deinit(struct comp_info*, void*);

__dllexp u1 comp_conf_g(struct comp_info*, void*, void*);
__dllexp u1 comp_conf_s(struct comp_info*, void*, void*);
