/**
* @file     mix_impl.inl
* @brief    Deailed implementation of the mix function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::mix::_default_f(float x, float y, float a)
{
    return x * (1.0f - a) + y * a;
}

inline double glm2::detail::core::common::mix::_default_d(double x, double y, double a)
{
    return x * (1.0f - a) + y * a;
}

inline __m128 glm2::detail::core::common::mix::_default_fv(__m128 x, __m128 y, __m128 a)
{
    __m128 xmm0 = _mm_set1_ps(1.0f);
    xmm0 = _mm_sub_ps(xmm0, a);
    xmm0 = _mm_mul_ps(xmm0, x);
    return _mm_fmadd_ps(a, y, xmm0);
}

inline __m128d glm2::detail::core::common::mix::_default_dv2(__m128d x, __m128d y, __m128d a)
{
    __m128d xmm0 = _mm_set1_pd(1.0);
    xmm0 = _mm_sub_pd(xmm0, a);
    xmm0 = _mm_mul_pd(xmm0, x);
    return _mm_fmadd_pd(a, y, xmm0);
}

inline __m256d glm2::detail::core::common::mix::_default_dv(__m256d x, __m256d y, __m256d a)
{
    __m256d ymm0 = _mm256_set1_pd(1.0);
    ymm0 = _mm256_sub_pd(ymm0, a);
    ymm0 = _mm256_mul_pd(ymm0, x);
    return _mm256_fmadd_pd(a, y, ymm0);
}
