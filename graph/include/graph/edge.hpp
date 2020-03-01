#pragma once

#include <graph/node.hpp>

#include <memory>

namespace graph {

class edge {
public:
    edge(std::shared_ptr<graph::node> source, std::shared_ptr<graph::node> destination, int weight);

    std::shared_ptr<graph::node> get_source() const;
    std::shared_ptr<graph::node> get_destination() const;
    int get_weight() const;

private:
    std::shared_ptr<graph::node> source;
    std::shared_ptr<graph::node> destination;
    int weight;
};

}