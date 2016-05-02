#pragma once

#include <prim.h>



//==============================================================================
// Macros
//==============================================================================
#define typeof(VAR) __typeof__((VAR))

#define likely(EXPR) __builtin_expect((EXPR), 1)
#define unlikely(EXPR) __builtin_expect((EXPR), 0)

#define __dll_import __declspec(dllimport)
#define __dll_export __declspec(dllexport)

#define __stmt_expr __extension__

#define containerof(PTR, N_TYPE, N_MEMB) \
__stmt_expr ({ \
	const typeof(((N_TYPE *)0)->N_MEMB) *_memb = (PTR); \
	(N_TYPE *)((u1 *)_memb - offsetof(N_TYPE, N_MEMB)); \
})
