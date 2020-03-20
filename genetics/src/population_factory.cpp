#include <genetics/population_factory.hpp>

namespace evolution {

population_factory::population_factory(std::vector<int> genotype) : genotype(genotype) {}

std::vector<std::shared_ptr<genetics::solution>> population_factory::generate_population() {
    constexpr auto population_size_multiplier = 100;

    population.clear();
    auto population_size = genotype.size() * population_size_multiplier;

    for (int i = 0; i < population_size; i++)
        population.push_back(std::make_shared<genetics::random_solution>(genotype));

    return population;
}

}