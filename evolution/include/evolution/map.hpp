#pragma once

#include <graph/graph.hpp>

#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace evolution {

class map {
public:
    explicit map(std::string configuration_file_path);

    int get_absolute_distance(std::vector<int> path) const;
    int get_cities_count() const;

private:
    int get_distance(int lhs_city_id, int rhs_city_id) const;
    std::shared_ptr<graph::graph> graph_representation;
};

}