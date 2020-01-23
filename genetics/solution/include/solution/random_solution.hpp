#pragma once

#include <solution/solution.hpp>

namespace genetics {

class random_solution : public solution {
public:
	random_solution();

	void mutate() override;
};

}