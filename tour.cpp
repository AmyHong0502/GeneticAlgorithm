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
    double d = 0;
    for (unsigned long i = 0; i < size() - 1; i++) {
        d += at(i)->get_distance_between_cities(* at(i + 1));
    }
    return 1 / d;
}

double tour::get_tour_distance() const {
    city c = *(this->at(0));
    return 0;
}

bool tour::contains_city(city *c) const {
    return this->end() != std::find(this->begin(), this->end(), c);
}

void tour::shuffle_cities() {
    vector<city *> new_tour;

    // deep copy --> shuffle_cities()
}

void tour::add_city(city *c) {
    push_back(c);
}

std::ostream &operator<<(std::ostream &os, const tour &t) {
    const int width = 7;
    for (unsigned long i = 0; i < t.size(); i++) {
        os << std::setw(width) << t.at(i)->get_name();
        os << std::endl;
    }
    os << std::setw(width * 2) << t.determine_fitness();
    return os;
}
