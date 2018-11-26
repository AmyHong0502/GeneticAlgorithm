//
// Created by Amy Hong on 2018-11-24.
//

#ifndef GENETICALGORITHM_ALGORITHM_HPP
#define GENETICALGORITHM_ALGORITHM_HPP

#include "randomizer.hpp"

#define POPULATION_SIZE 32  // it would be nice if the user can choose
#define SHUFFLES 64
#define ITERATIONS 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15    // it would be nice if the user can choose
#define NUMBER_OF ELITES 1  // How changing this would modify the algorithm's
                            // effectiveness?
                            // Should start at 1.
#define NUMBER_OF_PARENTS 1 // TODO Change this number

class algorithm {
private:
    randomizer rand;

    std::vector<tour> population;

public:
    algorithm() = default;

    ~algorithm() = default;

    bool contains_city(tour t, city c);

    void start();
};

#endif //GENETICALGORITHM_ALGORITHM_HPP
