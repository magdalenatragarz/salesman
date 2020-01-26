#include <graph/adjacency_matrix.hpp>

namespace graph {

adjacency_matrix::adjacency_matrix(std::shared_ptr<graph::matrix_serializer> serializer)
    : serializer(std::move(serializer)) {}

void adjacency_matrix::add_node(std::shared_ptr<graph::node> node) {
    if (!node_exists(node)) {
        nodes_names.push_back(node->get_name());
        resize_matrix();
    }
}

bool adjacency_matrix::node_exists(std::shared_ptr<graph::node> node) {
    return std::find(nodes_names.begin(), nodes_names.end(), node->get_name()) != nodes_names.end();
}

void adjacency_matrix::resize_matrix() {
    auto new_row = std::vector<int>{};
    matrix.push_back(new_row);

    for( auto & row : matrix)
        row.resize(nodes_names.size());
}

void adjacency_matrix::add_edge(std::shared_ptr<graph::edge> edge) {
    auto x = get_position(edge->get_source()->get_name());
    auto y = get_position(edge->get_destination()->get_name());
    matrix.at(y).at(x) = edge->get_weight();
}

int adjacency_matrix::get_position(std::string node_name) {
    auto it = std::find(nodes_names.begin(), nodes_names.end(), node_name);
    return std::distance(nodes_names.begin(), it);
}

void adjacency_matrix::to_file(std::string path) {

}

void adjacency_matrix::from_file(std::string path) {
    auto recipe = read_from_file(std::move(path));
    auto edges = serializer->deserialize(recipe);
    for (auto & edge : edges) {
        add_node(edge->get_source());
        add_node(edge->get_destination());
        add_edge(edge);
    }
}

int adjacency_matrix::get(std::string source, std::string destination) {
    auto x = get_position(std::move(source));
    auto y = get_position(std::move(destination));
    return matrix.at(y).at(x);
}

std::string adjacency_matrix::read_from_file(std::string path) {
    auto file = std::ifstream(path);
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

}