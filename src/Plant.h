#pragma once

#include "Organism.h"

class Plant : public Organism {
public:
    Plant(int power, int initiative, int liveLength, int powerToReproduce,
          Position position);
    Plant(Position position);
    ~Plant() override;

    Organism *reproduce() const override;
    void move(int dx, int dy) override;
    std::string toString() const override;
};
