//
// Created by Amy Hong on 2018-11-11.
//

#include "tour.hpp"

tour::tour() {
    cities = new city[CITIES_IN_TOUR];
}

tour::~tour() {
    delete cities;
}
