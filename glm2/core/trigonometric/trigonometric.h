/**
* @file     trigonometric.h
* @brief    Template specialization of all trigonometric functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "trigonometric_base.h"
#include "../../detail/core/trigonometric/trigonometric.h"

namespace glm2
{
    /*------------------------------ Function: acos ------------------------------*/
    template<> inline float acos(float x);
    template<> inline double acos(double x);


    template<> inline vec<2, float> acos(const vec<2, float>& x);
    template<> inline vec<3, float> acos(const vec<3, float>& x);
    template<> inline vec<4, float> acos(const vec<4, float>& x);

    template<> inline vec<2, double> acos(const vec<2, double>& x);
    template<> inline vec<3, double> acos(const vec<3, double>& x);
    template<> inline vec<4, double> acos(const vec<4, double>& x);

    /*------------------------------ Function: acosh ------------------------------*/
    template<> inline float acosh(float x);
    template<> inline double acosh(double x);


    template<> inline vec<2, float> acosh(const vec<2, float>& x);
    template<> inline vec<3, float> acosh(const vec<3, float>& x);
    template<> inline vec<4, float> acosh(const vec<4, float>& x);

    template<> inline vec<2, double> acosh(const vec<2, double>& x);
    template<> inline vec<3, double> acosh(const vec<3, double>& x);
    template<> inline vec<4, double> acosh(const vec<4, double>& x);

    /*------------------------------ Function: asin ------------------------------*/
    template<> inline float asin(float x);
    template<> inline double asin(double x);


    template<> inline vec<2, float> asin(const vec<2, float>& x);
    template<> inline vec<3, float> asin(const vec<3, float>& x);
    template<> inline vec<4, float> asin(const vec<4, float>& x);

    template<> inline vec<2, double> asin(const vec<2, double>& x);
    template<> inline vec<3, double> asin(const vec<3, double>& x);
    template<> inline vec<4, double> asin(const vec<4, double>& x);

    /*------------------------------ Function: asinh ------------------------------*/
    template<> inline float asinh(float x);
    template<> inline double asinh(double x);


    template<> inline vec<2, float> asinh(const vec<2, float>& x);
    template<> inline vec<3, float> asinh(const vec<3, float>& x);
    template<> inline vec<4, float> asinh(const vec<4, float>& x);

    template<> inline vec<2, double> asinh(const vec<2, double>& x);
    template<> inline vec<3, double> asinh(const vec<3, double>& x);
    template<> inline vec<4, double> asinh(const vec<4, double>& x);

    /*------------------------------ Function: atan ------------------------------*/
    template<> inline float atan(float x);
    template<> inline double atan(double x);


    template<> inline vec<2, float> atan(const vec<2, float>& x);
    template<> inline vec<3, float> atan(const vec<3, float>& x);
    template<> inline vec<4, float> atan(const vec<4, float>& x);

    template<> inline vec<2, double> atan(const vec<2, double>& x);
    template<> inline vec<3, double> atan(const vec<3, double>& x);
    template<> inline vec<4, double> atan(const vec<4, double>& x);

    /*------------------------------ Function: atanh ------------------------------*/
    template<> inline float atanh(float x);
    template<> inline double atanh(double x);


    template<> inline vec<2, float> atanh(const vec<2, float>& x);
    template<> inline vec<3, float> atanh(const vec<3, float>& x);
    template<> inline vec<4, float> atanh(const vec<4, float>& x);

    template<> inline vec<2, double> atanh(const vec<2, double>& x);
    template<> inline vec<3, double> atanh(const vec<3, double>& x);
    template<> inline vec<4, double> atanh(const vec<4, double>& x);

    /*------------------------------ Function: cos ------------------------------*/
    template<> inline float cos(float x);
    template<> inline double cos(double x);


    template<> inline vec<2, float> cos(const vec<2, float>& x);
    template<> inline vec<3, float> cos(const vec<3, float>& x);
    template<> inline vec<4, float> cos(const vec<4, float>& x);

    template<> inline vec<2, double> cos(const vec<2, double>& x);
    template<> inline vec<3, double> cos(const vec<3, double>& x);
    template<> inline vec<4, double> cos(const vec<4, double>& x);

    /*------------------------------ Function: cosh ------------------------------*/
    template<> inline float cosh(float x);
    template<> inline double cosh(double x);


    template<> inline vec<2, float> cosh(const vec<2, float>& x);
    template<> inline vec<3, float> cosh(const vec<3, float>& x);
    template<> inline vec<4, float> cosh(const vec<4, float>& x);

    template<> inline vec<2, double> cosh(const vec<2, double>& x);
    template<> inline vec<3, double> cosh(const vec<3, double>& x);
    template<> inline vec<4, double> cosh(const vec<4, double>& x);

    /*------------------------------ Function: degrees ------------------------------*/
    template<> inline float degrees(float radians);
    template<> inline double degrees(double radians);


    template<> inline vec<2, float> degrees(const vec<2, float>& radians);
    template<> inline vec<3, float> degrees(const vec<3, float>& radians);
    template<> inline vec<4, float> degrees(const vec<4, float>& radians);

    template<> inline vec<2, double> degrees(const vec<2, double>& radians);
    template<> inline vec<3, double> degrees(const vec<3, double>& radians);
    template<> inline vec<4, double> degrees(const vec<4, double>& radians);

    /*------------------------------ Function: radians ------------------------------*/
    template<> inline float radians(float degrees);
    template<> inline double radians(double degrees);


    template<> inline vec<2, float> radians(const vec<2, float>& degrees);
    template<> inline vec<3, float> radians(const vec<3, float>& degrees);
    template<> inline vec<4, float> radians(const vec<4, float>& degrees);

    template<> inline vec<2, double> radians(const vec<2, double>& degrees);
    template<> inline vec<3, double> radians(const vec<3, double>& degrees);
    template<> inline vec<4, double> radians(const vec<4, double>& degrees);

    /*------------------------------ Function: sin ------------------------------*/
    template<> inline float sin(float x);
    template<> inline double sin(double x);


    template<> inline vec<2, float> sin(const vec<2, float>& x);
    template<> inline vec<3, float> sin(const vec<3, float>& x);
    template<> inline vec<4, float> sin(const vec<4, float>& x);

    template<> inline vec<2, double> sin(const vec<2, double>& x);
    template<> inline vec<3, double> sin(const vec<3, double>& x);
    template<> inline vec<4, double> sin(const vec<4, double>& x);

    /*------------------------------ Function: sinh ------------------------------*/
    template<> inline float sinh(float x);
    template<> inline double sinh(double x);


    template<> inline vec<2, float> sinh(const vec<2, float>& x);
    template<> inline vec<3, float> sinh(const vec<3, float>& x);
    template<> inline vec<4, float> sinh(const vec<4, float>& x);

    template<> inline vec<2, double> sinh(const vec<2, double>& x);
    template<> inline vec<3, double> sinh(const vec<3, double>& x);
    template<> inline vec<4, double> sinh(const vec<4, double>& x);

    /*------------------------------ Function: tan ------------------------------*/
    template<> inline float tan(float x);
    template<> inline double tan(double x);


    template<> inline vec<2, float> tan(const vec<2, float>& x);
    template<> inline vec<3, float> tan(const vec<3, float>& x);
    template<> inline vec<4, float> tan(const vec<4, float>& x);

    template<> inline vec<2, double> tan(const vec<2, double>& x);
    template<> inline vec<3, double> tan(const vec<3, double>& x);
    template<> inline vec<4, double> tan(const vec<4, double>& x);

    /*------------------------------ Function: tanh ------------------------------*/
    template<> inline float tanh(float x);
    template<> inline double tanh(double x);


    template<> inline vec<2, float> tanh(const vec<2, float>& x);
    template<> inline vec<3, float> tanh(const vec<3, float>& x);
    template<> inline vec<4, float> tanh(const vec<4, float>& x);

    template<> inline vec<2, double> tanh(const vec<2, double>& x);
    template<> inline vec<3, double> tanh(const vec<3, double>& x);
    template<> inline vec<4, double> tanh(const vec<4, double>& x);

}

#include "acos_impl.inl"
#include "acosh_impl.inl"
#include "asin_impl.inl"
#include "asinh_impl.inl"
#include "atan_impl.inl"
#include "atanh_impl.inl"
#include "cos_impl.inl"
#include "cosh_impl.inl"
#include "degrees_impl.inl"
#include "radians_impl.inl"
#include "sin_impl.inl"
#include "sinh_impl.inl"
#include "tan_impl.inl"
#include "tanh_impl.inl"
