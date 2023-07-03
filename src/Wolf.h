#pragma once

#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(int power, int initiative, int liveLength, int powerToReproduce,
         Position position);
    Wolf(Position position);
    ~Wolf() override;

    Organism *reproduce() const override;
    void move(int dx, int dy) override;
    std::string toString() const override;
};
