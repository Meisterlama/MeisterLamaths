//
// Created by lama on 16/12/2020.
//

#ifndef MEISTERLAMATHS_VECTOR3_H
#define MEISTERLAMATHS_VECTOR3_H

#include "Meta.h"
#include <type_traits>
#include <concepts>
#include <cmath>


namespace MeisterLamaths
{
    template<ArithmeticType T>
    class Vector3 : Vector
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

    template<ArithmeticType T>
    ML_FUNC_DECL ML_FLOAT Vector3<T>::DotProduct(const Vector3& v) const
    {
        return (X * v.X + Y * v.Y + Z * v.Z);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL ML_FLOAT Vector3<T>::Amplitude() const
    {
        return DotProduct(*this);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL ML_FLOAT Vector3<T>::Length() const
    {
        return std::sqrt(Amplitude());
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::Add(const Vector3& vec)
    {
        *this += vec;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::Sub(const Vector3& vec)
    {
        *this -= vec;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::Scale(const ML_FLOAT& factor)
    {
        *this *= factor;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T> Vector3<T>::GetScaled(const ML_FLOAT& factor) const
    {
        return *this * factor;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::Normalize()
    {
        *this /= Length();
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T> Vector3<T>::GetNormalized() const
    {
        return Vector3{*this} / Length();
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::SafeNormalize()
    {
        if (Amplitude() == 0) return *this;
        return Normalize();
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T> Vector3<T>::GetSafeNormalized() const
    {
        if (Amplitude() == 0) return Vector3<T>{0};
        return GetNormalized();
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector3<T>::Equals(const Vector3& rhs) const
    {
        return *this == rhs;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector3<T>::IsZero() const
    {
        return *this == Vector3<T>{0};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::operator=(const Vector3& other)
    {
        X = other.X;
        Y = other.Y;
        Z = other.Z;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector3<T>::operator==(const Vector3& rhs) const
    {
        return (X == rhs.X &&
                Y == rhs.Y &&
                Z == rhs.Z);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector3<T>::operator!=(const Vector3& rhs) const
    {
        return !(*this == rhs);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL const T& Vector3<T>::operator[](int idx) const
    {
        return values[idx];
    }

    template<ArithmeticType T>
    ML_FUNC_DECL T& Vector3<T>::operator[](int idx)
    {
        return values[idx];
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T> Vector3<T>::operator+(const Vector3& rhs) const
    {
        return Vector3<T>{X + rhs.X,
                          Y + rhs.Y,
                          Z + rhs.Z};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::operator+=(const Vector3& vec)
    {
        X += vec.X;
        Y += vec.Y;
        Z += vec.Z;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::operator++()
    {
        X++;
        Y++;
        Z++;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T> Vector3<T>::operator-(const Vector3& rhs) const
    {
        return Vector3<T>{X - rhs.X,
                          Y - rhs.Y,
                          Z - rhs.Z};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::operator-=(const Vector3& vec)
    {
        X -= vec.X;
        Y -= vec.Y;
        Z -= vec.Z;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::operator--()
    {
        X--;
        Y--;
        Z--;
        return *this;
    }

    // TODO: Forward declaration to improve header readability
    template<ArithmeticType T>
    [[nodiscard]] ML_FUNC_DECL Vector3<T> operator-(Vector3<T> vec)
    {
        return Vector3<T>{-vec.X, -vec.Y, -vec.Z};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T> Vector3<T>::operator*(const ML_FLOAT& scalar) const
    {
        return Vector3<T>{X * scalar,
                          Y * scalar,
                          Z * scalar};
    }

    // TODO: Forward declaration to improve header readability
    template<ArithmeticType T>
    [[nodiscard]] ML_FUNC_DECL Vector3<T> operator*(const ML_FLOAT& scalar, Vector3<T> rhs)
    {
        return rhs * scalar;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::operator*=(const ML_FLOAT& scalar)
    {
        X *= scalar;
        Y *= scalar;
        Z *= scalar;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T> Vector3<T>::operator/(const ML_FLOAT& scalar) const
    {
        return Vector3<T>{X / scalar,
                          Y / scalar,
                          Z / scalar};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector3<T>& Vector3<T>::operator/=(const ML_FLOAT& scalar)
    {
        X /= scalar;
        Y /= scalar;
        Z /= scalar;
        return *this;
    }

}
#endif //MEISTERLAMATHS_VECTOR3_H
