#include <evolution/map.hpp>

namespace evolution {

map::map(const std::string &configuration_string) : graph_representation(configuration_string) {}

int map::get_absolute_distance(std::vector<int> path) const {
    auto absolute_distance = 0;

    for (int i = 0; i < path.size() - 1; i++)
        absolute_distance += get_distance(path.at(i), path.at(i + 1));
    absolute_distance += get_distance(path.back(), path.front());

    return absolute_distance;
}

int map::get_distance(int lhs_city_id, int rhs_city_id) const {
    return graph_representation.get_weight(lhs_city_id, rhs_city_id);
}

int map::get_cities_count() const{
    return graph_representation.get_nodes_count();
}

}