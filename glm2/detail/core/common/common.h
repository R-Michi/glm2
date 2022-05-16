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
                    template<typename T>
                    inline T _default(T x);
                    inline float _default_f(float x);
                    inline double _default_d(double x);
                    inline int32_t _default_i32(int32_t x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                    inline __m128i _default_i32v(__m128i x);
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
                    inline int32_t _default_i32(int32_t x, int32_t minVal, int32_t maxVal);
                    inline uint32_t _default_u32(uint32_t x, uint32_t minVal, uint32_t maxVal);
                    inline __m128 _default_fv(__m128 x, __m128 minVal, __m128 maxVal);
                    inline __m128d _default_dv2(__m128d x, __m128d minVal, __m128d maxVal);
                    inline __m256d _default_dv(__m256d x, __m256d minVal, __m256d maxVal);
                    inline __m128i _default_i32v(__m128i x, __m128i minVal, __m128i maxVal);
                    inline __m128i _default_u32v(__m128i x, __m128i minVal, __m128i maxVal);
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

                namespace frexp
                {
                    template<typename T>
                    inline void _default(const T* x, T* fract, int32_t* exp, uint32_t n);
                }

                namespace ldexp
                {
                    template<typename T>
                    inline void _default(const T* x, T* fract, int32_t* exp, uint32_t n);
                }

                namespace max
                {
                    inline float _default_f(float x, float y);
                    inline double _default_d(double x, double y);
                    inline int32_t _default_i32(int32_t x, int32_t y);
                    inline uint32_t _default_u32(uint32_t x, uint32_t y);
                    inline __m128 _default_fv(__m128 x, __m128 y);
                    inline __m128d _default_dv2(__m128d x, __m128d y);
                    inline __m256d _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                    inline __m128i _default_u32v(__m128i x, __m128i y);
                }

                namespace min
                {
                    inline float _default_f(float x, float y);
                    inline double _default_d(double x, double y);
                    inline int32_t _default_i32(int32_t x, int32_t y);
                    inline uint32_t _default_u32(uint32_t x, uint32_t y);
                    inline __m128 _default_fv(__m128 x, __m128 y);
                    inline __m128d _default_dv2(__m128d x, __m128d y);
                    inline __m256d _default_dv(__m256d x, __m256d y);
                    inline __m128i _default_i32v(__m128i x, __m128i y);
                    inline __m128i _default_u32v(__m128i x, __m128i y);
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

                namespace modf
                {
                    inline float _default_f(float x, float* i);
                    inline double _default_d(double x, double* i);
                    inline __m128 _default_fv(__m128 x, __m128* i);
                    inline __m128d _default_dv2(__m128d x, __m128d* i);
                    inline __m256d _default_dv(__m256d x, __m256d* i);
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
                    inline int32_t _default_i32(int32_t x);
                    inline __m128 _default_fv(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv(__m256d x);
                    inline __m128i _default_i32v(__m128i x);
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

                namespace isinf
                {
                    inline bool _default_f(float x);
                    inline bool _default_d(double x);
                    inline __m128i _default_fv(__m128 x);
                    inline __m128i _default_dv2(__m128d x);
                    inline __m128i _default_dv(__m256d x);
                }

                namespace isnan
                {
                    inline bool _default_f(float x);
                    inline bool _default_d(double x);
                    inline __m128i _default_fv(__m128 x);
                    inline __m128i _default_dv2(__m128d x);
                    inline __m128i _default_dv(__m256d x);
                }

                namespace floatBitsToInt
                {
                    inline int32_t _default_i32(float x);
                    inline __m128i _default_i32v(__m128 x);
                }

                namespace floatBitsToUint
                {
                    inline uint32_t _default_u32(float x);
                    inline __m128i _default_u32v(__m128 x);
                }

                namespace intBitsToFloat
                {
                    inline float _default_f(int32_t x);
                    inline __m128 _default_fv(__m128i x);
                }

                namespace uintBitsToFloat
                {
                    inline float _default_f(uint32_t x);
                    inline __m128 _default_fv(__m128i x);
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
#include "frexp_impl.inl"
#include "ldexp_impl.inl"
#include "max_impl.inl"
#include "min_impl.inl"
#include "mix_impl.inl"
#include "mod_impl.inl"
#include "modf_impl.inl"
#include "round_impl.inl"
#include "roundEven_impl.inl"
#include "sign_impl.inl"
#include "smoothstep_impl.inl"
#include "step_impl.inl"
#include "trunc_impl.inl"
#include "isinf_impl.inl"
#include "isnan_impl.inl"
#include "floatBitsToInt_impl.inl"
#include "floatBitsToUint_impl.inl"
#include "intBitsToFloat_impl.inl"
#include "uintBitsToFloat_impl.inl"
