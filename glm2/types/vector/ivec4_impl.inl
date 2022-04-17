/**
* @file     ivec4_impl.inl
* @brief    Implamentation of 4-component integer vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T> inline glm2::vec<4, T, 4>::vec(void)
{
    this->_v = _mm_setzero_si128();
}
template<typename T> inline glm2::vec<4, T, 4>::vec(T i)
{
    this->_v = _mm_set1_epi32((int32_t)i);
}
template<typename T> inline glm2::vec<4, T, 4>::vec(T i0, T i1, T i2, T i3)
{
    this->_v = _mm_set_epi32((int32_t)i3, (int32_t)i2, (int32_t)i1, (int32_t)i0);
}
template<typename T> inline glm2::vec<4, T, 4>::vec(const T* iv)
{
    this->_v = _mm_load_si128((const __m128i*)iv);
}
template<typename T> inline glm2::vec<4, T, 4>::vec(const __m128i& v)
{
    this->_v = intrin::_mm_move_si128(v);
}
template<typename T> inline glm2::vec<4, T, 4>::vec(const vec& v)
{
    this->_v = intrin::_mm_move_si128(v._v);
}

template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator= (T i)
{
    this->_v = _mm_set1_epi32((int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator= (const T* iv)
{
    this->_v = _mm_load_si128((const __m128i*)iv);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator= (const __m128i& v)
{
    this->_v = intrin::_mm_move_si128(v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator= (const vec& v)
{
    this->_v = intrin::_mm_move_si128(v._v);
    return *this;
}

template<typename T> inline bool glm2::vec<4, T, 4>::operator== (const vec& v) const
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_cmpeq_epi32(this->_v, v._v);
    xmm1 = _mm_setzero_si128();
    return (_mm_movemask_ps(xmm0) == 0xF);
}
template<typename T> inline bool glm2::vec<4, T, 4>::operator!= (const vec& v) const
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_cmpeq_epi32(this->_v, v._v);
    xmm1 = _mm_setzero_si128();
    return (_mm_movemask_ps(xmm0) != 0xF);
}

template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator+ (T i) const
{
    vec xmm0 = *this;
    xmm0 += i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator+ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 += v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator- (T i) const
{
    vec xmm0 = *this;
    xmm0 -= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator- (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 -= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator* (T i) const
{
    vec xmm0 = *this;
    xmm0 *= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator* (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 *= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator/ (T i) const
{
    vec xmm0 = *this;
    xmm0 /= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator/ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 /= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator% (T i) const
{
    vec xmm0 = *this;
    xmm0 %= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator% (const vec& i) const
{
    vec xmm0 = *this;
    xmm0 %= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator+ (void) const
{
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator- (void) const
{
    vec xmm0 = *this;
    __m128i xmm1;
    xmm1 = _mm_set1_epi32(0xFFFFFFFF);
    xmm0._v = _mm_xor_si128(xmm0._v, xmm1);
    xmm1 = _mm_set1_epi32(1);
    xmm0._v = _mm_add_epi32(xmm0._v, xmm1);
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator++ (void)
{
    __m128i xmm0 = _mm_set1_epi32(1);
    this->_v = _mm_add_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator-- (void)
{
    __m128i xmm0 = _mm_set1_epi32(1);
    this->_v = _mm_sub_epi32(this->_v, xmm0);
    return *this;
}

template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator~ (void) const
{
    vec xmm0 = *this;
    __m128i xmm1 = _mm_set1_epi32(0xFFFFFFFF);
    xmm0._v = _mm_xor_si128(xmm0._v, xmm1);
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator& (T i) const
{
    vec xmm0 = *this;
    xmm0 &= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator& (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 &= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator| (T i) const
{
    vec xmm0 = *this;
    xmm0 |= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator| (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 |= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator^ (T i) const
{
    vec xmm0 = *this;
    xmm0 ^= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator^ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 ^= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator<< (T i) const
{
    vec xmm0 = *this;
    xmm0 <<= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator<< (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 <<= v;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator>> (T i) const
{
    vec xmm0 = *this;
    xmm0 >>= i;
    return xmm0;
}
template<typename T> inline glm2::vec<4, T, 4> glm2::vec<4, T, 4>::operator>> (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 >>= v;
    return xmm0;
}

template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator+= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_add_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator+= (const vec& v)
{
    this->_v = _mm_add_epi32(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator-= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_sub_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator-= (const vec& v)
{
    this->_v = _mm_sub_epi32(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator*= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_mul_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator*= (const vec& v)
{
    this->_v = _mm_mul_epi32(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator/= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_div_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator/= (const vec& v)
{
    this->_v = _mm_div_epi32(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator%= (T i)
{
    __m128i xmm0;
    xmm0 = _mm_div_epi32(this->_v, _mm_set1_epi32((int32_t)i));
    xmm0 = _mm_mul_epi32(v._v, xmm0);
    this->_v = _mm_sub_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator%= (const vec& v)
{
    __m128i xmm0;
    xmm0 = _mm_div_epi32(this->_v, v._v);
    xmm0 = _mm_mul_epi32(v._v, xmm0);
    this->_v = _mm_sub_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator&= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_and_si128(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator&= (const vec& v)
{
    this->_v = _mm_and_si128(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator|= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_or_si128(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator|= (const vec& v)
{
    this->_v = _mm_or_si128(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator^= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_xor_si128(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator^= (const vec& v)
{
    this->_v = _mm_xor_si128(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator<<= (T i)
{
    this->_v = _mm_slli_epi32(this->_v, (int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<4, T, 4>& glm2::vec<4, T, 4>::operator<<= (const vec& v)
{
    this->_v = _mm_sllv_epi32(this->_v, v._v);
    return *this;
}
template<> inline glm2::vec<4, int32_t, 4>& glm2::vec<4, int32_t, 4>::operator>>= (int32_t i)
{
    this->_v = _mm_srai_epi32(this->_v, (int32_t)i);
    return *this;
}
template<> inline glm2::vec<4, uint32_t, 4>& glm2::vec<4, uint32_t, 4>::operator>>= (uint32_t i)
{
    this->_v = _mm_srli_epi32(this->_v, (int32_t)i);
    return *this;
}
template<> inline glm2::vec<4, int32_t, 4>& glm2::vec<4, int32_t, 4>::operator>>= (const vec& v)
{
    this->_v = _mm_srav_epi32(this->_v, v._v);
    return *this;
}
template<> inline glm2::vec<4, uint32_t, 4>& glm2::vec<4, uint32_t, 4>::operator>>= (const vec& v)
{
    this->_v = _mm_srlv_epi32(this->_v, v._v);
    return *this;
}

template<typename T> inline __m128i glm2::vec<4, T, 4>::operator() (void) const
{
    return this->_v;
}
template<typename T> inline T glm2::vec<4, T, 4>::operator[] (uint32_t i) const
{
    return this->_v[i];
}
template<typename T> inline T glm2::vec<4, T, 4>::insert(uint32_t i, T x)
{
    return (this->_v[i] = x);
}

template<typename T> inline T glm2::vec<4, T, 4>::x(void) const
{
    return _mm_extract_epi32(this->_v, 0x0);
}
template<typename T> inline T glm2::vec<4, T, 4>::y(void) const
{
    return _mm_extract_epi32(this->_v, 0x1);
}
template<typename T> inline T glm2::vec<4, T, 4>::z(void) const
{
    return _mm_extract_epi32(this->_v, 0x2);
}
template<typename T> inline T glm2::vec<4, T, 4>::w(void) const
{
    return _mm_extract_epi32(this->_v, 0x3);
}
template<typename T> inline T glm2::vec<4, T, 4>::r(void) const
{
    return this->x();
}
template<typename T> inline T glm2::vec<4, T, 4>::g(void) const
{
    return this->y();
}
template<typename T> inline T glm2::vec<4, T, 4>::b(void) const
{
    return this->z();
}
template<typename T> inline T glm2::vec<4, T, 4>::a(void) const
{
    return this->w();
}

template<typename T> inline T glm2::vec<4, T, 4>::x(T i)
{
    this->_v = _mm_insert_epi32(this->_v, (int32_t)i, 0x0);
    return i;
}
template<typename T> inline T glm2::vec<4, T, 4>::y(T i)
{
    this->_v = _mm_insert_epi32(this->_v, (int32_t)i, 0x1);
    return i;
}
template<typename T> inline T glm2::vec<4, T, 4>::z(T i)
{
    this->_v = _mm_insert_epi32(this->_v, (int32_t)i, 0x2);
    return i;
}
template<typename T> inline T glm2::vec<4, T, 4>::w(T i)
{
    this->_v = _mm_insert_epi32(this->_v, (int32_t)i, 0x3);
    return i;
}
template<typename T> inline T glm2::vec<4, T, 4>::r(T i)
{
    return this->x(i);
}
template<typename T> inline T glm2::vec<4, T, 4>::g(T i)
{
    return this->y(i);
}
template<typename T> inline T glm2::vec<4, T, 4>::b(T i)
{
    return this->z(i);
}
template<typename T> inline T glm2::vec<4, T, 4>::a(T i)
{
    return this->w(i);
}

template<typename T> inline T* glm2::vec<4, T, 4>::value_ptr(vec& v)
{
    return (T*)&v;
}
template<typename T> inline T* glm2::vec<4, T, 4>::value_ptr(vec* vv)
{
    return (T*)vv;
}
template<typename T> inline const T* glm2::vec<4, T, 4>::value_ptr(const vec& v)
{
    return (const T*)&v;
}
template<typename T> inline const T* glm2::vec<4, T, 4>::value_ptr(const vec* vv)
{
    return (const T*)vv;
}

template<typename T> inline __m128i* glm2::vec<4, T, 4>::intrin_ptr(vec& v)
{
    return (__m128i*)&v;
}
template<typename T> inline __m128i* glm2::vec<4, T, 4>::intrin_ptr(vec* v)
{
    return (__m128i*)v;
}
template<typename T> inline const __m128i* glm2::vec<4, T, 4>::intrin_ptr(const vec& v)
{
    return (const __m128i*)&v;
}
template<typename T> inline const __m128i* glm2::vec<4, T, 4>::intrin_ptr(const vec* v)
{
    return (const __m128i*)v;
} 
