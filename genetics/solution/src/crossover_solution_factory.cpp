#pragma once

#include <solution/crossover_solution_factory.hpp>
#include <solution/crossover_solution.hpp>

std::shared_ptr<genetics::solution> genetics::crossover_solution_factory::create_solution() {
    return std::make_shared<genetics::crossover_solution>();
}
