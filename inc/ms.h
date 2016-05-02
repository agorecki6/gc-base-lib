#pragma once

#include <macro/gen.h>



//==============================================================================
// Macros
//==============================================================================
#define MS_BEG(STEP) \
typeof(STEP) _cur = 0; \
typeof(STEP) _step = (STEP);

#define MS_EM \
++_cur;

#define MS_SP \
MS_EM \
if (_cur > _step)

#define MS_EV(EXPR) \
if (unlikely(!(EXPR))) \
	return _cur;
