/**
* @file     min_impl.inl
* @brief    Deailed implementation of the min function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::min::_default_f(float x, float y)
{
    return std::min(x, y);
}

inline double glm2::detail::core::common::min::_default_d(double x, double y)
{
    return std::min(x, y);
}

inline __m128i glm2::detail::core::common::min::_default_i32(__m128i x, __m128i y)
{
    return _mm_min_epi32(x, y);
}
inline __m128 glm2::detail::core::common::min::_default_fv(__m128 x, __m128 y)
{
    return _mm_min_ps(x, y);
}

inline __m128d glm2::detail::core::common::min::_default_dv2(__m128d x, __m128d y)
{
    return _mm_min_pd(x, y);
}

inline __m256d glm2::detail::core::common::min::_default_dv(__m256d x, __m256d y)
{
    return _mm256_min_pd(x, y);
}

inline __m128i glm2::detail::core::common::min::_default_i32v(__m128i x, __m128i y)
{
    return _mm_min_epi32(x, y);
}
