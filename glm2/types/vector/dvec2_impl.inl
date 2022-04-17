/**
* @file     dvec2_impl.inl
* @brief    Implamentation of 2-component double vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<2, double>::vec(void)
{
    this->_v = _mm_setzero_si128();
}
inline glm2::vec<2, double>::vec(double d)
{
    this->_v = _mm_set1_pd(d);
}
inline glm2::vec<2, double>::vec(double x, double y)
{
    this->_v = _mm_set_pd(y, x);
}
inline glm2::vec<2, double>::vec(const double* dv)
{
    this->_v = _mm_load_pd(dv);
}
inline glm2::vec<2, double>::vec(const __m128d& v)
{
    this->_v = v;
}
inline glm2::vec<2, double>::vec(const vec& v)
{
    this->_v = v._v;
}

inline glm2::vec<2, double>& glm2::vec<2, double>::operator= (double d)
{
    this->_v = _mm_set1_pd(d);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator= (const double* dv)
{
    this->_v = _mm_load_pd(dv);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator= (const __m128d& v)
{
    this->_v = v;
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator= (const vec& v)
{
    this->_v = v._v;
    return *this;
}

inline bool glm2::vec<2, double>::operator== (const vec& v) const
{
    __m128d xmm0 = _mm_cmpeq_epi64(this->_v, v._v);
    return (_mm_movemask_pd(xmm0) == 0x3);
}
inline bool glm2::vec<2, double>::operator!= (const vec& v) const
{
    __m128d xmm0 = _mm_cmpeq_epi64(this->_v, v._v);
    return (_mm_movemask_pd(xmm0) != 0x3);
}

inline glm2::vec<2, double> glm2::vec<2, double>::operator+ (double d) const
{
    vec xmm0 = *this;
    xmm0 += d;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator+ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 += v;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator- (double d) const
{
    vec xmm0 = *this;
    xmm0 -= d;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator- (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 -= v;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator* (double d) const
{
    vec xmm0 = *this;
    xmm0 *= d;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator* (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 *= v;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator/ (double d) const
{
    vec xmm0 = *this;
    xmm0 /= d;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator/ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 /= v;
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator+ (void) const
{
    return *this;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator- (void) const
{
    vec xmm0 = *this;
    __m128d xmm1 = _mm_set1_epi64x(0x8000000000000000);
    xmm0._v = _mm_xor_pd(xmm0._v, xmm1);
    return xmm0;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator++ (void)
{
    __m128d xmm0 = _mm_set1_pd(1.0);
    this->_v = _mm_add_pd(this->_v, xmm0);
    return *this;
}
inline glm2::vec<2, double> glm2::vec<2, double>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator-- (void)
{
    __m128d xmm0 = _mm_set1_pd(1.0);
    this->_v = _mm_sub_pd(this->_v, xmm0);
    return *this;
}

inline glm2::vec<2, double>& glm2::vec<2, double>::operator+= (double d)
{
    __m128d xmm0 = _mm_set1_pd(d);
    this->_v = _mm_add_pd(this->_v, xmm0);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator+= (const vec& v)
{
    this->_v = _mm_add_pd(this->_v, v._v);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator-= (double d)
{
    __m128d xmm0 = _mm_set1_pd(d);
    this->_v = _mm_sub_pd(this->_v, xmm0);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator-= (const vec& v)
{
    this->_v = _mm_sub_pd(this->_v, v._v);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator*= (double d)
{
    __m128d xmm0 = _mm_set1_pd(d);
    this->_v = _mm_mul_pd(this->_v, xmm0);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator*= (const vec& v)
{
    this->_v = _mm_mul_pd(this->_v, v._v);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator/= (double d)
{
    __m128d xmm0 = _mm_set1_pd(d);
    this->_v = _mm_div_pd(this->_v, xmm0);
    return *this;
}
inline glm2::vec<2, double>& glm2::vec<2, double>::operator/= (const vec& v)
{
    this->_v = _mm_div_pd(this->_v, v._v);
    return *this;
}

inline __m128d glm2::vec<2, double>::operator() (void) const
{
    return this->_v;
}
inline double glm2::vec<2, double>::operator[] (uint32_t i) const
{
    return this->_v[i];
}
inline double glm2::vec<2, double>::insert(uint32_t i, double d)
{
    return (this->_v[i] = d);
}

inline double glm2::vec<2, double>::x(void) const
{
    double d;
    _mm_storeh_pd(&d, this->_v);
    return d;
}
inline double glm2::vec<2, double>::y(void) const
{
    double d;
    _mm_storel_pd(&d, this->_v);
    return d;
}
inline double glm2::vec<2, double>::r(void) const
{
    return this->x();
}
inline double glm2::vec<2, double>::g(void) const
{
    return this->y();
}

inline double glm2::vec<2, double>::x(double d)
{
    this->_v = _mm_loadh_pd(this->_v, &d);
    return d;
}
inline double glm2::vec<2, double>::y(double d)
{
    this->_v = _mm_loadl_pd(this->_v, &d);
    return d;
}
inline double glm2::vec<2, double>::r(double d)
{
    return this->x(d);
}
inline double glm2::vec<2, double>::g(double d)
{
    return this->y(d);
}

inline double* glm2::vec<2, double>::value_ptr(vec& v)
{
    return (double*)&v;
}
inline double* glm2::vec<2, double>::value_ptr(vec* vv)
{
    return (double*)vv;
}
inline const double* glm2::vec<2, double>::value_ptr(const vec& v)
{
    return (const double*)&v;
}
inline const double* glm2::vec<2, double>::value_ptr(const vec* vv)
{
    return (const double*)vv;
}

inline __m128d* glm2::vec<2, double>::intrin_ptr(vec& v)
{
    return (__m128d*)&v;
}
inline __m128d* glm2::vec<2, double>::intrin_ptr(vec* v)
{
    return (__m128d*)v;
}
inline const __m128d* glm2::vec<2, double>::intrin_ptr(const vec& v)
{
    return (const __m128d*)&v;
}
inline const __m128d* glm2::vec<2, double>::intrin_ptr(const vec* v)
{
    return (const __m128d*)v;
} 