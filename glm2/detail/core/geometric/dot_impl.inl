/**
* @file     dot_impl.inl
* @brief    Detailed implementation of the dot function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128 glm2::detail::core::geometric::dot::_default_fv2(__m128 x, __m128 y)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_mul_ps(x, y);
    xmm1 = _mm_shuffle_ps(xmm0, xmm0, 0x01);
    return _mm_add_ps(xmm0, xmm1);
}

inline __m128 glm2::detail::core::geometric::dot::_default_fv3(__m128 x, __m128 y)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_mul_ps(x, y);
    xmm1 = _mm_shuffle_ps(xmm0, xmm0, 0x09);
    xmm1 = _mm_add_ps(xmm0, xmm1);
    xmm0 = _mm_shuffle_ps(xmm0, xmm0, 0x12);
    return _mm_add_ps(xmm0, xmm1);
}

inline __m128 glm2::detail::core::geometric::dot::_default_fv4(__m128 x, __m128 y)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_mul_ps(x, y);
    xmm1 = _mm_shuffle_ps(xmm0, xmm0, 0xB1);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    xmm1 = _mm_shuffle_ps(xmm0, xmm0, 0x0A);
    return _mm_add_ps(xmm0, xmm1);
}

inline __m128d glm2::detail::core::geometric::dot::_default_dv2(__m128d x, __m128d y)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_mul_pd(x, y);
    xmm1 = _mm_shuffle_pd(xmm0, xmm0, 0x1);
    return _mm_add_pd(xmm0, xmm1);
}

inline __m256d glm2::detail::core::geometric::dot::_default_dv3(__m256d x, __m256d y)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_mul_pd(x, y);
    ymm1 = _mm256_permute4x64_pd(ymm0, 0x09);
    ymm1 = _mm256_add_pd(ymm0, ymm1);
    ymm0 = _mm256_permute4x64_pd(ymm0, 0x12);
    return _mm256_add_pd(ymm0, ymm1);
}

inline __m256d glm2::detail::core::geometric::dot::_default_dv4(__m256d x, __m256d y)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_mul_pd(x, y);
    ymm1 = _mm256_permute_pd(ymm0, 0x05);
    ymm0 = _mm256_add_pd(ymm0, ymm1);
    ymm1 = _mm256_permute4x64_pd(ymm0, 0x0A);
    return _mm256_add_pd(ymm0, ymm1);
}


inline __m128 glm2::detail::core::geometric::dot::_alternative_fv2(__m128 x, __m128 y)
{
    return _mm_dp_ps(x, y, 0x33);
}

inline __m128 glm2::detail::core::geometric::dot::_alternative_fv3(__m128 x, __m128 y)
{
    return _mm_dp_ps(x, y, 0x77);
}

inline __m128 glm2::detail::core::geometric::dot::_alternative_fv4(__m128 x, __m128 y)
{
    return _mm_dp_ps(x, y, 0xFF);
}

inline __m128d glm2::detail::core::geometric::dot::_alternative_dv2(__m128d x, __m128d y)
{
    return _mm_dp_pd(x, y, 0x33);
}
