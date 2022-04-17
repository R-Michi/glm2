/**
* @file     exponential.h
* @brief    Detailed declaration of all exponential functions.
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
            namespace exponential
            {
                namespace exp
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

                namespace exp2
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

                namespace fastInversesqrt
                {
                    inline float _default_f(float x);
                    inline __m128 _default_fv(__m128 x);
                }

                namespace inversesqrt
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace log
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

                namespace log2
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

                namespace pow
                {
                    inline float _default_f(float base, float exponent);
                    inline double _default_d(double base, double exponent);
                    inline __m128 _default_fv2(__m128 base, float exponent);
                    inline __m128 _default_fv2(__m128 base, __m128 exponent);
                    inline __m128 _default_fv3(__m128 base, float exponent);
                    inline __m128 _default_fv3(__m128 base, __m128 exponent);
                    inline __m128 _default_fv4(__m128 base, float exponent);
                    inline __m128 _default_fv4(__m128 base, __m128 exponent);
                    inline __m128d _default_dv2(__m128d base, double exponent);
                    inline __m128d _default_dv2(__m128d base, __m128d exponent);
                    inline __m256d _default_dv3(__m256d base, double exponent);
                    inline __m256d _default_dv3(__m256d base, __m256d exponent);
                    inline __m256d _default_dv4(__m256d base, double exponent);
                    inline __m256d _default_dv4(__m256d base, __m256d exponent);
                }

                namespace sqrt
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }
            }
        }
    }
}

#include "exp_impl.inl"
#include "exp2_impl.inl"
#include "fastInversesquare_impl.inl"
#include "inversesquare_impl.inl"
#include "log_impl.inl"
#include "log2_impl.inl"
#include "pow_impl.inl"
#include "sqrt_impl.inl"
