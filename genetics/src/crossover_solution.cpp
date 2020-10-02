#include <genetics/crossover_solution.hpp>

#include <stdexcept>
#include <algorithm>

namespace genetics {

crossover_solution::crossover_solution(std::shared_ptr<genetics::solution> mother,
        std::shared_ptr<genetics::solution> father) {
    cross(mother, father);
}


void crossover_solution::cross(std::shared_ptr<genetics::solution> mother, std::shared_ptr<genetics::solution> father) {

    if (!father->fit_to(mother))
        throw std::logic_error("Mother and father have different genetic material lengths.");

    fill_with_mother_genes(mother);
    fill_with_father_genes(father);

    perform_mutation();
}


void crossover_solution::fill_with_mother_genes(std::shared_ptr<genetics::solution> mother) {
    auto genes_quantity = mother->get_genetic_material_size();
    auto mother_genes_quantity = genes_quantity / 2;

    for (int i = 0; i < mother_genes_quantity; i++)
        genetic_material.push_back(mother->get_gene(i));
}


void crossover_solution::fill_with_father_genes(std::shared_ptr<genetics::solution> father) {
    for (auto& father_gene : father->get_genetic_material()) {
        if (is_present_in_genetic_material(father_gene))
            continue;
        else
            genetic_material.push_back(father_gene);
    }
}


void crossover_solution::perform_mutation() {
    constexpr auto mutation_quantity = 3;

    for (int i = 0; i < mutation_quantity; i++)
        mutate();
}


bool crossover_solution::is_present_in_genetic_material(int gene) const {
    return std::find(genetic_material.begin(), genetic_material.end(), gene) != genetic_material.end();
}

}
