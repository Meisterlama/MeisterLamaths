#ifndef MEISTERLAMATHS_COMMON_INL_HPP
#define MEISTERLAMATHS_COMMON_INL_HPP

#include "Meta.hpp"
#include <cmath>

// Currently only wrapping std functions
namespace MeisterLamaths
{
    [[nodiscard]] ML_FUNC_DECL ML_FLOAT ToRads(ML_FLOAT x)
    {
        return (x / 180) * PI;
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT ToDegs(ML_FLOAT x)
    {
        return (x / PI) * 180;
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Sin(ML_FLOAT x)
    {
        return std::sin(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Asin(ML_FLOAT x)
    {
        return std::asin(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Cos(ML_FLOAT x)
    {
        return std::cos(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Acos(ML_FLOAT x)
    {
        return std::acos(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Tan(ML_FLOAT x)
    {
        return std::tan(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Atan(ML_FLOAT x)
    {
        return std::atan(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Pow(ML_FLOAT x, ML_FLOAT y)
    {
        return std::pow(x, y);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Sqrt(ML_FLOAT x)
    {
        return std::sqrt(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Exp(ML_FLOAT x)
    {
        return std::exp(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Log(ML_FLOAT x)
    {
        return std::log(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Log10(ML_FLOAT x)
    {
        return std::log10(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Log2(ML_FLOAT x)
    {
        return std::log2(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Floor(ML_FLOAT x)
    {
        return std::floor(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Ceil(ML_FLOAT x)
    {
        return std::ceil(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Round(ML_FLOAT x)
    {
        return std::round(x);
    }

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Trunc(ML_FLOAT x)
    {
        return std::trunc(x);
    }
}

#endif //MEISTERLAMATHS_COMMON_INL_HPP