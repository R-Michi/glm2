/**
* @file     distance_impl.inl
* @brief    Deailed implementation of the distance function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128 glm2::detail::core::geometric::distance::_default_fv2(__m128 p0, __m128 p1)
{
    __m128 xmm0;
    xmm0 = _mm_sub_ps(p1, p0);
    xmm0 = dot::_default_fv2(xmm0, xmm0);
    return _mm_sqrt_ps(xmm0);
}

inline __m128 glm2::detail::core::geometric::distance::_alternative_fv2(__m128 p0, __m128 p1)
{
    __m128 xmm0;
    xmm0 = _mm_sub_ps(p1, p0);
    xmm0 = dot::_alternative_fv2(xmm0, xmm0);
    return _mm_sqrt_ps(xmm0);
}

inline __m128 glm2::detail::core::geometric::distance::_default_fv3(__m128 p0, __m128 p1)
{
    __m128 xmm0;
    xmm0 = _mm_sub_ps(p1, p0);
    xmm0 = dot::_alternative_fv3(xmm0, xmm0);
    return _mm_sqrt_ps(xmm0);
}

inline __m128 glm2::detail::core::geometric::distance::_default_fv4(__m128 p0, __m128 p1)
{
    __m128 xmm0;
    xmm0 = _mm_sub_ps(p1, p0);
    xmm0 = dot::_alternative_fv4(xmm0, xmm0);
    return _mm_sqrt_ps(xmm0);
}

inline __m128d glm2::detail::core::geometric::distance::_default_dv2(__m128d p0, __m128d p1)
{
    __m128d xmm0;
    xmm0 = _mm_sub_pd(p1, p0);
    xmm0 = dot::_alternative_dv2(xmm0, xmm0);
    return _mm_sqrt_pd(xmm0);
}

inline __m256d glm2::detail::core::geometric::distance::_default_dv3(__m256d p0, __m256d p1)
{
    __m256d ymm0;
    __m128d xmm0;
    ymm0 = _mm256_sub_pd(p1, p0);
    xmm0 = _mm256_castpd256_pd128(dot::_default_dv3(ymm0, ymm0));
    xmm0 = _mm_sqrt_sd(xmm0, xmm0);
    return _mm256_broadcastsd_pd(xmm0);
}

inline __m256d glm2::detail::core::geometric::distance::_default_dv4(__m256d p0, __m256d p1)
{
    __m256d ymm0;
    __m128d xmm0;
    ymm0 = _mm256_sub_pd(p1, p0);
    xmm0 = _mm256_castpd256_pd128(dot::_default_dv4(ymm0, ymm0));
    xmm0 = _mm_sqrt_sd(xmm0, xmm0);
    return _mm256_broadcastsd_pd(xmm0);
}

inline __m128d glm2::detail::core::geometric::distance::_single_dv3(__m256d p0, __m256d p1)
{
    __m256d ymm0;
    __m128d xmm0;
    ymm0 = _mm256_sub_pd(p1, p0);
    xmm0 = _mm256_castpd256_pd128(dot::_default_dv3(ymm0, ymm0));
    return _mm_sqrt_sd(xmm0, xmm0);
}

inline __m128d glm2::detail::core::geometric::distance::_single_dv4(__m256d p0, __m256d p1)
{
    __m256d ymm0;
    __m128d xmm0;
    ymm0 = _mm256_sub_pd(p1, p0);
    xmm0 = _mm256_castpd256_pd128(dot::_default_dv4(ymm0, ymm0));
    return _mm_sqrt_sd(xmm0, xmm0);
}

