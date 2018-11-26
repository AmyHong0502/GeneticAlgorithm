//
// Created by Amy Hong on 2018-11-24.
//

#include <iostream>
#include "algorithm.hpp"

void algorithm::run() {

    init();
    report();
    select();

    report();
}

void algorithm::init() {
    tour t = rand.generate_tour();
    population.push_back(t);

    for (unsigned long i = 0; i < POPULATION_SIZE; i++) {
        tour temp(t);
        temp.shuffle_cities();

        population.push_back(temp);
    }
}

void algorithm::select() {
    std::sort(population.begin(), population.end());
}

void algorithm::report() {
    for (const auto &i : population) {
        std::cout << i;
    }
    std::cout << std::endl;
}
