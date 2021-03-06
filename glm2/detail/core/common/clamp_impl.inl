/**
* @file     clamp_impl.inl
* @brief    Detailed implementation of the clamp function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::clamp::_default_f(float x, float minVal, float maxVal)
{
    return std::max(std::min(x, maxVal), minVal);
}

inline double glm2::detail::core::common::clamp::_default_d(double x, double minVal, double maxVal)
{
    return std::max(std::min(x, maxVal), minVal);
}

inline int32_t glm2::detail::core::common::clamp::_default_i32(int32_t x, int32_t minVal, int32_t maxVal)
{
    return std::max(std::min(x, maxVal), minVal);
}
inline uint32_t glm2::detail::core::common::clamp::_default_u32(uint32_t x, uint32_t minVal, uint32_t maxVal)
{
    return std::max(std::min(x, maxVal), minVal);
}


inline __m128 glm2::detail::core::common::clamp::_default_fv(__m128 x, __m128 minVal, __m128 maxVal)
{
    __m128 min = _mm_min_ps(x, maxVal);
    return _mm_max_ps(min, minVal);
}

inline __m128d glm2::detail::core::common::clamp::_default_dv2(__m128d x, __m128d minVal, __m128d maxVal)
{
    __m128d min = _mm_min_pd(x, maxVal);
    return _mm_max_pd(min, minVal);
}

inline __m256d glm2::detail::core::common::clamp::_default_dv(__m256d x, __m256d minVal, __m256d maxVal)
{
    __m256d min = _mm256_min_pd(x, maxVal);
    return _mm256_max_pd(min, minVal);
}

inline __m128i glm2::detail::core::common::clamp::_default_i32v(__m128i x, __m128i minVal, __m128i maxVal)
{
    __m128i xmm0;
    xmm0 = _mm_min_epi32(x, maxVal);
    return _mm_max_epi32(xmm0, minVal);
}
inline __m128i glm2::detail::core::common::clamp::_default_u32v(__m128i x, __m128i minVal, __m128i maxVal)
{
    __m128i xmm0;
    xmm0 = _mm_min_epu32(x, maxVal);
    return _mm_max_epu32(xmm0, minVal);
}
