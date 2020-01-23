#include <solution/random_solution_factory.hpp>
#include <solution/crossover_solution_factory.hpp>

int main() {
    auto random_factory = std::make_shared<genetics::random_solution_factory>();
    auto crossover_factory = std::make_shared<genetics::crossover_solution_factory>();

    random_factory->create_solution();
    crossover_factory->create_solution();
}