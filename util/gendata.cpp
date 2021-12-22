
#include <random>

#include "gendata.h"


void genData (ValPosVec &data, int seed, int itemsNum, int maxValue)
{
    std::default_random_engine e1 (seed);
    std::uniform_int_distribution<int> uniform_dist (0, maxValue);

    data.reserve (itemsNum);

    for (int i = 0; i < itemsNum; ++i)
        data.emplace_back (uniform_dist (e1), i + 1);
}
