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
#define NUMBER_OF_ELITES 1
#define NUMBER_OF_PARENTS 2

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

    void sort();

    void print();

    std::vector<tour> sub_tour(int first, int last);

    tour choose_parent();
};

#endif //GENETICALGORITHM_ALGORITHM_HPP
