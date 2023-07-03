#pragma once

#include "Plant.h"

class Dandelion : public Plant {
public:
    Dandelion(int power, int initiative, int liveLength, int powerToReproduce,
              Position position);
    Dandelion(Position position);
    ~Dandelion() override;

    Organism *reproduce() const override;
    void move(int dx, int dy) override;
    std::string toString() const override;
};
