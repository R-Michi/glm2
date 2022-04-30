/**
* @file     step_impl.inl
* @brief    Detailed implementation of the step function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::step::_default_f(float edge, float x)
{
    return (x < edge) ? 0.0f : 1.0f;
}

inline double glm2::detail::core::common::step::_default_d(double edge, double x)
{
    return (x < edge) ? 0.0 : 1.0;
}

inline __m128 glm2::detail::core::common::step::_default_fv(__m128 edge, __m128 x)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_cmple_ps(edge, x);
    xmm1 = _mm_set_ps1(1.0f);
    return _mm_and_ps(xmm0, xmm1);
}

inline __m128d glm2::detail::core::common::step::_default_dv2(__m128d edge, __m128d x)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_cmple_pd(edge, x);
    xmm1 = _mm_set1_pd(1.0);
    return _mm_and_pd(xmm0, xmm1);
}

inline __m256d glm2::detail::core::common::step::_default_dv(__m256d edge, __m256d x)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_cmp_pd(edge, x, _CMP_LE_OQ);
    ymm1 = _mm256_set1_pd(1.0);
    return _mm256_and_pd(ymm0, ymm1);
}
