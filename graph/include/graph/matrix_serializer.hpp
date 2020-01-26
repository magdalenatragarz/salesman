#pragma once

#include <graph/node.hpp>
#include <graph/edge.hpp>

#include <tuple>
#include <vector>
#include <memory>
#include <iostream>

namespace graph {

class matrix_serializer {
public:
    std::vector<std::shared_ptr<graph::edge>> deserialize(std::string content);

private:
    std::shared_ptr<graph::edge> create_edge(std::string line);
    std::tuple<std::shared_ptr<graph::node>, std::shared_ptr<graph::node>, int> parse_edge_components(std::string line);
    bool is_comment(std::string line);

};

}