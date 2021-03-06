#pragma once

#include <string>

namespace graph {

class node {
public:
    explicit node(std::string name);
    std::string get_name() const;

private:
    std::string name;
};

}