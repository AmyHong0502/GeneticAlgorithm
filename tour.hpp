//
// Created by Amy Hong on 2018-11-11.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#define CITIES_IN_TOUR 32
#define MUTATION_RATE 15

#include <iomanip>
#include <numeric>
#include <vector>
#include "city.hpp"

/**
 * A list of cities to travel.
 */
class tour : std::vector<city *> {
public:

    /**
     * Constructor of this tour.
     */
    tour() = default;

    /**
     * Constructor of this tour.
     *
     * @param cities cities to travel.
     */
    explicit tour(std::vector<city *> cities);

    /**
     * Adds a city at the end of this tour.
     *
     * @param c city to travel.
     */
    void add_city(city *c);

    /**
     * Shuffles the cities in this tour.
     */
    void shuffle_cities();

    /**
     * Reports the distance between the cities as they are listed in this tour.
     *
     * @return distance between the cities as they are listed in this tour.
     */
    double get_tour_distance() const;

    /**
     * Determines the fitness of this tour.
     *
     * @return
     */
    double determine_fitness() const;

    /**
     * Mutates this tour.
     */
    void mutate();

    /**
     * Creates a new tour from a given set of parent tours.
     *
     * @return new tour from a given set of parent tours.
     */
    tour crossover(tour parent);

    /**
     * Checks if this tour contains a specified city.
     *
     * @param c city to check.
     * @return true if this tour contains the specified city.
     */
    bool contains_city(city *c) const;

    /**
     * Beautifies output text.
     *
     * @param os ostream.
     * @param t  tour to beautify output text.
     * @return   beautified output text.
     */
    friend std::ostream &operator<<(std::ostream &os, const tour &t);

    /**
     * Returns true if l's total tour distance is shorter than r's distance.
     *
     * @param l tour to compare.
     * @param r tour to compare.
     * @return true if l's total tour distance is shorter than r's distance.
     */
    friend bool operator<(const tour &l, const tour &r);
};

#endif //GENETICALGORITHM_TOUR_HPP
