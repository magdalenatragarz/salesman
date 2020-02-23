#include <genetics/crossover_solution.hpp>

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

genetics::crossover_solution::crossover_solution(std::shared_ptr<solution> mother,
        std::shared_ptr<solution> father) {
    genetic_material = cross(mother, father);
    mutate();
}


std::vector<int> genetics::crossover_solution::cross(std::shared_ptr<solution> mother,
        std::shared_ptr<solution> father) {

    if (!father->fit_to(mother))
        throw std::logic_error("Mother and father have different genetic material lengths. Impossible to create an offspring.");

    auto genes_quantity = mother->get_genetic_material_size();
    auto genetic_material = std::vector<int>{};

    auto mother_genes_quantity = genes_quantity / 2;

    for (int i = 0; i < mother_genes_quantity; i++)
        genetic_material.push_back(mother->get_gene(i));

    for (auto& father_gene : father->get_genetic_material()){
        if (std::find(genetic_material.begin(), genetic_material.end(), father_gene) != genetic_material.end()) {
            continue;
        } else {
            genetic_material.push_back(father_gene);
        }
    }

    return genetic_material;
}



