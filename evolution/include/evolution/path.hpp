#pragma once

#include <genetics/solution.hpp>
#include <evolution/map.hpp>

#include <memory>

namespace evolution {

class path {

public:
    path() = default;
    path(std::shared_ptr<genetics::solution> solution, const evolution::map &map);

    std::shared_ptr<genetics::solution> get_solution() const;
    int get_distance() const;

    friend bool operator < (const evolution::path &lhs, const evolution::path &rhs);
    friend bool operator == (const evolution::path &lhs, const evolution::path &rhs);
    friend std::ostream & operator << (std::ostream &out, const evolution::path &rhs);

private:
    std::shared_ptr<genetics::solution> solution;
    int distance{0};

};

}