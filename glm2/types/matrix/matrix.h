/**
* @file     matrix.h
* @brief    Declatation of all matrix classes.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "matrix_base.h"
#include "../../detail/core/matrix/matrix.h"

namespace glm2
{
    // float matrices
    template<>
    class mat<2, 2, float>
    {
    public:
        using col_type = vec<2, float>;
        using row_type = vec<2, float>;
        using transpose_type = mat<2, 2, float>;

    private:
        alignas(8) col_type _M[2];

    public:

        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1,
                   float n1m0, float n1m1);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1);
        inline mat(const col_type* vv);
        inline mat(const __m64* m64v);
        inline mat(const __m128* m128v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m64* m64v);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);
        
        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;
        inline col_type operator/ (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<3, 2, float> operator* (const mat<3, 2, float>& M) const;
        inline mat<4, 2, float> operator* (const mat<4, 2, float>& M) const;
        inline mat operator* (const mat& M) const;
        inline mat operator/ (const mat& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat& M);
        inline mat& operator/= (const mat& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m64* intrin_ptr(mat& M);
        static inline __m64* intrin_ptr(mat* Mv);
        static inline const __m64* intrin_ptr(const mat& M);
        static inline const __m64* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<2, 3, float>
    {
    public:
        using col_type = vec<3, float>;
        using row_type = vec<2, float>;
        using transpose_type = mat<3, 2, float>;

    private:
        alignas(16) col_type _M[2];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1, float n0m2,
                   float n1m0, float n1m1, float n1m2);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1);
        inline mat(const col_type* vv);
        inline mat(const __m128* m128v);
        inline mat(const __m256* m256v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const __m256* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<3, 3, float> operator* (const mat<3, 2, float>& M) const;
        inline mat<4, 3, float> operator* (const mat<4, 2, float>& M) const;
        inline mat operator* (const mat<2, 2, float>& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<2, 2, float>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m128* intrin_ptr(mat& M);
        static inline __m128* intrin_ptr(mat* Mv);
        static inline const __m128* intrin_ptr(const mat& M);
        static inline const __m128* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<2, 4, float>
    {
    public:
        using col_type = vec<4, float>;
        using row_type = vec<2, float>;
        using transpose_type = mat<4, 2, float>;

    private:
        alignas(16) col_type _M[2];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1, float n0m2, float n0m3,
                   float n1m0, float n1m1, float n1m2, float n1m3);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1);
        inline mat(const col_type* vv);
        inline mat(const __m128* m128v);
        inline mat(const __m256* m256v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const __m256* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<3, 4, float> operator* (const mat<3, 2, float>& M) const;
        inline mat<4, 4, float> operator* (const mat<4, 2, float>& M) const;
        inline mat operator* (const mat<2, 2, float>& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<2, 2, float>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m128* intrin_ptr(mat& M);
        static inline __m128* intrin_ptr(mat* Mv);
        static inline const __m128* intrin_ptr(const mat& M);
        static inline const __m128* intrin_ptr(const mat* Mv);
    }; 

    template<>
    class mat<3, 2, float>
    {
    public:
        using col_type = vec<2, float>;
        using row_type = vec<3, float>;
        using transpose_type = mat<2, 3, float>;

    private:
        alignas(8) col_type _M[3];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1,
                   float n1m0, float n1m1,
                   float n2m0, float n2m1);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2);
        inline mat(const col_type* vv);
        inline mat(const __m64* m64v);
        inline mat(const __m128* m128v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m64* m64v);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 2, float> operator* (const mat<2, 3, float>& M) const;
        inline mat<4, 2, float> operator* (const mat<4, 3, float>& M) const;
        inline mat operator* (const mat<3, 3, float>& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<3, 3, float>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m64* intrin_ptr(mat& M);
        static inline __m64* intrin_ptr(mat* Mv);
        static inline const __m64* intrin_ptr(const mat& M);
        static inline const __m64* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<3, 3, float>
    {
    public:
        using col_type = vec<3, float>;
        using row_type = vec<3, float>;
        using transpose_type = mat<3, 3, float>;

    private:
        alignas(16) col_type _M[3];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1, float n0m2,
                   float n1m0, float n1m1, float n1m2,
                   float n2m0, float n2m1, float n2m2);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2);
        inline mat(const col_type* vv);
        inline mat(const __m128* m128v);
        inline mat(const __m256* m256v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const __m256* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;
        inline col_type operator/ (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 3, float> operator* (const mat<2, 3, float>& M) const;
        inline mat<4, 3, float> operator* (const mat<4, 3, float>& M) const;
        inline mat operator* (const mat& M) const;
        inline mat operator/ (const mat& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const mat& M);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat& M);
        inline mat& operator/= (const col_type& v);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m128* intrin_ptr(mat& M);
        static inline __m128* intrin_ptr(mat* Mv);
        static inline const __m128* intrin_ptr(const mat& M);
        static inline const __m128* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<3, 4, float>
    {
    public:
        using col_type = vec<4, float>;
        using row_type = vec<3, float>;
        using transpose_type = mat<4, 3, float>;

    private:
        alignas(16) col_type _M[3];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1, float n0m2, float n0m3,
                   float n1m0, float n1m1, float n1m2, float n1m3,
                   float n2m0, float n2m1, float n2m2, float n2m3);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2);
        inline mat(const col_type* vv);
        inline mat(const __m128* m128v);
        inline mat(const __m256* m256v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const __m256* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 4, float> operator* (const mat<2, 3, float>& M) const;
        inline mat<4, 4, float> operator* (const mat<4, 3, float>& M) const;
        inline mat operator* (const mat<3, 3, float>& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<3, 3, float>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m128* intrin_ptr(mat& M);
        static inline __m128* intrin_ptr(mat* Mv);
        static inline const __m128* intrin_ptr(const mat& M);
        static inline const __m128* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<4, 2, float>
    {
    public:
        using col_type = vec<2, float>;
        using row_type = vec<4, float>;
        using transpose_type = mat<2, 4, float>;

    private:
        alignas(8) col_type _M[4];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1,
                   float n1m0, float n1m1,
                   float n2m0, float n2m1,
                   float n3m0, float n3m1);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2,
                   const col_type& n3);
        inline mat(const col_type* vv);
        inline mat(const __m64* m64v);
        inline mat(const __m128* m128v);
        inline mat(const __m256* m256v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m64* m64v);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const __m256* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 2, float> operator* (const mat<2, 4, float>& M) const;
        inline mat<3, 2, float> operator* (const mat<3, 4, float>& M) const;
        inline mat operator* (const mat<4, 4, float>& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<4, 4, float>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m64* intrin_ptr(mat& M);
        static inline __m64* intrin_ptr(mat* Mv);
        static inline const __m64* intrin_ptr(const mat& M);
        static inline const __m64* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<4, 3, float>
    {
    public:
        using col_type = vec<3, float>;
        using row_type = vec<4, float>;
        using transpose_type = mat<3, 4, float>;

    private:
        alignas(16) col_type _M[4];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1, float n0m2,
                   float n1m0, float n1m1, float n1m2,
                   float n2m0, float n2m1, float n2m2,
                   float n3m0, float n3m1, float n3m2);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2,
                   const col_type& n3);
        inline mat(const col_type* vv);
        inline mat(const __m128* m128v);
        inline mat(const __m256* m256v);
        inline mat(const mat& M);

        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const __m256* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 3, float> operator* (const mat<2, 4, float>& M) const;
        inline mat<3, 3, float> operator* (const mat<3, 4, float>& M) const;
        inline mat operator* (const mat<4, 4, float>& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<4, 4, float>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m128* intrin_ptr(mat& M);
        static inline __m128* intrin_ptr(mat* Mv);
        static inline const __m128* intrin_ptr(const mat& M);
        static inline const __m128* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<4, 4, float>
    {
    public:
        using col_type = vec<4, float>;
        using row_type = vec<4, float>;
        using transpose_type = mat<4, 4, float>;

    private:
        alignas(16) col_type _M[4];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(float f);
        inline mat(float n0m0, float n0m1, float n0m2, float n0m3,
                   float n1m0, float n1m1, float n1m2, float n1m3,
                   float n2m0, float n2m1, float n2m2, float n2m3,
                   float n3m0, float n3m1, float n3m2, float n3m3);
        inline mat(const float* fv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2,
                   const col_type& n3);
        inline mat(const col_type* vv);
        inline mat(const __m128* m128v);
        inline mat(const __m256* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (float f);
        inline mat& operator= (const float* fv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128* m128v);
        inline mat& operator= (const __m256* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (float f) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (float f) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (float f) const;
        inline mat operator/ (float f) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;
        inline col_type operator/ (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 4, float> operator* (const mat<2, 4, float>& M) const;
        inline mat<3, 4, float> operator* (const mat<3, 4, float>& M) const;
        inline mat operator* (const mat& M) const;
        inline mat operator/ (const mat& M) const;

        /* assignment operators */
        inline mat& operator+= (float f);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (float f);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (float f);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (float f);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat& M);
        inline mat& operator/= (const mat& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline float* value_ptr(mat& M);
        static inline float* value_ptr(mat* Mv);
        static inline const float* value_ptr(const mat& M);
        static inline const float* value_ptr(const mat* Mv);
        static inline __m128* intrin_ptr(mat& M);
        static inline __m128* intrin_ptr(mat* Mv);
        static inline const __m128* intrin_ptr(const mat& M);
        static inline const __m128* intrin_ptr(const mat* Mv);
    };

    // double matrices
    template<>
    class mat<2, 2, double>
    {
    public:
        using col_type = vec<2, double>;
        using row_type = vec<2, double>;
        using transpose_type = mat<2, 2, double>;

    private:
        alignas(16) col_type _M[2];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1,
                   double n1m0, double n1m1);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1);
        inline mat(const col_type* vv);
        inline mat(const __m128d* m128v);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128d* m128v);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;
        inline col_type operator/ (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<3, 2, double> operator* (const mat<3, 2, double>& M) const;
        inline mat<4, 2, double> operator* (const mat<4, 2, double>& M) const;
        inline mat operator* (const mat& M) const;
        inline mat operator/ (const mat& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat& M);
        inline mat& operator/= (const mat& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m128d* intrin_ptr(mat& M);
        static inline __m128d* intrin_ptr(mat* Mv);
        static inline const __m128d* intrin_ptr(const mat& M);
        static inline const __m128d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<2, 3, double>
    {
    public:
        using col_type = vec<3, double>;
        using row_type = vec<2, double>;
        using transpose_type = mat<3, 2, double>;

    private:
        alignas(32) col_type _M[2];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1, double n0m2,
                   double n1m0, double n1m1, double n1m2);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1);
        inline mat(const col_type* vv);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<3, 3, double> operator* (const mat<3, 2, double>& M) const;
        inline mat<4, 3, double> operator* (const mat<4, 2, double>& M) const;
        inline mat operator* (const mat<2, 2, double>& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<2, 2, double>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m256d* intrin_ptr(mat& M);
        static inline __m256d* intrin_ptr(mat* Mv);
        static inline const __m256d* intrin_ptr(const mat& M);
        static inline const __m256d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<2, 4, double>
    {
    public:
        using col_type = vec<4, double>;
        using row_type = vec<2, double>;
        using transpose_type = mat<4, 2, double>;

    private:
        alignas(32) col_type _M[2];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1, double n0m2, double n0m3,
                   double n1m0, double n1m1, double n1m2, double n1m3);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1);
        inline mat(const col_type* vv);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<3, 4, double> operator* (const mat<3, 2, double>& M) const;
        inline mat<4, 4, double> operator* (const mat<4, 2, double>& M) const;
        inline mat operator* (const mat<2, 2, double>& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<2, 2, double>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m256d* intrin_ptr(mat& M);
        static inline __m256d* intrin_ptr(mat* Mv);
        static inline const __m256d* intrin_ptr(const mat& M);
        static inline const __m256d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<3, 2, double>
    {
    public:
        using col_type = vec<2, double>;
        using row_type = vec<3, double>;
        using transpose_type = mat<2, 3, double>;

    private:
        alignas(16) col_type _M[3];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1,
                   double n1m0, double n1m1,
                   double n2m0, double n2m1);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2);
        inline mat(const col_type* vv);
        inline mat(const __m128d* m128v);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128d* m128v);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 2, double> operator* (const mat<2, 3, double>& M) const;
        inline mat<4, 2, double> operator* (const mat<4, 3, double>& M) const;
        inline mat operator* (const mat<3, 3, double>& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<3, 3, double>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m128d* intrin_ptr(mat& M);
        static inline __m128d* intrin_ptr(mat* Mv);
        static inline const __m128d* intrin_ptr(const mat& M);
        static inline const __m128d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<3, 3, double>
    {
    public:
        using col_type = vec<3, double>;
        using row_type = vec<3, double>;
        using transpose_type = mat<3, 3, double>;

    private:
        alignas(32) col_type _M[3];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1, double n0m2,
                   double n1m0, double n1m1, double n1m2,
                   double n2m0, double n2m1, double n2m2);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2);
        inline mat(const col_type* vv);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;
        inline col_type operator/ (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 3, double> operator* (const mat<2, 3, double>& M) const;
        inline mat<4, 3, double> operator* (const mat<4, 3, double>& M) const;
        inline mat operator* (const mat& M) const;
        inline mat operator/ (const mat& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat& M);
        inline mat& operator/= (const mat& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m256d* intrin_ptr(mat& M);
        static inline __m256d* intrin_ptr(mat* Mv);
        static inline const __m256d* intrin_ptr(const mat& M);
        static inline const __m256d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<3, 4, double>
    {
    public:
        using col_type = vec<4, double>;
        using row_type = vec<3, double>;
        using transpose_type = mat<4, 3, double>;

    private:
        alignas(32) col_type _M[3];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1, double n0m2, double n0m3,
                   double n1m0, double n1m1, double n1m2, double n1m3,
                   double n2m0, double n2m1, double n2m2, double n2m3);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2);
        inline mat(const col_type* vv);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 4, double> operator* (const mat<2, 3, double>& M) const;
        inline mat<4, 4, double> operator* (const mat<4, 3, double>& M) const;
        inline mat operator* (const mat<3, 3, double>& M) const;
        inline mat operator* (const mat& M) const = delete;
        inline mat operator/ (const mat& M) const = delete;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<3, 3, double>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;


        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m256d* intrin_ptr(mat& M);
        static inline __m256d* intrin_ptr(mat* Mv);
        static inline const __m256d* intrin_ptr(const mat& M);
        static inline const __m256d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<4, 2, double>
    {
    public:
        using col_type = vec<2, double>;
        using row_type = vec<4, double>;
        using transpose_type = mat<2, 4, double>;

    private:
        alignas(16) col_type _M[4];

        public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1,
                   double n1m0, double n1m1,
                   double n2m0, double n2m1,
                   double n3m0, double m3n1);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2,
                   const col_type& n3);
        inline mat(const col_type* vv);
        inline mat(const __m128d* m128v);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m128d* m128v);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 2, double> operator* (const mat<2, 4, double>& M) const;
        inline mat<3, 2, double> operator* (const mat<3, 4, double>& M) const;
        inline mat operator* (const mat<4, 4, double>& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<4, 4, double>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m128d* intrin_ptr(mat& M);
        static inline __m128d* intrin_ptr(mat* Mv);
        static inline const __m128d* intrin_ptr(const mat& M);
        static inline const __m128d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<4, 3, double>
    {
    public:
        using col_type = vec<3, double>;
        using row_type = vec<4, double>;
        using transpose_type = mat<3, 4, double>;

    private:
        alignas(32) col_type _M[4];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1, double n0m2,
                   double n1m0, double n1m1, double n1m2,
                   double n2m0, double n2m1, double n2m2,
                   double n3m0, double n3m1, double n3m2);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2,
                   const col_type& n3);
        inline mat(const col_type* vv);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 3, double> operator* (const mat<2, 4, double>& M) const;
        inline mat<3, 3, double> operator* (const mat<3, 4, double>& M) const;
        inline mat operator* (const mat<4, 4, double>& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat<4, 4, double>& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m256d* intrin_ptr(mat& M);
        static inline __m256d* intrin_ptr(mat* Mv);
        static inline const __m256d* intrin_ptr(const mat& M);
        static inline const __m256d* intrin_ptr(const mat* Mv);
    };

    template<>
    class mat<4, 4, double>
    {
    public:
        using col_type = vec<4, double>;
        using row_type = vec<4, double>;
        using transpose_type = mat<4, 4, double>;

    private:
        alignas(32) col_type _M[4];

    public:
        /* default constructors */
        inline mat(void);
        inline mat(double d);
        inline mat(double n0m0, double n0m1, double n0m2, double n0m3,
                   double n1m0, double n1m1, double n1m2, double n1m3,
                   double n2m0, double n2m1, double n2m2, double n2m3,
                   double n3m0, double n3m1, double n3m2, double n3m3);
        inline mat(const double* dv);
        inline mat(const col_type& n0,
                   const col_type& n1,
                   const col_type& n2,
                   const col_type& n3);
        inline mat(const col_type* vv);
        inline mat(const __m256d* m256v);
        inline mat(const mat& M);
        
        /* destructor */
        ~mat(void) = default;

        /* default copy operators */
        inline mat& operator= (double d);
        inline mat& operator= (const double* dv);
        inline mat& operator= (const col_type* vv);
        inline mat& operator= (const __m256d* m256v);
        inline mat& operator= (const mat& M);

        /* copare operators */
        inline bool operator== (const mat& M) const;
        inline bool operator!= (const mat& M) const;

        /* arithmetic operators */
        inline mat operator+ (double d) const;
        inline mat operator+ (const col_type& v) const;
        inline mat operator+ (const mat& M) const;
        inline mat operator- (double d) const;
        inline mat operator- (const col_type& v) const;
        inline mat operator- (const mat& M) const;
        inline mat operator* (double d) const;
        inline mat operator/ (double d) const;
        inline mat operator+ (void) const;
        inline mat operator- (void) const;
        inline mat operator++ (int);
        inline mat& operator++ (void);
        inline mat operator-- (int);
        inline mat& operator-- (void);

        // matrix - vector multiplication and division
        inline col_type operator* (const row_type& v) const;
        inline col_type operator/ (const row_type& v) const;

        // matrix - matrix multiplication and division
        inline mat<2, 4, double> operator* (const mat<2, 4, double>& M) const;
        inline mat<3, 4, double> operator* (const mat<3, 4, double>& M) const;
        inline mat operator* (const mat& M) const;
        inline mat operator/ (const mat& M) const;

        /* assignment operators */
        inline mat& operator+= (double d);
        inline mat& operator+= (const col_type& v);
        inline mat& operator+= (const mat& M);
        inline mat& operator-= (double d);
        inline mat& operator-= (const col_type& v);
        inline mat& operator-= (const mat& M);
        inline mat& operator*= (double d);
        inline mat& operator*= (const col_type& v);
        inline mat& operator/= (double d);
        inline mat& operator/= (const col_type& v);

        // matrix - matrix multiplication and division (assigment operator)
        inline mat& operator*= (const mat& M);
        inline mat& operator/= (const mat& M);

        /* common operators and methods */
        inline col_type& operator[] (uint32_t i);
        inline const col_type& operator[] (uint32_t i) const;

        /* implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<2, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<3, 4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator mat<4, 3, double>(void) const;

        static inline double* value_ptr(mat& M);
        static inline double* value_ptr(mat* Mv);
        static inline const double* value_ptr(const mat& M);
        static inline const double* value_ptr(const mat* Mv);
        static inline __m256d* intrin_ptr(mat& M);
        static inline __m256d* intrin_ptr(mat* Mv);
        static inline const __m256d* intrin_ptr(const mat& M);
        static inline const __m256d* intrin_ptr(const mat* Mv);
    };

    template<length_t N, length_t M, typename T> 
    class mat
    {
        static_assert(detail::util::mat_false_helper<N, M, T>::value, "[glm2::mat]: Invalid matrix-type!");
    };
}

#include "mat2x2_impl.inl"
#include "mat2x3_impl.inl"
#include "mat2x4_impl.inl"
#include "mat3x2_impl.inl"
#include "mat3x3_impl.inl"
#include "mat3x4_impl.inl"
#include "mat4x2_impl.inl"
#include "mat4x3_impl.inl"
#include "mat4x4_impl.inl"
#include "dmat2x2_impl.inl"
#include "dmat2x3_impl.inl"
#include "dmat2x4_impl.inl"
#include "dmat3x2_impl.inl"
#include "dmat3x3_impl.inl"
#include "dmat3x4_impl.inl"
#include "dmat4x2_impl.inl"
#include "dmat4x3_impl.inl"
#include "dmat4x4_impl.inl"
