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

#include <macro/base.h>



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
