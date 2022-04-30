/**
* @file     log2_impl.inl
* @brief    Detailed implementation of the log2 function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::exponential::log2::_default_f(float x)
{
    return std::log2f(x);
}

inline double glm2::detail::core::exponential::log2::_default_d(double x)
{
    return std::log2(x);
}

inline __m128 glm2::detail::core::exponential::log2::_default_fv2(__m128 x)
{
    __m128 xmm0;
    xmm0[0] = std::log2f(x[0]);
    xmm0[1] = std::log2f(x[1]);
    return xmm0;
}

inline __m128 glm2::detail::core::exponential::log2::_default_fv3(__m128 x)
{
    __m128 xmm0;
    xmm0[0] = std::log2f(x[0]);
    xmm0[1] = std::log2f(x[1]);
    xmm0[2] = std::log2f(x[2]);
    return xmm0;
}

inline __m128 glm2::detail::core::exponential::log2::_default_fv4(__m128 x)
{
    __m128 xmm0;
    xmm0[0] = std::log2f(x[0]);
    xmm0[1] = std::log2f(x[1]);
    xmm0[2] = std::log2f(x[2]);
    xmm0[3] = std::log2f(x[3]);
    return xmm0;
}

inline __m128d glm2::detail::core::exponential::log2::_default_dv2(__m128d x)
{
    __m128d xmm0;
    xmm0[0] = std::log2(x[0]);
    xmm0[1] = std::log2(x[1]);
    return xmm0;
}

inline __m256d glm2::detail::core::exponential::log2::_default_dv3(__m256d x)
{
    __m256d ymm0;
    ymm0[0] = std::log2(x[0]);
    ymm0[1] = std::log2(x[1]);
    ymm0[2] = std::log2(x[2]);
    return ymm0;
}

inline __m256d glm2::detail::core::exponential::log2::_default_dv4(__m256d x)
{
    __m256d ymm0;
    ymm0[0] = std::log2(x[0]);
    ymm0[1] = std::log2(x[1]);
    ymm0[2] = std::log2(x[2]);
    ymm0[3] = std::log2(x[3]);
    return ymm0;
}