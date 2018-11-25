//
// Created by Amy Hong on 2018-11-11.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
#include <utility>
#include <stdexcept>
#include <math.h>

#define MAP_BOUNDARY 1000

class city {

private:

    /**
     * Name of this city.
     */
    std::string name;

    /**
     * Latitude of this city. Must be between [0, MAP_BOUNDARY] inclusive.
     */
    double x;

    /**
     * Longitude of this city. Must be between [0, MAP_BOUNDARY] inclusive.
     */
    double y;

public:

    /**
     *
     * @param name This city's name.
     */
    void set_name(std::string name);

    /**
     *
     * @param x Latitude of this city.
     *          Must be between [0, MAP_BOUNDARY] inclusive.
     */
    void set_x(double x);

    /**
     *
     * @param y Longitude of this city.
     *          Must be between [0, MAP_BOUNDARY] inclusive.
     */
    void set_y(double y);

    /**
     * Returns this city's name.
     *
     * @return this city's name.
     */
    std::string get_name() const;

    /**
     * Returns this city's latitude.
     *
     * @return this city's latitude.
     */
    double get_x() const;

    /**
     * Returns this city's longitude.
     *
     * @return this city's longitude.
     */
    double get_y() const;

    /**
     * Returns distance between the given city.
     *
     * @param c city to measure distance.
     * @return distance between this city and the given city.
     */
    double get_distance_between_cities(const city& c) const;
};

#endif //GENETICALGORITHM_CITY_HPP
