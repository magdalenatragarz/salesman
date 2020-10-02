#pragma once

#include <vector>

namespace graph {

class matrix {
public:
    matrix();

    int get(const int &x, const int &y) const;
    int get_dimension() const;
    void set(const int &x, const int &y, const int &value);

private:
    void resize();

    std::vector<std::vector<int>> content{};
};


}
