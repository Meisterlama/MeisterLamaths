#ifndef MEISTERLAMATHS_NOISE_INL_HPP
#define MEISTERLAMATHS_NOISE_INL_HPP

#include <limits>

[[nodiscard]] ML_FUNC_DECL unsigned int Get1dNoiseUint(unsigned int posX, unsigned int seed)
{
    constexpr unsigned int BIT_NOISE1 = 0x68E21DA4; // 01101000111000100001110110100100
    constexpr unsigned int BIT_NOISE2 = 0xB5297A4D; // 10110101001010010111101001001101
    constexpr unsigned int BIT_NOISE3 = 0x1B56C4E9; // 00011011010101101100010011101001

    posX *= BIT_NOISE1;
    posX += seed;
    posX ^= (posX >> 8);
    posX += BIT_NOISE2;
    posX ^= (posX << 8);
    posX *= BIT_NOISE3;
    posX ^= (posX >> 8);
    return posX;
}

[[nodiscard]] ML_FUNC_DECL unsigned int Get2dNoiseUint(unsigned int posX, unsigned int posY, unsigned int seed)
{
    constexpr int PRIME1 = 0x1CA4B297; // 011100101001001011001010010111

    return Get1dNoiseUint(posX + (PRIME1 * posY), seed);
}
[[nodiscard]] ML_FUNC_DECL unsigned int Get3dNoiseUint(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int seed)
{
    constexpr int PRIME1 = 0x1CA4B297; // 011100101001001011001010010111
    constexpr int PRIME2 = 0x23E59173; // 100011111001011001000101110011

    return Get1dNoiseUint(posX + (PRIME1 * posY) + (PRIME2 * posZ), seed);
}
[[nodiscard]] ML_FUNC_DECL unsigned int Get4dNoiseUint(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int posW, unsigned int seed)
{
    constexpr int PRIME1 = 0x1CA4B297; // 011100101001001011001010010111
    constexpr int PRIME2 = 0x23E59173; // 100011111001011001000101110011
    constexpr int PRIME3 = 0x1CE859DB; // 011100111010000101100111011011

    return Get1dNoiseUint(posX + (PRIME1 * posY) + (PRIME2 * posZ) + (PRIME3 * posW), seed);
}

[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get1dNoiseZeroToOne(unsigned int posX, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get1dNoiseUint(posX, seed)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max());
}
[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get2dNoiseZeroToOne(unsigned int posX, unsigned int posY, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get2dNoiseUint(posX, posY, seed)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max());
}
[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get3dNoiseZeroToOne(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get3dNoiseUint(posX, posY, posZ, seed)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max());
}
[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get4dNoiseZeroToOne(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int posW, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get4dNoiseUint(posX, posY, posZ, posW, seed)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max());
}

[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get1dNoiseNegOneToOne(unsigned int posX, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get1dNoiseUint(posX)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max() * 0.5) - 1.f;
}
[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get2dNoiseNegOneToOne(unsigned int posX, unsigned int posY, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get2dNoiseUint(posX, posY, seed)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max() * 0.5) - 1.f;
}
[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get3dNoiseNegOneToOne(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get3dNoiseUint(posX, posY, posZ, seed)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max() * 0.5) - 1.f;
}
[[nodiscard]] ML_FUNC_DECL ML_FLOAT Get4dNoiseNegOneToOne(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int posW, unsigned int seed)
{
    return static_cast<ML_FLOAT>(Get4dNoiseUint(posX, posY, posZ, posW, seed)) / static_cast<ML_FLOAT>(std::numeric_limits<unsigned int>::max() * 0.5) - 1.f;
}

#endif //MEISTERLAMATHS_NOISE_INL_HPP