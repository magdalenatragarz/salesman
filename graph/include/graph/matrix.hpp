#pragma once

#include <vector>

namespace graph {

class matrix {
public:
    matrix();

    int get(int const& x, int const& y);
    int get_dimension();
    void set(int const& x, int const& y, int const& value);

private:
    void resize();

    std::vector<std::vector<int>> content{};
};


}
