//
// Created by lama on 16/12/2020.
//

#include <gtest/gtest.h>
#include <Vector/Vector2.hpp>
#include <string>

TEST(Vector2, Addition)
{
    using MeisterLamaths::Vector2;

    const Vector2<float> vec1{1,0};
    const Vector2<float> vec2{2,1};
    const Vector2<float> vec3{3,1};
    ASSERT_EQ(vec1 + vec2, vec3);
}
