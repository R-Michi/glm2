/**
* @file     mat2x2_impl.inl
* @brief    Implemantation of the 2x2 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<2, 2, float>::mat(void)
{
    *this = 0.0f;
}
inline glm2::mat<2, 2, float>::mat(float f)
{
    *this = f;
}
inline glm2::mat<2, 2, float>::mat(
    float n0m0, float n0m1,
    float n1m0, float n1m1
)
{
    this->_M[0] = col_type(n0m0, n0m1);
    this->_M[1] = col_type(n1m0, n1m1);
}
inline glm2::mat<2, 2, float>::mat(const float* fv)
{
    *this = this->load(fv);
}
inline glm2::mat<2, 2, float>::mat(
    const col_type& n0,
    const col_type& n1
)
{
    this->_M[0] = n0;
    this->_M[1] = n1;
}
inline glm2::mat<2, 2, float>::mat(const col_type* vv)
{
    *this = this->load(vv);
}
inline glm2::mat<2, 2, float>::mat(const __m64* m64v)
{
    *this = this->load(m64v);
}
inline glm2::mat<2, 2, float>::mat(const __m128* m128v)
{
    *this = this->load(m128v);
}
inline glm2::mat<2, 2, float>::mat(const mat& M)
{
    *this = M;
}

inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator= (float f)
{
    this->_M[0] = f;
    this->_M[1] = f;
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator= (const mat& M)
{
    this->_M[0] = M[0];
    this->_M[1] = M[1];
    return *this;
}

inline bool glm2::mat<2, 2, float>::operator== (const mat& M) const
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_castps_si128(_mm_loadu_ps(col_type::value_ptr(this->_M)));
    xmm1 = _mm_castps_si128(_mm_loadu_ps(col_type::value_ptr(M._M)));
    xmm0 = _mm_cmpeq_epi32(xmm0, xmm1);
    return (_mm_movemask_ps(_mm_castsi128_ps(xmm0)) == 0x0F);
}
inline bool glm2::mat<2, 2, float>::operator!= (const mat& M) const
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_castps_si128(_mm_loadu_ps(col_type::value_ptr(this->_M)));
    xmm1 = _mm_castps_si128(_mm_loadu_ps(col_type::value_ptr(M._M)));
    xmm0 = _mm_cmpeq_epi32(xmm0, xmm1);
    return (_mm_movemask_ps(_mm_castsi128_ps(xmm0)) != 0x0F);
}

inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator+ (float f) const
{
    mat _M = *this;
    _M += f;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator+ (const col_type& v) const
{
    mat _M = *this;
    _M += v;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator+ (const mat& M) const
{
    mat _M = *this;
    _M += M;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator- (float f) const
{
    mat _M = *this;
    _M -= f;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator- (const col_type& v) const
{
    mat _M = *this;
    _M -= v;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator- (const mat& M) const
{
    mat _M = *this;
    _M -= M;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator* (float f) const
{
    mat _M = *this;
    _M *= f;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator/ (float f) const
{
    mat _M = *this;
    _M /= f;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator+ (void) const
{
    return *this;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator- (void) const
{
    mat M;
    __m128 xmm0, xmm1;
    xmm0 = _mm_castsi128_ps(_mm_set1_epi32(0x80000000));
    xmm1 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm0 = _mm_xor_ps(xmm1, xmm0);
    _mm_storeu_ps(col_type::value_ptr(M._M), xmm0);
    return M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator++ (int)
{
    mat M = *this;
    ++*this;
    return M;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator++ (void)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_set1_ps(1.0f);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator-- (int)
{
    mat M = *this;
    --*this;
    return M;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator-- (void)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_set1_ps(1.0f);
    xmm0 = _mm_sub_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}

inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator+= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_set1_ps(f);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator+= (const col_type& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_broadcastq_epi64(_mm_castps_si128(v.intrinEXT()));
    xmm0 = _mm_add_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator+= (const mat& M)
{
    __m128 xmm0;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm0 = _mm_add_ps(xmm0, _mm_loadu_ps(col_type::value_ptr(M._M)));
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator-= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_set1_ps(f);
    xmm0 = _mm_sub_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator-= (const col_type& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_broadcastq_epi64(_mm_castps_si128(v.intrinEXT()));
    xmm0 = _mm_sub_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator-= (const mat& M)
{
    __m128 xmm0;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm0 = _mm_sub_ps(xmm0, _mm_loadu_ps(col_type::value_ptr(M._M)));
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator*= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_set1_ps(f);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator*= (const col_type& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_broadcastq_epi64(_mm_castps_si128(v.intrinEXT()));
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator/= (float f)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_set1_ps(f);
    xmm0 = _mm_div_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator/= (const col_type& v)
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_broadcastq_epi64(_mm_castps_si128(v.intrinEXT()));
    xmm0 = _mm_div_ps(xmm0, xmm1);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}

inline glm2::mat<2, 2, float>::col_type& glm2::mat<2, 2, float>::operator[] (uint32_t i)
{
    return this->_M[i];
}
inline const glm2::mat<2, 2, float>::col_type& glm2::mat<2, 2, float>::operator[] (uint32_t i) const
{
    return this->_M[i];
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::load(const float* src)
{
    this->_M[0].load(src + 0);
    this->_M[1].load(src + 2);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::load(const col_type* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::load(const __m64* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::load(const __m128* src)
{
    _mm_storeu_ps(col_type::value_ptr(this->_M), src[0]);
    return *this;
}
inline void  glm2::mat<2, 2, float>::store(float* dst) const
{
    this->_M[0].store(dst + 0);
    this->_M[1].store(dst + 2);
}
inline void  glm2::mat<2, 2, float>::store(col_type* dst) const
{
    dst[0] = this->_M[0];
    dst[1] = this->_M[1];
}
inline void  glm2::mat<2, 2, float>::store(__m64* dst) const
{
    dst[0] = this->_M[0].intrin();
    dst[1] = this->_M[1].intrin();
}
inline void  glm2::mat<2, 2, float>::store(__m128* dst) const
{
    dst[0] = _mm_loadu_ps(col_type::value_ptr(this->_M));
}

inline float* glm2::mat<2, 2, float>::value_ptr(mat& M)
{
    return col_type::value_ptr(M._M);
}
inline float* glm2::mat<2, 2, float>::value_ptr(mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}
inline const float* glm2::mat<2, 2, float>::value_ptr(const mat& M)
{
    return col_type::value_ptr(M._M);
}
inline const float* glm2::mat<2, 2, float>::value_ptr(const mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}
inline __m64* glm2::mat<2, 2, float>::intrin_ptr(mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline __m64* glm2::mat<2, 2, float>::intrin_ptr(mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
inline const __m64* glm2::mat<2, 2, float>::intrin_ptr(const mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline const __m64* glm2::mat<2, 2, float>::intrin_ptr(const mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}