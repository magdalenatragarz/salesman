#include <graph/matrix.hpp>

namespace graph {

matrix::matrix(){
    resize();
    resize();
}


int matrix::get(int const& x, int const& y) {
    return content.at(y).at(x);
}


void matrix::set(int const& x, int const& y, int const& value) {
    while (content.size() <= x || content.size() <= y)
        resize();

    content.at(y).at(x) = value;
}


int matrix::get_dimension() {
    return content.size();
}


void matrix::resize() {
    auto new_row = std::vector<int>{};
    content.push_back(new_row);

    for( auto & row : content)
        row.resize(content.size());
}

}