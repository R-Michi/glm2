/**
* @file     geometric.h
* @brief    Template specialization of all geometric functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "geometric_base.h"
#include "../../detail/core/geometric/geometric.h"

namespace glm2
{
    /*------------------------------ Function: cross ------------------------------*/
    template<> inline vec<3, float> cross(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<3, double> cross(const vec<3, double>& x, const vec<3, double>& y);

    /*------------------------------ Function: distance ------------------------------*/
    template<> inline vec<2, float> distance(const vec<2, float>& p0, const vec<2, float>& p1);
    template<> inline vec<3, float> distance(const vec<3, float>& p0, const vec<3, float>& p1);
    template<> inline vec<4, float> distance(const vec<4, float>& p0, const vec<4, float>& p1);

    template<> inline vec<2, double> distance(const vec<2, double>& p0, const vec<2, double>& p1);
    template<> inline vec<3, double> distance(const vec<3, double>& p0, const vec<3, double>& p1);
    template<> inline vec<4, double> distance(const vec<4, double>& p0, const vec<4, double>& p1);

    /*------------------------------ Function: dot ------------------------------*/
    template<> inline vec<2, float> dot(const vec<2, float>& x, const vec<2, float>& y);
    template<> inline vec<3, float> dot(const vec<3, float>& x, const vec<3, float>& y);
    template<> inline vec<4, float> dot(const vec<4, float>& x, const vec<4, float>& y);

    template<> inline vec<2, double> dot(const vec<2, double>& x, const vec<2, double>& y);
    template<> inline vec<3, double> dot(const vec<3, double>& x, const vec<3, double>& y);
    template<> inline vec<4, double> dot(const vec<4, double>& x, const vec<4, double>& y);

    /*------------------------------ Function: faceforward ------------------------------*/
    template<> inline vec<2, float> faceforward(const vec<2, float>& n, const vec<2, float>& i, const vec<2, float>& nref);
    template<> inline vec<3, float> faceforward(const vec<3, float>& n, const vec<3, float>& i, const vec<3, float>& nref);
    template<> inline vec<4, float> faceforward(const vec<4, float>& n, const vec<4, float>& i, const vec<4, float>& nref);

    template<> inline vec<2, double> faceforward(const vec<2, double>& n, const vec<2, double>& i, const vec<2, double>& nref);
    template<> inline vec<3, double> faceforward(const vec<3, double>& n, const vec<3, double>& i, const vec<3, double>& nref);
    template<> inline vec<4, double> faceforward(const vec<4, double>& n, const vec<4, double>& i, const vec<4, double>& nref);

    /*------------------------------ Function: length ------------------------------*/
    template<> inline vec<2, float> length(const vec<2, float>& x);
    template<> inline vec<3, float> length(const vec<3, float>& x);
    template<> inline vec<4, float> length(const vec<4, float>& x);

    template<> inline vec<2, double> length(const vec<2, double>& x);
    template<> inline vec<3, double> length(const vec<3, double>& x);
    template<> inline vec<4, double> length(const vec<4, double>& x);

    /*------------------------------ Function: normalize ------------------------------*/
    template<> inline vec<2, float> normalize(const vec<2, float>& x);
    template<> inline vec<3, float> normalize(const vec<3, float>& x);
    template<> inline vec<4, float> normalize(const vec<4, float>& x);

    template<> inline vec<2, double> normalize(const vec<2, double>& x);
    template<> inline vec<3, double> normalize(const vec<3, double>& x);
    template<> inline vec<4, double> normalize(const vec<4, double>& x);

    /*------------------------------ Function: fastNormalize ------------------------------*/
    template<> inline vec<2, float> fastNormalize(const vec<2, float>& x);
    template<> inline vec<3, float> fastNormalize(const vec<3, float>& x);
    template<> inline vec<4, float> fastNormalize(const vec<4, float>& x);

    /*------------------------------ Function: reflect ------------------------------*/         // TODO: !!! its slower than the traditional glm version !!!
    template<> inline vec<2, float> reflect(const vec<2, float>& i, const vec<2, float>& n);
    template<> inline vec<3, float> reflect(const vec<3, float>& i, const vec<3, float>& n);
    template<> inline vec<4, float> reflect(const vec<4, float>& i, const vec<4, float>& n);

    template<> inline vec<2, double> reflect(const vec<2, double>& i, const vec<2, double>& n);
    template<> inline vec<3, double> reflect(const vec<3, double>& i, const vec<3, double>& n);
    template<> inline vec<4, double> reflect(const vec<4, double>& i, const vec<4, double>& n);

    /*------------------------------ Function: refract ------------------------------*/
    template<> inline vec<2, float> refract(const vec<2, float>& i, const vec<2, float>& n, float eta);         
    template<> inline vec<3, float> refract(const vec<3, float>& i, const vec<3, float>& n, float eta);
    template<> inline vec<4, float> refract(const vec<4, float>& i, const vec<4, float>& n, float eta);

    template<> inline vec<2, double> refract(const vec<2, double>& i, const vec<2, double>& n, double eta);
    template<> inline vec<3, double> refract(const vec<3, double>& i, const vec<3, double>& n, double eta);
    template<> inline vec<4, double> refract(const vec<4, double>& i, const vec<4, double>& n, double eta);
}

#include "cross_impl.inl"
#include "distance_impl.inl"
#include "dot_impl.inl"
#include "faceforward_impl.inl"
#include "length_impl.inl"
#include "normalize_impl.inl"
#include "fastNormalize_impl.inl"
#include "reflect_impl.inl"
#include "refract_impl.inl"
