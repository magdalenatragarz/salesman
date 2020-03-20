#include <genetics/random_solution.hpp>

#include <chrono>
#include <random>

namespace genetics {

random_solution::random_solution(std::vector<int> const& genotype) {
    genetic_material = genotype;
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(genetic_material.begin(), genetic_material.end(), std::default_random_engine(seed));
}

}