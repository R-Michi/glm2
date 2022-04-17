/**
* @file     trigonometric_base.h
* @brief    Declaration of all trigonometric functions.
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
    /*------------------------------ Function: acos ------------------------------*/
    template<typename genType>
    inline genType acos(genType x);

    template<length_t L, typename T>
    inline vec<L, T> acos(const vec<L, T>& x);

    /*------------------------------ Function: acosh ------------------------------*/
    template<typename genType>
    inline genType acosh(genType x);

    template<length_t L, typename T>
    inline vec<L, T> acosh(const vec<L, T>& x);

    /*------------------------------ Function: asin ------------------------------*/
    template<typename genType>
    inline genType asin(genType x);

    template<length_t L, typename T>
    inline vec<L, T> asin(const vec<L, T>& x);

    /*------------------------------ Function: asinh ------------------------------*/
    template<typename genType>
    inline genType asinh(genType x);

    template<length_t L, typename T>
    inline vec<L, T> asinh(const vec<L, T>& x);

    /*------------------------------ Function: atan ------------------------------*/
    template<typename genType>
    inline genType atan(genType x);

    template<length_t L, typename T>
    inline vec<L, T> atan(const vec<L, T>& x);

    /*------------------------------ Function: atanh ------------------------------*/
    template<typename genType>
    inline genType atanh(genType x);

    template<length_t L, typename T>
    inline vec<L, T> atanh(const vec<L, T>& x);

    /*------------------------------ Function: cos ------------------------------*/
    template<typename genType>
    inline genType cos(genType x);

    template<length_t L, typename T>
    inline vec<L, T> cos(const vec<L, T>& x);

    /*------------------------------ Function: cosh ------------------------------*/
    template<typename genType>
    inline genType cosh(genType x);

    template<length_t L, typename T>
    inline vec<L, T> cosh(const vec<L, T>& x);

    /*------------------------------ Function: degrees ------------------------------*/
    template<typename genType>
    inline genType degrees(genType radians);

    template<length_t L, typename T>
    inline vec<L, T> degrees(const vec<L, T>& radians);

    /*------------------------------ Function: radians ------------------------------*/
    template<typename genType>
    inline genType radians(genType degrees);

    template<length_t L, typename T>
    inline vec<L, T> radians(const vec<L, T>& degrees);

    /*------------------------------ Function: sin ------------------------------*/
    template<typename genType>
    inline genType sin(genType x);

    template<length_t L, typename T>
    inline vec<L, T> sin(const vec<L, T>& x);

    /*------------------------------ Function: sinh ------------------------------*/
    template<typename genType>
    inline genType sinh(genType x);

    template<length_t L, typename T>
    inline vec<L, T> sinh(const vec<L, T>& x);

    /*------------------------------ Function: tan ------------------------------*/
    template<typename genType>
    inline genType tan(genType x);

    template<length_t L, typename T>
    inline vec<L, T> tan(const vec<L, T>& x);

    /*------------------------------ Function: tanh ------------------------------*/
    template<typename genType>
    inline genType tanh(genType x);

    template<length_t L, typename T>
    inline vec<L, T> tanh(const vec<L, T>& x);
}
