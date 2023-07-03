#pragma once

#include "Organism.h"

class Animal : public Organism {
public:
    Animal(int power, int initiative, int liveLength, int powerToReproduce,
           Position position);
    Animal(Position position);
    ~Animal() override;

    Organism *reproduce() const override;
    void move(int dx, int dy) override;
    std::string toString() const override;
};
