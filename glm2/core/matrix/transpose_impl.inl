/**
* @file     transpose_impl.inl
* @brief    Implementation of transpose function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline glm2::mat<2, 2, float> glm2::transpose(const mat<2, 2, float>& m)
{
    __m128 xmm[1];
    detail::core::matrix::transpose::_default_fm2x2(mat<2, 2, float>::intrin_ptr(m), xmm);
    return mat<2, 2, float>(xmm);
}
template<> inline glm2::mat<3, 2, float> glm2::transpose(const mat<2, 3, float>& m)
{
    __m128 xmm[2];
    detail::core::matrix::transpose::_default_fm2x3(mat<2, 3, float>::intrin_ptr(m), xmm);
    return mat<3, 2, float>(xmm);
}
template<> inline glm2::mat<4, 2, float> glm2::transpose(const mat<2, 4, float>& m)
{
    __m256 ymm[1];
    detail::core::matrix::transpose::_default_fm2x4(mat<2, 4, float>::intrin_ptr(m), ymm);
    return mat<4, 2, float>(ymm);
}
template<> inline glm2::mat<2, 3, float> glm2::transpose(const mat<3, 2, float>& m)
{
    __m128 xmm[2];
    detail::core::matrix::transpose::_default_fm3x2(mat<3, 2, float>::intrin_ptr(m), xmm);
    return mat<2, 3, float>(xmm);
}
template<> inline glm2::mat<3, 3, float> glm2::transpose(const mat<3, 3, float>& m)
{
    __m256 ymm[2];
    detail::core::matrix::transpose::_default_fm3x3(mat<3, 3, float>::intrin_ptr(m), ymm);
    return mat<3, 3, float>(ymm);
}
template<> inline glm2::mat<4, 3, float> glm2::transpose(const mat<3, 4, float>& m)
{
    __m256 ymm[2];
    detail::core::matrix::transpose::_default_fm3x4(mat<3, 4, float>::intrin_ptr(m), ymm);
    return mat<4, 3, float>(ymm);
}
template<> inline glm2::mat<2, 4, float> glm2::transpose(const mat<4, 2, float>& m)
{
    __m256 ymm[1];
    detail::core::matrix::transpose::_default_fm4x2(mat<4, 2, float>::intrin_ptr(m), ymm);
    return mat<2, 4, float>(ymm);
}
template<> inline glm2::mat<3, 4, float> glm2::transpose(const mat<4, 3, float>& m)
{
    __m256 ymm[2];
    detail::core::matrix::transpose::_default_fm4x3(mat<4, 3, float>::intrin_ptr(m), ymm);
    return mat<3, 4, float>(ymm);
}
template<> inline glm2::mat<4, 4, float> glm2::transpose(const mat<4, 4, float>& m)
{
    __m256 ymm[2];
    detail::core::matrix::transpose::_default_fm4x4(mat<4, 4, float>::intrin_ptr(m), ymm);
    return mat<4, 4, float>(ymm);
}

template<> inline glm2::mat<2, 2, double> glm2::transpose(const mat<2, 2, double>& m)
{
    __m256d ymm[1];
    detail::core::matrix::transpose::_default_dm2x2(mat<2, 2, double>::intrin_ptr(m), ymm);
    return mat<2, 2, double>(ymm);
}
template<> inline glm2::mat<3, 2, double> glm2::transpose(const mat<2, 3, double>& m)
{
    __m256d ymm[2];
    detail::core::matrix::transpose::_default_dm2x3(mat<2, 3, double>::intrin_ptr(m), ymm);
    return mat<3, 2, double>(ymm);
}
template<> inline glm2::mat<4, 2, double> glm2::transpose(const mat<2, 4, double>& m)
{
    __m256d ymm[2];
    detail::core::matrix::transpose::_default_dm2x4(mat<2, 4, double>::intrin_ptr(m), ymm);
    return mat<4, 2, double>(ymm);
}
template<> inline glm2::mat<2, 3, double> glm2::transpose(const mat<3, 2, double>& m)
{
    __m256d ymm[2];
    detail::core::matrix::transpose::_default_dm3x2(mat<3, 2, double>::intrin_ptr(m), ymm);
    return mat<2, 3, double>(ymm);
}
template<> inline glm2::mat<3, 3, double> glm2::transpose(const mat<3, 3, double>& m)
{
    __m256d ymm[3];
    detail::core::matrix::transpose::_default_dm3x3(mat<3, 3, double>::intrin_ptr(m), ymm);
    return mat<3, 3, double>(ymm);
}
template<> inline glm2::mat<4, 3, double> glm2::transpose(const mat<3, 4, double>& m)
{
    __m256d ymm[4];
    detail::core::matrix::transpose::_default_dm3x4(mat<3, 4, double>::intrin_ptr(m), ymm);
    return mat<4, 3, double>(ymm);
}
template<> inline glm2::mat<2, 4, double> glm2::transpose(const mat<4, 2, double>& m)
{
    __m256d ymm[2];
    detail::core::matrix::transpose::_default_dm4x2(mat<4, 2, double>::intrin_ptr(m), ymm);
    return mat<2, 4, double>(ymm);
}
template<> inline glm2::mat<3, 4, double> glm2::transpose(const mat<4, 3, double>& m)
{
    __m256d ymm[3];
    detail::core::matrix::transpose::_default_dm4x3(mat<4, 3, double>::intrin_ptr(m), ymm);
    return mat<3, 4, double>(ymm);
}
template<> inline glm2::mat<4, 4, double> glm2::transpose(const mat<4, 4, double>& m)
{
    __m256d ymm[4];
    detail::core::matrix::transpose::_default_dm4x4(mat<4, 4, double>::intrin_ptr(m), ymm);
    return mat<4, 4, double>(ymm);
}