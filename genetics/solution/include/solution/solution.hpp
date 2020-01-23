#pragma once

#include <solution/chromosome.hpp>

#include <memory>

namespace genetics {

class solution {
public:
	virtual void mutate() = 0;

protected:
	std::shared_ptr<chromosome> chromosome{ nullptr };
};

}