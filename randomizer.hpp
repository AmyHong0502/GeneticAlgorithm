//
// Created by Amy Hong on 2018-11-24.
//

#ifndef GENETICALGORITHM_RANDOMIZER_HPP
#define GENETICALGORITHM_RANDOMIZER_HPP

#include <random>
#include "tour.hpp"

class randomizer {

public:

    int generate_random_int(int min, int max);

    double generate_random_double(double min, double max);

    city* generate_city(std::string name);

    tour generate_tour();
};

#endif //GENETICALGORITHM_RANDOMIZER_HPP
