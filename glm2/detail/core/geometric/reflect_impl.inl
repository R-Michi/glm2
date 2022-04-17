/**
* @file     reflect_impl.inl
* @brief    Deailed implementation of the reflect function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

/* Implementation that works the fastest according to my testings. */
inline __m128 glm2::detail::core::geometric::reflect::_default_fv2(__m128 i, __m128 n)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set_ps1(-2.0f);
    xmm1 = dot::_default_fv2(n, i);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    return _mm_fmadd_ps(xmm0, n, i);
}

inline __m128 glm2::detail::core::geometric::reflect::_default_fv3(__m128 i, __m128 n)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set_ps1(-2.0f);
    xmm1 = dot::_default_fv3(n, i);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    return _mm_fmadd_ps(xmm0, n, i);
}

inline __m128 glm2::detail::core::geometric::reflect::_default_fv4(__m128 i, __m128 n)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set_ps1(-2.0f);
    xmm1 = dot::_default_fv4(n, i);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    return _mm_fmadd_ps(xmm0, n, i);
}

inline __m128d glm2::detail::core::geometric::reflect::_default_dv2(__m128d i, __m128d n)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_set1_pd(-2.0);
    xmm1 = dot::_default_dv2(n, i);
    xmm0 = _mm_mul_pd(xmm0, xmm1);
    return _mm_fmadd_pd(xmm0, n, i);
}

inline __m256d glm2::detail::core::geometric::reflect::_default_dv3(__m256d i, __m256d n)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_set1_pd(-2.0);
    ymm1 = dot::_default_dv3(n, i);
    ymm0 = _mm256_mul_pd(ymm0, ymm1);
    return _mm256_fmadd_pd(ymm0, n, i);
}

inline __m256d glm2::detail::core::geometric::reflect::_default_dv4(__m256d i, __m256d n)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_set1_pd(-2.0);
    ymm1 = dot::_default_dv4(n, i);
    ymm0 = _mm256_mul_pd(ymm0, ymm1);
    return _mm256_fmadd_pd(ymm0, n, i);
}


/* Alternative implementation with dedicated dot-product instruction. */
inline __m128 glm2::detail::core::geometric::reflect::_alternative_fv2(__m128 i, __m128 n)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set_ps1(-2.0f);
    xmm1 = dot::_alternative_fv2(n, i);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    return _mm_fmadd_ps(xmm0, n, i);
}

inline __m128 glm2::detail::core::geometric::reflect::_alternative_fv3(__m128 i, __m128 n)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set_ps1(-2.0f);
    xmm1 = dot::_alternative_fv3(n, i);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    return _mm_fmadd_ps(xmm0, n, i);
}

inline __m128 glm2::detail::core::geometric::reflect::_alternative_fv4(__m128 i, __m128 n)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_set_ps1(-2.0f);
    xmm1 = dot::_alternative_fv4(n, i);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    return _mm_fmadd_ps(xmm0, n, i);
}

inline __m128d glm2::detail::core::geometric::reflect::_alternative_dv2(__m128d i, __m128d n)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_set1_pd(-2.0);
    xmm1 = dot::_alternative_dv2(n, i);
    xmm0 = _mm_mul_pd(xmm0, xmm1);
    return _mm_fmadd_pd(xmm0, n, i);
}
