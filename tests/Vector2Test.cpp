//
// Created by lama on 16/12/2020.
//

#include <gtest/gtest.h>
#include <Vector/Vector2.hpp>
#include <string>

TEST(Vector2, Addition)
{
    using MeisterLamaths::Vector2;

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

    vec1 = {0};
    vec1.Add({1});
    checkVec = {1};
    ASSERT_EQ(vec1, checkVec);

}
