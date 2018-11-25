//
// Created by Amy Hong on 2018-11-11.
//

#include "city.hpp"

void city::set_x(double x) {
    if (x > MAP_BOUNDARY) {
        throw std::invalid_argument(
                "x (latitude) must be in the range [0, MAP_BOUNDARY]."
        );
    }

    this->x = x;
}

void city::set_y(double y) {
    if (y > MAP_BOUNDARY) {
        throw std::invalid_argument(
                "y (longitude) must be in the range [0, MAP_BOUNDARY]."
        );
    }

    this->y = y;
}

void city::set_name(std::string name) {
    if (name.empty()) {
        throw std::invalid_argument(
                "name should not be empty."
        );
    }

    this->name = name;
}

double city::get_x() const {
    return x;
}

double city::get_y() const {
    return y;
}

std::string city::get_name() const {
    return name;
}

double city::get_distance_between_cities(const city& c) const {
    double delta_x = c.get_x() - this->x;
    double delta_y = c.get_y() - this->y;

    return sqrt(delta_x * delta_x + delta_y * delta_y);
}
