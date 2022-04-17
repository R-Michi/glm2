/**
* @file     matrix_base.h
* @brief    Declaration of all matrix functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

namespace glm2
{
    /*------------------------------ Function: transpose ------------------------------*/
    template<length_t N, length_t M, typename T>
    inline mat<N, M, T> transpose(const mat<N, M, T>& m);

    /*------------------------------ Function: determinant ------------------------------*/
    template<length_t N, length_t M, typename T>
    inline T determinant(const mat<N, M, T>& m);

    /*------------------------------ Function: inverse ------------------------------*/
    template<length_t N, length_t M, typename T>
    inline mat<N, M, T> inverse(const mat<N, M, T>& m);
}