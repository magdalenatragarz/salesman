#include <genetics/solution.hpp>
#include <iostream>

namespace genetics {

bool solution::fit_to(std::shared_ptr<solution> soulmate) {
    return get_genetic_material_size() == soulmate->get_genetic_material_size();
}

int solution::get_genetic_material_size() {
    return genetic_material.size();
}

int solution::get_gene(int index) {
    return genetic_material.at(index);
}

std::vector<int> solution::get_genetic_material() {
    return genetic_material;
}

void solution::mutate() {
    std::vector<std::function<void()>> mutations = {
            [&]{ return no_mutation(); },
            [&]{ return element_switch_mutation(); },
            [&]{ return block_move_mutation(); }
    };

    perform_random_mutation(mutations);
}

void solution::element_switch_mutation() {
    auto first_of_swapped_index = std::random_device()() % get_genetic_material_size() - 1;
    auto second_of_swapped_index = first_of_swapped_index + 1;

    std::swap(genetic_material[first_of_swapped_index],
            genetic_material[second_of_swapped_index]);
}

void solution::block_move_mutation() {
    auto length_of_block = std::random_device()() % (get_genetic_material_size() / 2);


    std::swap_ranges(genetic_material.begin(), genetic_material.begin() + length_of_block,
            genetic_material.begin() + length_of_block);
}

void solution::no_mutation() {}

void solution::perform_random_mutation(std::vector<std::function<void()>> mutations) {
    auto chosen_mutation_index =  std::random_device()() % mutations.size();
    mutations.at(chosen_mutation_index)();
}



}