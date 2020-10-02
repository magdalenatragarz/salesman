#include <graph/matrix.hpp>

namespace graph {

matrix::matrix(){
    resize();
}

int matrix::get(const int &x, const int &y) const {
    return content.at(y).at(x);
}

void matrix::set(const int &x, const int &y, const int &value) {
    while (content.size() <= x || content.size() <= y)
        resize();

    content.at(y).at(x) = value;
}

int matrix::get_dimension() const {
    return content.size();
}

void matrix::resize() {
    auto new_row = std::vector<int>{};
    content.push_back(new_row);

    for(auto &&row : content)
        row.resize(content.size());
}

}