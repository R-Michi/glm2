/**
* @file     test.h
* @brief    Utility functions for library testing.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "../glm2/glm2.h"
#include <glm/glm.hpp>

#define ATTRIBUTE_UNDERLINE     "\u001b[4m"
#define COLOR_RED               "\u001b[38;5;1m"
#define COLOR_GREEN             "\u001b[38;5;2m"
#define COLOR_YELLOW            "\u001b[38;5;3m"
#define COLOR_RESET             "\u001b[0m"
#define CMP_BYPASS              8

namespace glm2
{
    namespace test
    {
        extern int count_true, count_false;

        // Some floating-point results are off by 1, 2 or 3, if you bit-cast them to integers.
        // This is due to the nature of the limited floating-point precision, caused by a different order
        // of mathematical operations of my library. This compare function will take the inprecision
        // into consideration and the magnitude of the bypass can be adjusted with the 'bypass' parameter.
        template<typename T>
        bool cmp(T _a, T _b, int32_t bypass)
        {
            bool res = false;
            // get rid of the 1-bit inprecision, if the value is floating-point
            if(std::is_floating_point<T>::value)
            {
                // decide between float and double
                if(sizeof(T) == sizeof(float))
                {
                    // bit cast parameters
                    int32_t a = glm2::detail::util::bit_cast<int32_t, float>(_a);
                    int32_t b = glm2::detail::util::bit_cast<int32_t, float>(_b);
                    // normalize values
                    b = a - b;
                    res = (b <= bypass && b >= -bypass);
                }
                else if(sizeof(T) == sizeof(double))
                {
                    // bit cast parameters
                    int64_t a = glm2::detail::util::bit_cast<int64_t, double>(_a);
                    int64_t b = glm2::detail::util::bit_cast<int64_t, double>(_b);
                    // normalize values
                    b = a - b;
                    res = (b <= bypass && b >= -bypass);
                }
            }
            // do normal comparison
            else
                res = (_a == _b);
            return res;
        }

        template<length_t L, typename T>
        void print_vec_glm2(const vec<L, T>& v, std::string& line)
        {
            static const char table[4] = {'x', 'y', 'z', 'w'};
            std::stringstream ss;
            ss << std::setprecision(6) << std::fixed;
            for(length_t i = 0; i < L; i++)
                ss << table[i] << ": " << v[i] << "    ";
            line = ss.str();
        }

        template<length_t L, typename T>
        void print_vec_glm(const glm::vec<L, T>& v, std::string& line)
        {
            static const char table[4] = {'x', 'y', 'z', 'w'};
            std::stringstream ss;
            ss << std::setprecision(6) << std::fixed;
            for(length_t i = 0; i < L; i++)
                ss << table[i] << ": " << v[i] << "    ";
            line = ss.str();
        }

        template<length_t N, length_t M, typename T>
        void print_mat_glm2(const mat<N, M, T>& m, std::vector<std::string>& lines)
        {
            static const char table[4] = {'x', 'y', 'z', 'w'};
            for(length_t i = 0; i < M; i++)
            {
                std::stringstream ss;
                ss << std::setprecision(6) << std::fixed;
                for(length_t j = 0; j < N; j++)
                    ss << table[j] << i << ": " << m[j][i] << "    ";
                lines.push_back(ss.str());
            }
        }

        template<length_t N, length_t M, typename T>
        void print_mat_glm(const glm::mat<N, M, T>& m, std::vector<std::string>& lines)
        {
            static const char table[4] = {'x', 'y', 'z', 'w'};
            for(length_t i = 0; i < M; i++)
            {
                std::stringstream ss;
                ss << std::setprecision(6) << std::fixed;
                for(length_t j = 0; j < N; j++)
                    ss << table[j] << i << ": " << m[j][i] << "    ";
                lines.push_back(ss.str());
            }
        }

        template<length_t L, typename T>
        bool cmp_vec(const glm::vec<L, T>& _glm, const glm2::vec<L, T>& _glm2)
        {
            for(length_t i = 0; i < L; i++)
            {
                if(!cmp<T>(_glm[i], _glm2[i], CMP_BYPASS))
                    return false;
            }
            return true;
        }

        template<length_t N, length_t M, typename T>
        bool cmp_mat(const glm::mat<N, M, T>& _glm, const glm2::mat<N, M, T>& _glm2)
        {
            for(length_t i = 0; i < M; i++)
            {
                for(length_t j = 0; j < N; j++)
                {
                    if(!cmp<T>(_glm[j][i], _glm2[j][i], CMP_BYPASS))
                        return false;
                }
            }
            return true;
        }

        template<typename T>
        void print_single(T _glm, T _glm2, const std::string& function)
        {
            bool b = cmp<T>(_glm, _glm2, CMP_BYPASS);
            b ? ++count_true : ++count_false;
            std::cout << std::setprecision(6) << std::fixed;
            std::cout << COLOR_YELLOW ATTRIBUTE_UNDERLINE << function << ":" << COLOR_RESET << std::endl;
            std::cout << (b ? COLOR_GREEN : COLOR_RED);
            std::cout << "    [glm]:  " << _glm << std::endl;
            std::cout << "    [glm2]: " << _glm2 << std::endl;
            std::cout << COLOR_RESET << std::endl;
        }

        template<length_t L, typename T>
        void print_vec(const glm::vec<L, T>& _glm, const vec<L, T>& _glm2, const std::string& function)
        {
            std::string line_glm, line_glm2;
            bool b = cmp_vec<L, T>(_glm, _glm2);
            b ? ++count_true : ++count_false;
            print_vec_glm<L, T>(_glm, line_glm);
            print_vec_glm2<L, T>(_glm2, line_glm2);
            std::cout << COLOR_YELLOW ATTRIBUTE_UNDERLINE << function << ":" << COLOR_RESET << std::endl;
            std::cout << (b ? COLOR_GREEN : COLOR_RED);
            std::cout << "    [glm]:  " << line_glm << std::endl;
            std::cout << "    [glm2]: " << line_glm2 << std::endl;
            std::cout << COLOR_RESET << std::endl;
        }

        template<length_t N, length_t M, typename T>
        void print_mat(const glm::mat<N, M, T>& _glm, const mat<N, M, T>& _glm2, const std::string& function)
        {
            std::vector<std::string> lines_glm, lines_glm2;
            bool b = cmp_mat<N, M, T>(_glm, _glm2);
            b ? ++count_true : ++count_false;
            print_mat_glm<N, M, T>(_glm, lines_glm);
            print_mat_glm2<N, M, T>(_glm2, lines_glm2);
            std::cout << COLOR_YELLOW ATTRIBUTE_UNDERLINE << function << ":" << COLOR_RESET << std::endl;
            std::cout << (b ? COLOR_GREEN : COLOR_RED);
            std::cout << "    [glm]:  " << lines_glm[0] << std::endl;
            for(int i = 1; i < lines_glm.size(); i++)
                std::cout << "            " << lines_glm[i] << std::endl;
            std::cout << "    [glm2]: " << lines_glm2[0] << std::endl;
            for(int i = 1; i < lines_glm2.size(); i++)
                std::cout << "            " << lines_glm2[i] << std::endl;
            std::cout << COLOR_RESET << std::endl;
        }

        void run_test(void);
    }
}