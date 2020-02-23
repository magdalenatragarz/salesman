#include <genetics/random_solution.hpp>

#include <iostream>

namespace genetics {

random_solution::random_solution(int size) {
    for (int i = 0; i < size; i++) {
        genetic_material.push_back(i);
    }
}


}