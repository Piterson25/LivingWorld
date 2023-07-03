#pragma once

#include "Plant.h"

class Grass : public Plant {
public:
    Grass(int power, int initiative, int liveLength, int powerToReproduce,
          Position position);
    Grass(Position position);
    ~Grass() override;

    Organism *reproduce() const override;
    void move(int dx, int dy) override;
    std::string toString() const override;
};
