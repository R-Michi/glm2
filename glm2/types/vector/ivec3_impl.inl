/**
* @file     ivec3_impl.inl
* @brief    Implamentation of 3-component integer vector.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>::vec(void)
{
    this->_v = _mm_setzero_si128();
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>::vec(T i)
{
    this->_v = _mm_set1_epi32((int32_t)i);
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>::vec(T i0, T i1, T i2)
{
    this->_v = _mm_set_epi32((int32_t)i2, (int32_t)i2, (int32_t)i1, (int32_t)i0);
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>::vec(const T* iv)
{
    this->_v = _mm_load_si128((const __m128i*)iv);
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>::vec(const __m128i& v)
{
    this->_v = intrin::_mm_move_si128(v);
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>::vec(const vec& v)
{
    this->_v = intrin::_mm_move_si128(v._v);
}

template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator= (T i)
{
    this->_v = _mm_set1_epi32((int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator= (const T* iv)
{
    this->_v = _mm_load_si128((const __m128i*)iv);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator= (const __m128i& v)
{
    this->_v = intrin::_mm_move_si128(v);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator= (const vec& v)
{
    this->_v = intrin::_mm_move_si128(v._v);
    return *this;
}

template<typename T> inline bool glm2::vec<3, T, sizeof(int32_t)>::operator== (const vec& v) const
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_cmpeq_epi32(this->_v, v._v);
    xmm1 = _mm_setzero_si128();
    xmm0 = _mm_blend_epi32(xmm0, xmm1, 0x8);   // exclude last component
    return (_mm_movemask_ps(xmm0) == 0x7);
}
template<typename T> inline bool glm2::vec<3, T, sizeof(int32_t)>::operator!= (const vec& v) const
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_cmpeq_epi32(this->_v, v._v);
    xmm1 = _mm_setzero_si128();
    xmm0 = _mm_blend_epi32(xmm0, xmm1, 0x8);   // exclude last component
    return (_mm_movemask_ps(xmm0) != 0x7);
}

template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator+ (T i) const
{
    vec xmm0 = *this;
    xmm0 += i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator+ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 += v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator- (T i) const
{
    vec xmm0 = *this;
    xmm0 -= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator- (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 -= v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator* (T i) const
{
    vec xmm0 = *this;
    xmm0 *= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator* (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 *= v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator/ (T i) const
{
    vec xmm0 = *this;
    xmm0 /= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator/ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 /= v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator% (T i) const
{
    vec xmm0 = *this;
    xmm0 %= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator% (const vec& i) const
{
    vec xmm0 = *this;
    xmm0 %= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator+ (void) const
{
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator- (void) const
{
    vec xmm0 = *this;
    __m128i xmm1;
    xmm1    = _mm_set1_epi32(0xFFFFFFFF);
    xmm0._v = _mm_xor_si128(xmm0._v, xmm1);
    xmm1    = _mm_set1_epi32(1);
    xmm0._v = _mm_add_epi32(xmm0._v, xmm1);
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator++ (void)
{
    __m128i xmm0 = _mm_set1_epi32(1);
    this->_v = _mm_add_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator-- (void)
{
    __m128i xmm0 = _mm_set1_epi32(1);
    this->_v = _mm_sub_epi32(this->_v, xmm0);
    return *this;
}

template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator~ (void) const
{
    vec xmm0 = *this;
    __m128i xmm1 = _mm_set1_epi32(0xFFFFFFFF);
    xmm0._v = _mm_xor_si128(xmm0._v, xmm1);
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator& (T i) const
{
    vec xmm0 = *this;
    xmm0 &= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator& (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 &= v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator| (T i) const
{
    vec xmm0 = *this;
    xmm0 |= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator| (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 |= v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator^ (T i) const
{
    vec xmm0 = *this;
    xmm0 ^= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator^ (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 ^= v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator<< (T i) const
{
    vec xmm0 = *this;
    xmm0 <<= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator<< (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 <<= v;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator>> (T i) const
{
    vec xmm0 = *this;
    xmm0 >>= i;
    return xmm0;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)> glm2::vec<3, T, sizeof(int32_t)>::operator>> (const vec& v) const
{
    vec xmm0 = *this;
    xmm0 >>= v;
    return xmm0;
}

template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator+= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_add_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator+= (const vec& v)
{
    this->_v = _mm_add_epi32(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator-= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_sub_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator-= (const vec& v)
{
    this->_v = _mm_sub_epi32(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator*= (T i)
{
    __m128i xmm0 = _mm_set1_epi32(i);
    this->_v = _mm_mullo_epi32(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator*= (const vec& v)
{
    this->_v = _mm_mullo_epi32(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator/= (T i)
{
    alignas(16) T _this[4];
    _mm_store_si128((__m128i*)_this, this->_v);

    #pragma unroll_completely
    for(uint32_t j = 0; j < 3; j++)
        _this[j] = (_this[j] / i);

    this->_v = _mm_load_si128((const __m128i*)_this);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator/= (const vec& v)
{
    alignas(16) T _this[4], _v[4];
    _mm_store_si128((__m128i*)_this, this->_v);
    _mm_store_si128((__m128i*)_v, v._v);

    #pragma unroll_completely
    for(uint32_t i = 0; i < 3; i++)
        _this[i] = (_this[i] / _v[i]);

    this->_v = _mm_load_si128((const __m128i*)_this);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator%= (T i)
{
    alignas(16) T _this[4];
    _mm_store_si128((__m128i*)_this, this->_v);

    #pragma unroll_completely
    for(uint32_t j = 0; j < 3; j++)
        _this[j] = (_this[j] % i);

    this->_v = _mm_load_si128((const __m128i*)_this);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator%= (const vec& v)
{
    alignas(16) T _this[4], _v[4];
    _mm_store_si128((__m128i*)_this, this->_v);
    _mm_store_si128((__m128i*)_v, v._v);

    #pragma unroll_completely
    for(uint32_t i = 0; i < 3; i++)
        _this[i] = (_this[i] % _v[i]);

    this->_v = _mm_load_si128((const __m128i*)_this);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator&= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_and_si128(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator&= (const vec& v)
{
    this->_v = _mm_and_si128(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator|= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_or_si128(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator|= (const vec& v)
{
    this->_v = _mm_or_si128(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator^= (T i)
{
    __m128i xmm0 = _mm_set1_epi32((int32_t)i);
    this->_v = _mm_xor_si128(this->_v, xmm0);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator^= (const vec& v)
{
    this->_v = _mm_xor_si128(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator<<= (T i)
{
    this->_v = _mm_slli_epi32(this->_v, (int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<3, T, sizeof(int32_t)>& glm2::vec<3, T, sizeof(int32_t)>::operator<<= (const vec& v)
{
    this->_v = _mm_sllv_epi32(this->_v, v._v);
    return *this;
}
template<> inline glm2::vec<3, int32_t, sizeof(int32_t)>& glm2::vec<3, int32_t, sizeof(int32_t)>::operator>>= (int32_t i)
{
    this->_v = _mm_srai_epi32(this->_v, (int32_t)i);
    return *this;
}
template<> inline glm2::vec<3, uint32_t, sizeof(int32_t)>& glm2::vec<3, uint32_t, sizeof(int32_t)>::operator>>= (uint32_t i)
{
    this->_v = _mm_srli_epi32(this->_v, (int32_t)i);
    return *this;
}
template<> inline glm2::vec<3, int32_t, sizeof(int32_t)>& glm2::vec<3, int32_t, sizeof(int32_t)>::operator>>= (const vec& v)
{
    this->_v = _mm_srav_epi32(this->_v, v._v);
    return *this;
}
template<> inline glm2::vec<3, uint32_t, sizeof(int32_t)>& glm2::vec<3, uint32_t, sizeof(int32_t)>::operator>>= (const vec& v)
{
    this->_v = _mm_srlv_epi32(this->_v, v._v);
    return *this;
}

template<typename T> inline __m128i glm2::vec<3, T, sizeof(int32_t)>::operator() (void) const
{
    return this->_v;
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::operator[] (uint32_t i) const
{
    alignas(16) T ret[4];
    _mm_store_si128((__m128i*)ret, this->_v);
    return ret[i];
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::insert(uint32_t i, T x)
{
    alignas(16) T tmp[4];
    _mm_store_si128((__m128i*)ret, this->_v);
    tmp[i] = f;
    this->_v = _mm_load_si128((const __m128i*)ret);
    return f;
}

template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::x(void) const
{
    return _mm_extract_epi32(this->_v, 0x0);
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::y(void) const
{
    return _mm_extract_epi32(this->_v, 0x1);
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::z(void) const
{
    return _mm_extract_epi32(this->_v, 0x2);
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::r(void) const
{
    return this->x();
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::g(void) const
{
    return this->y();
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::b(void) const
{
    return this->z();
}

template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::x(T i)
{
    this->_v = _mm_insert_epi32(this->_v, (int32_t)i, 0x0);
    return i;
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::y(T i)
{
    this->_v = _mm_insert_epi32(this->_v, (int32_t)i, 0x1);
    return i;
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::z(T i)
{
    this->_v = _mm_insert_epi32(this->_v, (int32_t)i, 0x2);
    return i;
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::r(T i)
{
    return this->x(i);
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::g(T i)
{
    return this->y(i);
}
template<typename T> inline T glm2::vec<3, T, sizeof(int32_t)>::b(T i)
{
    return this->z(i);
}

template<typename T> inline T* glm2::vec<3, T, sizeof(int32_t)>::value_ptr(vec& v)
{
    return (T*)&v;
}
template<typename T> inline T* glm2::vec<3, T, sizeof(int32_t)>::value_ptr(vec* vv)
{
    return (T*)vv;
}
template<typename T> inline const T* glm2::vec<3, T, sizeof(int32_t)>::value_ptr(const vec& v)
{
    return (const T*)&v;
}
template<typename T> inline const T* glm2::vec<3, T, sizeof(int32_t)>::value_ptr(const vec* vv)
{
    return (const T*)vv;
}

template<typename T> inline __m128i* glm2::vec<3, T, sizeof(int32_t)>::intrin_ptr(vec& v)
{
    return (__m128i*)&v;
}
template<typename T> inline __m128i* glm2::vec<3, T, sizeof(int32_t)>::intrin_ptr(vec* v)
{
    return (__m128i*)v;
}
template<typename T> inline const __m128i* glm2::vec<3, T, sizeof(int32_t)>::intrin_ptr(const vec& v)
{
    return (const __m128i*)&v;
}
template<typename T> inline const __m128i* glm2::vec<3, T, sizeof(int32_t)>::intrin_ptr(const vec* v)
{
    return (const __m128i*)v;
} 
