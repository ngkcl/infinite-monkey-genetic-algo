#include "randomgen.h"

// Generates pseudo-random int between min & max
int genRandom(int min, int max) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(min, max);

	auto dice = std::bind(distribution, generator);

    return dice();
}