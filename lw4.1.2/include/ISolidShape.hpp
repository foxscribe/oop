#pragma once

#include "IShape.hpp"
#include <cstdint>

class ISolidShape : public IShape
{
public:
    virtual uint32_t GetFillColor() const = 0;
};
