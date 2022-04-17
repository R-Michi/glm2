/**
* @file     exponantial_base.h
* @brief    Declaration of all exponential functions.
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
    /*------------------------------ Function: exp ------------------------------*/
    template<typename genType>
    inline genType exp(genType x);

    template<length_t L, typename T>
    inline vec<L, T> exp(const vec<L, T>& x);

    /*------------------------------ Function: exp2 ------------------------------*/
    template<typename genType>
    inline genType exp2(genType x);

    template<length_t L, typename T>
    inline vec<L, T> exp2(const vec<L, T>& x);

    /*------------------------------ Function: inversesqrt ------------------------------*/
    template<typename genType>
    inline genType inversesqrt(genType x);

    template<length_t L, typename T>
    inline vec<L, T> inversesqrt(const vec<L, T>& x);

    /*------------------------------ Function: fastInversesqrt ------------------------------*/
    template<typename genType>
    inline genType fastInversesqrt(genType x);

    template<length_t L, typename T>
    inline vec<L, T> fastInversesqrt(const vec<L, T>& x);

    /*------------------------------ Function: log ------------------------------*/
    template<typename genType>
    inline genType log(genType x);

    template<length_t L, typename T>
    inline vec<L, T> log(const vec<L, T>& x);

    /*------------------------------ Function: log2 ------------------------------*/
    template<typename genType>
    inline genType log2(genType x);

    template<length_t L, typename T>
    inline vec<L, T> log2(const vec<L, T>& x);

    /*------------------------------ Function: pow ------------------------------*/
    template<typename genType>
    inline genType pow(genType base, genType exponent);

    template<length_t L, typename T>
    inline vec<L, T> pow(const vec<L, T>& base, T exponent);

    template<length_t L, typename T>
    inline vec<L, T> pow(const vec<L, T>& base, const vec<L, T>& exponent);

    /*------------------------------ Function: sqrt ------------------------------*/
    template<typename genType>
    inline genType sqrt(genType x);

    template<length_t L, typename T>
    inline vec<L, T> sqrt(const vec<L, T>& x);
}
