//
// Created by Amy Hong on 2018-11-24.
//

#include "algorithm.hpp"

void algorithm::run() {
    init();
    sort();

    int iteration_counter = 0;
    double improvement = 1;
    tour prev;
    while (iteration_counter < ITERATIONS || improvement < IMPROVEMENT_FACTOR) {
        ++iteration_counter;
        prev = population.front();

        crossover();
        sort();

        mutate();
        sort();

        improvement = evaluate(prev);

        report(improvement);
    }
}

void algorithm::init() {
    tour t = rand.generate_tour();
    population.push_back(t);

    for (unsigned long i = 0; i < POPULATION_SIZE; i++) {
        tour temp(t);
        temp.shuffle_cities();

        population.push_back(temp);
    }
}

void algorithm::crossover() {
    std::vector<tour> new_population;
    new_population.push_back(population.at(0));

    tour parents[NUMBER_OF_PARENTS];
    for (auto &parent : parents) {
        parent = choose_parent();
    }

    while (new_population.size() < POPULATION_SIZE) {
        new_population.push_back(parents[0].crossover(parents[1]));
    }

    population = new_population;
}

tour algorithm::choose_parent() {
    std::vector<tour> parent;
    parent.reserve(PARENT_POOL_SIZE);
    for (int i = 0; i < PARENT_POOL_SIZE; i++) {
        parent.push_back(population.at(
                static_cast<unsigned long>(
                        rand.generate_random_int(NUMBER_OF_ELITES,
                                                 POPULATION_SIZE - 1)
                )));
    }

    std::sort(parent.begin(), parent.end());
    return parent.at(0);
}

void algorithm::sort() {
    std::sort(population.begin(), population.end());
}

void algorithm::report(double improvement) {
    double best = population.front().determine_fitness();
    double worst = population.at(population.size() - 1).determine_fitness();
    std::cout
            << std::setw(12) << "BEST"
            << std::setw(12) << best * 100000
            << std::setw(12) << "WORST"
            << std::setw(12) << worst * 100000
            << std::setw(12) << "IMPROVEMENT"
            << std::setw(12) << improvement << std::endl;
}

void algorithm::print() {
    for (const auto &i : population) {
        std::cout << i;
    }
    std::cout << std::endl;
}

void algorithm::mutate() {
    for (unsigned long i = NUMBER_OF_ELITES; i < population.size(); i++) {
        if (rand.generate_random_int(0, MUTATION_RATE) == MUTATION_RATE) {
            population.at(i).mutate();
        }
    }
}

double algorithm::evaluate(tour prev) {
    double before = prev.determine_fitness();
    double after = population.front().determine_fitness();

    return (after - before) * 100000;
}
