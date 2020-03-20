#include <genetics/solution.hpp>
#include <iostream>

namespace genetics {

void solution::mutate() {
    std::vector<std::function<void()>> mutations = {
            [&]{ return no_mutation(); },
            [&]{ return element_switch_mutation(); },
            [&]{ return block_switch_mutation(); }
    };

    perform_random_mutation(mutations);
}


void solution::perform_random_mutation(std::vector<std::function<void()>> mutations) {
    auto chosen_mutation_index =  std::random_device()() % mutations.size();
    mutations.at(chosen_mutation_index)();
}


void solution::no_mutation() {}


void solution::element_switch_mutation() {
    auto first_of_swapped = std::random_device()() % (get_genetic_material_size() - 1);
    auto second_of_swapped = first_of_swapped + 1;

    std::swap(genetic_material[first_of_swapped],
              genetic_material[second_of_swapped]);
}


void solution::block_switch_mutation() {
    auto length_of_block = std::random_device()() % (get_genetic_material_size() / 2);

    std::swap_ranges(genetic_material.begin(), genetic_material.begin() + length_of_block,
                     genetic_material.begin() + length_of_block);
}


std::vector<int> solution::get_genetic_material() const{
    return genetic_material;
}


int solution::get_genetic_material_size() const {
    return genetic_material.size();
}


int solution::get_gene(int index) const {
    return genetic_material.at(index);
}


bool solution::fit_to(std::shared_ptr<solution> soulmate) const {
    return get_genetic_material_size() == soulmate->get_genetic_material_size();
}


std::ostream & operator << (std::ostream &out, const std::shared_ptr<genetics::solution> &s) {
    for (auto& gene: s->get_genetic_material())
        out << std::to_string(gene);
    return out;
}

}