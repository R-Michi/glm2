/**
* @file     fastInversesquare_impl.inl
* @brief    Detailed implementation of the fastInversesqrt function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::exponential::fastInversesqrt::_default_f(float x) 
{
    float f;
    __m128 xmm0;
    xmm0 = _mm_load_ss(&x);
    xmm0 = _mm_rsqrt_ss(xmm0);
    _mm_store_ss(&f, xmm0);
    return f;
}

inline __m128 glm2::detail::core::exponential::fastInversesqrt::_default_fv(__m128 x)
{
    return _mm_rsqrt_ps(x);
}
