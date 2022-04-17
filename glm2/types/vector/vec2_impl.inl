/**
* @file     vec2_impl.inl
* @brief    Implamentation of 2-component float vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::vec<2, float>::vec(void)
{
    this->_v = _mm_setzero_si64();
}
inline glm2::vec<2, float>::vec(float f)
{
    this->_v = intrin::_m_set1_ps(f);
}
inline glm2::vec<2, float>::vec(float x, float y)
{
    this->_v = intrin::_m_set_ps(y, x);
}
inline glm2::vec<2, float>::vec(const float* fv)
{
    this->_v = intrin::_m_load_ps(fv);
}
inline glm2::vec<2, float>::vec(const __m64& v)
{
    this->_v = intrin::_m_move_si64(v);
}
inline glm2::vec<2, float>::vec(const __m128& v)
{
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(v));
}
inline glm2::vec<2, float>::vec(const vec& v)
{
    this->_v = intrin::_m_move_si64(v._v);
}

inline glm2::vec<2, float>& glm2::vec<2, float>::operator= (float f)
{
    this->_v = intrin::_m_set1_ps(f);
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator= (const float* fv)
{
    this->_v = intrin::_m_load_ps(fv);
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator= (const __m64& v)
{
    this->_v = intrin::_m_move_si64(v);
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator= (const __m128& v)
{
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(v));
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator= (const vec& v)
{
    this->_v = intrin::_m_move_si64(v._v);
    return *this;
}

inline bool glm2::vec<2, float>::operator== (const vec& v) const
{
    uint64_t x = (uint64_t)_mm_cmpeq_pi32(v._v, this->_v);
    return (x == 0xFFFFFFFFFFFFFFFF); // true if x = 0xFFFFFFFFFFFFFFFF
}
inline bool glm2::vec<2, float>::operator!= (const vec& v) const
{
    uint64_t x = (uint64_t)_mm_cmpeq_pi32(v._v, this->_v);
    return (x != 0xFFFFFFFFFFFFFFFF); // false if x != 0xFFFFFFFFFFFFFFFF
}

inline glm2::vec<2, float> glm2::vec<2, float>::operator+ (float f) const
{
    vec xmm0 = *this;
    xmm0 += f;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator+ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 += v;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator- (float f) const
{
    vec xmm0 = *this;
    xmm0 -= f;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator- (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 -= v;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator* (float f) const
{
    vec xmm0 = *this;
    xmm0 *= f;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator* (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 *= v;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator/ (float f) const
{
    vec xmm0 = *this;
    xmm0 /= f;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator/ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 /= v;
    return xmm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator+ (void) const
{
    return *this;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator- (void) const
{
    vec mm0 = *this;
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set1_epi32(0x80000000);
    xmm0 = _mm_xor_ps(xmm0, xmm1);
    mm0._v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return mm0;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator++ (void)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set_ps1(1.0f);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}
inline glm2::vec<2, float> glm2::vec<2, float>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator-- (void)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set_ps1(1.0f);
    xmm0 = _mm_sub_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}

inline glm2::vec<2, float>& glm2::vec<2, float>::operator+= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set_ps1(f);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;

}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator+= (const vec& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator-= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set_ps1(f);
    xmm0 = _mm_sub_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator-= (const vec& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm0 = _mm_sub_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator*= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set_ps1(f);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator*= (const vec& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator/= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set_ps1(f);
    xmm0 = _mm_div_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}
inline glm2::vec<2, float>& glm2::vec<2, float>::operator/= (const vec& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm0 = _mm_div_ps(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return *this;
}

inline __m64 glm2::vec<2, float>::operator() (void) const
{
    return this->_v;
}
inline __m128 glm2::vec<2, float>::si128(void) const
{
    __m128 xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    return xmm0;
}
inline float glm2::vec<2, float>::operator[] (uint32_t i) const
{
    __m128 xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    return xmm0[i];
}
inline float glm2::vec<2, float>::insert(uint32_t i, float f)
{
    __m128 xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm0[i] = f;
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return f;
}

inline float glm2::vec<2, float>::x(void) const
{
    __m128 xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    return detail::util::bit_cast<float, int>(_mm_extract_ps(xmm0, 0x0));
}
inline float glm2::vec<2, float>::y(void) const
{
    __m128 xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    return detail::util::bit_cast<float, int>(_mm_extract_ps(xmm0, 0x1));
}
inline float glm2::vec<2, float>::r(void) const
{
    return this->x();
}
inline float glm2::vec<2, float>::g(void) const
{
    return this->y();
}

inline float glm2::vec<2, float>::x(float f)
{
    __m128 xmm0;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm0 = _mm_insert_ps(xmm0, _mm_load_ss(&f), 0x0);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return f;
}
inline float glm2::vec<2, float>::y(float f)
{
    __m128 xmm0;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm0 = _mm_insert_ps(xmm0, _mm_load_ss(&f), 0x10);
    this->_v = _mm_movepi64_pi64(_mm_castps_si128(xmm0));
    return f;
}
inline float glm2::vec<2, float>::r(float f)
{
    return this->x(f);
}
inline float glm2::vec<2, float>::g(float f)
{
    return this->y(f);
}

inline float* glm2::vec<2, float>::value_ptr(vec& v)
{
    return (float*)&v;
}
inline float* glm2::vec<2, float>::value_ptr(vec* vv)
{
    return (float*)vv;
}
inline const float* glm2::vec<2, float>::value_ptr(const vec& v)
{
    return (const float*)&v;
}
inline const float* glm2::vec<2, float>::value_ptr(const vec* vv)
{
    return (const float*)vv;
}

inline __m64* glm2::vec<2, float>::intrin_ptr(vec& v)
{
    return (__m64*)&v;
}
inline __m64* glm2::vec<2, float>::intrin_ptr(vec* v)
{
    return (__m64*)v;
}
inline const __m64* glm2::vec<2, float>::intrin_ptr(const vec& v)
{
    return (const __m64*)&v;
}
inline const __m64* glm2::vec<2, float>::intrin_ptr(const vec* v)
{
    return (const __m64*)v;
}   
