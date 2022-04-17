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
    *this = dv;
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
    *this = vv;
}
inline glm2::mat<4, 4, double>::mat(const __m256d* m256v)
{
    *this = m256v;
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
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator= (const double* dv)
{
    this->_M[0] = dv + 0 * sizeof(col_type);
    this->_M[1] = dv + 1 * sizeof(col_type);
    this->_M[2] = dv + 2 * sizeof(col_type);
    this->_M[3] = dv + 3 * sizeof(col_type);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator= (const col_type* vv)
{
    this->_M[0] = vv[0];
    this->_M[1] = vv[1];
    this->_M[2] = vv[2];
    this->_M[3] = vv[3];
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator= (const __m256d* m256v)
{
    this->_M[0] = m256v[0];
    this->_M[1] = m256v[1];
    this->_M[2] = m256v[2];
    this->_M[3] = m256v[3];
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
    ymm0 = _mm256_castpd_si256(this->_M[0]());
    ymm1 = _mm256_castpd_si256(this->_M[1]());
    ymm2 = _mm256_castpd_si256(this->_M[2]());
    ymm3 = _mm256_castpd_si256(this->_M[3]());
    ymm0 = _mm256_cmpeq_epi64(ymm0, M._M[0]());
    ymm1 = _mm256_cmpeq_epi64(ymm1, M._M[1]());
    ymm2 = _mm256_cmpeq_epi64(ymm2, M._M[2]());
    ymm3 = _mm256_cmpeq_epi64(ymm3, M._M[3]());
    ymm0 = _mm256_and_si256(ymm0, ymm1);
    ymm2 = _mm256_and_si256(ymm2, ymm3);
    ymm0 = _mm256_and_si256(ymm0, ymm2);
    return (_mm256_movemask_pd(_mm256_castsi256_pd(ymm0)) == 0x0F);
}
inline bool glm2::mat<4, 4, double>::operator!= (const mat& M) const
{
    __m256i ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_castpd_si256(this->_M[0]());
    ymm1 = _mm256_castpd_si256(this->_M[1]());
    ymm2 = _mm256_castpd_si256(this->_M[2]());
    ymm3 = _mm256_castpd_si256(this->_M[3]());
    ymm0 = _mm256_cmpeq_epi64(ymm0, M._M[0]());
    ymm1 = _mm256_cmpeq_epi64(ymm1, M._M[1]());
    ymm2 = _mm256_cmpeq_epi64(ymm2, M._M[2]());
    ymm3 = _mm256_cmpeq_epi64(ymm3, M._M[3]());
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
    ymm1 = _mm256_castpd_si256(this->_M[0]());
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    M._M[0] = _mm256_castsi256_pd(ymm1);
    ymm1 = _mm256_castpd_si256(this->_M[1]());
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    M._M[1] = _mm256_castsi256_pd(ymm1);
    ymm1 = _mm256_castpd_si256(this->_M[2]());
    ymm1 = _mm256_xor_si256(ymm1, ymm0);
    M._M[2] = _mm256_castsi256_pd(ymm1);
    ymm1 = _mm256_castpd_si256(this->_M[3]());
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
    this->_M[0] = _mm256_add_pd(this->_M[0](), ymm0);
    this->_M[1] = _mm256_add_pd(this->_M[1](), ymm0);
    this->_M[2] = _mm256_add_pd(this->_M[2](), ymm0);
    this->_M[3] = _mm256_add_pd(this->_M[3](), ymm0);
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
    this->_M[0] = _mm256_sub_pd(this->_M[0](), ymm0);
    this->_M[1] = _mm256_sub_pd(this->_M[1](), ymm0);
    this->_M[2] = _mm256_sub_pd(this->_M[2](), ymm0);
    this->_M[3] = _mm256_sub_pd(this->_M[3](), ymm0);
    return *this;
}

inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator+= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_add_pd(this->_M[0](), ymm0);
    this->_M[1] = _mm256_add_pd(this->_M[1](), ymm0);
    this->_M[2] = _mm256_add_pd(this->_M[2](), ymm0);
    this->_M[3] = _mm256_add_pd(this->_M[3](), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator+= (const col_type& v)
{
    this->_M[0] = _mm256_add_pd(this->_M[0](), v());
    this->_M[1] = _mm256_add_pd(this->_M[1](), v());
    this->_M[2] = _mm256_add_pd(this->_M[2](), v());
    this->_M[3] = _mm256_add_pd(this->_M[3](), v());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator+= (const mat& M)
{
    this->_M[0] = _mm256_add_pd(this->_M[0](), M._M[0]());
    this->_M[1] = _mm256_add_pd(this->_M[1](), M._M[1]());
    this->_M[2] = _mm256_add_pd(this->_M[2](), M._M[2]());
    this->_M[3] = _mm256_add_pd(this->_M[3](), M._M[3]());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator-= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_sub_pd(this->_M[0](), ymm0);
    this->_M[1] = _mm256_sub_pd(this->_M[1](), ymm0);
    this->_M[2] = _mm256_sub_pd(this->_M[2](), ymm0);
    this->_M[3] = _mm256_sub_pd(this->_M[3](), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator-= (const col_type& v)
{
    this->_M[0] = _mm256_sub_pd(this->_M[0](), v());
    this->_M[1] = _mm256_sub_pd(this->_M[1](), v());
    this->_M[2] = _mm256_sub_pd(this->_M[2](), v());
    this->_M[3] = _mm256_sub_pd(this->_M[3](), v());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator-= (const mat& M)
{
    this->_M[0] = _mm256_sub_pd(this->_M[0](), M._M[0]());
    this->_M[1] = _mm256_sub_pd(this->_M[1](), M._M[1]());
    this->_M[2] = _mm256_sub_pd(this->_M[2](), M._M[2]());
    this->_M[3] = _mm256_sub_pd(this->_M[3](), M._M[3]());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator*= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_mul_pd(this->_M[0](), ymm0);
    this->_M[1] = _mm256_mul_pd(this->_M[1](), ymm0);
    this->_M[2] = _mm256_mul_pd(this->_M[2](), ymm0);
    this->_M[3] = _mm256_mul_pd(this->_M[3](), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator*= (const col_type& v)
{
    this->_M[0] = _mm256_mul_pd(this->_M[0](), v());
    this->_M[1] = _mm256_mul_pd(this->_M[1](), v());
    this->_M[2] = _mm256_mul_pd(this->_M[2](), v());
    this->_M[3] = _mm256_mul_pd(this->_M[3](), v());
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator/= (double d)
{
    __m256d ymm0;
    ymm0 = _mm256_set1_pd(d);
    this->_M[0] = _mm256_div_pd(this->_M[0](), ymm0);
    this->_M[1] = _mm256_div_pd(this->_M[1](), ymm0);
    this->_M[2] = _mm256_div_pd(this->_M[2](), ymm0);
    this->_M[3] = _mm256_div_pd(this->_M[3](), ymm0);
    return *this;
}
inline glm2::mat<4, 4, double>& glm2::mat<4, 4, double>::operator/= (const col_type& v)
{
    this->_M[0] = _mm256_div_pd(this->_M[0](), v());
    this->_M[1] = _mm256_div_pd(this->_M[1](), v());
    this->_M[2] = _mm256_div_pd(this->_M[2](), v());
    this->_M[3] = _mm256_div_pd(this->_M[3](), v());
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