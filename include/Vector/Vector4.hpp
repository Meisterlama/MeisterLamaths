//
// Created by lama on 16/12/2020.
//

#ifndef MEISTERLAMATHS_VECTOR4_HPP
#define MEISTERLAMATHS_VECTOR4_HPP

#include "Meta.hpp"
#include <type_traits>
#include <concepts>
#include <cmath>


namespace MeisterLamaths
{
    template<typename T>
    class Vector4
    {
    public:
        union
        {
            struct
            {
                T X;
                T Y;
                T Z;
                T W;
            };
            T values[4];
        };

        ML_FUNC_DECL Vector4(T x = 0)
                : X(x), Y(x), Z(x), W(x)
        {}

        ML_FUNC_DECL Vector4(T x, T y, T z, T w)
                : X(x), Y(y), Z(z), W(w)
        {}

        ML_FUNC_DECL Vector4(const Vector4& vec) = default;
        ML_FUNC_DECL Vector4(Vector4&& vec) noexcept = default;
        ~Vector4() = default;

        [[nodiscard]] ML_FUNC_DECL ML_FLOAT DotProduct(const Vector4& v) const;

        // Compute the amplitude without computing the sqrt
        // Valid for comparisons, but actually equals to length squared
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Amplitude() const;

        // Return the length of the vector
        // If you only need it for comparison consider using Amplitude()
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Length() const;

        // Scale in place
        ML_FUNC_DECL Vector4& Scale(const ML_FLOAT& factor);

        // Get a scaled copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector4 GetScaled(const ML_FLOAT& factor) const;

        // Normalize in place
        ML_FUNC_DECL Vector4& Normalize();

        // Get a normalized copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector4 GetNormalized() const;

        // Normalize in place.
        // Check for length != 0
        ML_FUNC_DECL Vector4& SafeNormalize();

        // Get a normalized copy of the vector
        // If vector length == 0, return Vector{0}
        [[nodiscard]] ML_FUNC_DECL Vector4 GetSafeNormalized() const;

        [[nodiscard]] ML_FUNC_DECL bool Equals(const Vector4& rhs) const;
        [[nodiscard]] ML_FUNC_DECL bool IsZero() const;

        ML_FUNC_DECL Vector4& operator=(const Vector4& other);

        [[nodiscard]] ML_FUNC_DECL bool operator==(const Vector4& rhs) const;

        [[nodiscard]] ML_FUNC_DECL bool operator!=(const Vector4& rhs) const;

        [[nodiscard]] ML_FUNC_DECL const T& operator[](int idx) const;
        [[nodiscard]] ML_FUNC_DECL T& operator[](int idx);

        ML_FUNC_DECL Vector4& Add(const Vector4& vec);
        [[nodiscard]] ML_FUNC_DECL Vector4 operator+(const Vector4& rhs) const;
        ML_FUNC_DECL Vector4& operator+=(const Vector4& vec);
        ML_FUNC_DECL Vector4& operator++();

        ML_FUNC_DECL Vector4& Sub(const Vector4& vec);
        [[nodiscard]] ML_FUNC_DECL Vector4 operator-(const Vector4& rhs) const;
        ML_FUNC_DECL Vector4& operator-=(const Vector4& vec);
        ML_FUNC_DECL Vector4& operator--();

        [[nodiscard]] ML_FUNC_DECL Vector4 operator*(const ML_FLOAT& scalar) const;
        ML_FUNC_DECL Vector4& operator*=(const ML_FLOAT& scalar);

        [[nodiscard]] ML_FUNC_DECL Vector4 operator/(const ML_FLOAT& scalar) const;
        ML_FUNC_DECL Vector4& operator/=(const ML_FLOAT& scalar);

    };
    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector4<T> operator-(Vector4<T> vec);

    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector4<T> operator*(const ML_FLOAT& scalar, Vector4<T> rhs);

    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector4<T> Lerp(Vector4<T> begin, Vector4<T> end, ML_FLOAT ratio);

#ifdef ML_IMPLEMENTATION
#include "inl/Vector4.inl.hpp"
#endif //ML_IMPLEMENTATION
}
#endif //MEISTERLAMATHS_VECTOR4_HPP
