#pragma once

#include <genetics/solution.hpp>
#include <evolution/map.hpp>

#include <memory>

namespace evolution {

class path {

public:
    path(std::shared_ptr<genetics::solution> solution, std::shared_ptr<evolution::map> map);

    std::shared_ptr<genetics::solution> get_solution() const;
    int get_distance() const;

    friend bool operator < (const std::shared_ptr<path> &lhs, const std::shared_ptr<path> &rhs);
    friend bool operator == (const std::shared_ptr<path> &lhs, const std::shared_ptr<path> &rhs);
    friend std::ostream & operator << (std::ostream &out, const std::shared_ptr<path> &rhs);

private:
    std::shared_ptr<genetics::solution> solution;
    int distance;

};

}