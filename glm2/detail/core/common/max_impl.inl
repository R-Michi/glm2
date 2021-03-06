/**
* @file     max_impl.inl
* @brief    Detailed implementation of the max function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::max::_default_f(float x, float y)
{
    return std::max(x, y);
}

inline double glm2::detail::core::common::max::_default_d(double x, double y)
{
    return std::max(x, y);
}

inline int32_t glm2::detail::core::common::max::_default_i32(int32_t x, int32_t y)
{
    return std::max(x, y);
}
inline uint32_t glm2::detail::core::common::max::_default_u32(uint32_t x, uint32_t y)
{
    return std::max(x, y);
}

inline __m128 glm2::detail::core::common::max::_default_fv(__m128 x, __m128 y)
{
    return _mm_max_ps(x, y);
}

inline __m128d glm2::detail::core::common::max::_default_dv2(__m128d x, __m128d y)
{
    return _mm_max_pd(x, y);
}

inline __m256d glm2::detail::core::common::max::_default_dv(__m256d x, __m256d y)
{
    return _mm256_max_pd(x, y);
}

inline __m128i glm2::detail::core::common::max::_default_i32v(__m128i x, __m128i y)
{
    return _mm_max_epi32(x, y);
}
inline __m128i glm2::detail::core::common::max::_default_u32v(__m128i x, __m128i y)
{
    return _mm_max_epu32(x, y);
}
