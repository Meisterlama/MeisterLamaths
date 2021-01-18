//
// Created by lama on 16/12/2020.
//

#ifndef MEISTERLAMATHS_VECTOR3_HPP
#define MEISTERLAMATHS_VECTOR3_HPP

#include "Meta.hpp"
#include <type_traits>
#include <concepts>
#include <cmath>


namespace MeisterLamaths
{
    template<typename T>
    class Vector3
    {
    public:
        union
        {
            struct
            {
                T X;
                T Y;
                T Z;
            };
            T values[3];
        };

        ML_FUNC_DECL Vector3(T x = 0)
            : X(x), Y(x), Z(x)
        {}

        ML_FUNC_DECL Vector3(T x, T y, T z)
            : X(x), Y(y), Z(z)
        {}

        ML_FUNC_DECL Vector3(const Vector3& vec) = default;
        ML_FUNC_DECL Vector3(Vector3&& vec) noexcept = default;
        ~Vector3() = default;

        [[nodiscard]] ML_FUNC_DECL ML_FLOAT DotProduct(const Vector3& v) const;

        // Compute the amplitude without computing the sqrt
        // Valid for comparisons, but actually equals to length squared
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Amplitude() const;

        // Return the length of the vector
        // If you only need it for comparison consider using Amplitude()
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Length() const;

        // Scale in place
        ML_FUNC_DECL Vector3& Scale(const ML_FLOAT& factor);

        // Get a scaled copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector3 GetScaled(const ML_FLOAT& factor) const;

        // Normalize in place
        ML_FUNC_DECL Vector3& Normalize();

        // Get a normalized copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector3 GetNormalized() const;

        // Normalize in place.
        // Check for length != 0
        ML_FUNC_DECL Vector3& SafeNormalize();

        // Get a normalized copy of the vector
        // If vector length == 0, return Vector{0}
        [[nodiscard]] ML_FUNC_DECL Vector3 GetSafeNormalized() const;

        [[nodiscard]] ML_FUNC_DECL bool Equals(const Vector3& rhs) const;
        [[nodiscard]] ML_FUNC_DECL bool IsZero() const;

        ML_FUNC_DECL Vector3& operator=(const Vector3& other);

        [[nodiscard]] ML_FUNC_DECL bool operator==(const Vector3& rhs) const;

        [[nodiscard]] ML_FUNC_DECL bool operator!=(const Vector3& rhs) const;

        [[nodiscard]] ML_FUNC_DECL const T& operator[](int idx) const;
        [[nodiscard]] ML_FUNC_DECL T& operator[](int idx);

        ML_FUNC_DECL Vector3& Add(const Vector3& vec);
        [[nodiscard]] ML_FUNC_DECL Vector3 operator+(const Vector3& rhs) const;
        ML_FUNC_DECL Vector3& operator+=(const Vector3& vec);
        ML_FUNC_DECL Vector3& operator++();

        ML_FUNC_DECL Vector3& Sub(const Vector3& vec);
        [[nodiscard]] ML_FUNC_DECL Vector3 operator-(const Vector3& rhs) const;
        ML_FUNC_DECL Vector3& operator-=(const Vector3& vec);
        ML_FUNC_DECL Vector3& operator--();

        [[nodiscard]] ML_FUNC_DECL Vector3 operator*(const ML_FLOAT& scalar) const;
        ML_FUNC_DECL Vector3& operator*=(const ML_FLOAT& scalar);

        [[nodiscard]] ML_FUNC_DECL Vector3 operator/(const ML_FLOAT& scalar) const;
        ML_FUNC_DECL Vector3& operator/=(const ML_FLOAT& scalar);

    };
    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector3<T> operator-(Vector3<T> vec);

    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector3<T> operator*(const ML_FLOAT& scalar, Vector3<T> rhs);

    template<typename T>
    [[nodiscard]] ML_FUNC_DECL Vector3<T> Lerp(Vector3<T> begin, Vector3<T> end, ML_FLOAT ratio);

#ifdef ML_IMPLEMENTATION
    #include "inl/Vector3.inl.hpp"
#endif //ML_IMPLEMENTATION
}
#endif //MEISTERLAMATHS_VECTOR3_HPP
