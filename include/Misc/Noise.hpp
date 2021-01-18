//
// Created by lama on 18/01/2021.
//

#ifndef MEISTERLAMATHS_NOISE_HPP
#define MEISTERLAMATHS_NOISE_HPP

#include "Meta.hpp"

namespace MeisterLamaths {
    // Based on Math for Game Programmers: Noise-Based RNG from GDC 2017

    [[nodiscard]] ML_FUNC_DECL
    unsigned int Get1dNoiseUint(unsigned int posX,
                                unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    unsigned int Get2dNoiseUint(unsigned int posX, unsigned int posY,
                                unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    unsigned int Get3dNoiseUint(unsigned int posX, unsigned int posY, unsigned int posZ,
                                unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    unsigned int Get4dNoiseUint(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int posW,
                                unsigned int seed = 0);

    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get1dNoiseZeroToOne(unsigned int posX,
                              unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get2dNoiseZeroToOne(unsigned int posX, unsigned int posY,
                              unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get3dNoiseZeroToOne(unsigned int posX, unsigned int posY, unsigned int posZ,
                              unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get4dNoiseZeroToOne(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int posW,
                              unsigned int seed = 0);

    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get1dNoiseNegOneToOne(unsigned int posX,
                                unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get2dNoiseNegOneToOne(unsigned int posX, unsigned int posY,
                                unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get3dNoiseNegOneToOne(unsigned int posX, unsigned int posY, unsigned int posZ,
                                unsigned int seed = 0);
    [[nodiscard]] ML_FUNC_DECL
    ML_FLOAT Get4dNoiseNegOneToOne(unsigned int posX, unsigned int posY, unsigned int posZ, unsigned int posW,
                                unsigned int seed = 0);

#ifdef ML_IMPLEMENTATION
    #include "inl/Noise.inl.hpp"
#endif //ML_IMPLEMENTATION
}
#endif //MEISTERLAMATHS_NOISE_HPP
