#pragma once

#include "Plant.h"

class Toadstool : public Plant {
public:
    Toadstool(int power, int initiative, int liveLength, int powerToReproduce,
              Position position);
    Toadstool(Position position);
    ~Toadstool() override;

    Organism *reproduce() const override;
    void move(int dx, int dy) override;
    std::string toString() const override;
};
