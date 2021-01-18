#ifndef MEISTERLAMATHS_RNG_HPP
#define MEISTERLAMATHS_RNG_HPP

#include "Meta.hpp"

namespace MeisterLamaths
{
    class RNG {
    public:
        RNG(unsigned int seed = 0) : m_seed(seed), m_position(0) {};

        // State modifiers
        ML_FUNC_DECL void ResetSeed(unsigned int seed, int position = 0) {m_seed = seed; m_position = position;}
        [[nodiscard]] ML_FUNC_DECL unsigned int GetSeed() const { return m_seed; }
        ML_FUNC_DECL void SetCurrentPosition(int position) { m_position = position;}
        [[nodiscard]] ML_FUNC_DECL int GetCurrentPosition() const {return m_position;}

        // RNGs
        [[nodiscard]] ML_FUNC_DECL unsigned int RollRandomUint32();
        [[nodiscard]] ML_FUNC_DECL unsigned short RollRandomUint16();
        [[nodiscard]] ML_FUNC_DECL unsigned char RollRandomByte();
        [[nodiscard]] ML_FUNC_DECL unsigned int RollRandomIntLessThan(unsigned int maxValue);
        [[nodiscard]] ML_FUNC_DECL int RollRandomIntInRange(int minValue, int maxValue);
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT RollRandomFloatZeroToOne();
        [[nodiscard]] ML_FUNC_DECL ML_FLOAT RollRandomFloatInRange(ML_FLOAT minValue, ML_FLOAT maxValue);
        [[nodiscard]] ML_FUNC_DECL bool RollRandomChance(ML_FLOAT probabilityOfReturningTrue);

    private:
        unsigned int m_seed;
        int m_position;
    };

    #include "inl/RNG.inl.hpp"
}
#endif //MEISTERLAMATHS_RNG_HPP