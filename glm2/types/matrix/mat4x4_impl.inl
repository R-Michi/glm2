/**
* @file     mat4x4_impl.inl
* @brief    Implemantation of the 4x4 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<4, 4, float>::mat(void)
{
    *this = 0.0f;
}
inline glm2::mat<4, 4, float>::mat(float f)
{
    *this = f;
}
inline glm2::mat<4, 4, float>::mat(
    float n0m0, float n0m1, float n0m2, float n0m3,
    float n1m0, float n1m1, float n1m2, float n1m3,
    float n2m0, float n2m1, float n2m2, float n2m3,
    float n3m0, float n3m1, float n3m2, float n3m3
)
{
    this->_M[0] = col_type(n0m0, n0m1, n0m2, n0m3);
    this->_M[1] = col_type(n1m0, n1m1, n1m2, n1m3);
    this->_M[2] = col_type(n2m0, n2m1, n2m2, n2m3);
    this->_M[3] = col_type(n3m0, n3m1, n3m2, n3m3);
}               
inline glm2::mat<4, 4, float>::mat(const float* fv)
{
    *this = this->load(fv);
}
inline glm2::mat<4, 4, float>::mat(
    const col_type& n0,
    const col_type& n1,
    const col_type& n2,
    const col_type& n3
)
{
    this->_M[0] = n0;
    this->_M[1] = n1;
    this->_M[2] = n2;
    this->_M[3] = n3;
}
inline glm2::mat<4, 4, float>::mat(const col_type* vv)
{
    *this = this->load(vv);
}
inline glm2::mat<4, 4, float>::mat(const __m128* m128v)
{
    *this = this->load(m128v);
}
inline glm2::mat<4, 4, float>::mat(const __m256* m256v)
{
    *this = this->load(m256v);
}
inline glm2::mat<4, 4, float>::mat(const mat& M)
{
    *this = M;
}

inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator= (float f)
{
    this->_M[0] = f;
    this->_M[1] = f;
    this->_M[2] = f;
    this->_M[3] = f;
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator= (const mat& M)
{
    this->_M[0] = M._M[0];
    this->_M[1] = M._M[1];
    this->_M[2] = M._M[2];
    this->_M[3] = M._M[3];
    return *this;
}

inline bool glm2::mat<4, 4, float>::operator== (const mat& M) const
{
    __m256i ymm0, ymm1;
    ymm0 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 0));
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 2));
    ymm0 = _mm256_cmpeq_epi32(ymm0, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 0)));
    ymm1 = _mm256_cmpeq_epi32(ymm1, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 2)));
    ymm0 = _mm256_and_si256(ymm0, ymm1);
    return (_mm256_movemask_ps(_mm256_castsi256_ps(ymm0)) == 0xFF);
}
inline bool glm2::mat<4, 4, float>::operator!= (const mat& M) const
{
    __m256i ymm0, ymm1;
    ymm0 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 0));
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 2));
    ymm0 = _mm256_cmpeq_epi32(ymm0, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 0)));
    ymm1 = _mm256_cmpeq_epi32(ymm1, _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(M._M + 2)));
    ymm0 = _mm256_and_si256(ymm0, ymm1);
    return (_mm256_movemask_ps(_mm256_castsi256_ps(ymm0)) != 0xFF);
}

inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator+ (float f) const
{
    mat _M = *this;
    _M += f;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator+ (const col_type& v) const
{
    mat _M = *this;
    _M += v;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator+ (const mat& M) const
{
    mat _M = *this;
    _M += M;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator- (float f) const
{
    mat _M = *this;
    _M -= f;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator- (const col_type& v) const
{
    mat _M = *this;
    _M -= v;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator- (const mat& M) const
{
    mat _M = *this;
    _M -= M;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator* (float f) const
{
    mat _M = *this;
    _M *= f;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator/ (float f) const
{
    mat _M = *this;
    _M /= f;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator+ (void) const
{
    return *this;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator- (void) const
{
    mat M;
    __m256i ymm0, ymm1;
    ymm0 = _mm256_set1_epi32(0x80000000);
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 0));
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(M._M + 0), ymm1);
    ymm1 = _mm256_loadu_si256(reinterpret_cast<const __m256i_u*>(this->_M + 2));
    ymm0 = _mm256_xor_si256(ymm1, ymm0);
    _mm256_storeu_si256(reinterpret_cast<__m256i_u*>(M._M + 2), ymm0);
    return M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator++ (int)
{
    mat M = *this;
    ++*this;
    return M;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator++ (void)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(1.0f);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_add_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_add_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator-- (int)
{
    mat M = *this;
    --*this;
    return M;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator-- (void)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(1.0f);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_sub_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_sub_ps(ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}

inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator+= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator+= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v.intrin()));
    ymm1 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_add_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator+= (const mat& M)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_add_ps(ymm0, _mm256_loadu_ps(col_type::value_ptr(M._M + 0)));
    ymm1 = _mm256_add_ps(ymm1, _mm256_loadu_ps(col_type::value_ptr(M._M + 2)));  
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm1);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator-= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator-= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v.intrin()));
    ymm1 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_sub_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator-= (const mat& M)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    ymm1 = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
    ymm0 = _mm256_sub_ps(ymm0, _mm256_loadu_ps(col_type::value_ptr(M._M + 0)));
    ymm1 = _mm256_sub_ps(ymm1, _mm256_loadu_ps(col_type::value_ptr(M._M + 2)));    
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm1);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator*= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator*= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v.intrin()));
    ymm1 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_mul_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator/= (float f)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_set1_ps(f);
    ymm1 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator/= (const col_type& v)
{
    __m256 ymm0, ymm1;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v.intrin()));
    ymm1 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 0)), ymm0);
    ymm0 = _mm256_div_ps(_mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm1);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}

inline glm2::mat<4, 4, float>::col_type& glm2::mat<4, 4, float>::operator[] (uint32_t i)
{
    return this->_M[i];
}
inline const glm2::mat<4, 4, float>::col_type& glm2::mat<4, 4, float>::operator[] (uint32_t i) const
{
    return this->_M[i];
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::load(const float* src)
{
    this->_M[0].load(src + 0);
    this->_M[1].load(src + 4);
    this->_M[2].load(src + 8);
    this->_M[3].load(src + 12);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::load(const col_type* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    this->_M[2] = src[2];
    this->_M[3] = src[3];
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::load(const __m128* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    this->_M[2] = src[2];
    this->_M[3] = src[3];
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::load(const __m256* src)
{
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), src[0]);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), src[1]);
    return *this;
}
inline void glm2::mat<4, 4, float>::store(float* dst) const
{
    this->_M[0].store(dst + 0);
    this->_M[1].store(dst + 4);
    this->_M[2].store(dst + 8);
    this->_M[3].store(dst + 12);
}
inline void glm2::mat<4, 4, float>::store(col_type* dst) const
{
    dst[0] = this->_M[0];
    dst[1] = this->_M[1];
    dst[2] = this->_M[2];
    dst[3] = this->_M[3];
}
inline void glm2::mat<4, 4, float>::store(__m128* dst) const
{
    dst[0] = this->_M[0].intrin();
    dst[1] = this->_M[1].intrin();
    dst[2] = this->_M[2].intrin();
    dst[3] = this->_M[3].intrin();
}
inline void glm2::mat<4, 4, float>::store(__m256* dst) const
{
    dst[0] = _mm256_loadu_ps(col_type::value_ptr(this->_M + 0));
    dst[1] = _mm256_loadu_ps(col_type::value_ptr(this->_M + 2));
}

inline float* glm2::mat<4, 4, float>::value_ptr(mat& M)
{
    return col_type::value_ptr(M._M);
}
inline float* glm2::mat<4, 4, float>::value_ptr(mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}
inline const float* glm2::mat<4, 4, float>::value_ptr(const mat& M)
{
    return col_type::value_ptr(M._M);
}
inline const float* glm2::mat<4, 4, float>::value_ptr(const mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}

inline __m128* glm2::mat<4, 4, float>::intrin_ptr(mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline __m128* glm2::mat<4, 4, float>::intrin_ptr(mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
inline const __m128* glm2::mat<4, 4, float>::intrin_ptr(const mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline const __m128* glm2::mat<4, 4, float>::intrin_ptr(const mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
