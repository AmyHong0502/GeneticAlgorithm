//
// Created by Amy Hong on 2018-11-11.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#define CITIES_IN_TOUR 32 // it would be nice if the user can choose

#include "city.hpp"

/**
 * A list of cities to travel.
 */
class tour {

private:

    /**
     * A list of all cities.
     */
    city *cities;

    /**
     * Represents the quality of the tour.
     * Fitness evaluates the distance the travelling salesman would need to
     * travel to visit the cities in the order they appear in the tour.
     */
    double fitness;

public:

    /**
     * Constructor of this tour.
     */
    tour();

    /**
     * Destructor of this tour.
     */
    ~tour();

    /**
     * Sets cities for this tour.
     *
     * @param cities cities to travel.
     */
    void set_cities(city *cities);

    /**
     * Returns cities in this tour.
     *
     * @return cities in this tour.
     */
    city *get_cities();

    /**
     * Shuffles the cities in this tour.
     */
    void shuffle_cities();

    /**
     * Returns as-the-crow-flies distance between cities in this tour.
     *
     * @return distance between cities in this tour.
     */
    double get_distance_between_cities(city a, city b) const;

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
    double determine_fitness();

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
    bool contains_city(city c);
};

#endif //GENETICALGORITHM_TOUR_HPP
