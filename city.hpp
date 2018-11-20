//
// Created by Amy Hong on 2018-11-11.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
#include <utility>
#include <stdexcept>

class city {
private:
    std::string name;
    std::pair<unsigned int, unsigned int> coordinates;
public:

    // TODO ASK JEFF to see if it's ok to have a `pair` instead of int x / int y

    /**
     *
     * @param x latitude of this city. Range: [0, 1000]
     * @param y longitude of this city. Range: [0, 1000]
     */
    void set_coordinates(unsigned int x, unsigned int y);

    /**
     *
     * @param x latitude of this city. Range: [0, 1000]
     */
    void set_latitude(unsigned int x);

    /**
     *
     * @param y longitude of this city. Range: [0, 1000]
     */
    void set_longitude(unsigned int y);

    std::pair<unsigned int, unsigned int> get_coordinates();

    unsigned int get_latitude();

    unsigned int get_longitude();
};

#endif //GENETICALGORITHM_CITY_HPP
