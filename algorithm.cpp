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

    base_case = find_fittest_tour();

    std::cout << "base case: ";
    std::cout << base_case;

    std::sort(population.begin(), population.end());

    select_elite_tour();

    std::cout << "\n\n\n";
    for (const auto &i : population) {
        std::cout << i;
    }
}

tour algorithm::find_fittest_tour() {
    double fitness = 0;
    tour fittest_tour;

    for (const auto &i : population) {
        double f = i.determine_fitness();

        if (f > fitness) {
            fittest_tour = i;
            fitness = f;
        }
    }

    return fittest_tour;
}

void algorithm::select_elite_tour() {
}