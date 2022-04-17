/**
* @file     mod_impl.inl
* @brief    Deailed implementation of the mod function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::mod::_default_f(float x, float y)
{
    return std::fmodf(x, y);
}

inline double glm2::detail::core::common::mod::_default_d(double x, double y)
{
    return std::fmod(x, y);
}

inline __m128 glm2::detail::core::common::mod::_default_fv(__m128 x, __m128 y)
{
    __m128 xmm0 = _mm_div_ps(x, y);
    xmm0 = _mm_round_ps(xmm0, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    xmm0 = _mm_mul_ps(xmm0, y);
    return _mm_sub_ps(x, xmm0);
}

inline __m128d glm2::detail::core::common::mod::_default_dv2(__m128d x, __m128d y)
{
    __m128d xmm0 = _mm_div_pd(x, y);
    xmm0 = _mm_round_pd(xmm0, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    xmm0 = _mm_mul_pd(xmm0, y);
    return _mm_sub_pd(x, xmm0);
}

inline __m256d glm2::detail::core::common::mod::_default_dv(__m256d x, __m256d y)
{
    __m256d ymm0 = _mm256_div_pd(x, y);
    ymm0 = _mm256_round_pd(ymm0, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    ymm0 = _mm256_mul_pd(ymm0, y);
    return _mm256_sub_pd(x, ymm0);
}
