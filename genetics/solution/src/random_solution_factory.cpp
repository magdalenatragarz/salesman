#pragma once

#include <solution/random_solution_factory.hpp>
#include <solution/random_solution.hpp>

std::shared_ptr<genetics::solution> genetics::random_solution_factory::create_solution() {
	return std::make_shared<genetics::random_solution>();
}