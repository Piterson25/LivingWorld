#include "Grass.h"

Grass::Grass(int power, int initiative, int liveLength, int powerToReproduce,
             Position position)
    : Plant(power, initiative, liveLength, powerToReproduce, position)
{
    setSpecies("G");
}

Grass::Grass(Position position) : Plant(0, 0, 6, 3, position)
{
    setSpecies("G");
}

Grass::~Grass() = default;

Organism *Grass::reproduce() const
{
    return new Grass(0, 0, 6, 3, position);
}

void Grass::move(int dx, int dy)
{
}

std::string Grass::toString() const
{
    return "Grass " + getPosition().toString();
}
