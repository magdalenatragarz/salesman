#include <evolution/path.hpp>

namespace evolution {

path::path(std::shared_ptr<genetics::solution> solution, std::shared_ptr<evolution::map> map)
    : solution(solution),
      distance(map->get_absolute_distance(solution->get_genetic_material())) {}


std::shared_ptr<genetics::solution> path::get_solution() const {
    return solution;
}


int path::get_distance() const {
    return distance;
}


bool operator < (const std::shared_ptr<path> &lhs, const std::shared_ptr<path> &rhs){
    return lhs->distance < rhs->distance;
}


bool operator == (const std::shared_ptr<path> &lhs, const std::shared_ptr<path> &rhs){
    return lhs->distance == rhs->distance;
}


std::ostream & operator << (std::ostream &out, const std::shared_ptr<path> &s){
    out << s->get_solution();
    return out;
}

}