/**
* @file     vector.h
* @brief    Declatation of all vector classes.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "vec_base.h"

namespace glm2
{
    /// float vectors
    template<>
    class vec<2, float>
    {
    private:
        alignas(8) __m64 _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(float f);
        inline vec(float x, float y);
        inline vec(const float* fv);
        inline vec(const __m64& v);
        inline vec(const __m128& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (float f);
        inline vec& operator= (const float* fv);
        inline vec& operator= (const __m64& v);
        inline vec& operator= (const __m128& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (float f) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (float f) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (float f) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (float f) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* assignment operators */
        inline vec& operator+= (float f);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (float f);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (float f);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (float f);
        inline vec& operator/= (const vec& v);

        /* common operators and methods */
        inline __m64 operator() (void) const;
        inline __m128 si128(void) const;
        inline float operator[] (uint32_t i) const;
        inline float insert(uint32_t i, float f);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;

        /* component-wise access methods */
        inline float x(void) const;
        inline float y(void) const;
        inline float r(void) const;
        inline float g(void) const;

        inline float x(float f);
        inline float y(float f);
        inline float r(float f);
        inline float g(float f);

        static inline float* value_ptr(vec& v);
        static inline float* value_ptr(vec* vv);
        static inline const float* value_ptr(const vec& v);
        static inline const float* value_ptr(const vec* vv);
        static inline __m64* intrin_ptr(vec& v);
        static inline __m64* intrin_ptr(vec* v);
        static inline const __m64* intrin_ptr(const vec& v);
        static inline const __m64* intrin_ptr(const vec* v);
    };

    template<>
    class vec<3, float>
    {
    private:
        alignas(16) __m128 _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(float f);
        inline vec(float x, float y, float z);
        inline vec(const float* fv);
        inline vec(const __m128& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec<2, float>& xy, float z);
        inline vec(float x, const vec<2, float>& yz);
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (float f);
        inline vec& operator= (const float* fv);
        inline vec& operator= (const __m128& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (float f) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (float f) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (float f) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (float f) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* assignment operators */
        inline vec& operator+= (float f);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (float f);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (float f);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (float f);
        inline vec& operator/= (const vec& v);

        /* common operators and methods */
        inline __m128 operator() (void) const;
        inline float operator[] (uint32_t i) const;
        inline float insert(uint32_t i, float f);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, uint32_t>(void) const;

        /* component-wise access methods */
        inline float x(void) const;
        inline float y(void) const;
        inline float z(void) const;
        inline float r(void) const;
        inline float g(void) const;
        inline float b(void) const;

        inline float x(float f);
        inline float y(float f);
        inline float z(float f);
        inline float r(float f);
        inline float g(float f);
        inline float b(float f);

        static inline float* value_ptr(vec& v);
        static inline float* value_ptr(vec* vv);
        static inline const float* value_ptr(const vec& v);
        static inline const float* value_ptr(const vec* vv);
        static inline __m128* intrin_ptr(vec& v);
        static inline __m128* intrin_ptr(vec* v);
        static inline const __m128* intrin_ptr(const vec& v);
        static inline const __m128* intrin_ptr(const vec* v);
    };

    template<>
    class vec<4, float>
    {
    private:
        alignas(16) __m128 _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(float f);
        inline vec(float x, float y, float z, float w);
        inline vec(const float* fv);
        inline vec(const __m128& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec<2, float>& xy, float z, float w);
        inline vec(float x, const vec<2, float>& yz, float w);
        inline vec(float x, float y, const vec<2, float>& zw);
        inline vec(const vec<2, float>& xy, const vec<2, float>& zw);
        inline vec(const vec<3, float>& xyz, float w);
        inline vec(float x, const vec<3, float>& yzw);
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (float f);
        inline vec& operator= (const float* fv);
        inline vec& operator= (const __m128& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (float f) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (float f) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (float f) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (float f) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* assignment operators */
        inline vec& operator+= (float f);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (float f);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (float f);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (float f);
        inline vec& operator/= (const vec& v);

        /* common operators and methods */
        inline __m128 operator() (void) const;
        inline float operator[] (uint32_t i) const;
        inline float insert(uint32_t i, float f);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, uint32_t>(void) const;

        /* component-wise access methods */
        inline float x(void) const;
        inline float y(void) const;
        inline float z(void) const;
        inline float w(void) const;
        inline float r(void) const;
        inline float g(void) const;
        inline float b(void) const;
        inline float a(void) const;

        inline float x(float f);
        inline float y(float f);
        inline float z(float f);
        inline float w(float f);
        inline float r(float f);
        inline float g(float f);
        inline float b(float f);
        inline float a(float f);

        static inline float* value_ptr(vec& v);
        static inline float* value_ptr(vec* vv);
        static inline const float* value_ptr(const vec& v);
        static inline const float* value_ptr(const vec* vv);
        static inline __m128* intrin_ptr(vec& v);
        static inline __m128* intrin_ptr(vec* v);
        static inline const __m128* intrin_ptr(const vec& v);
        static inline const __m128* intrin_ptr(const vec* v);
    };

    /// double vectors
    template<>
    class vec<2, double>
    {
    private:
        alignas(16) __m128d _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(double d);
        inline vec(double x, double y);
        inline vec(const double* dv);
        inline vec(const __m128d& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (double d);
        inline vec& operator= (const double* fv);
        inline vec& operator= (const __m128d& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (double d) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (double d) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (double d) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (double d) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* assignment operators */
        inline vec& operator+= (double d);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (double d);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (double d);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (double d);
        inline vec& operator/= (const vec& v);

        /* common operators and methods */
        inline __m128d operator() (void) const;
        inline double operator[] (uint32_t i) const;
        inline double insert(uint32_t i, double d);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;

        /* component-wise access methods */
        inline double x(void) const;
        inline double y(void) const;
        inline double r(void) const;
        inline double g(void) const;

        inline double x(double d);
        inline double y(double d);
        inline double r(double d);
        inline double g(double d);

        static inline double* value_ptr(vec& v);
        static inline double* value_ptr(vec* vv);
        static inline const double* value_ptr(const vec& v);
        static inline const double* value_ptr(const vec* vv);
        static inline __m128d* intrin_ptr(vec& v);
        static inline __m128d* intrin_ptr(vec* v);
        static inline const __m128d* intrin_ptr(const vec& v);
        static inline const __m128d* intrin_ptr(const vec* v);
    };

    template<>
    class vec<3, double>
    {
    private:
        alignas(32) __m256d _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(double d);
        inline vec(double x, double y, double z);
        inline vec(const double* dv);
        inline vec(const __m256d& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec<2, double>& xy, double z);
        inline vec(double x, const vec<2, double>& yz);
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (double d);
        inline vec& operator= (const double* fv);
        inline vec& operator= (const __m256d& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (double d) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (double d) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (double d) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (double d) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* assignment operators */
        inline vec& operator+= (double d);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (double d);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (double d);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (double d);
        inline vec& operator/= (const vec& v);

        /* common operators and methods */
        inline __m256d operator() (void) const;
        inline double operator[] (uint32_t i) const;
        inline double insert(uint32_t i, double d);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, uint32_t>(void) const;

        /* component-wise access methods */
        inline double x(void) const;
        inline double y(void) const;
        inline double z(void) const;
        inline double r(void) const;
        inline double g(void) const;
        inline double b(void) const;

        inline double x(double d);
        inline double y(double d);
        inline double z(double d);
        inline double r(double d);
        inline double g(double d);
        inline double b(double d);

        static inline double* value_ptr(vec& v);
        static inline double* value_ptr(vec* vv);
        static inline const double* value_ptr(const vec& v);
        static inline const double* value_ptr(const vec* vv);
        static inline __m256d* intrin_ptr(vec& v);
        static inline __m256d* intrin_ptr(vec* v);
        static inline const __m256d* intrin_ptr(const vec& v);
        static inline const __m256d* intrin_ptr(const vec* v);
    };

    template<>
    class vec<4, double>
    {
    private:
        alignas(32) __m256d _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(double d);
        inline vec(double x, double y, double z, double w);
        inline vec(const double* dv);
        inline vec(const __m256d& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec<2, double>& xy, double z, double w);
        inline vec(double x, const vec<2, double>& yz, double w);
        inline vec(double x, double y, const vec<2, double>& zw);
        inline vec(const vec<2, double>& xy, const vec<2, double>& zw);
        inline vec(const vec<3, double>& xyz, double w);
        inline vec(double x, const vec<3, double>& yzw);
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (double d);
        inline vec& operator= (const double* fv);
        inline vec& operator= (const __m256d& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (double d) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (double d) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (double d) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (double d) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* assignment operators */
        inline vec& operator+= (double d);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (double d);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (double d);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (double d);
        inline vec& operator/= (const vec& v);

        /* common operators and methods */
        inline __m256d operator() (void) const;
        inline double operator[] (uint32_t i) const;
        inline double insert(uint32_t i, double d);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, uint32_t>(void) const;

        /* component-wise access methods */
        inline double x(void) const;
        inline double y(void) const;
        inline double z(void) const;
        inline double w(void) const;
        inline double r(void) const;
        inline double g(void) const;
        inline double b(void) const;
        inline double a(void) const;

        inline double x(double d);
        inline double y(double d);
        inline double z(double d);
        inline double w(double d);
        inline double r(double d);
        inline double g(double d);
        inline double b(double d);
        inline double a(double d);

        static inline double* value_ptr(vec& v);
        static inline double* value_ptr(vec* vv);
        static inline const double* value_ptr(const vec& v);
        static inline const double* value_ptr(const vec* vv);
        static inline __m256d* intrin_ptr(vec& v);
        static inline __m256d* intrin_ptr(vec* v);
        static inline const __m256d* intrin_ptr(const vec& v);
        static inline const __m256d* intrin_ptr(const vec* v);
    };

    /// Integer and Boolean vectors (32 bit per component)
    template<typename T>
    class vec<2, T, 4>
    {
        static_assert(detail::util::is_integer_32bit<T>::value, "[glm2::vec]: Vetcor-type is not asserted to 32 bit integer!");

    private:
        alignas(8) __m64 _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(T i);
        inline vec(T i0, T i1);
        inline vec(const T* iv);
        inline vec(const __m64& v);
        inline vec(const __m128i& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (T i);
        inline vec& operator= (const T* iv);
        inline vec& operator= (const __m64& v);
        inline vec& operator= (const __m128i& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (T i) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (T i) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (T i) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (T i) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator% (T i) const;
        inline vec operator% (const vec& i) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* bitwise operators */
        inline vec operator~ (void) const;
        inline vec operator& (T i) const;
        inline vec operator& (const vec& v) const;
        inline vec operator| (T i) const;
        inline vec operator| (const vec& v) const;
        inline vec operator^ (T i) const;
        inline vec operator^ (const vec& v) const;
        inline vec operator<< (T i) const;
        inline vec operator<< (const vec& v) const;
        inline vec operator>> (T i) const;
        inline vec operator>> (const vec& v) const;

        /* assignment operators */
        inline vec& operator+= (T i);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (T i);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (T i);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (T i);
        inline vec& operator/= (const vec& v);
        inline vec& operator%= (T i);
        inline vec& operator%= (const vec& i);
        inline vec& operator&= (T i);
        inline vec& operator&= (const vec& i);
        inline vec& operator|= (T i);
        inline vec& operator|= (const vec& i);
        inline vec& operator^= (T i);
        inline vec& operator^= (const vec& i);
        inline vec& operator<<= (T i);
        inline vec& operator<<= (const vec& i);
        inline vec& operator>>= (T i);
        inline vec& operator>>= (const vec& i);

        /* common operators and methods */
        inline __m64 operator() (void) const;
        inline __m128i si128(void) const;
        inline T operator[] (uint32_t i) const;
        inline T insert(uint32_t i, T x);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;

        /* component-wise access methods */
        inline T x(void) const;
        inline T y(void) const;
        inline T r(void) const;
        inline T g(void) const;

        inline T x(T i);
        inline T y(T i);
        inline T r(T i);
        inline T g(T i);

        static inline T* value_ptr(vec& v);
        static inline T* value_ptr(vec* vv);
        static inline const T* value_ptr(const vec& v);
        static inline const T* value_ptr(const vec* vv);
        static inline __m64* intrin_ptr(vec& v);
        static inline __m64* intrin_ptr(vec* v);
        static inline const __m64* intrin_ptr(const vec& v);
        static inline const __m64* intrin_ptr(const vec* v);
    };

    template<typename T>
    class vec<3, T, 4>
    {
        static_assert(detail::util::is_integer_32bit<T>::value, "[glm2::vec]: Vetcor-type is not asserted to 32 bit integer!");

    private:
        alignas(16) __m128i _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(T i);
        inline vec(T i0, T i1, T i2);
        inline vec(const T* iv);
        inline vec(const __m128i& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec<2, T, 4>& xy, T z);
        inline vec(T x, const vec<2, T, 4>& yz);
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (T i);
        inline vec& operator= (const T* iv);
        inline vec& operator= (const __m128i& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (T i) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (T i) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (T i) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (T i) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator% (T i) const;
        inline vec operator% (const vec& i) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* bitwise operators */
        inline vec operator~ (void) const;
        inline vec operator& (T i) const;
        inline vec operator& (const vec& v) const;
        inline vec operator| (T i) const;
        inline vec operator| (const vec& v) const;
        inline vec operator^ (T i) const;
        inline vec operator^ (const vec& v) const;
        inline vec operator<< (T i) const;
        inline vec operator<< (const vec& v) const;
        inline vec operator>> (T i) const;
        inline vec operator>> (const vec& v) const;

        /* assignment operators */
        inline vec& operator+= (T i);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (T i);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (T i);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (T i);
        inline vec& operator/= (const vec& v);
        inline vec& operator%= (T i);
        inline vec& operator%= (const vec& v);
        inline vec& operator&= (T i);
        inline vec& operator&= (const vec& v);
        inline vec& operator|= (T i);
        inline vec& operator|= (const vec& v);
        inline vec& operator^= (T i);
        inline vec& operator^= (const vec& v);
        inline vec& operator<<= (T i);
        inline vec& operator<<= (const vec& v);
        inline vec& operator>>= (T i);
        inline vec& operator>>= (const vec& v);

        /* common operators and methods */
        inline __m128i operator() (void) const;
        inline T operator[] (uint32_t i) const;
        inline T insert(uint32_t i, T x);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, uint32_t>(void) const;

        /* component-wise access methods */
        inline T x(void) const;
        inline T y(void) const;
        inline T z(void) const;
        inline T r(void) const;
        inline T g(void) const;
        inline T b(void) const;

        inline T x(T f);
        inline T y(T f);
        inline T z(T f);
        inline T r(T f);
        inline T g(T f);
        inline T b(T f);

        static inline T* value_ptr(vec& v);
        static inline T* value_ptr(vec* vv);
        static inline const T* value_ptr(const vec& v);
        static inline const T* value_ptr(const vec* vv);
        static inline __m128i* intrin_ptr(vec& v);
        static inline __m128i* intrin_ptr(vec* v);
        static inline const __m128i* intrin_ptr(const vec& v);
        static inline const __m128i* intrin_ptr(const vec* v);
    };

    template<typename T>
    class vec<4, T, 4>
    {
        static_assert(detail::util::is_integer_32bit<T>::value, "[glm2::vec]: Vetcor-type is not asserted to 32 bit integer!");
    private:
        alignas(16) __m128i _v;

    public:
        /* default constructors */
        inline vec(void);
        inline vec(T i);
        inline vec(T i0, T i1, T i2, T i3);
        inline vec(const T* iv);
        inline vec(const __m128i& v);

        /* conversion constructors according to the GLSL 4.6 specification 5.4.2. Vector and Matrix Constructors */
        inline vec(const vec<2, T, 4>& xy, T z, T w);
        inline vec(T x, const vec<2, T, 4>& yz, T w);
        inline vec(T x, T y, const vec<2, T, 4>& zw);
        inline vec(const vec<2, T, 4>& xy, const vec<2, T, 4>& zw);
        inline vec(const vec<3, T, 4>& xyz, T w);
        inline vec(T x, const vec<3, T, 4>& yzw);
        inline vec(const vec& v);

        /* destructor */
        ~vec(void) = default;

        /* default copy operators */
        inline vec& operator= (T i);
        inline vec& operator= (const T* iv);
        inline vec& operator= (const __m128i& v);
        inline vec& operator= (const vec& v);

        /* copare operators */
        inline bool operator== (const vec& v) const;
        inline bool operator!= (const vec& v) const;

        /* arithmetic operators */
        inline vec operator+ (T i) const;
        inline vec operator+ (const vec& v) const;
        inline vec operator- (T i) const;
        inline vec operator- (const vec& v) const;
        inline vec operator* (T i) const;
        inline vec operator* (const vec& v) const;
        inline vec operator/ (T i) const;
        inline vec operator/ (const vec& v) const;
        inline vec operator% (T i) const;
        inline vec operator% (const vec& i) const;
        inline vec operator+ (void) const;
        inline vec operator- (void) const;
        inline vec operator++ (int);
        inline vec& operator++ (void);
        inline vec operator-- (int);
        inline vec& operator-- (void);

        /* bitwise operators */
        inline vec operator~ (void) const;
        inline vec operator& (T i) const;
        inline vec operator& (const vec& v) const;
        inline vec operator| (T i) const;
        inline vec operator| (const vec& v) const;
        inline vec operator^ (T i) const;
        inline vec operator^ (const vec& v) const;
        inline vec operator<< (T i) const;
        inline vec operator<< (const vec& v) const;
        inline vec operator>> (T i) const;
        inline vec operator>> (const vec& v) const;

        /* assignment operators */
        inline vec& operator+= (T i);
        inline vec& operator+= (const vec& v);
        inline vec& operator-= (T i);
        inline vec& operator-= (const vec& v);
        inline vec& operator*= (T i);
        inline vec& operator*= (const vec& v);
        inline vec& operator/= (T i);
        inline vec& operator/= (const vec& v);
        inline vec& operator%= (T i);
        inline vec& operator%= (const vec& v);
        inline vec& operator&= (T i);
        inline vec& operator&= (const vec& v);
        inline vec& operator|= (T i);
        inline vec& operator|= (const vec& v);
        inline vec& operator^= (T i);
        inline vec& operator^= (const vec& v);
        inline vec& operator<<= (T i);
        inline vec& operator<<= (const vec& v);
        inline vec& operator>>= (T i);
        inline vec& operator>>= (const vec& v);

        /* common operators and methods */
        inline __m128i operator() (void) const;
        inline T operator[] (uint32_t i) const;
        inline T insert(uint32_t i, T x);

        /* Implicit cast operators */
        GLM2_EXPLICIT_CAST inline operator vec<2, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, float>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, double>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, int32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<2, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<3, uint32_t>(void) const;
        GLM2_EXPLICIT_CAST inline operator vec<4, uint32_t>(void) const;

        /* component-wise access methods */
        inline T x(void) const;
        inline T y(void) const;
        inline T z(void) const;
        inline T w(void) const;
        inline T r(void) const;
        inline T g(void) const;
        inline T b(void) const;
        inline T a(void) const;

        inline T x(T f);
        inline T y(T f);
        inline T z(T f);
        inline T w(T f);
        inline T r(T f);
        inline T g(T f);
        inline T b(T f);
        inline T a(T f);

        static inline T* value_ptr(vec& v);
        static inline T* value_ptr(vec* vv);
        static inline const T* value_ptr(const vec& v);
        static inline const T* value_ptr(const vec* vv);
        static inline __m128i* intrin_ptr(vec& v);
        static inline __m128i* intrin_ptr(vec* v);
        static inline const __m128i* intrin_ptr(const vec& v);
        static inline const __m128i* intrin_ptr(const vec* v);
    };

    ///// Error vector-type
    template<length_t L, typename T, size_t S>
    class vec
    {
        static_assert(detail::util::vec_false_helper<L, T, S>::value, "[glm2::vec]: Invalid vector-type!");
    };
}

#include "vec2_impl.inl"
#include "vec3_impl.inl"
#include "vec4_impl.inl"
#include "dvec2_impl.inl"
#include "dvec3_impl.inl"
#include "dvec4_impl.inl"
#include "ivec2_impl.inl"
#include "ivec3_impl.inl"
#include "ivec4_impl.inl"
