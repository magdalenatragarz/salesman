#include <graph/node.hpp>

namespace graph {

node::node(std::string name) : name(std::move(name)){}

std::string node::get_name() const {
    return name;
}

}
