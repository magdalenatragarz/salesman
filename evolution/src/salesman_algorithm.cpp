#include <evolution/salesman_algorithm.hpp>

namespace evolution {

salesman_algorithm::salesman_algorithm(evolution::map map,
                                       int max_iterations_without_change)
    : map(std::move(map)), population(),
      max_iterations_without_change(max_iterations_without_change),
      current_best_solution() {

  generate_population();
  sort_population_members();
  update_current_best_solution();
}

void salesman_algorithm::run() { perform_evolution(); }

void salesman_algorithm::perform_evolution() {
  if (is_in_termination_stage())
    return;

  perform_evolution_iteration();
  update_current_best_solution_info();
  perform_evolution();
}

void salesman_algorithm::perform_evolution_iteration() {
  remove_weak_solutions();

  auto population_count = population.size();
  for (int i = 0; i < population_count; i++)
    generate_crossover_solution();

  sort_population_members();
}

void salesman_algorithm::remove_weak_solutions() {
  auto half = population.begin() + population.size() / 2;
  population.erase(half, population.end());
}

void salesman_algorithm::generate_population() {
  auto genetic_material = generate_cities_ids();
  auto population_factory =
      std::make_shared<evolution::population_factory>(genetic_material);
  auto solutions_population = population_factory->generate_population();

  for (auto &solution : solutions_population)
    population.emplace_back(evolution::path(solution, map));
}

void salesman_algorithm::generate_crossover_solution() {
  auto mother_index = std::random_device()() % population.size();
  auto father_index = std::random_device()() % population.size();

  auto mother = population.at(mother_index).get_solution();
  auto father = population.at(father_index).get_solution();

  auto offspring_solution = std::make_shared<genetics::crossover_solution>(mother, father);

  population.emplace_back(evolution::path(offspring_solution, map));
}

std::vector<int> salesman_algorithm::generate_cities_ids() const {
  auto genetic_material_size = map.get_cities_count();

  std::vector<int> genetic_material(genetic_material_size);
  std::iota(genetic_material.begin(), genetic_material.end(), 0);

  return genetic_material;
}

void salesman_algorithm::update_current_best_solution_info() {
  if (current_best_solution == get_best_solution()) {
    iterations_without_change += 1;
  } else {
    iterations_without_change = 0;
    update_current_best_solution();
  }
}

void salesman_algorithm::sort_population_members() {
  std::sort(population.begin(), population.end());
}

void salesman_algorithm::update_current_best_solution() {
  current_best_solution = get_best_solution();
}

bool salesman_algorithm::is_in_termination_stage() const {
  return max_iterations_without_change == iterations_without_change;
}

evolution::path salesman_algorithm::get_best_solution() const {
  return population.front();
}

} // namespace evolution