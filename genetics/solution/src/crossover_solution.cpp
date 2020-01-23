#pragma once

#include <solution/crossover_solution.hpp>

#include <iostream>

genetics::crossover_solution::crossover_solution() {
    std::cout << "Crossover solution created" << std::endl;
}

void genetics::crossover_solution::mutate() {
    std::cout << "Crossover solution mutated" << std::endl;
}