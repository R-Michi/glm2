/**
* @file     common.h
* @brief    Detailed declaration of all common functions.
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
            namespace common
            {
                namespace abs
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace ceil
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace clamp
                {
                    inline float _default_f(float x, float minVal, float maxVal);
                    inline double _default_d(double x, double minVal, double maxVal);
                    inline __m128 _default_fv(__m128 x, __m128 minVal, __m128 maxVal);
                    inline __m128d _default_dv2(__m128d x, __m128d minVal, __m128d maxVal);
                    inline __m256d _default_dv(__m256d x, __m256d minVal, __m256d maxVal);
                }

                namespace floor
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace fma
                {
                    inline float _default_f(float a, float b, float c);
                    inline double _default_d(double a, double b, double c);
                    inline __m128 _default_fv(__m128 a, __m128 b, __m128 c);
                    inline __m128d _default_dv2(__m128d a, __m128d b, __m128d c);
                    inline __m256d _default_dv(__m256d a, __m256d b, __m256d c);
                }

                namespace fms
                {
                    inline float _default_f(float a, float b, float c);
                    inline double _default_d(double a, double b, double c);
                    inline __m128 _default_fv(__m128 a, __m128 b, __m128 c);
                    inline __m128d _default_dv2(__m128d a, __m128d b, __m128d c);
                    inline __m256d _default_dv(__m256d a, __m256d b, __m256d c);
                }

                namespace fract
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace max
                {
                    inline float _default_f(float x, float y);
                    inline double _default_d(double x, double y);
                    inline __m128 _default_fv(__m128 x, __m128 y);
                    inline __m128d _default_dv2(__m128d x, __m128d y);
                    inline __m256d _default_dv(__m256d x, __m256d y);
                }

                namespace min
                {
                    inline float _default_f(float x, float y);
                    inline double _default_d(double x, double y);
                    inline __m128 _default_fv(__m128 x, __m128 y);
                    inline __m128d _default_dv2(__m128d x, __m128d y);
                    inline __m256d _default_dv(__m256d x, __m256d y);
                }

                namespace mix
                {
                    inline float _default_f(float x, float y, float a);
                    inline double _default_d(double x, double y, double a);
                    inline __m128 _default_fv(__m128 x, __m128 y, __m128 a);
                    inline __m128d _default_dv2(__m128d x, __m128d y, __m128d a);
                    inline __m256d _default_dv(__m256d x, __m256d y, __m256d a);
                }

                namespace mod
                {
                    inline float _default_f(float x, float y);
                    inline double _default_d(double x, double y);
                    inline __m128 _default_fv(__m128 x, __m128 y);
                    inline __m128d _default_dv2(__m128d x, __m128d y);
                    inline __m256d _default_dv(__m256d x, __m256d y);
                }

                namespace round
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace roundEven
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace sign
                {
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                }

                namespace smoothstep
                {
                    inline float _default_f(float edge0, float edge1, float x);
                    inline double _default_d(double edge0, double edge1, double x);
                    inline __m128 _default_fv(__m128 edge0, __m128 edge1, __m128 x);
                    inline __m128d _default_dv2(__m128d edge0, __m128d edge1, __m128d x);
                    inline __m256d _default_dv(__m256d edge0, __m256d edge1, __m256d x);
                }

                namespace step
                {
                    inline float _default_f(float edge, float x);
                    inline double _default_d(double edge, double x);
                    inline __m128 _default_fv(__m128 edge, __m128 x);
                    inline __m128d _default_dv2(__m128d edge, __m128d x);
                    inline __m256d _default_dv(__m256d edge, __m256d x);
                }

                namespace trunc
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

#include "abs_impl.inl"
#include "ceil_impl.inl"
#include "clamp_impl.inl"
#include "floor_impl.inl"
#include "fma_impl.inl"
#include "fms_impl.inl"
#include "fract_impl.inl"
#include "max_impl.inl"
#include "min_impl.inl"
#include "mix_impl.inl"
#include "mod_impl.inl"
#include "round_impl.inl"
#include "roundEven_impl.inl"
#include "sign_impl.inl"
#include "smoothstep_impl.inl"
#include "step_impl.inl"
#include "trunc_impl.inl"
