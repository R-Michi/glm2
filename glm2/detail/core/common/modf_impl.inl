/**
* @file     modf_impl.inl
* @brief    Detailed implementation of the modf function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::modf::_default_f(float x, float* i)
{
    float _fract;
    __m128 xmm0, xmm1;
    xmm0 = _mm_load_ss(&x);
    xmm1 = _mm_round_ss(xmm0, xmm0, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    _mm_store_ss(i, xmm1);
    xmm0 = _mm_sub_ss(xmm0, xmm1);
    _mm_store_ss(&_fract, xmm0);
    return _fract;
}

inline double glm2::detail::core::common::modf::_default_d(double x, double* i)
{
    double _fract;
    __m128d xmm0, xmm1;
    xmm0 = _mm_load_sd(&x);
    xmm1 = _mm_round_sd(xmm0, xmm0, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    _mm_store_sd(i, xmm1);
    xmm0 = _mm_sub_sd(xmm0, xmm1);
    _mm_store_sd(&_fract, xmm0);
    return _fract;
}

inline __m128 glm2::detail::core::common::modf::_default_fv(__m128 x, __m128* i)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_round_ps(x, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    xmm1 = _mm_sub_ps(x, xmm0);
    *i = xmm0;
    return xmm1;
}

inline __m128d glm2::detail::core::common::modf::_default_dv2(__m128d x, __m128d* i)
{
    __m128d xmm0, xmm1;
    xmm0 = _mm_round_pd(x, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    xmm1 = _mm_sub_pd(x, xmm0);
    *i = xmm0;
    return xmm1;
}

inline __m256d glm2::detail::core::common::modf::_default_dv(__m256d x, __m256d* i)
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_round_pd(x, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    ymm1 = _mm256_sub_pd(x, ymm0);
    *i = ymm0;
    return ymm1;
}
