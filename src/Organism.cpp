#include "Organism.h"

Organism::Organism(int power, int initiative, int liveLength,
                   int powerToReproduce, Position position)
    : power(power), initiative(initiative), liveLength(liveLength),
      powerToReproduce(powerToReproduce), position(position), species("O"),
      birth(0)
{
}

Organism::Organism(Position position)
    : power(0), initiative(0), position(position), liveLength(0),
      powerToReproduce(0), species("O"), birth(0)
{
}

Organism::Organism(const Organism &other)
    : ancestors(other.ancestors), birth(0), power(other.power),
      initiative(other.initiative), liveLength(other.liveLength),
      powerToReproduce(other.powerToReproduce), position(other.position)
{
}

Organism::Organism(Organism *other)
    : ancestors(other->ancestors), birth(0), power(other->power),
      initiative(other->initiative), liveLength(other->liveLength),
      powerToReproduce(other->powerToReproduce), position(other->position)
{
}

Organism::~Organism() = default;

std::string Organism::ancestorsToString() const
{
    std::string ancestorsStr;
    for (const auto &ancestor : ancestors) {
        ancestorsStr += "(" + std::to_string(ancestor.first) + ", " +
                        std::to_string(ancestor.second) + "), ";
    }
    ancestorsStr = ancestorsStr.substr(0, ancestorsStr.size() - 2);
    return "ancestors: [" + ancestorsStr + "]";
}

void Organism::addAncestor(int t_birth, int t_death)
{
    std::pair<int, int> ancestor(t_birth, t_death);
    this->ancestors.push_back(ancestor);
}

bool Organism::isKilledBy(Organism *organism) const
{
    return (organism->getPower() > this->power &&
            this->position.isEqual(organism->getPosition()));
}

void Organism::writeOrganism(std::fstream &stream)
{
    char species = this->species[0];
    stream.write((char *)&species, sizeof(char));
    int x = this->position.getX();
    stream.write((char *)&x, sizeof(int));
    int y = this->position.getY();
    stream.write((char *)&y, sizeof(int));
    stream.write((char *)&this->power, sizeof(int));
    stream.write((char *)&this->initiative, sizeof(int));
    stream.write((char *)&this->liveLength, sizeof(int));
    stream.write((char *)&this->powerToReproduce, sizeof(int));
    int ancestors_size = static_cast<int>(this->ancestors.size());
    stream.write((char *)&ancestors_size, sizeof(int));
    for (const auto &ancestor : this->ancestors) {
        stream.write((char *)&ancestor.first, sizeof(int));
        stream.write((char *)&ancestor.second, sizeof(int));
    }
    stream.write((char *)&this->birth, sizeof(int));
}

void Organism::readOrganism(std::fstream &stream)
{
    stream.read((char *)&this->power, sizeof(int));
    stream.read((char *)&this->initiative, sizeof(int));
    stream.read((char *)&this->liveLength, sizeof(int));
    stream.read((char *)&this->powerToReproduce, sizeof(int));
    int ancestors_size = 0;
    stream.read((char *)&ancestors_size, sizeof(int));
    for (int i = 0; i < ancestors_size; i++) {
        int birth = 0, death = 0;
        stream.read((char *)&birth, sizeof(int));
        stream.read((char *)&death, sizeof(int));
        this->ancestors.push_back(std::make_pair(birth, death));
    }
    stream.read((char *)&this->birth, sizeof(int));
}

bool Organism::operator==(Organism &other) const
{
    return (this->power == other.power &&
            this->position.isEqual(other.getPosition()) &&
            this->species == other.species &&
            this->ancestors == other.ancestors);
}

int Organism::getPower() const
{
    return this->power;
}

int Organism::getInitiative() const
{
    return this->initiative;
}

Position Organism::getPosition() const
{
    return this->position;
}

int Organism::getPositionX() const
{
    return this->position.getX();
}

int Organism::getPositionY() const
{
    return this->position.getY();
}

int Organism::getLiveLength() const
{
    return this->liveLength;
}

int Organism::getPowerToReproduce() const
{
    return this->powerToReproduce;
}

std::string Organism::getSpecies() const
{
    return this->species;
}

int Organism::getBirth() const
{
    return this->birth;
}

std::list<std::pair<int, int>> Organism::getAncestors()
{
    return this->ancestors;
}

bool Organism::isReproduce() const
{
    return this->power >= this->powerToReproduce;
}

void Organism::setPower(int t_power)
{
    this->power = t_power;
}

void Organism::setInitiative(int t_initiative)
{
    this->initiative = t_initiative;
}

void Organism::setPosition(Position t_position)
{
    this->position = t_position;
}

void Organism::setLiveLength(int t_liveLength)
{
    this->liveLength = t_liveLength;
}

void Organism::setPowerToReproduce(int t_powerToReproduce)
{
    this->powerToReproduce = t_powerToReproduce;
}

void Organism::setSpecies(const std::string &t_spec)
{
    this->species = t_spec;
}

void Organism::setBirth(int t_birth)
{
    this->birth = t_birth;
}

void Organism::setAncestors(const std::list<std::pair<int, int>> &t_ancestors)
{
    this->ancestors = t_ancestors;
}
