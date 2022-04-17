/**
* @file     internal_util.h
* @brief    Useful utility functions for internal usage (declaration).
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
    namespace detail
    {
        namespace util
        {
            template<typename T_dst, typename T_src>
            inline T_dst bit_cast(T_src src);

            template<typename T>
            struct is_integer_32bit                         { static const bool value = false; };
            template<> struct is_integer_32bit<int32_t>     { static const bool value = true; };
            template<> struct is_integer_32bit<uint32_t>    { static const bool value = true; };

            template<length_t L, typename T, size_t S = sizeof(T)>
            struct vec_false_helper                         { static const bool value = false; };
            template<typename T>
            struct vec_false_helper<2, T, 4>                { static const bool value = true; };
            template<> struct vec_false_helper<2, float>    { static const bool value = true; };
            template<> struct vec_false_helper<3, float>    { static const bool value = true; };
            template<> struct vec_false_helper<4, float>    { static const bool value = true; };
            template<> struct vec_false_helper<2, double>   { static const bool value = true; };
            template<> struct vec_false_helper<3, double>   { static const bool value = true; };
            template<> struct vec_false_helper<4, double>   { static const bool value = true; };

            template<length_t L_cast, typename T_cast>
            struct vec2_cast_helper                         { static const bool value = false; };
            template<> struct vec2_cast_helper<2, double>   { static const bool value = true; };
            template<> struct vec2_cast_helper<2, int32_t>  { static const bool value = true; };
            template<> struct vec2_cast_helper<2, uint32_t> { static const bool value = true; };

            template<length_t N, length_t M, typename T> 
            struct mat_false_helper                         { static const bool value = false; };
            template<> struct mat_false_helper<2, 2, float> { static const bool value = true; };
            template<> struct mat_false_helper<2, 3, float> { static const bool value = true; };
            template<> struct mat_false_helper<2, 4, float> { static const bool value = true; };
            template<> struct mat_false_helper<3, 2, float> { static const bool value = true; };
            template<> struct mat_false_helper<3, 3, float> { static const bool value = true; };
            template<> struct mat_false_helper<3, 4, float> { static const bool value = true; };
            template<> struct mat_false_helper<4, 2, float> { static const bool value = true; };
            template<> struct mat_false_helper<4, 3, float> { static const bool value = true; };
            template<> struct mat_false_helper<4, 4, float> { static const bool value = true; };
            template<> struct mat_false_helper<2, 2, double> { static const bool value = true; };
            template<> struct mat_false_helper<2, 3, double> { static const bool value = true; };
            template<> struct mat_false_helper<2, 4, double> { static const bool value = true; };
            template<> struct mat_false_helper<3, 2, double> { static const bool value = true; };
            template<> struct mat_false_helper<3, 3, double> { static const bool value = true; };
            template<> struct mat_false_helper<3, 4, double> { static const bool value = true; };
            template<> struct mat_false_helper<4, 2, double> { static const bool value = true; };
            template<> struct mat_false_helper<4, 3, double> { static const bool value = true; };
            template<> struct mat_false_helper<4, 4, double> { static const bool value = true; };
        }
    }
}

#include "internal_util_impl.inl"
