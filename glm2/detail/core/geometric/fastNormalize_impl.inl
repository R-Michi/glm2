/**
* @file     fastNormalize_impl.inl
* @brief    Deailed implementation of the fastNormalize function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128 glm2::detail::core::geometric::fastNormalize::_default_fv2(__m128 x)
{
    __m128 xmm0;
    xmm0 = dot::_default_fv2(x, x);
    xmm0 = _mm_rsqrt_ps(xmm0); 
    return _mm_mul_ps(xmm0, x);
}

inline __m128 glm2::detail::core::geometric::fastNormalize::_alternative_fv2(__m128 x)
{
    __m128 xmm0;
    xmm0 = dot::_alternative_fv2(x, x);
    xmm0 = _mm_rsqrt_ps(xmm0);
    return _mm_mul_ps(xmm0, x);
}

inline __m128 glm2::detail::core::geometric::fastNormalize::_default_fv3(__m128 x)
{
    __m128 xmm0;
    xmm0 = dot::_alternative_fv3(x, x);
    xmm0 = _mm_rsqrt_ps(xmm0);
    return _mm_mul_ps(xmm0, x);
}

inline __m128 glm2::detail::core::geometric::fastNormalize::_default_fv4(__m128 x)
{
    __m128 xmm0, xmm1;
    xmm0 = dot::_alternative_fv4(x, x);
    xmm0 = _mm_rsqrt_ps(xmm0);
    return _mm_mul_ps(xmm0, x);
}
