#include <evolution/map.hpp>
#include <evolution/salesman_algorithm.hpp>

#include <iostream>
#include <memory>
#include <chrono>

int main() {

    std::string file_path = "D:\\projekty\\salesman_parser\\15cities.map";

    auto map = evolution::map(file_path);
    auto algorithm = evolution::salesman_algorithm(map, 50);

    auto start = std::chrono::steady_clock::now();
    algorithm.run();
    auto end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;
    std::cout << "path: " <<  algorithm.get_best_solution() << std::endl;
    std::cout << "distance: " << algorithm.get_best_solution().get_distance() << std::endl;


}