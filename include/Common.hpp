#ifndef MEISTERLAMATHS_COMMON_HPP
#define MEISTERLAMATHS_COMMON_HPP

#include "Meta.hpp"
#include <cmath>

// Currently only wrapping std functions
namespace MeisterLamaths
{
    ML_FUNC_DECL ML_FLOAT ToRads(ML_FLOAT x)
    {
        return (x / 180) * PI;
    }

    ML_FUNC_DECL ML_FLOAT ToDegs(ML_FLOAT x)
    {
        return (x / PI) * 180;
    }

    ML_FUNC_DECL ML_FLOAT Sin(ML_FLOAT x)
    {
        return std::sin(x);
    }

    ML_FUNC_DECL ML_FLOAT Asin(ML_FLOAT x)
    {
        return std::asin(x);
    }

    ML_FUNC_DECL ML_FLOAT Cos(ML_FLOAT x)
    {
        return std::cos(x);
    }

    ML_FUNC_DECL ML_FLOAT Acos(ML_FLOAT x)
    {
        return std::acos(x);
    }

    ML_FUNC_DECL ML_FLOAT Tan(ML_FLOAT x)
    {
        return std::tan(x);
    }

    ML_FUNC_DECL ML_FLOAT Atan(ML_FLOAT x)
    {
        return std::atan(x);
    }

    ML_FUNC_DECL ML_FLOAT Pow(ML_FLOAT x, ML_FLOAT y)
    {
        return std::pow(x, y);
    }

    ML_FUNC_DECL ML_FLOAT Exp(ML_FLOAT x)
    {
        return std::exp(x);
    }

    ML_FUNC_DECL ML_FLOAT Log(ML_FLOAT x)
    {
        return std::log(x);
    }

    ML_FUNC_DECL ML_FLOAT Log10(ML_FLOAT x)
    {
        return std::log10(x);
    }

    ML_FUNC_DECL ML_FLOAT Log2(ML_FLOAT x)
    {
        return std::log2(x);
    }

    ML_FUNC_DECL ML_FLOAT Floor(ML_FLOAT x)
    {
        return std::floor(x);
    }

    ML_FUNC_DECL ML_FLOAT Ceil(ML_FLOAT x)
    {
        return std::ceil(x);
    }

    ML_FUNC_DECL ML_FLOAT Round(ML_FLOAT x)
    {
        return std::round(x);
    }

    ML_FUNC_DECL ML_FLOAT Trunc(ML_FLOAT x)
    {
        return std::trunc(x);
    }
}

#endif //MEISTERLAMATHS_COMMON_HPP