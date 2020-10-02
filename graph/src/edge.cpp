#include <graph/edge.hpp>

namespace graph {

edge::edge(graph::node source, graph::node destination, int weight)
    : source(std::move(source)),
      destination(std::move(destination)),
      weight(weight) {}

graph::node edge::get_source() const {
    return source;
}

graph::node edge::get_destination() const {
    return destination;
}

int edge::get_weight() const {
    return weight;
}

}