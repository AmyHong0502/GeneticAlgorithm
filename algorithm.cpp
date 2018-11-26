//
// Created by Amy Hong on 2018-11-24.
//

#include <iostream>
#include "algorithm.hpp"

void algorithm::run() {
    init();
    report();
//    select();
    sort();
    report();

    crossover();
    sort();
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

void algorithm::report() {
    for (const auto &i : population) {
        std::cout << i;
    }
    std::cout << std::endl;
}

void algorithm::crossover() {
    std::vector<tour> new_population;
    new_population.push_back(population.at(0));

    tour parents[NUMBER_OF_PARENTS];
    for (auto &parent : parents) {
        parent = choose_parent();
    }

    while (new_population.size() < POPULATION_SIZE) {
        new_population.push_back(parents[0].crossover(parents[1]));
    }

    population = new_population;
}

tour algorithm::choose_parent() {
    std::vector<tour> parent;
    parent.reserve(PARENT_POOL_SIZE);
    for (int i = 0; i < PARENT_POOL_SIZE; i++) {
        parent.push_back(population.at(
                static_cast<unsigned long>(
                        rand.generate_random_int(NUMBER_OF_ELITES,
                                                 POPULATION_SIZE)
                )));
    }

    std::sort(parent.begin(), parent.end());
    return parent.at(0);
}

void algorithm::sort() {
    std::sort(population.begin(), population.end());
}
