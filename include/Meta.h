//
// Created by lama on 16/12/2020.
//

#ifndef MEISTERLAMATHS_META_H
#define MEISTERLAMATHS_META_H

// Type definitions
#ifdef USE_DOUBLE_PRECISION
#define ML_FLOAT double
#else
#define ML_FLOAT float
#endif

// Magic numbers

namespace MeisterLamaths
{
    constexpr ML_FLOAT PI = 3.1415926535897932;
    constexpr ML_FLOAT EPSILON = 0.00000001;
}

#endif //MEISTERLAMATHS_META_H
