#include <evolution/path.hpp>

namespace evolution {

path::path(std::shared_ptr<genetics::solution> solution, const evolution::map &map)
    : solution(solution),
      distance(map.get_absolute_distance(solution->get_genetic_material())) {}

std::shared_ptr<genetics::solution> path::get_solution() const {
    return solution;
}

int path::get_distance() const {
    return distance;
}

bool operator < (const evolution::path &lhs, const evolution::path &rhs){
    return lhs.distance < rhs.distance;
}

bool operator == (const evolution::path &lhs, const evolution::path &rhs){
    return lhs.distance == rhs.distance;
}

std::ostream & operator << (std::ostream &out, const evolution::path &rhs){
    out << rhs.get_solution();
    return out;
}

}