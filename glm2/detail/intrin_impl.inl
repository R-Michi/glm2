/**
* @file     intrin_impl.inl
* @brief    Useful custom intrinsics (implementation).
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include <memory.h>

inline __m64 glm2::intrin::_m_set1_ps(float a)
{
    int x;
    memcpy(&x, &a, sizeof(float));
    return _mm_set1_pi32(x);
}
inline __m64 glm2::intrin::_m_set_ps(float a, float b)
{
    int x, y;
    memcpy(&x, &a, sizeof(float));
    memcpy(&y, &b, sizeof(float));
    return _mm_set_pi32(x, y);
}
inline __m64 glm2::intrin::_m_load_ps(const float* a)
{
    __m64 xmm0;
    memcpy(&xmm0, a, sizeof(__m64));
    return xmm0;
}
inline __m64 glm2::intrin::_m_load_pi32(const int* a)
{
    __m64 xmm0;
    memcpy(&xmm0, a, sizeof(__m64));
    return xmm0;
}
inline void glm2::intrin::_m_store_ps(float* a, __m64 xmm)
{
    memcpy(a, &xmm, sizeof(__m64));
}
inline __m64 glm2::intrin::_m_move_si64(__m64 a)
{
    return a;
}
inline __m128 glm2::intrin::_mm_move_si128(__m128 a)
{
    return a;
}
inline __m256 glm2::intrin::_mm256_move_si256(__m256 a)
{
    return a;
}
inline __m256i glm2::intrin::_mm256_castps128_si256(__m128 x)
{
    return _mm256_castsi128_si256(_mm_castps_si128(x));
}
inline __m128 glm2::intrin::_mm256_castsi256_ps128(__m256i x)
{   
    return _mm256_castps256_ps128(_mm256_castsi256_ps(x));
}
