/**
* @file     dvec3_impl.inl
* @brief    Implamentation of 3-component double vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<3, double>::vec(void)
{
    this->_v = _mm256_setzero_si256();
}
inline glm2::vec<3, double>::vec(double d)
{
    this->_v = _mm256_set1_pd(d);
}
inline glm2::vec<3, double>::vec(double x, double y, double z)
{
    this->_v = _mm256_set_pd(z, z, y, x);
}
inline glm2::vec<3, double>::vec(const double* dv)
{
    this->_v = _mm256_loadu_pd(dv);
}
inline glm2::vec<3, double>::vec(const __m256d& v)
{
    this->_v = v;
}
inline glm2::vec<3, double>::vec(const vec& v)
{
    this->_v = v._v;
}

inline glm2::vec<3, double>& glm2::vec<3, double>::operator= (double d)
{
    this->_v = _mm256_set1_pd(d);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator= (const __m256d& v)
{
    this->_v = v;
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator= (const vec& v)
{
    this->_v = v._v;
    return *this;
}

inline bool glm2::vec<3, double>::operator== (const vec& v) const
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_cmpeq_epi64(this->_v, v._v);
    ymm1 = _mm256_setzero_si256();
    ymm0 = _mm256_blend_pd(ymm0, ymm1, 0x8);  // exclude last component
    return (_mm256_movemask_pd(ymm0) == 0x7);
}
inline bool glm2::vec<3, double>::operator!= (const vec& v) const
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_cmpeq_epi64(this->_v, v._v);
    ymm1 = _mm256_setzero_si256();
    ymm0 = _mm256_blend_pd(ymm0, ymm1, 0x8);  // exclude last component
    return (_mm256_movemask_pd(ymm0) != 0x7);
}

inline glm2::vec<3, double> glm2::vec<3, double>::operator+ (double d) const
{
    vec ymm0 = *this;
    ymm0 += d;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator+ (const vec& v) const
{
    vec ymm0 = *this;
    ymm0 += v;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator- (double d) const
{
    vec ymm0 = *this;
    ymm0 -= d;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator- (const vec& v) const
{
    vec ymm0 = *this;
    ymm0 -= v;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator* (double d) const
{
    vec ymm0 = *this;
    ymm0 *= d;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator* (const vec& v) const
{
    vec ymm0 = *this;
    ymm0 *= v;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator/ (double d) const
{
    vec ymm0 = *this;
    ymm0 /= d;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator/ (const vec& v) const
{
    vec ymm0 = *this;
    ymm0 /= v;
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator+ (void) const
{
    return *this;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator- (void) const
{
    vec ymm0 = *this;
    __m256d ymm1 = _mm256_set1_epi64x(0x8000000000000000);
    ymm0._v = _mm256_xor_pd(ymm0._v, ymm1);
    return ymm0;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator++ (void)
{
    __m256d ymm0 = _mm256_set1_pd(1.0);
    this->_v = _mm256_add_pd(this->_v, ymm0);
    return *this;
}
inline glm2::vec<3, double> glm2::vec<3, double>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator-- (void)
{
    __m256d ymm0 = _mm256_set1_pd(1.0);
    this->_v = _mm256_sub_pd(this->_v, ymm0);
    return *this;
}


inline glm2::vec<3, double>& glm2::vec<3, double>::operator+= (double d)
{
    __m256d ymm0 = _mm256_set1_pd(d);
    this->_v = _mm256_add_pd(this->_v, ymm0);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator+= (const vec& v)
{
    this->_v = _mm256_add_pd(this->_v, v._v);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator-= (double d)
{
    __m256d ymm0 = _mm256_set1_pd(d);
    this->_v = _mm256_sub_pd(this->_v, ymm0);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator-= (const vec& v)
{
    this->_v = _mm256_sub_pd(this->_v, v._v);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator*= (double d)
{
    __m256d ymm0 = _mm256_set1_pd(d);
    this->_v = _mm256_mul_pd(this->_v, ymm0);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator*= (const vec& v)
{
    this->_v = _mm256_mul_pd(this->_v, v._v);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator/= (double d)
{
    __m256d ymm0 = _mm256_set1_pd(d);
    this->_v = _mm256_div_pd(this->_v, ymm0);
    return *this;
}
inline glm2::vec<3, double>& glm2::vec<3, double>::operator/= (const vec& v)
{
    this->_v = _mm256_div_pd(this->_v, v._v);
    return *this;
}

inline double glm2::vec<3, double>::operator[] (uint32_t i) const
{
    return this->_v[i];
}
inline double glm2::vec<3, double>::insert(uint32_t i, double d)
{
    return (this->_v[i] = d);
}
inline glm2::vec<3, double>& glm2::vec<3, double>::load(const double* src)
{
    this->_v = _mm256_loadu_pd(src);
    return *this;
}
inline void glm2::vec<3, double>::store(double* dst) const
{
    _mm256_storeu_pd(dst, this->_v);
}
inline __m256d glm2::vec<3, double>::intrin(void) const
{
    return this->_v;
}


inline double glm2::vec<3, double>::x(void) const
{
    double d;
    __m128d xmm0 = _mm256_extracti128_si256(this->_v, 0x0); // get low __m128
    _mm_storel_pd(&d, xmm0);                                // get low double
    return d;
}
inline double glm2::vec<3, double>::y(void) const
{
    double d;
    __m128d xmm0 = _mm256_extracti128_si256(this->_v, 0x0); // get low __m128
    _mm_storeh_pd(&d, xmm0);                                // get high double
    return d;
}
inline double glm2::vec<3, double>::z(void) const
{
    double d;
    __m128d xmm0 = _mm256_extracti128_si256(this->_v, 0x1); // get high __m128
    _mm_storel_pd(&d, xmm0);                                // get low double
    return d;
}
inline double glm2::vec<3, double>::r(void) const
{
    return this->x();
}
inline double glm2::vec<3, double>::g(void) const
{
    return this->y();
}
inline double glm2::vec<3, double>::b(void) const
{
    return this->z();
}

inline double glm2::vec<3, double>::x(double d)
{
    __m128d xmm0;
    xmm0 = _mm256_extracti128_si256(this->_v, 0x0);         // get low __m128
    xmm0 = _mm_loadl_pd(xmm0, &d);                          // override low double
    this->_v = _mm256_insertf128_pd(this->_v, xmm0, 0x0);   // insert low __m128 back
    return d;
}
inline double glm2::vec<3, double>::y(double d)
{
    __m128d xmm0;
    xmm0 = _mm256_extracti128_si256(this->_v, 0x0);         // get low __m128
    xmm0 = _mm_loadh_pd(xmm0, &d);                          // override high double
    this->_v = _mm256_insertf128_pd(this->_v, xmm0, 0x0);   // insert low __m128 back
    return d;
}
inline double glm2::vec<3, double>::z(double d)
{
    __m128d xmm0;
    xmm0 = _mm256_extracti128_si256(this->_v, 0x1);         // get high __m128
    xmm0 = _mm_loadl_pd(xmm0, &d);                          // override low double
    this->_v = _mm256_insertf128_pd(this->_v, xmm0, 0x1);   // insert high __m128 back
    return d;
}
inline double glm2::vec<3, double>::r(double d)
{
    return this->x();
}
inline double glm2::vec<3, double>::g(double d)
{
    return this->y();
}
inline double glm2::vec<3, double>::b(double d)
{
    return this->z();
}

inline double* glm2::vec<3, double>::value_ptr(vec& v)
{
    return (double*)&v;
}
inline double* glm2::vec<3, double>::value_ptr(vec* vv)
{
    return (double*)vv;
}
inline const double* glm2::vec<3, double>::value_ptr(const vec& v)
{
    return (const double*)&v;
}
inline const double* glm2::vec<3, double>::value_ptr(const vec* vv)
{
    return (const double*)vv;
}

inline __m256d* glm2::vec<3, double>::intrin_ptr(vec& v)
{
    return (__m256d*)&v;
}
inline __m256d* glm2::vec<3, double>::intrin_ptr(vec* v)
{
    return (__m256d*)v;
}
inline const __m256d* glm2::vec<3, double>::intrin_ptr(const vec& v)
{
    return (const __m256d*)&v;
}
inline const __m256d* glm2::vec<3, double>::intrin_ptr(const vec* v)
{
    return (const __m256d*)v;
} 