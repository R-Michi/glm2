/**
* @file     geometric_base.h
* @brief    Declaration of all geometric functions.
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
    /*------------------------------ Function: cross ------------------------------*/
    template<typename T>
    inline vec<3, T> cross(const vec<3, T>& x, const vec<3, T>& y);

    /*------------------------------ Function: distance ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> distance(const vec<L, T>& p0, const vec<L, T>& p1);

    /*------------------------------ Function: dot ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> dot(const vec<L, T>& x, const vec<L, T>& y);

    /*------------------------------ Function: faceforward ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> faceforward(const vec<L, T>& n, const vec<L, T>& i, const vec<L, T>& nref);

    /*------------------------------ Function: length ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> length(const vec<L, T>& x);

    /*------------------------------ Function: normalize ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> normalize(const vec<L, T>& x);

    /*------------------------------ Function: fastNormalize ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> fastNormalize(const vec<L, T>& x);

    /*------------------------------ Function: reflect ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> reflect(const vec<L, T>& i, const vec<L, T>& n);

    /*------------------------------ Function: refract ------------------------------*/
    template<length_t L, typename T>
    inline vec<L, T> refract(const vec<L, T>& i, const vec<L, T>& n, T eta);
}
