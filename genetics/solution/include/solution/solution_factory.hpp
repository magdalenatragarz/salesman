#pragma once

#include <solution/solution.hpp>

#include <memory>

namespace genetics {

class solution_factory {
public:
	virtual std::shared_ptr<solution> create_solution() = 0;
};

}