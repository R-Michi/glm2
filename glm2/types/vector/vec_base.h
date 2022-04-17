/**
* @file     vec_base.h
* @brief    Forward declaraion and template specialization of all aviable vectors.
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
    /// vector definition
    template<length_t L, typename T, size_t S = sizeof(T)> class vec;

    /// forward declarations
    /// vector types according to GLSL 4.6 specification section 4.1. Basic Types
    using vec2 = vec<2, float>;
    using vec3 = vec<3, float>;
    using vec4 = vec<4, float>;

    using dvec2 = vec<2, double>;
    using dvec3 = vec<3, double>;
    using dvec4 = vec<4, double>;

    using bvec2 = vec<2, bool32_t>;
    using bvec3 = vec<3, bool32_t>;
    using bvec4 = vec<4, bool32_t>;

    using ivec2 = vec<2, int32_t>;
    using ivec3 = vec<3, int32_t>;
    using ivec4 = vec<4, int32_t>;

    using uvec2 = vec<2, uint32_t>;
    using uvec3 = vec<3, uint32_t>;
    using uvec4 = vec<4, uint32_t>;
}
