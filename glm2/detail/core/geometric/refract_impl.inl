/**
* @file     refract_impl.inl
* @brief    Deailed implementation of the refract function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

/* Implementation that works the fastest according to my testings. */
inline __m128 glm2::detail::core::geometric::refract::_default_fv2(__m128 i, __m128 n, __m128 eta)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set_ps1(1.0f);
    xmm1 = dot::_default_fv2(n, i);
    xmm3 = _mm_mul_ps(eta, eta);
    xmm2 = _mm_fnmadd_ps(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_ps(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_ps(xmm0, xmm2);
    xmm0 = _mm_sqrt_ps(xmm0);
    xmm0 = _mm_fmadd_ps(xmm1, eta, xmm0);
    xmm1 = _mm_mul_ps(eta, i);
    xmm0 = _mm_fnmadd_ps(xmm0, n, xmm1);
    return _mm_and_ps(xmm0, xmm2);
}

inline __m128 glm2::detail::core::geometric::refract::_default_fv3(__m128 i, __m128 n, __m128 eta)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set_ps1(1.0f);
    xmm1 = dot::_default_fv3(n, i);
    xmm3 = _mm_mul_ps(eta, eta);
    xmm2 = _mm_fnmadd_ps(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_ps(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_ps(xmm0, xmm2);
    xmm0 = _mm_sqrt_ps(xmm0);
    xmm0 = _mm_fmadd_ps(xmm1, eta, xmm0);
    xmm1 = _mm_mul_ps(eta, i);
    xmm0 = _mm_fnmadd_ps(xmm0, n, xmm1);
    return _mm_and_ps(xmm0, xmm2);
}

inline __m128 glm2::detail::core::geometric::refract::_default_fv4(__m128 i, __m128 n, __m128 eta)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set_ps1(1.0f);
    xmm1 = dot::_default_fv4(n, i);
    xmm3 = _mm_mul_ps(eta, eta);
    xmm2 = _mm_fnmadd_ps(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_ps(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_ps(xmm0, xmm2);
    xmm0 = _mm_sqrt_ps(xmm0);
    xmm0 = _mm_fmadd_ps(xmm1, eta, xmm0);
    xmm1 = _mm_mul_ps(eta, i);
    xmm0 = _mm_fnmadd_ps(xmm0, n, xmm1);
    return _mm_and_ps(xmm0, xmm2);
}

inline __m128d glm2::detail::core::geometric::refract::_default_dv2(__m128d i, __m128d n, __m128d eta)
{
    __m128d xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set1_pd(1.0);
    xmm1 = dot::_default_dv2(n, i);
    xmm3 = _mm_mul_pd(eta, eta);
    xmm2 = _mm_fnmadd_pd(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_pd(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_pd(xmm0, xmm2);
    xmm0 = _mm_sqrt_pd(xmm0);
    xmm0 = _mm_fmadd_pd(xmm1, eta, xmm0);
    xmm1 = _mm_mul_pd(eta, i);
    xmm0 = _mm_fnmadd_pd(xmm0, n, xmm1);
    return _mm_and_pd(xmm0, xmm2);
}

inline __m256d glm2::detail::core::geometric::refract::_default_dv3(__m256d i, __m256d n, __m256d eta)
{
    __m256d ymm0, ymm1, ymm2, ymm3;
    __m128d xmm0;
    ymm0 = _mm256_set1_pd(1.0);
    ymm1 = dot::_default_dv3(n, i);
    ymm3 = _mm256_mul_pd(eta, eta);
    ymm2 = _mm256_fnmadd_pd(ymm1, ymm1, ymm0);
    ymm0 = _mm256_fnmadd_pd(ymm3, ymm2, ymm0);
    ymm2 = _mm256_setzero_si256();
    ymm2 = _mm256_cmp_pd(ymm0, ymm2, _CMP_GE_OQ);
    xmm0 = _mm256_castpd256_pd128(ymm0);
    xmm0 = _mm_sqrt_sd(xmm0, xmm0);
    ymm0 = _mm256_broadcastsd_pd(xmm0);
    ymm0 = _mm256_fmadd_pd(ymm1, eta, ymm0);
    ymm1 = _mm256_mul_pd(eta, i);
    ymm0 = _mm256_fnmadd_pd(ymm0, n, ymm1);
    return _mm256_and_pd(ymm0, ymm2);
}

inline __m256d glm2::detail::core::geometric::refract::_default_dv4(__m256d i, __m256d n, __m256d eta)
{
    __m256d ymm0, ymm1, ymm2, ymm3;
    __m128d xmm0;
    ymm0 = _mm256_set1_pd(1.0);
    ymm1 = dot::_default_dv4(n, i);
    ymm3 = _mm256_mul_pd(eta, eta);
    ymm2 = _mm256_fnmadd_pd(ymm1, ymm1, ymm0);
    ymm0 = _mm256_fnmadd_pd(ymm3, ymm2, ymm0);
    ymm2 = _mm256_setzero_si256();
    ymm2 = _mm256_cmp_pd(ymm0, ymm2, _CMP_GE_OQ);
    xmm0 = _mm256_castpd256_pd128(ymm0);
    xmm0 = _mm_sqrt_sd(xmm0, xmm0);
    ymm0 = _mm256_broadcastsd_pd(xmm0);
    ymm0 = _mm256_fmadd_pd(ymm1, eta, ymm0);
    ymm1 = _mm256_mul_pd(eta, i);
    ymm0 = _mm256_fnmadd_pd(ymm0, n, ymm1);
    return _mm256_and_pd(ymm0, ymm2);
}


/* Alternative implementation with dedicated dot-product instruction. */
inline __m128 glm2::detail::core::geometric::refract::_alternative_fv2(__m128 i, __m128 n, __m128 eta)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set_ps1(1.0f);
    xmm1 = dot::_alternative_fv2(n, i);
    xmm3 = _mm_mul_ps(eta, eta);
    xmm2 = _mm_fnmadd_ps(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_ps(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_ps(xmm0, xmm2);
    xmm0 = _mm_sqrt_ps(xmm0);
    xmm0 = _mm_fmadd_ps(xmm1, eta, xmm0);
    xmm1 = _mm_mul_ps(eta, i);
    xmm0 = _mm_fnmadd_ps(xmm0, n, xmm1);
    return _mm_and_ps(xmm0, xmm2);
}

inline __m128 glm2::detail::core::geometric::refract::_alternative_fv3(__m128 i, __m128 n, __m128 eta)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set_ps1(1.0f);
    xmm1 = dot::_alternative_fv3(n, i);
    xmm3 = _mm_mul_ps(eta, eta);
    xmm2 = _mm_fnmadd_ps(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_ps(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_ps(xmm0, xmm2);
    xmm0 = _mm_sqrt_ps(xmm0);
    xmm0 = _mm_fmadd_ps(xmm1, eta, xmm0);
    xmm1 = _mm_mul_ps(eta, i);
    xmm0 = _mm_fnmadd_ps(xmm0, n, xmm1);
    return _mm_and_ps(xmm0, xmm2);
}

inline __m128 glm2::detail::core::geometric::refract::_alternative_fv4(__m128 i, __m128 n, __m128 eta)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set_ps1(1.0f);
    xmm1 = dot::_alternative_fv4(n, i);
    xmm3 = _mm_mul_ps(eta, eta);
    xmm2 = _mm_fnmadd_ps(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_ps(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_ps(xmm0, xmm2);
    xmm0 = _mm_sqrt_ps(xmm0);
    xmm0 = _mm_fmadd_ps(xmm1, eta, xmm0);
    xmm1 = _mm_mul_ps(eta, i);
    xmm0 = _mm_fnmadd_ps(xmm0, n, xmm1);
    return _mm_and_ps(xmm0, xmm2);
}

inline __m128d glm2::detail::core::geometric::refract::_alternative_dv2(__m128d i, __m128d n, __m128d eta)
{
    __m128d xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set1_pd(1.0);
    xmm1 = dot::_alternative_dv2(n, i);
    xmm3 = _mm_mul_pd(eta, eta);
    xmm2 = _mm_fnmadd_pd(xmm1, xmm1, xmm0);
    xmm0 = _mm_fnmadd_pd(xmm3, xmm2, xmm0);
    xmm2 = _mm_setzero_si128();
    xmm2 = _mm_cmpge_pd(xmm0, xmm2);
    xmm0 = _mm_sqrt_pd(xmm0);
    xmm0 = _mm_fmadd_pd(xmm1, eta, xmm0);
    xmm1 = _mm_mul_pd(eta, i);
    xmm0 = _mm_fnmadd_pd(xmm0, n, xmm1);
    return _mm_and_pd(xmm0, xmm2);
}
