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

        ML_FUNC_DECL Vector2(T x = 0)
            : X(x), Y(x)
        {}

        ML_FUNC_DECL Vector2(T x, T y)
            : X(x), Y(y)
        {}

        ML_FUNC_DECL Vector2(const Vector2 &vec) = default;
        ML_FUNC_DECL Vector2(Vector2 &&vec) noexcept = default;
        ~Vector2() = default;

        [[nodiscard]] ML_FUNC_DECL ML_FLOAT DotProduct(const Vector2 &v) const;

        // Compute the amplitude without computing the sqrt
        // Valid for comparisons, but actually equals to length squared
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Amplitude() const;

        // Return the length of the vector
        // If you only need it for comparison consider using Amplitude()
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT Length() const;

        // Scale in place
        ML_FUNC_DECL Vector2 &Scale(const ML_FLOAT &factor);

        // Get a scaled copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector2 GetScaled(const ML_FLOAT &factor) const;

        // Normalize in place
        ML_FUNC_DECL Vector2 &Normalize();

        // Get a normalized copy of the vector
        [[nodiscard]] ML_FUNC_DECL Vector2 GetNormalized() const;

        // Normalize in place.
        // Check for length != 0
        ML_FUNC_DECL Vector2 &SafeNormalize();

        // Get a normalized copy of the vector
        // If vector length == 0, return Vector{0}
        ML_FUNC_DECL Vector2 GetSafeNormalized() const;

        [[nodiscard]] ML_FUNC_DECL bool Equals(const Vector2 &rhs) const;
        [[nodiscard]] ML_FUNC_DECL  bool IsZero() const;

        ML_FUNC_DECL Vector2 &operator=(const Vector2 &other);

        [[nodiscard]] ML_FUNC_DECL bool operator==(const Vector2 &rhs) const;

        [[nodiscard]] ML_FUNC_DECL bool operator!=(const Vector2 &rhs) const;

        [[nodiscard]] ML_FUNC_DECL const T &operator[](int idx) const;
        [[nodiscard]] ML_FUNC_DECL T &operator[](int idx);

        ML_FUNC_DECL Vector2 &Add(const Vector2 &vec);
        [[nodiscard]] ML_FUNC_DECL Vector2 operator+(const Vector2 &rhs) const;
        ML_FUNC_DECL Vector2 &operator+=(const Vector2 &vec);
        ML_FUNC_DECL Vector2 &operator++();

        ML_FUNC_DECL Vector2 &Sub(const Vector2 &vec);
        [[nodiscard]] ML_FUNC_DECL Vector2 operator-(const Vector2 &rhs) const;
        ML_FUNC_DECL Vector2 &operator-=(const Vector2 &vec);
        ML_FUNC_DECL Vector2 &operator--();

        [[nodiscard]] ML_FUNC_DECL Vector2 operator*(const ML_FLOAT &scalar) const;
        ML_FUNC_DECL Vector2 &operator*=(const ML_FLOAT &scalar);

        [[nodiscard]] ML_FUNC_DECL Vector2 operator/(const ML_FLOAT &scalar) const;
        ML_FUNC_DECL Vector2 &operator/=(const ML_FLOAT &scalar);

    };

    template<ArithmeticType T>
    ML_FUNC_DECL ML_FLOAT Vector2<T>::DotProduct(const Vector2 &v) const
    {
        return (X * v.X + Y * v.Y);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL ML_FLOAT Vector2<T>::Amplitude() const
    {
        return DotProduct(*this);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL ML_FLOAT Vector2<T>::Length() const
    {
        return std::sqrt(Amplitude());
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::Add(const Vector2 &vec)
    {
        *this += vec;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::Sub(const Vector2 &vec)
    {
        *this -= vec;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::Scale(const ML_FLOAT &factor)
    {
        *this *= factor;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> Vector2<T>::GetScaled(const ML_FLOAT &factor) const
    {
        return *this * factor;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::Normalize()
    {
        *this /= Length();
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> Vector2<T>::GetNormalized() const
    {
        return Vector2{*this} / Length();
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::SafeNormalize()
    {
        if (Amplitude() == 0) return *this;
        return Normalize();
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> Vector2<T>::GetSafeNormalized() const
    {
        if (Amplitude() == 0) return Vector2<T>{0};
        return GetNormalized();
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector2<T>::Equals(const Vector2 &rhs) const
    {
        return *this == rhs;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector2<T>::IsZero() const
    {
        return *this == Vector2<T>{0};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::operator=(const Vector2 &other)
    {
        X = other.X;
        Y = other.Y;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector2<T>::operator==(const Vector2 &rhs) const
    {
        return (X == rhs.X &&
            Y == rhs.Y);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL bool Vector2<T>::operator!=(const Vector2 &rhs) const
    {
        return !(*this == rhs);
    }

    template<ArithmeticType T>
    ML_FUNC_DECL const T &Vector2<T>::operator[](int idx) const
    {
        return values[idx];
    }

    template<ArithmeticType T>
    ML_FUNC_DECL T &Vector2<T>::operator[](int idx)
    {
        return values[idx];
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> Vector2<T>::operator+(const Vector2 &rhs) const
    {
        return Vector2<T>{X + rhs.X,
                          Y + rhs.Y};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::operator+=(const Vector2 &vec)
    {
        X += vec.X;
        Y += vec.Y;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::operator++()
    {
        X++;
        Y++;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> Vector2<T>::operator-(const Vector2 &rhs) const
    {
        return Vector2<T>{X - rhs.X,
                          Y - rhs.Y};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::operator-=(const Vector2 &vec)
    {
        X -= vec.X;
        Y -= vec.Y;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::operator--()
    {
        X--;
        Y--;
        return *this;
    }

    // TODO: Forward declaration to improve header readability
    template<ArithmeticType T>
    [[nodiscard]] ML_FUNC_DECL Vector2<T> operator-(Vector2<T> vec)
    {
        return Vector2<T>{-vec.X, -vec.Y};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> Vector2<T>::operator*(const ML_FLOAT &scalar) const
    {
        return Vector2<T>{X * scalar,
                          Y * scalar};
    }

    // TODO: Forward declaration to improve header readability
    template<ArithmeticType T>
    [[nodiscard]] ML_FUNC_DECL Vector2<T> operator*(const ML_FLOAT &scalar, Vector2<T> rhs)
    {
        return rhs * scalar;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::operator*=(const ML_FLOAT &scalar)
    {
        X *= scalar;
        Y *= scalar;
        return *this;
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> Vector2<T>::operator/(const ML_FLOAT &scalar) const
    {
        return Vector2<T>{X / scalar,
                          Y / scalar};
    }

    template<ArithmeticType T>
    ML_FUNC_DECL Vector2<T> &Vector2<T>::operator/=(const ML_FLOAT &scalar)
    {
        X /= scalar;
        Y /= scalar;
        return *this;
    }

}
#endif //MEISTERLAMATHS_VECTOR2_H
