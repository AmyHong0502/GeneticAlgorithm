//
// Created by Amy Hong on 2018-11-11.
//

#include "city.hpp"

void city::set_coordinates(unsigned int x, unsigned int y) {
    if (x > 1000) {
        throw std::invalid_argument(
                "x (latitude) must be in the range [0, 1000]."
        );
    }

    if (y > 1000) {
        throw std::invalid_argument(
                "y (longitude) must be in the range [0, 1000]."
        );
    }

    coordinates.first = x;
    coordinates.second = y;
}

void city::set_latitude(unsigned int x) {
    if (x > 1000) {
        throw std::invalid_argument(
                "x (latitude) must be in the range [0, 1000]."
        );
    }
    coordinates.first = x;
}

void city::set_longitude(unsigned int y) {
    if (y > 1000) {
        throw std::invalid_argument(
                "y (longitude) must be in the range [0, 1000]."
        );
    }
    coordinates.second = y;
}

std::pair<unsigned int, unsigned int> city::get_coordinates() {
    return coordinates;
}

unsigned int city::get_latitude() {
    return coordinates.first;
}

unsigned int city::get_longitude() {
    return coordinates.second;
}
