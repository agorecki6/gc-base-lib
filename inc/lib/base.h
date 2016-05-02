#include <macro/gen.h>

#undef __dllexp

#if !defined(_IN_GC_BASE)
	#define __dllexp __dll_import
#else
	#define __dllexp __dll_export
#endif
