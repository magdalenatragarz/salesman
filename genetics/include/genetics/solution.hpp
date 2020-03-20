#pragma once

#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <random>

namespace genetics {

class solution {
public:
	void mutate();

    std::vector<int> get_genetic_material() const;
    int get_genetic_material_size() const;
    int get_gene(int index) const;
    bool fit_to(std::shared_ptr<solution> soulmate) const;

    friend std::ostream & operator << (std::ostream &out, const std::shared_ptr<genetics::solution> &rhs);

protected:
    void perform_random_mutation(std::vector<std::function<void()>> mutations);
    void no_mutation();
    void element_switch_mutation();
    void block_switch_mutation();

    std::vector<int> genetic_material{};

};

}