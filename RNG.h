#pragma once

#include <random>

class RNG {
private:
    std::mt19937 rng;

    RNG();

public:
    static RNG& GetInstance();

    int ProduceInteger(int min, int max);
    float ProduceFloat(float min, float max);
    void SetSeed(unsigned int seed);

    RNG(const RNG&) = delete;
    RNG& operator=(const RNG&) = delete;
};
