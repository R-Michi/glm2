/**
* @file     matrix.h
* @brief    Template specialization of all matrix functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "matrix_base.h"
#include "../../detail/core/matrix/matrix.h"

namespace glm2
{
    /*------------------------------ Function: transpose ------------------------------*/
    template<> inline mat<2, 2, float>::transpose_type transpose(const mat<2, 2, float>& m);
    template<> inline mat<2, 3, float>::transpose_type transpose(const mat<2, 3, float>& m);
    template<> inline mat<2, 4, float>::transpose_type transpose(const mat<2, 4, float>& m);
    template<> inline mat<3, 2, float>::transpose_type transpose(const mat<3, 2, float>& m);
    template<> inline mat<3, 3, float>::transpose_type transpose(const mat<3, 3, float>& m);
    template<> inline mat<3, 4, float>::transpose_type transpose(const mat<3, 4, float>& m);
    template<> inline mat<4, 2, float>::transpose_type transpose(const mat<4, 2, float>& m);
    template<> inline mat<4, 3, float>::transpose_type transpose(const mat<4, 3, float>& m);
    template<> inline mat<4, 4, float>::transpose_type transpose(const mat<4, 4, float>& m);

    template<> inline mat<2, 2, double>::transpose_type transpose(const mat<2, 2, double>& m);
    template<> inline mat<2, 3, double>::transpose_type transpose(const mat<2, 3, double>& m);
    template<> inline mat<2, 4, double>::transpose_type transpose(const mat<2, 4, double>& m);
    template<> inline mat<3, 2, double>::transpose_type transpose(const mat<3, 2, double>& m);
    template<> inline mat<3, 3, double>::transpose_type transpose(const mat<3, 3, double>& m);
    template<> inline mat<3, 4, double>::transpose_type transpose(const mat<3, 4, double>& m);
    template<> inline mat<4, 2, double>::transpose_type transpose(const mat<4, 2, double>& m);
    template<> inline mat<4, 3, double>::transpose_type transpose(const mat<4, 3, double>& m);
    template<> inline mat<4, 4, double>::transpose_type transpose(const mat<4, 4, double>& m);

    /*------------------------------ Function: determinant ------------------------------*/
    template<> inline float determinant(const mat<2, 2, float>& m);
    template<> inline float determinant(const mat<3, 3, float>& m);
    template<> inline float determinant(const mat<4, 4, float>& m);

    template<> inline double determinant(const mat<2, 2, double>& m);
    template<> inline double determinant(const mat<3, 3, double>& m);
    template<> inline double determinant(const mat<4, 4, double>& m);

    /*------------------------------ Function: inverse ------------------------------*/
    template<> inline mat<2, 2, float> inverse(const mat<2, 2, float>& m);
    template<> inline mat<3, 3, float> inverse(const mat<3, 3, float>& m);
    template<> inline mat<4, 4, float> inverse(const mat<4, 4, float>& m);

    template<> inline mat<2, 2, double> inverse(const mat<2, 2, double>& m);
    template<> inline mat<3, 3, double> inverse(const mat<3, 3, double>& m);
    template<> inline mat<4, 4, double> inverse(const mat<4, 4, double>& m);
}

#include "transpose_impl.inl"
#include "determinant_impl.inl"
#include "inverse_impl.inl"