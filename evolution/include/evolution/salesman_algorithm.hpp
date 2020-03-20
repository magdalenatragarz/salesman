#pragma once

#include <evolution/map.hpp>
#include <evolution/path.hpp>
#include <genetics/population_factory.hpp>

#include <numeric>

namespace evolution {

class salesman_algorithm {
public:
    salesman_algorithm(std::shared_ptr<evolution::map> map, int max_iterations_without_change);

    void run();
    std::shared_ptr<evolution::path> get_best_solution() const;

private:
    void perform_evolution();
    void perform_evolution_iteration();
    void remove_weak_solutions();
    void generate_population();
    void generate_crossover_solution();
    void update_current_best_solution_info();
    void update_current_best_solution();
    void sort_population_members();
    std::vector<int> generate_cities_ids() const;
    bool is_in_termination_stage() const;

    int iterations_without_change{0};
    int max_iterations_without_change;
    std::shared_ptr<evolution::path> current_best_solution;

    std::shared_ptr<evolution::map> map;
    std::vector<std::shared_ptr<evolution::path>> population{};

};

}