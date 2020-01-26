#pragma once

#include <string>

namespace graph {

class node {
public:
    node(std::string name);
    std::string const get_name() const;

private:
    std::string name;
};

}