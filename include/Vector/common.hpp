#ifndef MEISTERLAMATHS_VECTORCOMMON_H
#define MEISTERLAMATHS_VECTORCOMMON_H

#include "Meta.h"

namespace MeisterLamaths
{
    template<VectorType VECTOR>
    [[nodiscard]] ML_FUNC_DECL VECTOR Lerp(VECTOR begin, VECTOR end, ML_FLOAT ratio);

    //OMG this works
    template<VectorType VECTOR>
    [[nodiscard]] ML_FUNC_DECL VECTOR Lerp(VECTOR begin, VECTOR end, ML_FLOAT ratio)
    {
    //TODO: use clamp
    ratio = (ratio > 1) ? 1 : (ratio < 0) ?  0 : ratio;

    return (1 - ratio) * begin + ratio * end;
    }
}


#endif //MEISTERLAMATHS_VECTORCOMMON_H