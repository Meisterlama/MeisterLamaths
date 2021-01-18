//
// Created by lama on 16/12/2020.
//

#ifndef MEISTERLAMATHS_VECTOR2_HPP
#define MEISTERLAMATHS_VECTOR2_HPP

#include "Meta.hpp"
#include <cmath>

namespace MeisterLamaths
{
    template<typename T>
    class Vector2
    {
    public:
        union
        {
            struct
            {
                T X;
                T Y;
            };
            T values[2];
        };

        ML_FUNC_DECL Vector2(T x = 0)
            : X(x), Y(x)
        {}

        ML_FUNC_DECL Vector2(T x, T y)
            : X(x), Y(y)
        {}

        ML_FUNC_DECL Vector2(const Vector2& vec) = default;
        ML_FUNC_DECL Vector2(Vector2&& vec) noexcept = default;
        ~Vector2() = default;

        [[nodiscard]] ML_FUNC_DECL ML_FLOAT DotProduct(const Vector2& v) const;

        // Compute the amplitude without computing the sqrt
        // Valid for comparisons, but actually equals to length squared
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Amplitude() const;

        // Return the length of the vector
        // If you only need it for comparison consider using Amplitude()
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Length() const;

        // Scale in place
        ML_FUNC_DECL Vector2& Scale(const ML_FLOAT& factor);

        // Get a scaled copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector2 GetScaled(const ML_FLOAT& factor) const;

        // Normalize in place
        ML_FUNC_DECL Vector2& Normalize();

        // Get a normalized copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector2 GetNormalized() const;

        // Normalize in place.
        // Check for length != 0
        ML_FUNC_DECL Vector2& SafeNormalize();

        // Get a normalized copy of the vector
        // If vector length == 0, return Vector{0}
        [[nodiscard]] ML_FUNC_DECL Vector2 GetSafeNormalized() const;

        [[nodiscard]] ML_FUNC_DECL bool Equals(const Vector2& rhs) const;
        [[nodiscard]] ML_FUNC_DECL bool IsZero() const;

        ML_FUNC_DECL Vector2& operator=(const Vector2& other);

        [[nodiscard]] ML_FUNC_DECL bool operator==(const Vector2& rhs) const;

        [[nodiscard]] ML_FUNC_DECL bool operator!=(const Vector2& rhs) const;

        [[nodiscard]] ML_FUNC_DECL const T& operator[](int idx) const;
        [[nodiscard]] ML_FUNC_DECL T& operator[](int idx);

        ML_FUNC_DECL Vector2& Add(const Vector2& vec);
        [[nodiscard]] ML_FUNC_DECL Vector2 operator+(const Vector2& rhs) const;
        ML_FUNC_DECL Vector2& operator+=(const Vector2& vec);
        ML_FUNC_DECL Vector2& operator++();

        ML_FUNC_DECL Vector2& Sub(const Vector2& vec);
        [[nodiscard]] ML_FUNC_DECL Vector2 operator-(const Vector2& rhs) const;
        ML_FUNC_DECL Vector2& operator-=(const Vector2& vec);
        ML_FUNC_DECL Vector2& operator--();

        [[nodiscard]] ML_FUNC_DECL Vector2 operator*(const ML_FLOAT& scalar) const;
        ML_FUNC_DECL Vector2& operator*=(const ML_FLOAT& scalar);

        [[nodiscard]] ML_FUNC_DECL Vector2 operator/(const ML_FLOAT& scalar) const;
        ML_FUNC_DECL Vector2& operator/=(const ML_FLOAT& scalar);


    };

    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector2<T> operator-(Vector2<T> vec);

    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector2<T> operator*(const ML_FLOAT& scalar, Vector2<T> rhs);

    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector2<T> Lerp(Vector2<T> begin, Vector2<T> end, ML_FLOAT ratio);

#ifdef ML_IMPLEMENTATION
    #include "inl/Vector2.inl.hpp"
#endif //ML_IMPLEMENTATION
}
#endif //MEISTERLAMATHS_VECTOR2_HPP
