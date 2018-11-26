#include <random>
#include <iostream>

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
    double td = get_tour_distance();
    return 1 / td;
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

tour tour::crossover(tour parent) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, CITIES_IN_TOUR);

    int pos1 = dis(gen);
    int pos2 = dis(gen);

    int first = pos1 < pos2 ? pos1 : pos2;
    int second = pos1 < pos2 ? pos2 : pos1;

    std::vector<city *> new_subset(
            begin() + first,
            begin() + second);

    tour new_tour(new_subset);

    for (const auto &i : parent) {
        if (!new_tour.contains_city(i)) {
            new_tour.add_city(i);
        }
    }

    return new_tour;
}
