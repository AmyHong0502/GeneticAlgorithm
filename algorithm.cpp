//
// Created by Amy Hong on 2018-11-24.
//

#include <iostream>
#include "algorithm.hpp"

void algorithm::start() {
    std::cout << "Hello, World!" << std::endl;

    tour t = rand.generate_tour();

    std::cout << t ;
}
