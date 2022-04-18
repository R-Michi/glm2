/**
* @file     matrix.h
* @brief    Detailed declaration of all matrix functions.
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
        namespace core
        {
            namespace matrix
            {
                namespace transpose
                {
                    inline void _default_fm2x2(const __m64* M_in, __m128* M_out);
                    inline void _default_fm2x3(const __m128* M_in, __m128* M_out);
                    inline void _default_fm2x4(const __m128* M_in, __m256* M_out);
                    inline void _default_fm3x2(const __m64* M_in, __m128* M_out);
                    inline void _default_fm3x3(const __m128* M_in, __m256* M_out);
                    inline void _default_fm3x4(const __m128* M_in, __m256* M_out);
                    inline void _default_fm4x2(const __m64* M_in, __m256* M_out);
                    inline void _default_fm4x3(const __m128* M_in, __m256* M_out);
                    inline void _default_fm4x4(const __m128* M_in, __m256* M_out);
                    inline void _default_dm2x2(const __m128d* M_in, __m256d* M_out);
                    inline void _default_dm2x3(const __m256d* M_in, __m256d* M_out);
                    inline void _default_dm2x4(const __m256d* M_in, __m256d* M_out);
                    inline void _default_dm3x2(const __m128d* M_in, __m256d* M_out);
                    inline void _default_dm3x3(const __m256d* M_in, __m256d* M_out);
                    inline void _default_dm3x4(const __m256d* M_in, __m256d* M_out);
                    inline void _default_dm4x2(const __m128d* M_in, __m256d* M_out);
                    inline void _default_dm4x3(const __m256d* M_in, __m256d* M_out);
                    inline void _default_dm4x4(const __m256d* M_in, __m256d* M_out);
                }

                namespace determinant
                {
                    inline float _default_fm2x2(const __m64* M_in);
                    inline float _default_fm3x3(const __m128* M_in);
                    inline float _default_fm4x4(const __m128* M_in);
                    inline double _default_dm2x2(const __m128d* M_in);
                    inline double _default_dm3x3(const __m256d* M_in);
                    inline double _default_dm4x4(const __m256d* M_in);

                    inline float _alternative_fm4x4(const __m128* M_in);
                    inline double _alternative_dm3x3(const __m256d* M_in);
                    inline double _alternative_dm4x4(const __m256d* M_in);
                }

                namespace inverse
                {
                    inline void _default_fm2x2(const __m64* M_in, __m128* M_out);
                    inline void _default_fm3x3(const __m128* M_in, __m128* M_out);
                    inline void _default_fm4x4(const __m128* M_in, __m128* M_out);
                    inline void _default_dm2x2(const __m128d* M_in, __m256d* M_out);
                    inline void _default_dm3x3(const __m256d* M_in, __m256d* M_out);
                    inline void _default_dm4x4(const __m256d* M_in, __m256d* M_out);
                }
            }
        }
    }
}

#include "transpose_impl.inl"
#include "determinant_impl.inl"
#include "inverse_impl.inl"
