//
// Created by lama on 16/12/2020.
//

#ifndef MEISTERLAMATHS_META_H
#define MEISTERLAMATHS_META_H

#include <type_traits>
#include <concepts>

// Type definitions
#ifdef USE_DOUBLE_PRECISION
#define ML_FLOAT double
#else
#define ML_FLOAT float
#endif

// Inline definition
#ifdef INLINE_FUNCTIONS
#define ML_INLINE inline
#else
#define ML_INLINE
#endif

// Concatenate constexpr and eventual inline
#define ML_FUNC_DECL constexpr ML_INLINE

namespace MeisterLamaths
{
    template<typename T>
    concept ArithmeticType = std::is_arithmetic_v<T>;

    class Vector {};
    template<class T>
    concept VectorType = std::is_base_of_v<Vector, T>;

    // Magic numbers
    constexpr ML_FLOAT PI = 3.1415926535897932;

    constexpr ML_FLOAT EPSILON = 0.00000001;
}

#endif //MEISTERLAMATHS_META_H
