#include <graph/edge.hpp>

namespace graph {

edge::edge(std::shared_ptr<graph::node> source, std::shared_ptr<graph::node> destination, int weight)
    : source(std::move(source)), destination(std::move(destination)), weight(weight) {}


std::shared_ptr<graph::node> edge::get_source() const {
    return source;
}


std::shared_ptr<graph::node> edge::get_destination() const {
    return destination;
}


int edge::get_weight() const {
    return weight;
}

}