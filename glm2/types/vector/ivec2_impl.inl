/**
* @file     ivec2_impl.inl
* @brief    Implamentation of 2-component integer vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T> inline glm2::vec<2, T, 4>::vec(void)
{
    this->_v = _mm_setzero_si64();
}
template<typename T> inline glm2::vec<2, T, 4>::vec(T i)
{
    this->_v = _mm_set1_pi32((int32_t)i);
}
template<typename T> inline glm2::vec<2, T, 4>::vec(T i0, T i1)
{
    this->_v = _mm_set_pi32((int32_t)i1, (int32_t)i0);
}
template<typename T> inline glm2::vec<2, T, 4>::vec(const T* iv)
{
    this->_v = intrin::_m_load_pi32((const int32_t*)iv);
}
template<typename T> inline glm2::vec<2, T, 4>::vec(const __m64& v)
{
    this->_v = intrin::_m_move_si64(v);
}
template<typename T> inline glm2::vec<2, T, 4>::vec(const __m128i& v)
{
    this->_v = _mm_movepi64_pi64(v);
}
template<typename T> inline glm2::vec<2, T, 4>::vec(const vec& v)
{
    this->_v = intrin::_m_move_si64(v._v);
}

template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator= (T i)
{
    this->_v = _mm_set1_pi32((int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator= (const T* iv)
{
    this->_v = intrin::_m_load_pi32((const int32_t*)iv);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator= (const __m64& v)
{
    this->_v = intrin::_m_move_si64(v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator= (const __m128i& v)
{
    this->_v = _mm_movepi64_pi64(v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator= (const vec& v)
{
    this->_v = intrin::_m_move_si64(v._v);
    return *this;
}

template<typename T> inline bool glm2::vec<2, T, 4>::operator== (const vec& v) const
{
    uint64_t x = detail::internal_util::bit_cast<uint64_t, __m64>(_mm_cmpeq_pi32(v._v, this->_v));
    return (x == 0xFFFFFFFFFFFFFFFF); // true if x = 0xFFFFFFFFFFFFFFFF
}
template<typename T> inline bool glm2::vec<2, T, 4>::operator!= (const vec& v) const
{
    uint64_t x = detail::internal_util::bit_cast<uint64_t, __m64>(_mm_cmpeq_pi32(v._v, this->_v));
    return (x != 0xFFFFFFFFFFFFFFFF); // false if x != 0xFFFFFFFFFFFFFFFF
}

template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator+ (T i) const
{
    vec mm0 = *this;
    mm0 += i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator+ (const vec& v) const
{
    vec mm0 = *this;
    mm0 += v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator- (T i) const
{
    vec mm0 = *this;
    mm0 -= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator- (const vec& v) const
{
    vec mm0 = *this;
    mm0 -= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator* (T i) const
{
    vec mm0 = *this;
    mm0 *= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator* (const vec& v) const
{
    vec mm0 = *this;
    mm0 *= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator/ (T i) const
{
    vec mm0 = *this;
    mm0 /= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator/ (const vec& v) const
{
    vec mm0 = *this;
    mm0 /= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator% (T i) const
{
    vec mm0 = *this;
    mm0 %= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator% (const vec& i) const
{
    vec mm0 = *this;
    mm0 %= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator+ (void) const
{
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator- (void) const
{
    vec mm0 = *this;
    __m64 mm1;
    mm1 = _mm_set1_pi32(0xFFFFFFFF);
    mm0._v = _m_pxor(mm0._v, mm1);
    mm1 = _mm_set1_pi32(1);
    mm0._v = _m_paddd(mm0._v, mm1);
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator++ (void)
{
    __m64 mm0 = _mm_set1_pi32(1);
    this->_v = _m_paddd(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator-- (void)
{
    __m64 mm0 = _mm_set1_pi32(1);
    this->_v = _m_psubd(this->_v, mm0);
    return *this;
}

template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator~ (void) const
{
    vec mm0 = *this;
    __m64 mm1 = _mm_set1_pi32(0xFFFFFFFF);
    mm0._v = _m_pxor(mm0._v, mm1);
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator& (T i) const
{
    vec mm0 = *this;
    mm0 &= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator& (const vec& v) const
{
    vec mm0 = *this;
    mm0 &= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator| (T i) const
{
    vec mm0 = *this;
    mm0 |= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator| (const vec& v) const
{
    vec mm0 = *this;
    mm0 |= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator^ (T i) const
{
    vec mm0 = *this;
    mm0 ^= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator^ (const vec& v) const
{
    vec mm0 = *this;
    mm0 ^= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator<< (T i) const
{
    vec mm0 = *this;
    mm0 <<= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator<< (const vec& v) const
{
    vec mm0 = *this;
    mm0 <<= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator>> (T i) const
{
    vec mm0 = *this;
    mm0 >>= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, 4> glm2::vec<2, T, 4>::operator>> (const vec& v) const
{
    vec mm0 = *this;
    mm0 >>= v;
    return mm0;
}

template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator+= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_paddd(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator+= (const vec& v)
{
    this->_v = _m_paddd(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator-= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_psubd(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator-= (const vec& v)
{
    this->_v = _m_psubd(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator*= (T i)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set1_epi32((int32_t)i);
    xmm0 = _mm_mul_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator*= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm0 = _mm_mul_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator/= (T i)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set1_epi32((int32_t)i);
    xmm0 = _mm_div_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator/= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm0 = _mm_div_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator%= (T i)
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_set1_epi32((int32_t)i);
    xmm2 = _mm_div_epi32(xmm0, xmm1);
    xmm1 = _mm_mul_epi32(xmm1, xmm2);
    xmm0 = _mm_sub_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator%= (const vec& i)
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm2 = _mm_div_epi32(xmm0, xmm1);
    xmm1 = _mm_mul_epi32(xmm1, xmm2);
    xmm0 = _mm_sub_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator&= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_pand(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator&= (const vec& i)
{
    this->_v = _m_pand(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator|= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_por(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator|= (const vec& i)
{
    this->_v = _m_por(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator^= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_pxor(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator^= (const vec& i)
{
    this->_v = _m_pxor(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator<<= (T i)
{
    this->_v = _m_pslldi(this->_v, (int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<2, T, 4>& glm2::vec<2, T, 4>::operator<<= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm1 = _mm_loadl_pi(xmm1, &v._v);
    xmm0 = _mm_sllv_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<> inline glm2::vec<2, int32_t, 4>& glm2::vec<2, int32_t, 4>::operator>>= (int32_t i)
{
    this->_v = _m_psradi(this->_v, (int32_t)i);
    return *this;
}
template<> inline glm2::vec<2, uint32_t, 4>& glm2::vec<2, uint32_t, 4>::operator>>= (uint32_t i)
{
    this->_v = _m_psrldi(this->_v, (int32_t)i);
    return *this;
}
template<> inline glm2::vec<2, int32_t, 4>& glm2::vec<2, int32_t, 4>::operator>>= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_loadl_pi(_mm_castsi128_ps(xmm0), &this->_v);
    xmm1 = _mm_loadl_pi(_mm_castsi128_ps(xmm1), &v._v);
    xmm0 = _mm_srav_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<> inline glm2::vec<2, uint32_t, 4>& glm2::vec<2, uint32_t, 4>::operator>>= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_loadl_pi(_mm_castsi128_ps(xmm0), &this->_v);
    xmm1 = _mm_loadl_pi(_mm_castsi128_ps(xmm1), &v._v);
    xmm0 = _mm_srlv_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}

template<typename T> inline __m64 glm2::vec<2, T, 4>::operator() (void) const
{
    return this->_v;
}
template<typename T> inline __m128i glm2::vec<2, T, 4>::si128(void) const
{
    __m128i xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    return xmm0;
}
template<typename T> inline T glm2::vec<2, T, 4>::operator[] (uint32_t i) const
{
    return this->_v[i];
}
template<typename T> inline T glm2::vec<2, T, 4>::insert(uint32_t i, T x)
{
    return (this->_v[i] = x);
}

template<typename T> inline T glm2::vec<2, T, 4>::x(void) const
{
    __m128i xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    return _mm_extract_epi32(xmm0, 0x0);
}
template<typename T> inline T glm2::vec<2, T, 4>::y(void) const
{
    __m128i xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    return _mm_extract_epi32(xmm0, 0x1);
}
template<typename T> inline T glm2::vec<2, T, 4>::r(void) const
{
    return this->x();
}
template<typename T> inline T glm2::vec<2, T, 4>::g(void) const
{
    return this->y();
}

template<typename T> inline T glm2::vec<2, T, 4>::x(T i)
{
    __m128i xmm0;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm0 = _mm_insert_epi32(xmm0, (int32_t)i, 0x0);
    this->_v = _mm_movepi64_pi64(xmm0);
    return i;
}
template<typename T> inline T glm2::vec<2, T, 4>::y(T i)
{
    __m128i xmm0;
    xmm0 = _mm_loadl_pi(xmm0, &this->_v);
    xmm0 = _mm_insert_epi32(xmm0, (int32_t)i, 0x1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return i;
}
template<typename T> inline T glm2::vec<2, T, 4>::r(T i)
{
    return this->x(i);
}
template<typename T> inline T glm2::vec<2, T, 4>::g(T i)
{
    return this->y(i);
}

template<typename T> inline T* glm2::vec<2, T, 4>::value_ptr(vec& v)
{
    return (T*)&v;
}
template<typename T> inline T* glm2::vec<2, T, 4>::value_ptr(vec* vv)
{
    return (T*)vv;
}
template<typename T> inline const T* glm2::vec<2, T, 4>::value_ptr(const vec& v)
{
    return (const T*)&v;
}
template<typename T> inline const T* glm2::vec<2, T, 4>::value_ptr(const vec* vv)
{
    return (const T*)vv;
}

template<typename T> inline __m64* glm2::vec<2, T, 4>::intrin_ptr(vec& v)
{
    return (__m64*)&v;
}
template<typename T> inline __m64* glm2::vec<2, T, 4>::intrin_ptr(vec* v)
{
    return (__m64*)v;
}
template<typename T> inline const __m64* glm2::vec<2, T, 4>::intrin_ptr(const vec& v)
{
    return (const __m64*)&v;
}
template<typename T> inline const __m64* glm2::vec<2, T, 4>::intrin_ptr(const vec* v)
{
    return (const __m64*)v;
} 