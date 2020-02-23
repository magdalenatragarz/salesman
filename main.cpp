#include <iostream>
#include <memory>
#include <graph/matrix.hpp>
#include <genetics/random_solution.hpp>
#include <genetics/crossover_solution.hpp>


int main() {
    auto solution_1 = std::make_shared<genetics::random_solution>(5);
    auto solution_2 = std::make_shared<genetics::random_solution>(5);

    solution_1->genetic_material.assign({1, 7, 2, 3, 4, 5, 6});
    solution_2->genetic_material.assign({7, 2, 5, 1, 4, 6, 3});

    auto x = std::make_shared<genetics::crossover_solution>(solution_1, solution_2);

    for (auto&  a : x->get_genetic_material())
        std::cout << a;

}