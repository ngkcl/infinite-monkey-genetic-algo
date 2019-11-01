#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>

struct Config {
    const int POPULATION_LIMIT = 200;
    const float MUTATION_RATE = 0.05;
    const std::string TARGET_PHRASE = "to be or not to be";
};

#endif