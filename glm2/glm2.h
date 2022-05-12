/**
* @file     glm2.h
* @brief    Main include file for the glm2 library.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#ifdef GLM2_FORCE_EXPLICIT_CAST
    #define GLM2_EXPLICIT_CAST explicit
#else
    #define GLM2_EXPLICIT_CAST
#endif

#include <cmath>
#include <inttypes.h>
#include <memory>

#include "types/constans.h"
#include "types/basic_types.h"

#include "detail/intrin.h"
#include "detail/internal_util.h"

#include "types/vector/vector.h"
#include "types/matrix/matrix.h"
#include "types/vector_ext/vector_ext.h"
#include "types/matrix_ext/matrix_ext.h"

#include "core/common/common.h"
#include "core/exponential/exponential.h"
#include "core/trigonometric/trigonometric.h"
#include "core/geometric/geometric.h"
#include "core/matrix/matrix.h"
#include "core/integer/integer.h"
#include "core/packing/packing.h"
#include "core/vector_relational/vector_relational.h"
