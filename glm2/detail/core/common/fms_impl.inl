/**
* @file     fms_impl.inl
* @brief    Detailed implementation of the fms function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::fms::_default_f(float a, float b, float c)
{
    return a * b - c;
}

inline double glm2::detail::core::common::fms::_default_d(double a, double b, double c)
{
    return a * b - c;
}

inline __m128 glm2::detail::core::common::fms::_default_fv(__m128 a, __m128 b, __m128 c)
{
    return _mm_fmsub_ps(a, b, c);
}

inline __m128d glm2::detail::core::common::fms::_default_dv2(__m128d a, __m128d b, __m128d c)
{
    return _mm_fmsub_pd(a, b, c);
}

inline __m256d glm2::detail::core::common::fms::_default_dv(__m256d a, __m256d b, __m256d c)
{
    return _mm256_fmsub_pd(a, b, c);
}
