/**
* @file     vec3_impl.inl
* @brief    Implamentation of 3-component float vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<3, float>::vec(void)
{
    this->_v = _mm_setzero_si128();
}
inline glm2::vec<3, float>::vec(float f)
{
    this->_v = _mm_set_ps1(f);
}
inline glm2::vec<3, float>::vec(float x, float y, float z)
{
    this->_v = _mm_set_ps(z, z, y, x);
}
inline glm2::vec<3, float>::vec(const float* fv)
{
    this->_v = _mm_loadu_ps(fv);
}
inline glm2::vec<3, float>::vec(const __m128& v)
{
    this->_v = intrin::_mm_move_si128(v);
}
inline glm2::vec<3, float>::vec(const vec& v)
{
    this->_v = intrin::_mm_move_si128(v._v);
}

inline glm2::vec<3, float>& glm2::vec<3, float>::operator= (float f)
{
    this->_v = _mm_set_ps1(f);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator= (const __m128& v)
{
    this->_v = intrin::_mm_move_si128(v);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator= (const vec& v)
{
    this->_v = intrin::_mm_move_si128(v._v);
    return *this;
}

inline bool glm2::vec<3, float>::operator== (const vec& v) const
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_cmpeq_epi32(_mm_castps_si128(this->_v), _mm_castps_si128(v._v));
    xmm1 = _mm_setzero_ps();
    xmm0 = _mm_blend_ps(xmm0, xmm1, 0x8);   // exclude last component
    return (_mm_movemask_ps(xmm0) == 0x7);
}
inline bool glm2::vec<3, float>::operator!= (const vec& v) const
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_cmpeq_epi32(_mm_castps_si128(this->_v), _mm_castps_si128(v._v));
    xmm1 = _mm_setzero_ps();
    xmm0 = _mm_blend_ps(xmm0, xmm1, 0x8);   // exclude last component
    return (_mm_movemask_ps(xmm0) != 0x7);
}

inline glm2::vec<3, float> glm2::vec<3, float>::operator+ (float f) const
{
    vec xmm0 = *this;
    xmm0 += f;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator+ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 += v;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator- (float f) const
{
    vec xmm0 = *this;
    xmm0 -= f;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator- (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 -= v;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator* (float f) const
{
    vec xmm0 = *this;
    xmm0 *= f;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator* (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 *= v;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator/ (float f) const
{
    vec xmm0 = *this;
    xmm0 /= f;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator/ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 /= v;
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator+ (void) const
{
    return *this;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator- (void) const
{
    vec xmm0 = *this;
    __m128 xmm1 = _mm_castsi128_ps(_mm_set1_epi32(0x80000000));
    xmm0._v = _mm_xor_ps(xmm0._v, xmm1);
    return xmm0;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator++ (void)
{
    __m128 xmm0 = _mm_set_ps1(1.0f);
    this->_v = _mm_add_ps(this->_v, xmm0);
    return *this;
}
inline glm2::vec<3, float> glm2::vec<3, float>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator-- (void)
{
    __m128 xmm0 = _mm_set_ps1(1.0f);
    this->_v = _mm_sub_ps(this->_v, xmm0);
    return *this;
}

inline glm2::vec<3, float>& glm2::vec<3, float>::operator+= (float f)
{
    __m128 xmm0 = _mm_set_ps1(f);
    this->_v = _mm_add_ps(this->_v, xmm0);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator+= (const vec& v)
{
    this->_v = _mm_add_ps(this->_v, v._v);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator-= (float f)
{
    __m128 xmm0 = _mm_set_ps1(f);
    this->_v = _mm_sub_ps(this->_v, xmm0);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator-= (const vec& v)
{
    this->_v = _mm_sub_ps(this->_v, v._v);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator*= (float f)
{
    __m128 xmm0 = _mm_set_ps1(f);
    this->_v = _mm_mul_ps(this->_v, xmm0);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator*= (const vec& v)
{
    this->_v = _mm_mul_ps(this->_v, v._v);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator/= (float f)
{
    __m128 xmm0 = _mm_set_ps1(f);
    this->_v = _mm_div_ps(this->_v, xmm0);
    return *this;
}
inline glm2::vec<3, float>& glm2::vec<3, float>::operator/= (const vec& v)
{
    this->_v = _mm_div_ps(this->_v, v._v);
    return *this;
}

inline float glm2::vec<3, float>::operator[] (uint32_t i) const
{
    return this->_v[i];
}
inline float glm2::vec<3, float>::insert(uint32_t i, float f)
{
    return (this->_v[i] = f);
}
inline glm2::vec<3, float>& glm2::vec<3, float>::load(const float* src)
{
    this->_v = _mm_loadu_ps(src);
    return *this;
}
inline void glm2::vec<3, float>::store(float* dst) const
{
    _mm_storeu_ps(dst, this->_v);
}
inline __m128 glm2::vec<3, float>::intrin(void) const
{
    return this->_v;
}

inline float glm2::vec<3, float>::x(void) const
{
    return detail::util::bit_cast<float, int>(_mm_extract_ps(this->_v, 0x0));
}
inline float glm2::vec<3, float>::y(void) const
{
    return detail::util::bit_cast<float, int>(_mm_extract_ps(this->_v, 0x1));
}
inline float glm2::vec<3, float>::z(void) const
{
    return detail::util::bit_cast<float, int>(_mm_extract_ps(this->_v, 0x2));
}
inline float glm2::vec<3, float>::r(void) const
{
    return this->x();
}
inline float glm2::vec<3, float>::g(void) const
{
    return this->y();
}
inline float glm2::vec<3, float>::b(void) const
{
    return this->z();
}

inline float glm2::vec<3, float>::x(float f)
{
    this->_v = _mm_insert_ps(this->_v, _mm_load_ss(&f), 0x00);
    return f;
}
inline float glm2::vec<3, float>::y(float f)
{
    this->_v = _mm_insert_ps(this->_v, _mm_load_ss(&f), 0x10);
    return f;
}
inline float glm2::vec<3, float>::z(float f)
{
    this->_v = _mm_insert_ps(this->_v, _mm_load_ss(&f), 0x20);
    return f;
}
inline float glm2::vec<3, float>::r(float f)
{
    return this->x(f);
}
inline float glm2::vec<3, float>::g(float f)
{
    return this->y(f);
}
inline float glm2::vec<3, float>::b(float f)
{
    return this->z(f);
}

inline float* glm2::vec<3, float>::value_ptr(vec& v)
{
    return (float*)&v;
}
inline float* glm2::vec<3, float>::value_ptr(vec* vv)
{
    return (float*)vv;
}
inline const float* glm2::vec<3, float>::value_ptr(const vec& v)
{
    return (const float*)&v;
}
inline const float* glm2::vec<3, float>::value_ptr(const vec* vv)
{
    return (const float*)vv;
}

inline __m128* glm2::vec<3, float>::intrin_ptr(vec& v)
{
    return (__m128*)&v;
}
inline __m128* glm2::vec<3, float>::intrin_ptr(vec* v)
{
    return (__m128*)v;
}
inline const __m128* glm2::vec<3, float>::intrin_ptr(const vec& v)
{
    return (const __m128*)&v;
}
inline const __m128* glm2::vec<3, float>::intrin_ptr(const vec* v)
{
    return (const __m128*)v;
} 