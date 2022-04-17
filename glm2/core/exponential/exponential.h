/**
* @file     exponential.h
* @brief    Template specialization of all exponential functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "exponential_base.h"
#include "../../detail/core/exponential/exponential.h"

namespace glm2
{
    /*------------------------------ Function: exp ------------------------------*/
    template<> inline float exp(float x);
    template<> inline double exp(double x);


    template<> inline vec<2, float> exp(const vec<2, float>& x);
    template<> inline vec<3, float> exp(const vec<3, float>& x);
    template<> inline vec<4, float> exp(const vec<4, float>& x);

    template<> inline vec<2, double> exp(const vec<2, double>& x);
    template<> inline vec<3, double> exp(const vec<3, double>& x);
    template<> inline vec<4, double> exp(const vec<4, double>& x);

    /*------------------------------ Function: exp2 ------------------------------*/
    template<> inline float exp2(float x);
    template<> inline double exp2(double x);


    template<> inline vec<2, float> exp2(const vec<2, float>& x);
    template<> inline vec<3, float> exp2(const vec<3, float>& x);
    template<> inline vec<4, float> exp2(const vec<4, float>& x);

    template<> inline vec<2, double> exp2(const vec<2, double>& x);
    template<> inline vec<3, double> exp2(const vec<3, double>& x);
    template<> inline vec<4, double> exp2(const vec<4, double>& x);

    /*------------------------------ Function: inversesqrt ------------------------------*/
    template<> inline float fastInversesqrt(float x);

    template<> inline vec<2, float> fastInversesqrt(const vec<2, float>& x);
    template<> inline vec<3, float> fastInversesqrt(const vec<3, float>& x);
    template<> inline vec<4, float> fastInversesqrt(const vec<4, float>& x);

    /*------------------------------ Function: fastInversesqrt ------------------------------*/
    template<> inline float inversesqrt(float x);
    template<> inline double inversesqrt(double x);


    template<> inline vec<2, float> inversesqrt(const vec<2, float>& x);
    template<> inline vec<3, float> inversesqrt(const vec<3, float>& x);
    template<> inline vec<4, float> inversesqrt(const vec<4, float>& x);

    template<> inline vec<2, double> inversesqrt(const vec<2, double>& x);
    template<> inline vec<3, double> inversesqrt(const vec<3, double>& x);
    template<> inline vec<4, double> inversesqrt(const vec<4, double>& x);

    /*------------------------------ Function: log ------------------------------*/
    template<> inline float log(float x);
    template<> inline double log(double x);


    template<> inline vec<2, float> log(const vec<2, float>& x);
    template<> inline vec<3, float> log(const vec<3, float>& x);
    template<> inline vec<4, float> log(const vec<4, float>& x);

    template<> inline vec<2, double> log(const vec<2, double>& x);
    template<> inline vec<3, double> log(const vec<3, double>& x);
    template<> inline vec<4, double> log(const vec<4, double>& x);

    /*------------------------------ Function: log2 ------------------------------*/
    template<> inline float log2(float x);
    template<> inline double log2(double x);


    template<> inline vec<2, float> log2(const vec<2, float>& x);
    template<> inline vec<3, float> log2(const vec<3, float>& x);
    template<> inline vec<4, float> log2(const vec<4, float>& x);

    template<> inline vec<2, double> log2(const vec<2, double>& x);
    template<> inline vec<3, double> log2(const vec<3, double>& x);
    template<> inline vec<4, double> log2(const vec<4, double>& x);

    /*------------------------------ Function: pow ------------------------------*/
    template<> inline float pow(float base, float exponent);
    template<> inline double pow(double base, double exponent);


    template<> inline vec<2, float> pow(const vec<2, float>& base, float exponent);
    template<> inline vec<3, float> pow(const vec<3, float>& base, float exponent);
    template<> inline vec<4, float> pow(const vec<4, float>& base, float exponent);

    template<> inline vec<2, double> pow(const vec<2, double>& base, double exponent);
    template<> inline vec<3, double> pow(const vec<3, double>& base, double exponent);
    template<> inline vec<4, double> pow(const vec<4, double>& base, double exponent);


    template<> inline vec<2, float> pow(const vec<2, float>& base, const vec<2, float>& exponent);
    template<> inline vec<3, float> pow(const vec<3, float>& base, const vec<3, float>& exponent);
    template<> inline vec<4, float> pow(const vec<4, float>& base, const vec<4, float>& exponent);

    template<> inline vec<2, double> pow(const vec<2, double>& base, const vec<2, double>& exponent);
    template<> inline vec<3, double> pow(const vec<3, double>& base, const vec<3, double>& exponent);
    template<> inline vec<4, double> pow(const vec<4, double>& base, const vec<4, double>& exponent);

    /*------------------------------ Function: sqrt ------------------------------*/
    template<> inline float sqrt(float x);
    template<> inline double sqrt(double x);


    template<> inline vec<2, float> sqrt(const vec<2, float>& x);
    template<> inline vec<3, float> sqrt(const vec<3, float>& x);
    template<> inline vec<4, float> sqrt(const vec<4, float>& x);

    template<> inline vec<2, double> sqrt(const vec<2, double>& x);
    template<> inline vec<3, double> sqrt(const vec<3, double>& x);
    template<> inline vec<4, double> sqrt(const vec<4, double>& x);
}

#include "exp_impl.inl"
#include "exp2_impl.inl"
#include "fastInversesquare_impl.inl"
#include "inversesquare_impl.inl"
#include "log_impl.inl"
#include "log2_impl.inl"
#include "pow_impl.inl"
#include "sqrt_impl.inl"
