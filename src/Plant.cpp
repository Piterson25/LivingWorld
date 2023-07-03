#include "Plant.h"

Plant::Plant(int power, int initiative, int liveLength, int powerToReproduce,
             Position position)
    : Organism(power, initiative, liveLength, powerToReproduce, position)
{
    setSpecies("P");
}

Plant::Plant(Position position) : Organism(position)
{
    setSpecies("P");
}

Plant::~Plant() = default;

Organism *Plant::reproduce() const
{
    return new Plant(position);
}

void Plant::move(int dx, int dy)
{
    this->position = Position(dx, dy);
}

std::string Plant::toString() const
{
    return "Plant " + getPosition().toString();
}
