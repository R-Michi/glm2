#pragma once

inline void glm2::detail::core::integer::usubBorrow::_default_u32v(const uint32_t* x, const uint32_t* y, uint32_t* res, uint32_t* borrow, const uint32_t n)
{
    #pragma unroll_completely
    for(uint32_t i = 0; i < n; i++)
    {
        const uint32_t a = y[i] - x[i];
        const uint32_t b = 0x0000000100000000ll + (static_cast<int64_t>(x[i]) - static_cast<int64_t>(y[i]));
        borrow[i] = (x[i] >= y[i]);
        res[i] = borrow[i] ? a : b;
    }
}
