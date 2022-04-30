/**
* @file     degrees_impl.inl
* @brief    Detailed implementation of the degrees function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::trigonometric::degrees::_default_f(float radians)
{
    return GLM2_180_PI * radians;
}

inline double glm2::detail::core::trigonometric::degrees::_default_d(double radians)
{
    return GLM2_180_PI * radians;
}

inline __m128 glm2::detail::core::trigonometric::degrees::_default_fv(__m128 radians)
{
    __m128 xmm0 = _mm_set_ps1(GLM2_180_PI);
    return _mm_mul_ps(xmm0, radians);
}

inline __m128d glm2::detail::core::trigonometric::degrees::_default_dv2(__m128d radians)
{
    __m128d xmm0 = _mm_set1_pd(GLM2_180_PI);
    return _mm_mul_pd(xmm0, radians);
}

inline __m256d glm2::detail::core::trigonometric::degrees::_default_dv(__m256d radians)
{
    __m256d ymm0 = _mm256_set1_pd(GLM2_180_PI);
    return _mm256_mul_pd(ymm0, radians);
}
