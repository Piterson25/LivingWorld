#include "Dandelion.h"

Dandelion::Dandelion(int power, int initiative, int liveLength,
                     int powerToReproduce, Position position)
    : Plant(power, initiative, liveLength, powerToReproduce, position)
{
    setSpecies("D");
}

Dandelion::Dandelion(Position position) : Plant(0, 0, 6, 2, position)
{
    setSpecies("D");
}

Dandelion::~Dandelion() = default;

Organism *Dandelion::reproduce() const
{
    return new Dandelion(0, 0, 6, 2, position);
}

void Dandelion::move(int dx, int dy)
{
}

std::string Dandelion::toString() const
{
    return "Dandelion " + getPosition().toString();
}
