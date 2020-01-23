#pragma once

#include <solution/solution.hpp>
#include <solution/solution_factory.hpp>

#include <memory>

namespace genetics {

class crossover_solution_factory : public solution_factory {
public:
    std::shared_ptr<genetics::solution> create_solution() override;
};

}