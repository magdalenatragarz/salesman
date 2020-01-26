#pragma once

#include <graph/edge.hpp>
#include <graph/matrix_serializer.hpp>

#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

namespace graph {

class adjacency_matrix {
public:
    friend class graph::matrix_serializer;

    adjacency_matrix(std::shared_ptr<graph::matrix_serializer> serializer);

    int get(std::string x, std::string y);

    void from_file(std::string path);
    void to_file(std::string path);

private:
    void add_node(std::shared_ptr<graph::node> node);
    bool node_exists(std::shared_ptr<graph::node> node);
    void resize_matrix();
    void add_edge(std::shared_ptr<graph::edge> edge);
    int get_position(std::string node_name);
    std::string read_from_file(std::string path);

    std::vector<std::vector<int>> matrix{};
    std::vector<std::string> nodes_names{};
    std::shared_ptr<graph::matrix_serializer> serializer;
};


}
