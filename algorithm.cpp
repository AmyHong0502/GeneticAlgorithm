//
// Created by Amy Hong on 2018-11-24.
//

#include <iostream>
#include "algorithm.hpp"

void algorithm::start() {
    std::cout << "Hello, World!" << std::endl;
    tour t = rand.generate_tour();

    population.push_back(t);
    for (unsigned long i = 0; i < POPULATION_SIZE; i++) {
        tour temp(t);
        temp.shuffle_cities();

        population.push_back(temp);
    }

    for (const auto &i : population) {
        std::cout << i;
    }
}
