/**
* @file     geometric.h
* @brief    Detailed declaration of all geometric functions.
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
            namespace geometric
            {
                namespace cross
                {
                    inline __m128 _default_fv3(__m128 x, __m128 y);
                    inline __m256d _default_dv3(__m256d x, __m256d y);
                }

                namespace distance
                {
                    /* Implementation that works the fastest according to my testings. All vector compomemts contain the result. */
                    inline __m128 _default_fv2(__m128 p0, __m128 p1);
                    inline __m128 _default_fv3(__m128 p0, __m128 p1);
                    inline __m128 _default_fv4(__m128 p0, __m128 p1);
                    inline __m128d _default_dv2(__m128d p0, __m128d p1);
                    inline __m256d _default_dv3(__m256d p0, __m256d p1);
                    inline __m256d _default_dv4(__m256d p0, __m256d p1);

                    /* Only the first component contains the result. */
                    inline __m128d _single_dv3(__m256d p0, __m256d p1);
                    inline __m128d _single_dv4(__m256d p0, __m256d p1);

                    /* Alternative implementation with dedicated dot-product instruction. All vector compomemts contain the result. */
                    inline __m128 _alternative_fv2(__m128 p0, __m128 p1);
                }

                namespace dot
                {
                    /* Implementation that works the fastest according to my testings. All vector compomemts contain the result. */
                    inline __m128 _default_fv2(__m128 x, __m128 y);
                    inline __m128 _default_fv3(__m128 x, __m128 y);
                    inline __m128 _default_fv4(__m128 x, __m128 y);
                    inline __m128d _default_dv2(__m128d x, __m128d y);
                    inline __m256d _default_dv3(__m256d x, __m256d y);
                    inline __m256d _default_dv4(__m256d x, __m256d y);

                    /* Alternative implementation with dedicated dot-product instruction. All compomemts contain the result. */
                    inline __m128 _alternative_fv2(__m128 x, __m128 y);
                    inline __m128 _alternative_fv3(__m128 x, __m128 y);
                    inline __m128 _alternative_fv4(__m128 x, __m128 y);
                    inline __m128d _alternative_dv2(__m128d x, __m128d y);
                }

                namespace faceforward
                {
                    /* Implementation that works the fastest according to my testings. */
                    inline __m128 _default_fv2(__m128 n, __m128 i, __m128 nref);
                    inline __m128 _default_fv3(__m128 n, __m128 i, __m128 nref);
                    inline __m128 _default_fv4(__m128 n, __m128 i, __m128 nref);
                    inline __m128d _default_dv2(__m128d n, __m128d i, __m128d nref);
                    inline __m256d _default_dv3(__m256d n, __m256d i, __m256d nref);
                    inline __m256d _default_dv4(__m256d n, __m256d i, __m256d nref);

                    /* Alternative implementation with dedicated dot-product instruction. */
                    inline __m128 _alternative_fv2(__m128 n, __m128 i, __m128 nref);
                    inline __m128 _alternative_fv3(__m128 n, __m128 i, __m128 nref);
                    inline __m128 _alternative_fv4(__m128 n, __m128 i, __m128 nref);
                    inline __m128d _alternative_dv2(__m128d n, __m128d i, __m128d nref);
                }

                namespace length
                {
                    /* Implementation that works the fastest according to my testings. All vector compomemts contain the result. */
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);

                    /* Only the first component contains the result. */
                    inline __m128d _single_dv3(__m256d x);
                    inline __m128d _single_dv4(__m256d x);

                    /* Alternative implementation with dedicated dot-product instruction. All vector compomemts contain the result. */
                    inline __m128 _alternative_fv2(__m128 x);
                }

                namespace normalize
                {
                    /* Implementation that works the fastest according to my testings. */
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);
                    inline __m128d _default_dv2(__m128d x);
                    inline __m256d _default_dv3(__m256d x);
                    inline __m256d _default_dv4(__m256d x);

                    /* Alternative implementation with dedicated dot-product instruction. */
                    inline __m128 _alternative_fv2(__m128 x);
                }

                namespace fastNormalize
                {
                    /* Implementation that works the fastest according to my testings. */
                    inline __m128 _default_fv2(__m128 x);
                    inline __m128 _default_fv3(__m128 x);
                    inline __m128 _default_fv4(__m128 x);

                    /* Alternative implementation with dedicated dot-product instruction. */
                    inline __m128 _alternative_fv2(__m128 x);
                }

                namespace reflect
                {
                    /* Implementation that works the fastest according to my testings. */
                    inline __m128 _default_fv2(__m128 i, __m128 n);
                    inline __m128 _default_fv3(__m128 i, __m128 n);
                    inline __m128 _default_fv4(__m128 i, __m128 n);
                    inline __m128d _default_dv2(__m128d i, __m128d n);
                    inline __m256d _default_dv3(__m256d i, __m256d n);
                    inline __m256d _default_dv4(__m256d i, __m256d n);

                    /* Alternative implementation with dedicated dot-product instruction. */
                    inline __m128 _alternative_fv2(__m128 i, __m128 n);
                    inline __m128 _alternative_fv3(__m128 i, __m128 n);
                    inline __m128 _alternative_fv4(__m128 i, __m128 n);
                    inline __m128d _alternative_dv2(__m128d i, __m128d n);
                }

                namespace refract
                {
                    /* Implementation that works the fastest according to my testings. */
                    inline __m128 _default_fv2(__m128 i, __m128 n, __m128 eta);
                    inline __m128 _default_fv3(__m128 i, __m128 n, __m128 eta);
                    inline __m128 _default_fv4(__m128 i, __m128 n, __m128 eta);
                    inline __m128d _default_dv2(__m128d i, __m128d n, __m128d eta);
                    inline __m256d _default_dv3(__m256d i, __m256d n, __m256d eta);
                    inline __m256d _default_dv4(__m256d i, __m256d n, __m256d eta);

                    /* Alternative implementation with dedicated dot-product instruction. */
                    inline __m128 _alternative_fv2(__m128 i, __m128 n, __m128 eta);
                    inline __m128 _alternative_fv3(__m128 i, __m128 n, __m128 eta);
                    inline __m128 _alternative_fv4(__m128 i, __m128 n, __m128 eta);
                    inline __m128d _alternative_dv2(__m128d i, __m128d n, __m128d eta);
                }
            }
        }
    }
}

#include "cross_impl.inl"
#include "dot_impl.inl"
#include "distance_impl.inl"
#include "faceforward_impl.inl"
#include "length_impl.inl"
#include "normalize_impl.inl"
#include "fastNormalize_impl.inl"
#include "reflect_impl.inl"
#include "refract_impl.inl"
