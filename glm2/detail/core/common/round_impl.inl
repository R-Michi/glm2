/**
* @file     round_impl.inl
* @brief    Detailed implementation of the round function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::round::_default_f(float x)
{
    return std::roundf(x);
}

inline double glm2::detail::core::common::round::_default_d(double x)
{
    return std::round(x);
}

inline __m128 glm2::detail::core::common::round::_default_fv(__m128 x)
{
    return _mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}

inline __m128d glm2::detail::core::common::round::_default_dv2(__m128d x)
{
    return _mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}

inline __m256d glm2::detail::core::common::round::_default_dv(__m256d x)
{
    return _mm256_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
}
