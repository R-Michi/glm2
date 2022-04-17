/**
* @file     pow_impl.inl
* @brief    Deailed implementation of the pow function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::exponential::pow::_default_f(float base, float exponent)
{
    return std::powf(base, exponent);
}

inline double glm2::detail::core::exponential::pow::_default_d(double base, double exponent)
{
    return std::pow(base, exponent);
}

inline __m128 glm2::detail::core::exponential::pow::_default_fv2(__m128 base, float exponent)
{
    __m128 xmm0;
    xmm0[0] = std::powf(base[0], exponent);
    xmm0[1] = std::powf(base[1], exponent);
    return xmm0;
}

inline __m128 glm2::detail::core::exponential::pow::_default_fv2(__m128 base, __m128 exponent)
{
    __m128 xmm0;
    xmm0[0] = std::powf(base[0], exponent[0]);
    xmm0[1] = std::powf(base[1], exponent[1]);
    return xmm0;
}

inline __m128 glm2::detail::core::exponential::pow::_default_fv3(__m128 base, float exponent)
{
    __m128 xmm0;
    xmm0[0] = std::powf(base[0], exponent);
    xmm0[1] = std::powf(base[1], exponent);
    xmm0[2] = std::powf(base[2], exponent);
    return xmm0;
}

inline __m128 glm2::detail::core::exponential::pow::_default_fv3(__m128 base, __m128 exponent)
{
    __m128 xmm0;
    xmm0[0] = std::powf(base[0], exponent[0]);
    xmm0[1] = std::powf(base[1], exponent[1]);
    xmm0[2] = std::powf(base[2], exponent[2]);
    return xmm0;
}

inline __m128 glm2::detail::core::exponential::pow::_default_fv4(__m128 base, float exponent)
{
    __m128 xmm0;
    xmm0[0] = std::powf(base[0], exponent);
    xmm0[1] = std::powf(base[1], exponent);
    xmm0[2] = std::powf(base[2], exponent);
    xmm0[3] = std::powf(base[3], exponent);
    return xmm0;
}

inline __m128 glm2::detail::core::exponential::pow::_default_fv4(__m128 base, __m128 exponent)
{
    __m128 xmm0;
    xmm0[0] = std::powf(base[0], exponent[0]);
    xmm0[1] = std::powf(base[1], exponent[1]);
    xmm0[2] = std::powf(base[2], exponent[2]);
    xmm0[3] = std::powf(base[3], exponent[3]);
    return xmm0;
}

inline __m128d glm2::detail::core::exponential::pow::_default_dv2(__m128d base, double exponent)
{
    __m128d ymm0;
    ymm0[0] = std::pow(base[0], exponent);
    ymm0[1] = std::pow(base[1], exponent);
    return ymm0;
}

inline __m128d glm2::detail::core::exponential::pow::_default_dv2(__m128d base, __m128d exponent)
{
    __m128d ymm0;
    ymm0[0] = std::pow(base[0], exponent[0]);
    ymm0[1] = std::pow(base[1], exponent[1]);
    return ymm0;
}

inline __m256d glm2::detail::core::exponential::pow::_default_dv3(__m256d base, double exponent)
{
    __m256d ymm0;
    ymm0[0] = std::pow(base[0], exponent);
    ymm0[1] = std::pow(base[1], exponent);
    ymm0[2] = std::pow(base[2], exponent);
    return ymm0;
}

inline __m256d glm2::detail::core::exponential::pow::_default_dv3(__m256d base, __m256d exponent)
{
    __m256d ymm0;
    ymm0[0] = std::pow(base[0], exponent[0]);
    ymm0[1] = std::pow(base[1], exponent[1]);
    ymm0[2] = std::pow(base[2], exponent[2]);
    return ymm0;
}

inline __m256d glm2::detail::core::exponential::pow::_default_dv4(__m256d base, double exponent)
{
    __m256d ymm0;
    ymm0[0] = std::pow(base[0], exponent);
    ymm0[1] = std::pow(base[1], exponent);
    ymm0[2] = std::pow(base[2], exponent);
    ymm0[3] = std::pow(base[3], exponent);
    return ymm0;
}

inline __m256d glm2::detail::core::exponential::pow::_default_dv4(__m256d base, __m256d exponent)
{
    __m256d ymm0;
    ymm0[0] = std::pow(base[0], exponent[0]);
    ymm0[1] = std::pow(base[1], exponent[1]);
    ymm0[2] = std::pow(base[2], exponent[2]);
    ymm0[3] = std::pow(base[3], exponent[3]);
    return ymm0;
}
