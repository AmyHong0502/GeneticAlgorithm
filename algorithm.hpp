//
// Created by Amy Hong on 2018-11-24.
//

#ifndef GENETICALGORITHM_ALGORITHM_HPP
#define GENETICALGORITHM_ALGORITHM_HPP

#include "randomizer.hpp"

#define POPULATION_SIZE 32
#define SHUFFLES 64
#define ITERATIONS 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15
#define NUMBER_OF ELITES 1
#define NUMBER_OF_PARENTS 1 // TODO Change this number

#define IMPROVEMENT_FACTOR 0

class algorithm {
private:
    randomizer rand;

    std::vector<tour> population;

    tour base_case;

public:
    algorithm() = default;

    ~algorithm() = default;

    void select();

    void crossover();

    void mutate();

    void evaluate();

    void report();

    void run();

    void init();

    bool contains_city(tour t, city c);
};

#endif //GENETICALGORITHM_ALGORITHM_HPP
