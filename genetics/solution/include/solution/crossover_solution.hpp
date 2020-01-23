#pragma once

#include <solution/solution.hpp>

namespace genetics {

class crossover_solution : public solution {
public:
    crossover_solution();

	void mutate() override;
};

}