#ifndef MEISTERLAMATHS_RNG_HPP
#define MEISTERLAMATHS_RNG_HPP

namespace MeisterLamaths
{
    unsigned int RNG::RollRandomUint32()
    {
        return Get1dNoiseUint(m_position++, m_seed);
    }
    unsigned short RNG::RollRandomUint16()
    {
        return static_cast<unsigned short>(Get1dNoiseUint(m_position++, m_seed));
    }
    unsigned char RNG::RollRandomByte()
    {
        return static_cast<unsigned char>(Get1dNoiseUint(m_position++, m_seed));
    }
    unsigned int RNG::RollRandomIntLessThan(unsigned int maxValue)
    {
        return static_cast<unsigned int>(Get1dNoiseZeroToOne(m_position++, m_seed) * maxValue);
    }
    int RNG::RollRandomIntInRange(int minValue, int maxValue)
    {
        return minValue + static_cast<unsigned int>(Get1dNoiseZeroToOne(m_position++, m_seed) * maxValue);
    }
    float RNG::RollRandomFloatZeroToOne()
    {
        return Get1dNoiseZeroToOne(m_position++, m_seed);
    }
    float RNG::RollRandomFloatInRange(float minValue, float maxValue)
    {
        return minValue * Get1dNoiseZeroToOne(m_position++, m_seed) * maxValue;
    }
    bool RNG::RollRandomChance(float probabilityOfReturningTrue)
    {
        return (Get1dNoiseZeroToOne(m_position++, m_seed) < probabilityOfReturningTrue) ? true : false;
    }
}
#endif //MEISTERLAMATHS_RNG_HPP