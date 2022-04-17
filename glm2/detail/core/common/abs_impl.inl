/**
* @file     abs_impl.inl
* @brief    Deailed implementation of the abs function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::abs::_default_f(float x)
{
    return std::abs(x);
}

inline double glm2::detail::core::common::abs::_default_d(double x)
{
    return std::abs(x);
}

inline __m128 glm2::detail::core::common::abs::_default_fv(__m128 x)
{
    return _mm_and_ps(x, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
}

inline __m128d glm2::detail::core::common::abs::_default_dv2(__m128d x)
{
    return _mm_and_pd(x, _mm_castsi128_pd(_mm_set1_epi64x(0x7FFFFFFFFFFFFFFF)));
}

inline __m256d glm2::detail::core::common::abs::_default_dv(__m256d x)
{
    return _mm256_and_pd(x, _mm256_castsi256_pd(_mm256_set1_epi64x(0x7FFFFFFFFFFFFFFF)));
}
