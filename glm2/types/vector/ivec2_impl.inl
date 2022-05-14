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

template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>::vec(void)
{
    this->_v = _mm_setzero_si64();
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>::vec(T i)
{
    this->_v = _mm_set1_pi32((int32_t)i);
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>::vec(T i0, T i1)
{
    this->_v = _mm_set_pi32((int32_t)i1, (int32_t)i0);
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>::vec(const T* iv)
{
    this->_v = intrin::_m_load_pi32((const int32_t*)iv);
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>::vec(const __m64& v)
{
    this->_v = intrin::_m_move_si64(v);
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>::vec(const __m128i& v)
{
    this->_v = _mm_movepi64_pi64(v);
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>::vec(const vec& v)
{
    this->_v = intrin::_m_move_si64(v._v);
}

template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator= (T i)
{
    this->_v = _mm_set1_pi32((int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator= (const T* iv)
{
    this->_v = intrin::_m_load_pi32((const int32_t*)iv);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator= (const __m64& v)
{
    this->_v = intrin::_m_move_si64(v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator= (const __m128i& v)
{
    this->_v = _mm_movepi64_pi64(v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator= (const vec& v)
{
    this->_v = intrin::_m_move_si64(v._v);
    return *this;
}

template<typename T> inline bool glm2::vec<2, T, sizeof(int32_t)>::operator== (const vec& v) const
{
    uint64_t x = detail::util::bit_cast<uint64_t, __m64>(_mm_cmpeq_pi32(v._v, this->_v));
    return (x == 0xFFFFFFFFFFFFFFFF); // true if x = 0xFFFFFFFFFFFFFFFF
}
template<typename T> inline bool glm2::vec<2, T, sizeof(int32_t)>::operator!= (const vec& v) const
{
    uint64_t x = detail::util::bit_cast<uint64_t, __m64>(_mm_cmpeq_pi32(v._v, this->_v));
    return (x != 0xFFFFFFFFFFFFFFFF); // false if x != 0xFFFFFFFFFFFFFFFF
}

template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator+ (T i) const
{
    vec mm0 = *this;
    mm0 += i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator+ (const vec& v) const
{
    vec mm0 = *this;
    mm0 += v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator- (T i) const
{
    vec mm0 = *this;
    mm0 -= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator- (const vec& v) const
{
    vec mm0 = *this;
    mm0 -= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator* (T i) const
{
    vec mm0 = *this;
    mm0 *= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator* (const vec& v) const
{
    vec mm0 = *this;
    mm0 *= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator/ (T i) const
{
    vec mm0 = *this;
    mm0 /= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator/ (const vec& v) const
{
    vec mm0 = *this;
    mm0 /= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator% (T i) const
{
    vec mm0 = *this;
    mm0 %= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator% (const vec& i) const
{
    vec mm0 = *this;
    mm0 %= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator+ (void) const
{
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator- (void) const
{
    vec mm0 = *this;
    __m64 mm1;
    mm1 = _mm_set1_pi32(0xFFFFFFFF);
    mm0._v = _m_pxor(mm0._v, mm1);
    mm1 = _mm_set1_pi32(1);
    mm0._v = _m_paddd(mm0._v, mm1);
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator++ (int)
{
    vec v = *this;
    ++*this;
    return v;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator++ (void)
{
    __m64 mm0 = _mm_set1_pi32(1);
    this->_v = _m_paddd(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator-- (int)
{
    vec v = *this;
    --*this;
    return v;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator-- (void)
{
    __m64 mm0 = _mm_set1_pi32(1);
    this->_v = _m_psubd(this->_v, mm0);
    return *this;
}

template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator~ (void) const
{
    vec mm0 = *this;
    __m64 mm1 = _mm_set1_pi32(0xFFFFFFFF);
    mm0._v = _m_pxor(mm0._v, mm1);
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator& (T i) const
{
    vec mm0 = *this;
    mm0 &= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator& (const vec& v) const
{
    vec mm0 = *this;
    mm0 &= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator| (T i) const
{
    vec mm0 = *this;
    mm0 |= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator| (const vec& v) const
{
    vec mm0 = *this;
    mm0 |= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator^ (T i) const
{
    vec mm0 = *this;
    mm0 ^= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator^ (const vec& v) const
{
    vec mm0 = *this;
    mm0 ^= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator<< (T i) const
{
    vec mm0 = *this;
    mm0 <<= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator<< (const vec& v) const
{
    vec mm0 = *this;
    mm0 <<= v;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator>> (T i) const
{
    vec mm0 = *this;
    mm0 >>= i;
    return mm0;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)> glm2::vec<2, T, sizeof(int32_t)>::operator>> (const vec& v) const
{
    vec mm0 = *this;
    mm0 >>= v;
    return mm0;
}

template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator+= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_paddd(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator+= (const vec& v)
{
    this->_v = _m_paddd(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator-= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_psubd(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator-= (const vec& v)
{
    this->_v = _m_psubd(this->_v, v._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator*= (T i)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_movpi64_epi64(this->_v);
    xmm1 = _mm_set1_epi32(i);
    xmm0 = _mm_mullo_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator*= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_movpi64_epi64(this->_v);
    xmm1 = _mm_movpi64_epi64(v._v);
    xmm0 = _mm_mullo_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator/= (T i)
{
    T _this[2];
    intrin::_m_store_pi32(_this, this->_v);

    #pragma unroll_completely
    for(uint32_t j = 0; j < 2; j++)
        _this[j] = (_this[j] / i);

    this->_v = intrin::_m_load_pi32(_this);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator/= (const vec& v)
{
    T _this[2], _v[2];
    intrin::_m_store_pi32(_this, this->_v);
    intrin::_m_store_pi32(_v, v._v);

    #pragma unroll_completely
    for(uint32_t i = 0; i < 2; i++)
        _this[i] = (_this[i] / _v[i]);

    this->_v = intrin::_m_load_pi32(_this);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator%= (T i)
{
    T _this[2];
    intrin::_m_store_pi32(_this, this->_v);

    #pragma unroll_completely
    for(uint32_t j = 0; j < 2; j++)
        _this[j] = (_this[j] % i);

    this->_v = intrin::_m_load_pi32(_this);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator%= (const vec& v)
{
    T _this[2], _v[2];
    intrin::_m_store_pi32(_this, this->_v);
    intrin::_m_store_pi32(_v, v._v);

    #pragma unroll_completely
    for(uint32_t i = 0; i < 2; i++)
        _this[i] = (_this[i] % _v[i]);

    this->_v = intrin::_m_load_pi32(_this);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator&= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_pand(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator&= (const vec& i)
{
    this->_v = _m_pand(this->_v, i._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator|= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_por(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator|= (const vec& i)
{
    this->_v = _m_por(this->_v, i._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator^= (T i)
{
    __m64 mm0 = _mm_set1_pi32((int32_t)i);
    this->_v = _m_pxor(this->_v, mm0);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator^= (const vec& i)
{
    this->_v = _m_pxor(this->_v, i._v);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator<<= (T i)
{
    this->_v = _m_pslldi(this->_v, (int32_t)i);
    return *this;
}
template<typename T> inline glm2::vec<2, T, sizeof(int32_t)>& glm2::vec<2, T, sizeof(int32_t)>::operator<<= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_movpi64_epi64(this->_v);
    xmm1 = _mm_movpi64_epi64(v._v);
    xmm0 = _mm_sllv_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<> inline glm2::vec<2, int32_t, sizeof(int32_t)>& glm2::vec<2, int32_t, sizeof(int32_t)>::operator>>= (int32_t i)
{
    this->_v = _m_psradi(this->_v, i);
    return *this;
}
template<> inline glm2::vec<2, uint32_t, sizeof(int32_t)>& glm2::vec<2, uint32_t, sizeof(int32_t)>::operator>>= (uint32_t i)
{
    this->_v = _m_psrldi(this->_v, (int32_t)i);
    return *this;
}
template<> inline glm2::vec<2, int32_t, sizeof(int32_t)>& glm2::vec<2, int32_t, sizeof(int32_t)>::operator>>= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_movpi64_epi64(this->_v);
    xmm1 = _mm_movpi64_epi64(v._v);
    xmm0 = _mm_srav_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}
template<> inline glm2::vec<2, uint32_t, sizeof(int32_t)>& glm2::vec<2, uint32_t, sizeof(int32_t)>::operator>>= (const vec& v)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_movpi64_epi64(this->_v);
    xmm1 = _mm_movpi64_epi64(v._v);
    xmm0 = _mm_srlv_epi32(xmm0, xmm1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return *this;
}

template<typename T> inline __m64 glm2::vec<2, T, sizeof(int32_t)>::operator() (void) const
{
    return this->_v;
}
template<typename T> inline __m128i glm2::vec<2, T, sizeof(int32_t)>::si128(void) const
{
    __m128i xmm0 = _mm_movpi64_epi64(this->_v);
    return xmm0;
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::operator[] (uint32_t i) const
{
    T ret[2];
    intrin::_m_store_pi32(ret, this->_v);
    return ret[i];
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::insert(uint32_t i, T x)
{
    T tmp[2];
    intrin::_m_store_pi32(tmp, this->_v);
    tmp[i] = f;
    this->_v = intrin::_m_load_pi32(tmp);
    return f;
}

template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::x(void) const
{
    __m128i xmm0 = _mm_movpi64_epi64(this->_v);
    return _mm_extract_epi32(xmm0, 0x0);
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::y(void) const
{
    __m128i xmm0 = _mm_movpi64_epi64(this->_v);
    return _mm_extract_epi32(xmm0, 0x1);
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::r(void) const
{
    return this->x();
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::g(void) const
{
    return this->y();
}

template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::x(T i)
{
    __m128i xmm0;
    xmm0 = _mm_movpi64_epi64(this->_v);
    xmm0 = _mm_insert_epi32(xmm0, (int32_t)i, 0x0);
    this->_v = _mm_movepi64_pi64(xmm0);
    return i;
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::y(T i)
{
    __m128i xmm0;
    xmm0 = _mm_movpi64_epi64(this->_v);
    xmm0 = _mm_insert_epi32(xmm0, (int32_t)i, 0x1);
    this->_v = _mm_movepi64_pi64(xmm0);
    return i;
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::r(T i)
{
    return this->x(i);
}
template<typename T> inline T glm2::vec<2, T, sizeof(int32_t)>::g(T i)
{
    return this->y(i);
}

template<typename T> inline T* glm2::vec<2, T, sizeof(int32_t)>::value_ptr(vec& v)
{
    return (T*)&v;
}
template<typename T> inline T* glm2::vec<2, T, sizeof(int32_t)>::value_ptr(vec* vv)
{
    return (T*)vv;
}
template<typename T> inline const T* glm2::vec<2, T, sizeof(int32_t)>::value_ptr(const vec& v)
{
    return (const T*)&v;
}
template<typename T> inline const T* glm2::vec<2, T, sizeof(int32_t)>::value_ptr(const vec* vv)
{
    return (const T*)vv;
}

template<typename T> inline __m64* glm2::vec<2, T, sizeof(int32_t)>::intrin_ptr(vec& v)
{
    return (__m64*)&v;
}
template<typename T> inline __m64* glm2::vec<2, T, sizeof(int32_t)>::intrin_ptr(vec* v)
{
    return (__m64*)v;
}
template<typename T> inline const __m64* glm2::vec<2, T, sizeof(int32_t)>::intrin_ptr(const vec& v)
{
    return (const __m64*)&v;
}
template<typename T> inline const __m64* glm2::vec<2, T, sizeof(int32_t)>::intrin_ptr(const vec* v)
{
    return (const __m64*)v;
} 