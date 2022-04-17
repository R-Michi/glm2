/**
* @file     matrix_base.h
* @brief    Forward declaration and template specialization of all possible matrices.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

namespace glm2
{
    /// matrix definition
    /// N = Column count
    /// M = Row count
    template<length_t N, length_t M, typename T> class mat;

    /// forward declarations
    /// matrix types according to GLSL 4.6 specification section 4.1. Basic Types
    using mat2x2 = mat<2, 2, float>;
    using mat2x3 = mat<2, 3, float>;
    using mat2x4 = mat<2, 4, float>;

    using mat3x2 = mat<3, 2, float>;
    using mat3x3 = mat<3, 3, float>;
    using mat3x4 = mat<3, 4, float>;

    using mat4x2 = mat<4, 2, float>;
    using mat4x3 = mat<4, 3, float>;
    using mat4x4 = mat<4, 4, float>;

    using mat2 = mat2x2;
    using mat3 = mat3x3;
    using mat4 = mat4x4;

    using dmat2x2 = mat<2, 2, double>;
    using dmat2x3 = mat<2, 3, double>;
    using dmat2x4 = mat<2, 4, double>;

    using dmat3x2 = mat<3, 2, double>;
    using dmat3x3 = mat<3, 3, double>;
    using dmat3x4 = mat<3, 4, double>;

    using dmat4x2 = mat<4, 2, double>;
    using dmat4x3 = mat<4, 3, double>;
    using dmat4x4 = mat<4, 4, double>;

    using dmat2 = dmat2x2;
    using dmat3 = dmat3x3;
    using dmat4 = dmat4x4;
}
