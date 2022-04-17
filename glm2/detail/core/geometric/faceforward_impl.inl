/**
* @file     faceforward_impl.inl
* @brief    Deailed implementation of the faceforward function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128 glm2::detail::core::geometric::faceforward::_default_fv2(__m128 n, __m128 i, __m128 nref)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0x80000000);
    xmm1 = dot::_default_fv2(nref, i);
    xmm0 = _mm_andnot_ps(xmm1, xmm0);
    return _mm_xor_ps(xmm0, n);
}

inline __m128 glm2::detail::core::geometric::faceforward::_default_fv3(__m128 n, __m128 i, __m128 nref)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0x80000000);
    xmm1 = dot::_default_fv3(nref, i);
    xmm0 = _mm_andnot_ps(xmm1, xmm0);
    return _mm_xor_ps(xmm0, n);
}

inline __m128 glm2::detail::core::geometric::faceforward::_default_fv4(__m128 n, __m128 i, __m128 nref)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0x80000000);
    xmm1 = dot::_default_fv4(nref, i);
    xmm0 = _mm_andnot_ps(xmm1, xmm0);
    return _mm_xor_ps(xmm0, n);
}

inline __m128d glm2::detail::core::geometric::faceforward::_default_dv2(__m128d n, __m128d i, __m128d nref)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_set1_epi64x(0x8000000000000000);
    xmm1 = dot::_default_dv2(nref, i);
    xmm0 = _mm_andnot_pd(xmm1, xmm0);
    return _mm_xor_pd(xmm0, n);
}

inline __m256d glm2::detail::core::geometric::faceforward::_default_dv3(__m256d n, __m256d i, __m256d nref)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_set1_epi64x(0x8000000000000000);
    ymm1 = dot::_default_dv3(nref, i);
    ymm0 = _mm256_andnot_pd(ymm1, ymm0);
    return _mm256_xor_pd(ymm0, n);
}

inline __m256d glm2::detail::core::geometric::faceforward::_default_dv4(__m256d n, __m256d i, __m256d nref)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_set1_epi64x(0x8000000000000000);
    ymm1 = dot::_default_dv4(nref, i);
    ymm0 = _mm256_andnot_pd(ymm1, ymm0);
    return _mm256_xor_pd(ymm0, n);
}


inline __m128 glm2::detail::core::geometric::faceforward::_alternative_fv2(__m128 n, __m128 i, __m128 nref)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0x80000000);
    xmm1 = dot::_alternative_fv2(nref, i);
    xmm0 = _mm_andnot_ps(xmm1, xmm0);
    return _mm_xor_ps(xmm0, n);
}

inline __m128 glm2::detail::core::geometric::faceforward::_alternative_fv3(__m128 n, __m128 i, __m128 nref)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0x80000000);
    xmm1 = dot::_alternative_fv3(nref, i);
    xmm0 = _mm_andnot_ps(xmm1, xmm0);
    return _mm_xor_ps(xmm0, n);
}

inline __m128 glm2::detail::core::geometric::faceforward::_alternative_fv4(__m128 n, __m128 i, __m128 nref)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set1_epi32(0x80000000);
    xmm1 = dot::_alternative_fv4(nref, i);
    xmm0 = _mm_andnot_ps(xmm1, xmm0);
    return _mm_xor_ps(xmm0, n);
}

inline __m128d glm2::detail::core::geometric::faceforward::_alternative_dv2(__m128d n, __m128d i, __m128d nref)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_set1_epi64x(0x8000000000000000);
    xmm1 = dot::_alternative_dv2(nref, i);
    xmm0 = _mm_andnot_pd(xmm1, xmm0);
    return _mm_xor_pd(xmm0, n);
}
