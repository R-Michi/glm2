/**
* @file     trigonometric.h
* @brief    Detailed declaration of all trigonometric functions.
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
    namespace detail
    {
        namespace core
        {
            namespace trigonometric
            {
                namespace acos
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace acosh
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace asin
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace asinh
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace atan
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace atanh
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace cos
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace cosh
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace degrees
                {
                    inline float _default_f(float radians);
                    inline double _default_d(double radians);
                    inline __m128 _default_fv(__m128 radians);
                    inline __m128d _default_dv2(__m128d radians);
                    inline __m256d _default_dv(__m256d radians);
                }

                namespace radians
                {
                    inline float _default_f(float degrees);
                    inline double _default_d(double degrees);
                    inline __m128 _default_fv(__m128 degrees);
                    inline __m128d _default_dv2(__m128d degrees);
                    inline __m256d _default_dv(__m256d degrees);
                }

                namespace sin
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace sinh
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace tan
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }

                namespace tanh
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);
                }
            }
        }
    }
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
