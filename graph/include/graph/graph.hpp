#pragma once

#include <graph/matrix.hpp>
#include <graph/node.hpp>
#include <graph/edge.hpp>

#include <algorithm>
#include <fstream>
#include <sstream>
#include <tuple>
#include <memory>

namespace graph {

class graph {

public:
    explicit graph(std::string const& configuration_file_path);

    int get_weight(int source, int destination) const;
    int get_nodes_count() const;

private:
    void from_file(std::string const& path);
    std::string read_from_file(std::string const& path) const;
    std::vector<edge> deserialize(const std::string &content);
    void add_node(const node &new_node);
    void add_edge(const edge &new_edge);
    edge create_edge(const std::string &line);
    std::tuple<node, node, int> parse_edge_components(const std::string &line) const;
    bool is_comment(std::string const& line) const;
    int get_position(std::string const& node_name) const;
    bool node_exists(const node &checked_node) const;

    matrix adjacency_matrix;
    std::vector<std::string> nodes_names{};

};

}