#include "Wolf.h"

Wolf::Wolf(int power, int initiative, int liveLength, int powerToReproduce,
           Position position)
    : Animal(power, initiative, liveLength, powerToReproduce, position)
{
    setSpecies("W");
}

Wolf::Wolf(Position position) : Animal(8, 5, 20, 16, position)
{
    setSpecies("W");
}

Wolf::~Wolf() = default;

Organism *Wolf::reproduce() const
{
    return new Wolf(8, 5, 20, 16, position);
}

void Wolf::move(int dx, int dy)
{
    setPosition({dx, dy});
}

std::string Wolf::toString() const
{
    return "Wolf " + getPosition().toString();
}
