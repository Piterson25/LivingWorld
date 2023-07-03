#include "OrganismCreator.h"

std::map<std::string, std::function<Organism *(const Position &)>>
    OrganismCreator::creator = {
        {"D", [](const Position &pos) { return new Dandelion(pos); }},
        {"G", [](const Position &pos) { return new Grass(pos); }},
        {"S", [](const Position &pos) { return new Sheep(pos); }},
        {"T", [](const Position &pos) { return new Toadstool(pos); }},
        {"W", [](const Position &pos) { return new Wolf(pos); }}};

Organism *OrganismCreator::createOrganism(const std::string &type,
                                          const Position &pos)
{
    auto it = creator.find(type);
    if (it != creator.end()) {
        return it->second(pos);
    }
    return nullptr;
}
