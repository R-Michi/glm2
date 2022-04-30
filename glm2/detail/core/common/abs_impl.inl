/**
* @file     abs_impl.inl
* @brief    Detailed implementation of the abs function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T>
inline T glm2::detail::core::common::abs::_default(T x)
{
    return std::abs(x);
}

inline float glm2::detail::core::common::abs::_default_f(float x)
{
    return std::abs(x);
}

inline double glm2::detail::core::common::abs::_default_d(double x)
{
    return std::abs(x);
}

inline int32_t glm2::detail::core::common::abs::_default_i32(int32_t x)
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

inline __m128i glm2::detail::core::common::abs::_default_i32v(__m128i x)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_sra_epi32(x, _mm_set_epi64x(0, 31));
    xmm1 = _mm_xor_si128(x, xmm0);
    return _mm_sub_epi32(xmm1, xmm0);
}
