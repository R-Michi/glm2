/**
* @file     radians_impl.inl
* @brief    Detailed implementation of the radians function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::trigonometric::radians::_default_f(float degrees)
{
    return GLM2_PI_180 * degrees;
}

inline double glm2::detail::core::trigonometric::radians::_default_d(double degrees)
{
    return GLM2_PI_180 * degrees;
}

inline __m128 glm2::detail::core::trigonometric::radians::_default_fv(__m128 degrees)
{
    __m128 xmm0 = _mm_set_ps1(GLM2_PI_180);
    return _mm_mul_ps(xmm0, degrees);
}

inline __m128d glm2::detail::core::trigonometric::radians::_default_dv2(__m128d degrees)
{
    __m128d xmm0 = _mm_set1_pd(GLM2_PI_180);
    return _mm_mul_pd(xmm0, degrees);
}

inline __m256d glm2::detail::core::trigonometric::radians::_default_dv(__m256d degrees)
{
    __m256d ymm0 = _mm256_set1_pd(GLM2_PI_180);
    return _mm256_mul_pd(ymm0, degrees);
}
