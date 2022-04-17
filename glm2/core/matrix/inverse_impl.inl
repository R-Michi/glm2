/**
* @file     inverse_impl.inl
* @brief    Implementation of inverse function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::mat<2, 2, float> glm2::inverse(const mat<2, 2, float>& m)
{
    __m128 xmm[1];
    detail::core::matrix::inverse::_default_fm2x2(mat<2, 2, float>::intrin_ptr(m), xmm);
    return mat<2, 2, float>(xmm);
}
template<> inline glm2::mat<3, 3, float> glm2::inverse(const mat<3, 3, float>& m)
{
    __m128 xmm[3];
    detail::core::matrix::inverse::_default_fm3x3(mat<3, 3, float>::intrin_ptr(m), xmm);
    return mat<3, 3, float>(xmm);
}
template<> inline glm2::mat<4, 4, float> glm2::inverse(const mat<4, 4, float>& m)
{
    __m128 xmm[4];
    detail::core::matrix::inverse::_default_fm4x4(mat<4, 4, float>::intrin_ptr(m), xmm);
    return mat<4, 4, float>(xmm);
}

template<> inline glm2::mat<2, 2, double> glm2::inverse(const mat<2, 2, double>& m)
{
    __m256d ymm[1];
    detail::core::matrix::inverse::_default_dm2x2(mat<2, 2, double>::intrin_ptr(m), ymm);
    return mat<2, 2, double>(ymm);
}
template<> inline glm2::mat<3, 3, double> glm2::inverse(const mat<3, 3, double>& m)
{
    __m256d ymm[3];
    detail::core::matrix::inverse::_default_dm3x3(mat<3, 3, double>::intrin_ptr(m), ymm);
    return mat<3, 3, double>(ymm);
}
template<> inline glm2::mat<4, 4, double> glm2::inverse(const mat<4, 4, double>& m)
{
    __m256d ymm[4];
    detail::core::matrix::inverse::_default_dm4x4(mat<4, 4, double>::intrin_ptr(m), ymm);
    return mat<4, 4, double>(ymm);
}