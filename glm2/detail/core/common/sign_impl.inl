/**
* @file     sign_impl.inl
* @brief    Deailed implementation of the sign function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::sign::_default_f(float x)
{
    float f;
    __m128i xmm0 = _mm_castps_si128(_mm_load_ss(&x));
    __m128i xmm1 = _mm_set1_epi32(0x1);
    xmm0 = _mm_sign_epi32(xmm1, xmm0);
    xmm0 = _mm_cvtepi32_ps(xmm0);
    _mm_store_ss(&f, _mm_castsi128_ps(xmm0));
    return f;
}

inline double glm2::detail::core::common::sign::_default_d(double x)
{
    int64_t xi = detail::util::bit_cast<int64_t, double>(x);
    int64_t a = xi & 0x8000000000000000;
    a |= 0x3ff0000000000000;
    int64_t b = (xi != 0) ? 0xFFFFFFFFFFFFFFFF : 0x0;
    return detail::util::bit_cast<double, int64_t>(a & b);
}

inline __m128 glm2::detail::core::common::sign::_default_fv(__m128 x)
{
    __m128i xmm0 = _mm_set1_epi32(0x1);
    xmm0 = _mm_sign_epi32(xmm0, _mm_castps_si128(x));
    return _mm_cvtepi32_ps(xmm0);
}

inline __m128d glm2::detail::core::common::sign::_default_dv2(__m128d x)
{
    __m128d xmm0, xmm1, xmm2;
    xmm0 = _mm_setzero_si128();
    xmm0 = _mm_cmpeq_epi64(x, xmm0);                // check if x is 0
    xmm1 = _mm_set1_epi64x(0x8000000000000000);
    xmm2 = _mm_and_si128(x, xmm1);                  // get sign bit
    xmm1 = _mm_set1_epi64x(0x3ff0000000000000);
    xmm2 = _mm_or_si128(xmm2, xmm1);                // set sign bit of value 1.0 -> -1.0 or 1.0 depending on the sign bit
    return _mm_andnot_si128(xmm0, xmm2);            // set bits to zero if x is 0.0
}

inline __m256d glm2::detail::core::common::sign::_default_dv(__m256d x)
{
    __m256d ymm0, ymm1, ymm2;
    ymm0 = _mm256_setzero_si256();
    ymm0 = _mm256_cmpeq_epi64(x, ymm0);             // check if x is 0
    ymm1 = _mm256_set1_epi64x(0x8000000000000000);
    ymm2 = _mm256_and_si256(x, ymm1);               // get sign bit
    ymm1 = _mm256_set1_epi64x(0x3ff0000000000000);
    ymm2 = _mm256_or_si256(ymm2, ymm1);             // set sign bit of value 1.0 -> -1.0 or 1.0 depending on the sign bit
    return _mm256_andnot_si256(ymm0, ymm2);         // set bits to zero if x is 0.0
}
