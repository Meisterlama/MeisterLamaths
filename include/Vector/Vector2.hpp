//
// Created by lama on 16/12/2020.
//

#ifndef MEISTERLAMATHS_VECTOR2_H
#define MEISTERLAMATHS_VECTOR2_H

#include "Meta.h"
#include <type_traits>
#include <concepts>
#include <cmath>

namespace MeisterLamaths
{
    template<typename T>
    concept ArithmeticType = std::is_arithmetic_v<T>;

    /**
     *
     * @tparam T A valid type to do arithmetic on it
     */
    template<ArithmeticType T>
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

        constexpr Vector2(T x = 0) : X(x), Y(x)
        {}

        constexpr Vector2(T x, T y) : X(x), Y(y)
        {}

        constexpr Vector2(const Vector2& vec) = default;
        constexpr Vector2(Vector2&& vec) noexcept = default;
        ~Vector2() = default;

        [[nodiscard]] ML_FLOAT DotProduct(const Vector2& v) const;

        // Compute the amplitude without computing the sqrt
        // Valid for comparisons, but actually equals to length squared
        [[nodiscard]] ML_FLOAT Amplitude() const;

        // Return the length of the vector
        // If you only need it for comparison consider using Amplitude()
        [[nodiscard]] ML_FLOAT Length() const;

        // Scale in place
        Vector2& Scale(const ML_FLOAT& factor);

        // Get a scaled copy of the vector
        [[nodiscard]] Vector2 GetScaled(const ML_FLOAT& factor) const;

        // Normalize in place
        Vector2& Normalize();

        // Get a normalized copy of the vector
        [[nodiscard]] Vector2 GetNormalized() const;

        // Normalize in place.
        // Check for length != 0
        Vector2& SafeNormalize();

        // Get a normalized copy of the vector
        // If vector length == 0, return Vector{0}
        Vector2 GetSafeNormalized() const;

        bool Equals(const Vector2& rhs) const;
        [[nodiscard]] bool IsZero() const;

        Vector2& operator=(const Vector2& other);

        [[nodiscard]] bool operator==(const Vector2& rhs) const;

        [[nodiscard]] bool operator!=(const Vector2& rhs) const;


        [[nodiscard]] const T& operator[](int idx) const;
        [[nodiscard]] T& operator[](int idx);

        Vector2& Add(const Vector2& vec);
        [[nodiscard]] Vector2 operator+(const Vector2& rhs) const;
        Vector2& operator+=(const Vector2& vec);
        Vector2& operator++();

        Vector2& Sub(const Vector2& vec);
        [[nodiscard]] Vector2 operator-(const Vector2& rhs) const;
        Vector2& operator-=(const Vector2& vec);
        Vector2& operator--();

        [[nodiscard]] Vector2 operator*(const ML_FLOAT& scalar) const;
        Vector2& operator*=(const ML_FLOAT& scalar);

        [[nodiscard]] Vector2 operator/(const ML_FLOAT& scalar) const;
        Vector2& operator/=(const ML_FLOAT& scalar);

    };

    template<ArithmeticType T>
    ML_FLOAT Vector2<T>::DotProduct(const Vector2& v) const
    {
        return (X * v.X + Y * v.Y);
    }

    template<ArithmeticType T>
    ML_FLOAT Vector2<T>::Amplitude() const
    {
        return X * X + Y * Y;
    }

    template<ArithmeticType T>
    ML_FLOAT Vector2<T>::Length() const
    {
        return std::sqrt(X * X + Y * Y);
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::Add(const Vector2& vec)
    {
        *this+= vec;
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::Sub(const Vector2& vec)
    {
        *this-= vec;
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::Scale(const ML_FLOAT& factor)
    {
        *this *= factor;
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T> Vector2<T>::GetScaled(const ML_FLOAT& factor) const
    {
        return *this * factor;
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::Normalize()
    {
        *this /= Length();
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T> Vector2<T>::GetNormalized() const
    {
        return Vector2{*this} / Length();
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::SafeNormalize()
    {
        if (Amplitude() == 0) return *this;
        return Normalize();
    }

    template<ArithmeticType T>
    Vector2<T> Vector2<T>::GetSafeNormalized() const
    {
        if (Amplitude() == 0) return Vector2<T>{0};
        return GetNormalized();
    }

    template<ArithmeticType T>
    bool Vector2<T>::Equals(const Vector2& rhs) const
    {
        return *this == rhs;
    }

    template<ArithmeticType T>
    bool Vector2<T>::IsZero() const
    {
        return *this == Vector2<T>{0};
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::operator=(const Vector2& other)
    {
        X = other.X;
        Y = other.Y;
        return *this;
    }

    template<ArithmeticType T>
    bool Vector2<T>::operator==(const Vector2& rhs) const
    {
        return (X == rhs.X &&
                Y == rhs.Y);
    }

    template<ArithmeticType T>
    bool Vector2<T>::operator!=(const Vector2& rhs) const
    {
        return *this != rhs;
    }

    template<ArithmeticType T>
    const T& Vector2<T>::operator[](int idx) const
    {
        return values[idx];
    }

    template<ArithmeticType T>
    T& Vector2<T>::operator[](int idx)
    {
        return values[idx];
    }

    template<ArithmeticType T>
    Vector2<T> Vector2<T>::operator+(const Vector2& rhs) const
    {
        return Vector2<T>{X + rhs.X,
                          Y + rhs.Y};
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2& vec)
    {
        X += vec.X;
        Y += vec.Y;
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::operator++()
    {
        X++;
        Y++;
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T> Vector2<T>::operator-(const Vector2& rhs) const
    {
        return Vector2<T>{X - rhs.X,
                          Y - rhs.Y};
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2& vec)
    {
        X -= vec.X;
        Y -= vec.Y;
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::operator--()
    {
        X--;
        Y--;
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T> Vector2<T>::operator*(const ML_FLOAT& scalar) const
    {
        return Vector2<T>{X * scalar,
                          Y * scalar};
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::operator*=(const ML_FLOAT& scalar)
    {
        X *= scalar;
        Y *= scalar;
        return *this;
    }

    template<ArithmeticType T>
    Vector2<T> Vector2<T>::operator/(const ML_FLOAT& scalar) const
    {
        return Vector2<T>{X / scalar,
                          Y / scalar};
    }

    template<ArithmeticType T>
    Vector2<T>& Vector2<T>::operator/=(const ML_FLOAT& scalar)
    {
        X /= scalar;
        Y /= scalar;
    }

}
#endif //MEISTERLAMATHS_VECTOR2_H
