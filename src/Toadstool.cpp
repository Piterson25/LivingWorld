#include "Toadstool.h"

Toadstool::Toadstool(int power, int initiative, int liveLength,
                     int powerToReproduce, Position position)
    : Plant(power, initiative, liveLength, powerToReproduce, position)
{
    setSpecies("T");
}

Toadstool::Toadstool(Position position) : Plant(0, 0, 12, 4, position)
{
    setSpecies("T");
}

Toadstool::~Toadstool() = default;

Organism *Toadstool::reproduce() const
{
    return new Toadstool(0, 0, 12, 4, position);
}

void Toadstool::move(int dx, int dy)
{
}

std::string Toadstool::toString() const
{
    return "Toadstool " + getPosition().toString();
}
