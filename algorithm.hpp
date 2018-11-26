//
// Created by Amy Hong on 2018-11-24.
//

#ifndef GENETICALGORITHM_ALGORITHM_HPP
#define GENETICALGORITHM_ALGORITHM_HPP

#include <iostream>
#include "randomizer.hpp"

#define POPULATION_SIZE 32
#define ITERATIONS 1000
#define PARENT_POOL_SIZE 5
#define NUMBER_OF_ELITES 1
#define NUMBER_OF_PARENTS 2

#define IMPROVEMENT_FACTOR 0.1

class algorithm {
private:

    /** Randomizer. */
    randomizer rand;

    /** List of tours. */
    std::vector<tour> population;

public:

    /**
     * Runs this algorithm.
     */
    void run();

    /**
     * Initializes population.
     */
    void init();

    /**
     * Makes children tours by crossover.
     */
    void crossover();

    /**
     * Mutates some tours in population.
     */
    void mutate();

    /**
     * Evaluates progression.
     *
     * @param prev previous tour to compare.
     * @return progression rate.
     */
    double evaluate(tour prev);

    /**
     * Reports progress by std::cout.
     *
     * @param improvement improvement rate to print.
     */
    void report(double improvement);

    /**
     * Sorts population.
     */
    void sort();

    /**
     * Prints the entire list of tours in population.
     */
    void print();

    /**
     * Returns a tour to use as a parent.
     *
     * @return tour to use as a parent tour.
     */
    tour choose_parent();
};

#endif //GENETICALGORITHM_ALGORITHM_HPP
