//
// Created by Amy Hong on 2018-11-24.
//

#ifndef GENETICALGORITHM_RANDOMIZER_HPP
#define GENETICALGORITHM_RANDOMIZER_HPP

#include <random>
#include "tour.hpp"

/**
 * Helper to generate random factors.
 */
class randomizer {

private:
    /**
     * Returns a randomly generated city.
     *
     * @param name name of the city
     * @return randomly generated city.
     */
    city* generate_city(std::string name);

public:

    /**
     * Returns a random integer in the given range.
     *
     * @param min Minimum value
     * @param max Maximum value
     * @return Random int in the given range
     */
    int generate_random_int(int min, int max);

    /**
     * Returns a random double in the given range.
     *
     * @param min Minimum value
     * @param max Maximum value
     * @return Random double in the given range
     */
    double generate_random_double(double min, double max);

    /**
     * Generates a tour and return the tour.
     *
     * @return randomly generated tour
     */
    tour generate_tour();
};

#endif //GENETICALGORITHM_RANDOMIZER_HPP
