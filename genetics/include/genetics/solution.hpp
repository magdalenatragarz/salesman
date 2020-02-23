#pragma once

#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <random>

namespace genetics {

class solution {
public:
	virtual void mutate();

    int get_genetic_material_size();
    std::vector<int> get_genetic_material();
    int get_gene(int index);
    bool fit_to(std::shared_ptr<solution> soulmate);

    std::vector<int> genetic_material{};

protected:
    void element_switch_mutation();
    void block_move_mutation();
    void no_mutation();
    void perform_random_mutation(std::vector<std::function<void()>> mutations);


};

}