#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>

namespace util
{
    class RandomGenerator
    {
        public:
            RandomGenerator();
            int randomInt(int from, int to);
            int randomInt(int to);
            float randomFloat(float from, float to);
            float randomFloat(float to);
        private:
            std::random_device rd;
            std::mt19937 mt;

    };
}

#endif // RANDOMGENERATOR_H
