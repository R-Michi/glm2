/**
* @file     fract_impl.inl
* @brief    Deailed implementation of the fract function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::fract::_default_f(float x)
{
    return x - std::floorf(x);
}

inline double glm2::detail::core::common::fract::_default_d(double x)
{
    return x - std::floor(x);
}

inline __m128 glm2::detail::core::common::fract::_default_fv(__m128 x)
{
    __m128 xmm0 = _mm_round_ps(x, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    return _mm_sub_ps(x, xmm0);
}

inline __m128d glm2::detail::core::common::fract::_default_dv2(__m128d x)
{
    __m128d xmm0 = _mm_round_pd(x, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    return _mm_sub_pd(x, xmm0);
}

inline __m256d glm2::detail::core::common::fract::_default_dv(__m256d x)
{
    __m256d ymm0 = _mm256_round_pd(x, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
    return _mm256_sub_pd(x, ymm0);
}
