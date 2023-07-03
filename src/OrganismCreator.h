#pragma once

#include "Dandelion.h"
#include "Grass.h"
#include "Organism.h"
#include "Position.h"
#include "Sheep.h"
#include "Toadstool.h"
#include "Wolf.h"
#include <functional>
#include <map>

class OrganismCreator {
private:
    static std::map<std::string, std::function<Organism *(const Position &)>>
        creator;

public:
    static Organism *createOrganism(const std::string &type,
                                    const Position &pos);
};
