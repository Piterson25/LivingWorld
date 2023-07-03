#pragma once

#include "OrganismCreator.h"
#include <algorithm>
#include <ctime>
#include <vector>

class World {
private:
    int worldX;
    int worldY;
    int turn = 0;
    std::vector<Organism *> organisms;
    char separator = '.';

    std::string getOrganismFromPosition(int x, int y);
    std::string getOrganismFromPosition(int x, int y, std::vector<Organism *> &temp);
    bool isPositionOnWorld(int x, int y);
    bool isPositionFree(Position position);
    bool isPositionFree(Position position, std::vector<Organism *> &temp);

    void sortByInitiative();

public:
    World(int worldX, int worldY);
    World() : World(6, 6){};
    ~World();

    int getWorldX();
    void setWorldX(int worldX);
    int getWorldY();
    void setWorldY(int worldY);

    int getTurn();

    void addOrganism(Organism *organism);
    std::vector<Position> getVectorOfPositionsAround(Position position);
    std::vector<Position> getVectorOfFreePositionsAround(Position position,
                                                         std::vector<Organism *> &temp);
    void makeTurn();

    void writeWorld(const std::string &fileName);
    void readWorld(const std::string &fileName);

    std::string toString();

    std::string organismsToString();
};
