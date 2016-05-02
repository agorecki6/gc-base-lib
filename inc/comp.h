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
