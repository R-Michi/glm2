/**
* @file     intrin.h
* @brief    Useful custom intrinsics (declaration).
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include <immintrin.h>

namespace glm2
{
    namespace intrin
    {
        inline __m64 _m_set1_ps(float a);
        inline __m64 _m_set_ps(float a, float b);
        inline __m64 _m_load_ps(const float* a);
        inline __m64 _m_load_pi32(const void* a);
        inline void _m_store_ps(float* a, __m64 xmm);
        inline void _m_store_pi32(void* a, __m64 xmm);
        inline __m64 _m_move_si64(__m64 a);
        inline __m128 _mm_move_si128(__m128 a);
        inline __m256 _mm256_move_si256(__m256 a);
        inline __m256i _mm256_castps128_si256(__m128 x);
        inline __m128 _mm256_castsi256_ps128(__m256i x);
    }
}

#include "intrin_impl.inl"
