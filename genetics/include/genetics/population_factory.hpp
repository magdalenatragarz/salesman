#pragma once

#include <genetics/solution.hpp>
#include <genetics/random_solution.hpp>
#include <genetics/crossover_solution.hpp>

#include <map>

namespace evolution {

class population_factory {

public:
    explicit population_factory(std::vector<int> genotype);

    std::vector<std::shared_ptr<genetics::solution>> generate_population();

private:
    std::vector<std::shared_ptr<genetics::solution>> population{};
    std::vector<int> genotype;

};

}