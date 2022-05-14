/**
* @file     packing_impl.inl
* @brief    Detailed implementation of all packing functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline double glm2::detail::core::packing::packDouble2x32::_default(__m128i x)
{
    double ret;
    _mm_store_sd(&ret, _mm_castsi128_pd(x));
    return ret;
}

inline uint32_t glm2::detail::core::packing::packHalf2x16::_default(__m128 x)
{
    uint32_t ret;
    __m128i xmm0 = _mm_cvtps_ph(x, _MM_FROUND_NO_EXC);
    _mm_storeu_si32(&ret, xmm0);
    return ret;
}

inline uint32_t glm2::detail::core::packing::packSnorm2x16::_default(__m128 x)
{
    uint32_t ret;
    __m128 xmm0;
    __m128i xmm0i;
    xmm0 = _mm_min_ps(x, _mm_set1_ps(1.0f));
    xmm0 = _mm_max_ps(xmm0, _mm_set1_ps(-1.0f));
    xmm0 = _mm_mul_ps(xmm0, _mm_set1_ps(32767.0f));
    xmm0 = _mm_round_ps(xmm0, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
    xmm0i = _mm_movpi64_epi64(_mm_cvtps_pi16(xmm0));
    _mm_storeu_si32(&ret, xmm0i);
    return ret;
}

inline uint32_t glm2::detail::core::packing::packSnorm4x8::_default(__m128 x)
{
    uint32_t ret;
    __m128 xmm0;
    __m128i xmm0i;
    xmm0 = _mm_min_ps(x, _mm_set1_ps(1.0f));
    xmm0 = _mm_max_ps(xmm0, _mm_set1_ps(-1.0f));
    xmm0 = _mm_mul_ps(xmm0, _mm_set1_ps(127.0f));
    xmm0 = _mm_round_ps(xmm0, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
    xmm0i = _mm_movpi64_epi64(_mm_cvtps_pi8(xmm0));
    _mm_storeu_si32(&ret, xmm0i);
    return ret;
}

inline uint32_t glm2::detail::core::packing::packUnorm2x16::_default(__m128 x)
{
    uint32_t ret;
    __m128 xmm0;
    __m128i xmm0i, xmm1;
    xmm0 = _mm_min_ps(x, _mm_set1_ps(1.0f));
    xmm0 = _mm_max_ps(xmm0, _mm_set1_ps(0.0f));
    xmm0 = _mm_mul_ps(xmm0, _mm_set1_ps(65535.0f));
    xmm0 = _mm_round_ps(xmm0, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
    xmm0i = _mm_cvtps_epi32(xmm0);          // a, b, X, X
    xmm0i = _mm_and_si128(xmm0i, _mm_set1_epi32(0x0000FFFF));
    xmm0i = _mm_sllv_epi32(xmm0i, _mm_set_epi32(0, 0, 16, 0));
    xmm1 = _mm_shuffle_epi32(xmm0i, 0x55);  // b, b, b, b
    xmm0i = _mm_or_si128(xmm0i, xmm1);
    _mm_storeu_si32(&ret, xmm0i);
    return ret;
}

inline uint32_t glm2::detail::core::packing::packUnorm4x8::_default(__m128 x)
{
    uint32_t ret;
    __m128 xmm0;
    __m128i xmm0i, xmm1;
    xmm0 = _mm_min_ps(x, _mm_set1_ps(1.0f));
    xmm0 = _mm_max_ps(xmm0, _mm_set1_ps(0.0f));
    xmm0 = _mm_mul_ps(xmm0, _mm_set1_ps(255.0f));
    xmm0 = _mm_round_ps(xmm0, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
    xmm0i = _mm_cvtps_epi32(xmm0);          // a, b, c, d
    xmm0i = _mm_and_si128(xmm0i, _mm_set1_epi32(0x000000FF));
    xmm0i = _mm_sllv_epi32(xmm0i, _mm_set_epi32(24, 16, 8, 0));
    xmm1 = _mm_shuffle_epi32(xmm0i, 0xEE);  // c, d, c, d
    xmm0i = _mm_or_si128(xmm0i, xmm1);      // x, y, X, X
    xmm1 = _mm_shuffle_epi32(xmm0i, 0x55);  // y, y, y, y
    xmm0i = _mm_or_si128(xmm0i, xmm1);
    _mm_storeu_si32(&ret, xmm0i);
    return ret;
}

inline __m128i glm2::detail::core::packing::unpackDouble2x32::_default(double x)
{
    __m128i xmm0;
    xmm0 = _mm_load_sd(&x);
    return _mm_castpd_si128(xmm0);
}

inline __m128 glm2::detail::core::packing::unpackHalf2x16::_default(uint32_t x)
{
    __m128i xmm0;
    xmm0 = _mm_loadu_si32(&x);
    xmm0 = _mm_cvtph_ps(xmm0);
    return _mm_castsi128_ps(xmm0);
}

inline __m128 glm2::detail::core::packing::unpackSnorm2x16::_default(uint32_t x)
{
    __m64 mm0;
    __m128 xmm0;
    mm0 = _mm_movepi64_pi64(_mm_loadu_si32(&x));
    xmm0 = _mm_cvtpi16_ps(mm0);
    xmm0 = _mm_mul_ps(xmm0, _mm_set1_ps(1.0f / 32767.0f));
    xmm0 = _mm_min_ps(xmm0, _mm_set1_ps(1.0f));
    return _mm_max_ps(xmm0, _mm_set1_ps(-1.0f));
}

inline __m128 glm2::detail::core::packing::unpackSnorm4x8::_default(uint32_t x)
{
    __m64 mm0;
    __m128 xmm0;
    mm0 = _mm_movepi64_pi64(_mm_loadu_si32(&x));
    xmm0 = _mm_cvtpi8_ps(mm0);
    xmm0 = _mm_mul_ps(xmm0, _mm_set1_ps(1.0f / 127.0f));
    xmm0 = _mm_min_ps(xmm0, _mm_set1_ps(1.0f));
    return _mm_max_ps(xmm0, _mm_set1_ps(-1.0f));
}

inline __m128 glm2::detail::core::packing::unpackUnorm2x16::_default(uint32_t x)
{
    __m64 mm0;
    __m128 xmm0;
    __m128i xmm0i;
    xmm0i = _mm_broadcastd_epi32(_mm_loadu_si32(&x));
    xmm0i = _mm_srlv_epi32(xmm0i, _mm_set_epi32(0, 0, 16, 0));
    xmm0i = _mm_and_si128(xmm0i, _mm_set1_epi32(0x0000FFFF));
    xmm0 = _mm_cvtepi32_ps(xmm0i);
    return _mm_mul_ps(xmm0, _mm_set1_ps(1.0f / 65535.0f));
}

inline __m128 glm2::detail::core::packing::unpackUnorm4x8::_default(uint32_t x)
{
    __m64 mm0;
    __m128 xmm0;
    __m128i xmm0i;
    xmm0i = _mm_broadcastd_epi32(_mm_loadu_si32(&x));
    xmm0i = _mm_srlv_epi32(xmm0i, _mm_set_epi32(24, 16, 8, 0));
    xmm0i = _mm_and_si128(xmm0i, _mm_set1_epi32(0x000000FF));
    xmm0 = _mm_cvtepi32_ps(xmm0i);
    return _mm_mul_ps(xmm0, _mm_set1_ps(1.0f / 255.0f));
}
