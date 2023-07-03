#include "Sheep.h"

Sheep::Sheep(int power, int initiative, int liveLength, int powerToReproduce,
             Position position)
    : Animal(power, initiative, liveLength, powerToReproduce, position)
{
    setSpecies("S");
}

Sheep::Sheep(Position position) : Animal(3, 3, 10, 6, position)
{
    setSpecies("S");
}

Sheep::~Sheep() = default;

Organism *Sheep::reproduce() const
{
    return new Sheep(3, 3, 10, 6, position);
}

void Sheep::move(int dx, int dy)
{
    setPosition({dx, dy});
}

std::string Sheep::toString() const
{
    return "Sheep " + getPosition().toString();
}
