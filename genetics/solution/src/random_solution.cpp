#pragma once

#include <solution/random_solution.hpp>

#include <iostream>

genetics::random_solution::random_solution() {
	std::cout << "Random solution created" << std::endl;
}

void genetics::random_solution::mutate() {
	std::cout << "Random solution mutated" << std::endl;
}