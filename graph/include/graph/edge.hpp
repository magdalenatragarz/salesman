#pragma once

#include <graph/node.hpp>

#include <memory>

namespace graph {

class edge {
public:
    edge(std::shared_ptr<graph::node> source, std::shared_ptr<graph::node> destination, int weight);

    std::shared_ptr<graph::node> get_source();
    std::shared_ptr<graph::node> get_destination();
    int get_weight();

private:
    std::shared_ptr<graph::node> source;
    std::shared_ptr<graph::node> destination;
    int weight;
};

}