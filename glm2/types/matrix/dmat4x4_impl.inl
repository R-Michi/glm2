/**
* @file     dmat4x4_impl.inl
* @brief    Implemantation of the 4x4 double matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<4, 4, double>::mat(void)
{
    *this = 0.0;
}
inline glm2::mat<4, 4, double>::mat(double d)
{
    *this = d;
}
inline glm2::mat<4, 4, double>::mat(
    double n0m0, double n0m1, double n0m2, double n0m3,
    double n1m0, double n1m1, double n1m2, double n1m3,
    double n2m0, double n2m1, double n2m2, double n2m3,
    double n3m0, double n3m1, double n3m2, double n3m3
)
{
    this->_M[0] = col_type(n0m0, n0m1, n0m2, n0m3);
    this->_M[1] = col_type(n1m0, n1m1, n1m2, n1m3);
    this->_M[2] = col_type(n2m0, n2m1, n2m2, n2m3);
    this->_M[3] = col_type(n3m0, n3m1, n3m2, n3m3);
}
inline glm2::mat<4, 4, double>::mat(const double* dv)
{
    *this = this->load(dv);
}
inline glm2::mat<4, 4, double>::mat(
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
inline glm2::mat<4, 4, double>::mat(const col_type* vv)
{
    *this = this->load(vv);
}
inline glm2::mat<4, 4, double>::mat(const __m256d* m256v)
{
    *this = this->load(m256v);
}
inline glm2::mat<4, 4, double>::mat(const mat& M)
{ 
    *this = M;
}

inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator= (double d)
{
    this->_M[0] = d;
    this->_M[1] = d;
    this->_M[2] = d;
    this->_M[3] = d;
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator= (const mat& M)
{
    this->_M[0] = M._M[0];
    this->_M[1] = M._M[1];
    this->_M[2] = M._M[2];
    this->_M[3] = M._M[3];
    return *this;
}

inline bool glm2::mat<4, 4, double>::operator== (const mat& M) const
{
    __m256i ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_castpd_si256(this->_M[0].intrin());
    ymm1 = _mm256_castpd_si256(this->_M[1].intrin());
    ymm2 = _mm256_castpd_si256(this->_M[2].intrin());
    ymm3 = _mm256_castpd_si256(this->_M[3].intrin());
    ymm0 = _mm256_cmpeq_epi64(ymm0, M._M[0].intrin());
    ymm1 = _mm256_cmpeq_epi64(ymm1, M._M[1].intrin());
    ymm2 = _mm256_cmpeq_epi64(ymm2, M._M[2].intrin());
    ymm3 = _mm256_cmpeq_epi64(ymm3, M._M[3].intrin());
    ymm0 = _mm256_and_si256(ymm0, ymm1);
    ymm2 = _mm256_and_si256(ymm2, ymm3);
    ymm0 = _mm256_and_si256(ymm0, ymm2);
    return (_mm256_movemask_pd(_mm256_castsi256_pd(ymm0)) == 0x0F);
}
inline bool glm2::mat<4, 4, double>::operator!= (const mat& M) const
{
    __m256i ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_castpd_si256(this->_M[0].intrin());
    ymm1 = _mm256_castpd_si256(this->_M[1].intrin());
    ymm2 = _mm256_castpd_si256(this->_M[2].intrin());
    ymm3 = _mm256_castpd_si256(this->_M[3].intrin());
    ymm0 = _mm256_cmpeq_epi64(ymm0, M._M[0].intrin());
    ymm1 = _mm256_cmpeq_epi64(ymm1, M._M[1].intrin());
    ymm2 = _mm256_cmpeq_epi64(ymm2, M._M[2].intrin());
    ymm3 = _mm256_cmpeq_epi64(ymm3, M._M[3].intrin());
    ymm0 = _mm256_and_si256(ymm0, ymm1);
    ymm2 = _mm256_and_si256(ymm2, ymm3);
    ymm0 = _mm256_and_si256(ymm0, ymm2);
    return (_mm256_movemask_pd(_mm256_castsi256_pd(ymm0)) != 0x0F);
}

inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator+ (double d) const
{
    mat _M = *this;
    _M += d;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator+ (const col_type& v) const
{
    mat _M = *this;
    _M += v;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator+ (const mat& M) const
{
    mat _M = *this;
    _M += M;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator- (double d) const
{
    mat _M = *this;
    _M -= d;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator- (const col_type& v) const
{
    mat _M = *this;
    _M -= v;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator- (const mat& M) const
{
    mat _M = *this;
    _M -= M;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator* (double d) const
{
    mat _M = *this;
    _M *= d;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator/ (double d) const
{
    mat _M = *this;
    _M /= d;
    return _M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator+ (void) const
{
    return *this;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator- (void) const
{
    mat M;
    __m256i ymm0, ymm1;
    ymm0 = _mm256_set1_epi64x(0x8000000000000000);
    ymm1 = _mm256_castpd_si256(this->_M[0].intrin());
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    M._M[0] = _mm256_castsi256_pd(ymm1);
    ymm1 = _mm256_castpd_si256(this->_M[1].intrin());
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    M._M[1] = _mm256_castsi256_pd(ymm1);
    ymm1 = _mm256_castpd_si256(this->_M[2].intrin());
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    M._M[2] = _mm256_castsi256_pd(ymm1);
    ymm1 = _mm256_castpd_si256(this->_M[3].intrin());
    ymm0 = _mm256_xor_si256(ymm1, ymm0);
    M._M[3] = _mm256_castsi256_pd(ymm0);
    return M;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator++ (int)
{
    mat M = *this;
    ++*this;
    return M;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator++ (void)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(1.0);
    this->_M[0] = _mm256_add_pd(this->_M[0].intrin(), ymm0);
    this->_M[1] = _mm256_add_pd(this->_M[1].intrin(), ymm0);
    this->_M[2] = _mm256_add_pd(this->_M[2].intrin(), ymm0);
    this->_M[3] = _mm256_add_pd(this->_M[3].intrin(), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double> glm2::mat<4, 4, double>::operator-- (int)
{
    mat M = *this;
    --*this;
    return M;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator-- (void)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(1.0);
    this->_M[0] = _mm256_sub_pd(this->_M[0].intrin(), ymm0);
    this->_M[1] = _mm256_sub_pd(this->_M[1].intrin(), ymm0);
    this->_M[2] = _mm256_sub_pd(this->_M[2].intrin(), ymm0);
    this->_M[3] = _mm256_sub_pd(this->_M[3].intrin(), ymm0);
    return *this;
}

inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator+= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_add_pd(this->_M[0].intrin(), ymm0);
    this->_M[1] = _mm256_add_pd(this->_M[1].intrin(), ymm0);
    this->_M[2] = _mm256_add_pd(this->_M[2].intrin(), ymm0);
    this->_M[3] = _mm256_add_pd(this->_M[3].intrin(), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator+= (const col_type& v)
{
    this->_M[0] = _mm256_add_pd(this->_M[0].intrin(), v.intrin());
    this->_M[1] = _mm256_add_pd(this->_M[1].intrin(), v.intrin());
    this->_M[2] = _mm256_add_pd(this->_M[2].intrin(), v.intrin());
    this->_M[3] = _mm256_add_pd(this->_M[3].intrin(), v.intrin());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator+= (const mat& M)
{
    this->_M[0] = _mm256_add_pd(this->_M[0].intrin(), M._M[0].intrin());
    this->_M[1] = _mm256_add_pd(this->_M[1].intrin(), M._M[1].intrin());
    this->_M[2] = _mm256_add_pd(this->_M[2].intrin(), M._M[2].intrin());
    this->_M[3] = _mm256_add_pd(this->_M[3].intrin(), M._M[3].intrin());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator-= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_sub_pd(this->_M[0].intrin(), ymm0);
    this->_M[1] = _mm256_sub_pd(this->_M[1].intrin(), ymm0);
    this->_M[2] = _mm256_sub_pd(this->_M[2].intrin(), ymm0);
    this->_M[3] = _mm256_sub_pd(this->_M[3].intrin(), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator-= (const col_type& v)
{
    this->_M[0] = _mm256_sub_pd(this->_M[0].intrin(), v.intrin());
    this->_M[1] = _mm256_sub_pd(this->_M[1].intrin(), v.intrin());
    this->_M[2] = _mm256_sub_pd(this->_M[2].intrin(), v.intrin());
    this->_M[3] = _mm256_sub_pd(this->_M[3].intrin(), v.intrin());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator-= (const mat& M)
{
    this->_M[0] = _mm256_sub_pd(this->_M[0].intrin(), M._M[0].intrin());
    this->_M[1] = _mm256_sub_pd(this->_M[1].intrin(), M._M[1].intrin());
    this->_M[2] = _mm256_sub_pd(this->_M[2].intrin(), M._M[2].intrin());
    this->_M[3] = _mm256_sub_pd(this->_M[3].intrin(), M._M[3].intrin());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator*= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_mul_pd(this->_M[0].intrin(), ymm0);
    this->_M[1] = _mm256_mul_pd(this->_M[1].intrin(), ymm0);
    this->_M[2] = _mm256_mul_pd(this->_M[2].intrin(), ymm0);
    this->_M[3] = _mm256_mul_pd(this->_M[3].intrin(), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator*= (const col_type& v)
{
    this->_M[0] = _mm256_mul_pd(this->_M[0].intrin(), v.intrin());
    this->_M[1] = _mm256_mul_pd(this->_M[1].intrin(), v.intrin());
    this->_M[2] = _mm256_mul_pd(this->_M[2].intrin(), v.intrin());
    this->_M[3] = _mm256_mul_pd(this->_M[3].intrin(), v.intrin());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator/= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_div_pd(this->_M[0].intrin(), ymm0);
    this->_M[1] = _mm256_div_pd(this->_M[1].intrin(), ymm0);
    this->_M[2] = _mm256_div_pd(this->_M[2].intrin(), ymm0);
    this->_M[3] = _mm256_div_pd(this->_M[3].intrin(), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator/= (const col_type& v)
{
    this->_M[0] = _mm256_div_pd(this->_M[0].intrin(), v.intrin());
    this->_M[1] = _mm256_div_pd(this->_M[1].intrin(), v.intrin());
    this->_M[2] = _mm256_div_pd(this->_M[2].intrin(), v.intrin());
    this->_M[3] = _mm256_div_pd(this->_M[3].intrin(), v.intrin());
    return *this;
}

inline  glm2::mat<4, 4, double>::col_type&  glm2::mat<4, 4, double>::operator[] (uint32_t i)
{
    return this->_M[i];
}
inline const  glm2::mat<4, 4, double>::col_type&  glm2::mat<4, 4, double>::operator[] (uint32_t i) const
{
    return this->_M[i];
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::load(const double* src)
{
    this->_M[0].load(src + 0);
    this->_M[1].load(src + 4);
    this->_M[2].load(src + 8);
    this->_M[3].load(src + 12);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::load(const col_type* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    this->_M[2] = src[2];
    this->_M[3] = src[3];
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::load(const __m256d* src)
{
    this->_M[0] = src[0];
    this->_M[1] = src[1];
    this->_M[2] = src[2];
    this->_M[3] = src[3];
    return *this;
}
inline void glm2::mat<4, 4, double>::store(double* dst) const
{
    this->_M[0].store(dst + 0);
    this->_M[1].store(dst + 4);
    this->_M[2].store(dst + 8);
    this->_M[3].store(dst + 12);
}
inline void glm2::mat<4, 4, double>::store(col_type* dst) const
{
    dst[0] = this->_M[0];
    dst[1] = this->_M[1];
    dst[2] = this->_M[2];
    dst[3] = this->_M[3];
}
inline void glm2::mat<4, 4, double>::store(__m256d* dst) const
{
    dst[0] = this->_M[0].intrin();
    dst[1] = this->_M[1].intrin();
    dst[2] = this->_M[2].intrin();
    dst[3] = this->_M[3].intrin();
}

inline double*  glm2::mat<4, 4, double>::value_ptr(mat& M)
{
    return col_type::value_ptr(M._M);
}
inline double*  glm2::mat<4, 4, double>::value_ptr(mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}
inline const double*  glm2::mat<4, 4, double>::value_ptr(const mat& M)
{
    return col_type::value_ptr(M._M);
}
inline const double*  glm2::mat<4, 4, double>::value_ptr(const mat* Mv)
{
    return col_type::value_ptr(Mv->_M);
}

inline __m256d*  glm2::mat<4, 4, double>::intrin_ptr(mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline __m256d*  glm2::mat<4, 4, double>::intrin_ptr(mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}
inline const __m256d*  glm2::mat<4, 4, double>::intrin_ptr(const mat& M)
{
    return col_type::intrin_ptr(M._M);
}
inline const __m256d*  glm2::mat<4, 4, double>::intrin_ptr(const mat* Mv)
{
    return col_type::intrin_ptr(Mv->_M);
}