#pragma once

#include <genetics/solution.hpp>

namespace genetics {

class random_solution : public solution {
public:
	explicit random_solution(std::vector<int> const& genotype);

};

}