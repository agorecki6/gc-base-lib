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
#include <comp_arr.h>
#include <ms.h>

#include <comp.h>



//==============================================================================
// Initialization and deinitialization
//==============================================================================
u1 comp_init_ms(struct comp_info *type, void *inst, void *conf)
{
	struct comp_info_extr *extr;

	MS_BEG(0);
	MS_SP { MS_EV(!comp_arr_init(&type->a_comp, inst, conf)); } // 1
	MS_SP { MS_EV(!comp_arr_init(&type->a_prim, inst, conf)); } // 2

	MS_SP { // 3
		if (!(type->flag & COMP_CONF_EXTR))
			extr = NULL;

		else {
			extr = containerof(type, struct comp_info_extr, gen);
			MS_EV(!comp_arr_init(&extr->a_comp_conf, inst, conf));
		}
	}

	MS_SP { MS_EV(type->fp_init == NULL || !type->fp_init(inst, conf)); } // 4

	MS_SP { // 5
		if (unlikely(extr != NULL)) {
			MS_EV(extr->fp_conf_s == NULL || !extr->fp_conf_s(inst, conf));
			comp_arr_deinit(&extr->a_comp_conf, inst);
		}
	}

	return 0;
}


void comp_deinit_ms(struct comp_info *type, void *inst, u1 step)
{
	struct comp_info_extr *extr;

	MS_BEG(step);

	MS_SP { // 5
		if (unlikely(step && (type->flag & COMP_CONF_EXTR))) { // Only if initialization failed.
			extr = containerof(type, struct comp_info_extr, gen);
			comp_arr_deinit(&extr->a_comp_conf, inst);
		}
	}

	MS_SP { // 4
		if (type->fp_deinit != NULL)
			type->fp_deinit(inst);
	}

	MS_EM; // 3
	MS_SP { comp_arr_deinit(&type->a_prim, inst); } // 2
	MS_SP { comp_arr_deinit(&type->a_comp, inst); } // 1
}



//==============================================================================
// Configuration
//==============================================================================
__dllexp u1 comp_conf_g(struct comp_info *type, void *inst, void *conf)
{
	return !(type->fp_conf_g == NULL || !type->fp_conf_g(inst, conf));
}


__dllexp u1 comp_conf_s(struct comp_info *type, void *inst, void *conf)
{
	return !(type->fp_conf_s == NULL || !type->fp_conf_s(inst, conf));
}
