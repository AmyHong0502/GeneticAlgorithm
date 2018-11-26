#include <random>

//
// Created by Amy Hong on 2018-11-11.
//

#include "tour.hpp"

tour::tour(std::vector<city *> cities) {
    if (cities.size() > CITIES_IN_TOUR) {
        throw std::invalid_argument(
                "number of cities in tour exceeded the limit"
        );
    }

    assign(cities.begin(), cities.end());
}

double tour::determine_fitness() const {
    return 1 / get_tour_distance();
}

double tour::get_tour_distance() const {
    double d = at(size() - 1)->get_distance_between_cities(*at(0));
    for (unsigned long i = 0; i < size() - 1; i++) {
        d += at(i)->get_distance_between_cities(*at(i + 1));
    }
    return d;
}

bool tour::contains_city(city *c) const {
    return this->end() != std::find(this->begin(), this->end(), c);
}

void tour::shuffle_cities() {
    std::shuffle(begin(), end(), std::mt19937(std::random_device()()));
}

void tour::add_city(city *c) {
    push_back(c);
}

std::ostream &operator<<(std::ostream &os, const tour &t) {
    const int width = 4;
    for (const auto &i : t) {
        os << std::setw(width) << i->get_name() << " ";
    }
    os << t.determine_fitness() << std::endl;
    return os;
}

//void tour::sort() {
//    std::sort(begin(), end());
//}

bool operator<(const tour &l, const tour &r) {
    return l.get_tour_distance() < r.get_tour_distance();
}
