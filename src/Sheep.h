#pragma once

#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(int power, int initiative, int liveLength, int powerToReproduce,
          Position position);
    Sheep(Position position);
    ~Sheep() override;

    Organism *reproduce() const override;
    void move(int dx, int dy) override;
    std::string toString() const override;
};
