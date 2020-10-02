#pragma once

#include <graph/node.hpp>

#include <memory>

namespace graph {

class edge {
public:
    edge(graph::node source, graph::node destination, int weight);

    graph::node get_source() const;
    graph::node get_destination() const;
    int get_weight() const;

private:
    graph::node source;
    graph::node destination;
    int weight;
};

}