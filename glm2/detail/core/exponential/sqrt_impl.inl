/**
* @file     sqrt_impl.inl
* @brief    Deailed implementation of the sqrt function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::exponential::sqrt::_default_f(float x)
{
    return std::sqrtf(x);
}

inline double glm2::detail::core::exponential::sqrt::_default_d(double x)
{
    return std::sqrt(x);
}

inline __m128 glm2::detail::core::exponential::sqrt::_default_fv(__m128 x)
{
    return _mm_sqrt_ps(x);
}

inline __m128d glm2::detail::core::exponential::sqrt::_default_dv2(__m128d x)
{
    return _mm_sqrt_pd(x);
}

inline __m256d glm2::detail::core::exponential::sqrt::_default_dv(__m256d x)
{
    return _mm256_sqrt_pd(x);
}
