#include <graph/matrix_serializer.hpp>

#include <iostream>
#include <graph/adjacency_matrix.hpp>


int main() {

    auto serializer = std::make_shared<graph::matrix_serializer>();
    auto matrix = std::make_shared<graph::adjacency_matrix>(serializer);

    matrix->from_file(R"(D:\projects\salesman\graph_example.map)");
    std::cout << matrix->get("Cracow", "Warsaw") << std::endl;

}