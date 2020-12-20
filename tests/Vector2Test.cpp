#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by lama on 16/12/2020.
//

#include <gtest/gtest.h>
#include <Vector/Vector2.hpp>
#include <Vector/common.hpp>

using MeisterLamaths::Vector2;

TEST(Vector2, Constructors)
{
    Vector2<float> vec{1, 0};
    ASSERT_EQ(vec.X, 1);
    ASSERT_EQ(vec.Y, 0);
    vec = {1};
    ASSERT_EQ(vec.X, 1);
    ASSERT_EQ(vec.Y, 1);
    vec = {0, 1};
    ASSERT_EQ(vec.X, 0);
    ASSERT_EQ(vec.Y, 1);
    Vector2<float> vec2 = vec;
    ASSERT_EQ(vec2.X, vec.X);
    ASSERT_EQ(vec2.Y, vec.Y);
}

TEST(Vector2, Addition)
{
    Vector2<float> vec1{1, 0};
    Vector2<float> vec2{2, 1};
    Vector2<float> checkVec{3, 1};
    ASSERT_EQ(vec1 + vec2, checkVec);

    vec2 = {-1, 0};
    checkVec = {0};
    ASSERT_EQ(vec1 + vec2, checkVec);

    vec2 = {0, -1};
    checkVec = {1, -1};
    ASSERT_EQ(vec1 + vec2, checkVec);

    vec1 += {1};
    checkVec = {2, 1};
    ASSERT_EQ(vec1, checkVec);

    vec1 = {0};
    vec1.Add({1});
    checkVec = {1};
    ASSERT_EQ(vec1, checkVec);

    vec1 = {0};
    checkVec = {1};
    ASSERT_EQ(++vec1, checkVec);
}

TEST(Vector2, Substraction)
{
    Vector2<float> vec1{1, 0};
    Vector2<float> vec2{2, 1};
    Vector2<float> checkVec{-1, -1};
    ASSERT_EQ(vec1 - vec2, checkVec);

    vec2 = {-1, 0};
    checkVec = {2, 0};
    ASSERT_EQ(vec1 - vec2, checkVec);

    vec2 = {0, -1};
    checkVec = {1, 1};
    ASSERT_EQ(vec1 - vec2, checkVec);

    vec1 -= {1};
    checkVec = {0, -1};
    ASSERT_EQ(vec1, checkVec);

    vec1 = {1};
    checkVec = {0};
    ASSERT_EQ(--vec1, checkVec);

    vec1 = {0};
    vec1.Sub({1});
    checkVec = {-1};
    ASSERT_EQ(vec1, checkVec);
}

TEST(Vector2, Multiplication)
{
    Vector2<float> vec1{1, 0};
    Vector2<float> checkVec{2,0};
    ASSERT_EQ(vec1 * 2, checkVec);
    ASSERT_EQ(2 * vec1, checkVec);

    vec1 = -vec1;
    checkVec = {-1, 0};
    ASSERT_EQ(vec1, checkVec);

    vec1 *= 2;
    checkVec = {-2, 0};
    ASSERT_EQ(vec1, checkVec);

    vec1 = {2};
    checkVec = {-2};
    ASSERT_EQ(-vec1, checkVec);

    checkVec = {1};
    ASSERT_EQ(vec1.Scale(0.5), checkVec);
    checkVec = {2};
    ASSERT_EQ(vec1.GetScaled(2), checkVec);
    checkVec = {1};
    ASSERT_EQ(vec1, checkVec);

}

TEST(Vector2, Division)
{
    Vector2<float> vec1{2, 0};
    Vector2<float> checkVec{1,0};
    ASSERT_EQ(vec1 / 2, checkVec);
    ASSERT_EQ(vec1 / -2, -checkVec);

    vec1 /= 2;
    ASSERT_EQ(vec1, checkVec);
}

TEST(Vector2, DotProduct)
{
    Vector2<float> vec1 = {3,4};
    ASSERT_EQ(vec1.DotProduct(vec1), 3 * 3 + 4 * 4);
    Vector2<float> vec2 = {2,5};
    ASSERT_EQ(vec1.DotProduct(vec2), vec1.X * vec2.X + vec1.Y * vec2.Y);


}

TEST(Vector2, Length)
{
    Vector2<float> vec1 = {3,4};
    ASSERT_EQ(vec1.Length(), 5);
    ASSERT_EQ(vec1.Amplitude(), 25);
    vec1 = {-3,4};
    ASSERT_EQ(vec1.Length(), 5);
    ASSERT_EQ(vec1.Amplitude(), 25);
    vec1 = {-3, -4};
    ASSERT_EQ(vec1.Length(), 5);
    ASSERT_EQ(vec1.Amplitude(), 25);

    vec1 = {0};
    ASSERT_EQ(vec1.Length(), 0);
    ASSERT_EQ(vec1.Amplitude(), 0);
}

TEST(Vector2, Normalize)
{
    Vector2<float> vec1 = {3,4};
    Vector2<float> checkVec = vec1;
    ASSERT_EQ(vec1.GetNormalized().Length(), 1);
    ASSERT_EQ(vec1, checkVec);
    ASSERT_EQ(vec1.Normalize().Length(), 1);
    ASSERT_NE(vec1, checkVec);

    vec1 = {0};
    ASSERT_EQ(vec1.SafeNormalize().Length(), 0);
    ASSERT_EQ(vec1.GetSafeNormalized().Length(), 0);
    ASSERT_NE(vec1.Normalize(), 0);
}

TEST(Vector2, Comparison)
{
    Vector2<float> vec1{1};
    ASSERT_TRUE(vec1.Equals(vec1));
    ASSERT_TRUE(vec1 == vec1);
    ASSERT_FALSE(vec1 != vec1);

    Vector2<float> vec2{1};
    ASSERT_FALSE(vec2.IsZero());
    ASSERT_TRUE(vec1.Equals(vec2));
    ASSERT_TRUE(vec1 == vec2);
    ASSERT_FALSE(vec1 != vec2);
    vec2 = {0};
    ASSERT_TRUE(vec2.IsZero());
    ASSERT_FALSE(vec1.Equals(vec2));
    ASSERT_FALSE(vec1 == vec2);
    ASSERT_TRUE(vec1 != vec2);
    vec2 = {-1};
    ASSERT_FALSE(vec1.Equals(vec2));
    ASSERT_FALSE(vec1 == vec2);
}

TEST(Vector2, Lerp)
{
    Vector2<float> vec1{0};
    Vector2<float> vec2{2};
    Vector2<float> interVec{Lerp(vec1, vec2, 0.5)};
    Vector2<float> checkVec{1};
    ASSERT_EQ(interVec, checkVec);
}