#pragma once

#include <genetics/solution.hpp>

namespace genetics {

class crossover_solution : public solution {

public:
    crossover_solution(std::shared_ptr<genetics::solution> mother, std::shared_ptr<genetics::solution> father);

private:
    void cross(std::shared_ptr<genetics::solution> mother, std::shared_ptr<genetics::solution> father);
    void fill_with_mother_genes(std::shared_ptr<genetics::solution> mother);
    void fill_with_father_genes(std::shared_ptr<genetics::solution> father);
    void perform_mutation();
    bool is_present_in_genetic_material(int gene) const;

};

}