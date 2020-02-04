#include <iostream>
#include <memory>
#include <graph/matrix.hpp>
#include <graph/graph.hpp>


int main() {

    auto graph = std::make_shared<graph::graph>(R"(D:\projects\salesman\graph_example.map)");

    std::cout << graph->get_weight("Cracow", "Warsaw") << std::endl;

}