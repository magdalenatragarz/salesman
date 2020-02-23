#pragma once

#include "solution.hpp"

namespace genetics {

class crossover_solution : public solution {
public:
    crossover_solution(std::shared_ptr<solution> mother, std::shared_ptr<solution> father);

private:
    std::vector<int> cross(std::shared_ptr<solution> mother,
            std::shared_ptr<solution> father);
};

}