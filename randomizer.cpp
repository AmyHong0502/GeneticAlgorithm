//
// Created by Amy Hong on 2018-11-24.
//

#include "randomizer.hpp"

double randomizer::generate_random_double(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

city *randomizer::generate_city(std::string name) {
    city *c = new city();
    c->set_name(std::move(name));
    c->set_x(generate_random_double(0, MAP_BOUNDARY));
    c->set_y(generate_random_double(0, MAP_BOUNDARY));
    return c;
}

int randomizer::generate_random_int(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

tour randomizer::generate_tour() {
    tour t;

    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        city *c = generate_city(std::to_string(i));
        t.add_city(c);
    }

    return t;
}
