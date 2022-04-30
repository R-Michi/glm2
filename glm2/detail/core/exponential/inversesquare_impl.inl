/**
* @file     inversesquare_impl.inl
* @brief    Detailed implementation of the exp function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::exponential::inversesqrt::_default_f(float x)
{
    return 1.0f / std::sqrtf(x);
}

inline double glm2::detail::core::exponential::inversesqrt::_default_d(double x)
{
    return 1.0 / std::sqrt(x);
}

inline __m128 glm2::detail::core::exponential::inversesqrt::_default_fv(__m128 x)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set_ps1(1.0f);
    xmm1 = _mm_sqrt_ps(x);
    return _mm_div_ps(xmm0, xmm1);
}

inline __m128d glm2::detail::core::exponential::inversesqrt::_default_dv2(__m128d x)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_set1_pd(1.0);
    xmm1 = _mm_sqrt_pd(x);
    return _mm_div_pd(xmm0, xmm1);
}

inline __m256d glm2::detail::core::exponential::inversesqrt::_default_dv(__m256d x)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_set1_pd(1.0);
    ymm1 = _mm256_sqrt_pd(x);
    return _mm256_div_pd(ymm0, ymm1);
}
