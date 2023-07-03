#include "Animal.h"

Animal::Animal(int power, int initiative, int liveLength, int powerToReproduce,
               Position position)
    : Organism(power, initiative, liveLength, powerToReproduce, position)
{
    setSpecies("A");
}

Animal::Animal(Position position) : Organism(position)
{
    setSpecies("A");
}

Animal::~Animal()
{
}

Organism *Animal::reproduce() const
{
    return new Animal(position);
}

void Animal::move(int dx, int dy)
{
    this->position = Position(dx, dy);
}

std::string Animal::toString() const
{
    return "Animal " + getPosition().toString();
}
