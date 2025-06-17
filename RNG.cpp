#include "RNG.h"

RNG::RNG()
{
    std::random_device rd;
    rng = std::mt19937(rd());
}

RNG& RNG::GetInstance()
{
    static RNG instance;
    return instance;
}

int RNG::ProduceInteger(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

float RNG::ProduceFloat(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
}

void RNG::SetSeed(unsigned int seed)
{
    rng.seed(seed);
}
