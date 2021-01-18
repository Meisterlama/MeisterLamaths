#ifndef MEISTERLAMATHS_COMMON_HPP
#define MEISTERLAMATHS_COMMON_HPP

#include "Meta.hpp"
#include <cmath>

// Currently only wrapping std functions
namespace MeisterLamaths
{
    [[nodiscard]] ML_FUNC_DECL ML_FLOAT ToRads(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT ToDegs(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Sin(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Asin(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Cos(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Acos(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Tan(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Atan(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Pow(ML_FLOAT x, ML_FLOAT y);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Sqrt(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Exp(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Log(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Log10(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Log2(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Floor(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Ceil(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Round(ML_FLOAT x);

    [[nodiscard]] ML_FUNC_DECL ML_FLOAT Trunc(ML_FLOAT x);

    #include "inl/Common.inl.hpp"
}

#endif //MEISTERLAMATHS_COMMON_HPP