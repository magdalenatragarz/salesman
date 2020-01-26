#include <graph/matrix_serializer.hpp>

#include <sstream>
#include <iostream>

namespace graph {

std::vector<std::shared_ptr<graph::edge>> matrix_serializer::deserialize(std::string content) {
    auto content_stream = std::istringstream(content);
    auto line = std::string();
    auto edges = std::vector<std::shared_ptr<graph::edge>>();

    while (std::getline(content_stream, line)) {
        if (is_comment(line) || line.empty())
            continue;
        edges.push_back(create_edge(line));
    }
    return edges;
}

std::shared_ptr<graph::edge> matrix_serializer::create_edge(std::string line) {
    auto [source, destination, weight] = parse_edge_components(line);
    return std::make_shared<graph::edge>(source, destination, weight);
}

std::tuple<std::shared_ptr<graph::node>, std::shared_ptr<graph::node>, int>
        matrix_serializer::parse_edge_components(std::string line) {
    auto edges_stream = std::istringstream(line);
    auto edge_component = std::string();
    auto edge_component_vector = std::vector<std::string>();

    while( edges_stream >> edge_component )
        edge_component_vector.push_back(edge_component);

    auto source = std::make_shared<graph::node>(edge_component_vector[0]);
    auto destination = std::make_shared<graph::node>(edge_component_vector[1]);
    auto weight = std::stoi(edge_component_vector[2]);

    return std::make_tuple<std::shared_ptr<graph::node>,
            std::shared_ptr<graph::node>, int>(std::move(source), std::move(destination), std::move(weight));
}

bool matrix_serializer::is_comment(std::string line) {
    auto constexpr comment_marker = "//";
    auto constexpr position = 0;

    return (line.rfind(comment_marker, position) == 0);
}

}