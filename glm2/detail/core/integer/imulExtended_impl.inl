#pragma once

inline void glm2::detail::core::integer::imulExtended::_default_i32v(const int32_t* x, const int32_t* y, int32_t* msb, int32_t* lsb, const uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
    {
        const int64_t x64 = static_cast<int64_t>(x[i]);
        const int64_t y64 = static_cast<int64_t>(y[i]);
        const int64_t res = x64 * y64;
        lsb[i] = static_cast<int32_t>(res);
        msb[i] = static_cast<int32_t>(res >> 32);
    }
}