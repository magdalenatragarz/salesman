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
    std::string read_from_file(std::string const& path);
    std::vector<std::shared_ptr<edge>> deserialize(std::string content);
    void add_node(std::shared_ptr<node> node);
    void add_edge(std::shared_ptr<edge> edge);
    std::shared_ptr<edge> create_edge(std::string line);
    std::tuple<std::shared_ptr<node>, std::shared_ptr<node>, int> parse_edge_components(std::string line);
    bool is_comment(std::string const& line);
    int get_position(std::string const& node_name);
    bool node_exists(std::shared_ptr<node> node);

    std::shared_ptr<matrix> adjacency_matrix;
    std::vector<std::string> nodes_names{};

};

}