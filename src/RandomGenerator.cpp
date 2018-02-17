#include "RandomGenerator.h"

namespace util
{
    RandomGenerator::RandomGenerator()
    {
       mt.seed(rd());
    }

    int RandomGenerator::randomInt(int from, int to)
    {
        std::uniform_int_distribution<int> randInt(from,to);
        return randInt(mt);
    }

    int RandomGenerator::randomInt(int to)
    {
        std::uniform_int_distribution<int> randInt(0,to);
        return randInt(mt);
    }

    float RandomGenerator::randomFloat(float from, float to)
    {
        std::uniform_real_distribution<float> randFloat(from,to);
        return randFloat(mt);
    }

    float RandomGenerator::randomFloat(float to)
    {
        std::uniform_real_distribution<float> randFloat(0.0f,to);
        return randFloat(mt);
    }

}
