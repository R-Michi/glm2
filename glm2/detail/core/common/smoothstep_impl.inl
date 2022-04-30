/**
* @file     smoothstep_impl.inl
* @brief    Detailed implementation of the smoothstep function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::smoothstep::_default_f(float edge0, float edge1, float x)
{
    float t = std::max(std::min((x - edge0) / (edge1 - edge0), 1.0f), 0.0f);
    return t * t * (3.0f - 2.0f * t);
}

inline double glm2::detail::core::common::smoothstep::_default_d(double edge0, double edge1, double x)
{
    double t = std::max(std::min((x - edge0) / (edge1 - edge0), 1.0), 0.0);
    return t * t * (3.0 - 2.0 * t);
}

inline __m128 glm2::detail::core::common::smoothstep::_default_fv(__m128 edge0, __m128 edge1, __m128 x)
{
    __m128 xmm0, xmm1, xmm2;
    xmm0 = _mm_sub_ps(x, edge0);
    xmm1 = _mm_sub_ps(edge1, edge0);
    xmm0 = _mm_div_ps(xmm0, xmm1);
    xmm1 = _mm_set_ps1(1.0f);
    xmm0 = _mm_min_ps(xmm0, xmm1);
    xmm1 = _mm_setzero_si128();
    xmm0 = _mm_max_ps(xmm0, xmm1);
    xmm1 = _mm_set_ps1(3.0f);
    xmm2 = _mm_set_ps1(-2.0f);
    xmm1 = _mm_fmadd_ps(xmm2, xmm0, xmm1);
    xmm2 = _mm_mul_ps(xmm0, xmm0);
    return _mm_mul_ps(xmm1, xmm2);
}

inline __m128d glm2::detail::core::common::smoothstep::_default_dv2(__m128d edge0, __m128d edge1, __m128d x)
{
    __m128d xmm0, xmm1, xmm2;
    xmm0 = _mm_sub_pd(x, edge0);
    xmm1 = _mm_sub_pd(edge1, edge0);
    xmm0 = _mm_div_pd(xmm0, xmm1);
    xmm1 = _mm_set1_pd(1.0);
    xmm0 = _mm_min_pd(xmm0, xmm1);
    xmm1 = _mm_setzero_si128();
    xmm0 = _mm_max_pd(xmm0, xmm1);
    xmm1 = _mm_set1_pd(3.0);
    xmm2 = _mm_set1_pd(-2.0);
    xmm1 = _mm_fmadd_pd(xmm2, xmm0, xmm1);
    xmm2 = _mm_mul_pd(xmm0, xmm0);
    return _mm_mul_pd(xmm1, xmm2);
}

inline __m256d glm2::detail::core::common::smoothstep::_default_dv(__m256d edge0, __m256d edge1, __m256d x)
{
    __m256d ymm0, ymm1, ymm2;
    ymm0 = _mm256_sub_pd(x, edge0);
    ymm1 = _mm256_sub_pd(edge1, edge0);
    ymm0 = _mm256_div_pd(ymm0, ymm1);
    ymm1 = _mm256_set1_pd(1.0);
    ymm0 = _mm256_min_pd(ymm0, ymm1);
    ymm1 = _mm256_setzero_si256();
    ymm0 = _mm256_max_pd(ymm0, ymm1);
    ymm1 = _mm256_set1_pd(3.0);
    ymm2 = _mm256_set1_pd(-2.0);
    ymm1 = _mm256_fmadd_pd(ymm2, ymm0, ymm1);
    ymm2 = _mm256_mul_pd(ymm0, ymm0);
    return _mm256_mul_pd(ymm1, ymm2);
}
