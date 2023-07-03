#include "World.h"
#include <fstream>
#include <iostream>

std::string World::getOrganismFromPosition(int x, int y)
{
    for (auto &org : organisms) {
        if (org->getPosition().getX() == x && org->getPosition().getY() == y) {
            return org->getSpecies();
        }
    }

    return "";
}

std::string World::getOrganismFromPosition(int x, int y,
                                           std::vector<Organism *> &temp)
{
    for (auto &org : organisms) {
        if (org->getPosition().getX() == x && org->getPosition().getY() == y) {
            return org->getSpecies();
        }
    }

    for (auto &org : temp) {
        if (org->getPosition().getX() == x && org->getPosition().getY() == y) {
            return org->getSpecies();
        }
    }

    return "";
}

bool World::isPositionOnWorld(int x, int y)
{
    return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
}

bool World::isPositionFree(Position position)
{
    return this->getOrganismFromPosition(position.getX(), position.getY())
        .empty();
}

bool World::isPositionFree(Position position, std::vector<Organism *> &temp)
{
    return this->getOrganismFromPosition(position.getX(), position.getY(), temp)
        .empty();
}

void World::sortByInitiative()
{
    std::sort(organisms.begin(), organisms.end(),
              [](const Organism *org1, const Organism *org2) {
                  return org1->getInitiative() > org2->getInitiative();
              });
}

std::vector<Position>
World::getVectorOfFreePositionsAround(Position position,
                                      std::vector<Organism *> &temp)
{
    int pos_x = position.getX(), pos_y = position.getY();
    std::vector<Position> result;
    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if ((x != 0 || y != 0) && isPositionOnWorld(pos_x + x, pos_y + y)) {
                result.push_back(Position(pos_x + x, pos_y + y));
            }
        }
    }
    auto iter =
        remove_if(result.begin(), result.end(), [&, this](Position pos) {
            return !isPositionFree(pos, temp);
        });
    result.erase(iter, result.end());

    return result;
}

std::vector<Position> World::getVectorOfPositionsAround(Position position)
{
    int pos_x = position.getX(), pos_y = position.getY();
    std::vector<Position> result;
    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            if ((x != 0 || y != 0) && isPositionOnWorld(pos_x + x, pos_y + y)) {
                result.push_back(Position(pos_x + x, pos_y + y));
            }
        }
    }

    return result;
}

World::World(int worldX, int worldY)
{
    setWorldX(worldX);
    setWorldY(worldY);
}

World::~World()
{
    this->organisms.clear();
}

int World::getWorldX()
{
    return this->worldX;
}

void World::setWorldX(int worldX)
{
    this->worldX = worldX;
}

int World::getWorldY()
{
    return this->worldY;
}

void World::setWorldY(int worldY)
{
    this->worldY = worldY;
}

int World::getTurn()
{
    return this->turn;
}

void World::addOrganism(Organism *organism)
{
    organism->setBirth(this->turn);
    this->organisms.emplace_back(organism);
}

void World::makeTurn()
{
    std::vector<Position> newPositions;
    std::vector<Organism *> temp_orgs;
    int numberOfNewPositions;
    int randomIndex;

    sortByInitiative();

    srand(unsigned(time(0)));
    for (auto &org : organisms) {
        newPositions =
            getVectorOfFreePositionsAround(org->getPosition(), temp_orgs);
        numberOfNewPositions = static_cast<int>(newPositions.size());
        org->setPower(org->getPower() + 1);
        org->setLiveLength(org->getLiveLength() - 1);
        if (org->isReproduce() && numberOfNewPositions > 0) {
            randomIndex = rand() % numberOfNewPositions;
            Position newPosition = newPositions[randomIndex];
            org->setPower(org->getPower() / 2);
            auto new_org = org->reproduce();
            if (new_org != nullptr) {
                new_org->setAncestors(org->getAncestors());
                new_org->addAncestor(org->getBirth(), this->turn);
                new_org->setBirth(this->turn);
                new_org->setPosition(newPositions[randomIndex]);
                temp_orgs.push_back(new_org);
                std::cout << org->toString() << " reproduced to "
                          << newPosition.toString() << '\n';
            }
        }
        else {
            newPositions = getVectorOfPositionsAround(org->getPosition());
            randomIndex = rand() % newPositions.size();
            org->move(newPositions[randomIndex].getX(),
                      newPositions[randomIndex].getY());
        }

        temp_orgs.push_back(org);
    }

    organisms = std::move(temp_orgs);

    sortByInitiative();

    std::vector<Organism *> eatenToadstools;

    auto new_end = std::remove_if(
        organisms.begin(), organisms.end(), [&, this](Organism *org1) {
            for (auto &org2 : organisms) {
                if (org1->isKilledBy(org2)) {
                    std::cout << org1->toString() << " was killed!\n";
                    if (org1->getSpecies() == "T") {
                        eatenToadstools.push_back(org2);
                        std::cout << org2->toString()
                                  << " has eaten Toadstool!\n";
                    }
                    return true;
                }
            }
            return false;
        });
    organisms.erase(new_end, organisms.end());

    organisms.erase(std::remove_if(organisms.begin(), organisms.end(),
                                   [&](Organism *org) {
                                       return std::find(eatenToadstools.begin(),
                                                        eatenToadstools.end(),
                                                        org) !=
                                              eatenToadstools.end();
                                   }),
                    organisms.end());

    eatenToadstools.clear();

    auto iter =
        std::remove_if(organisms.begin(), organisms.end(), [](Organism *org) {
            if (org->getLiveLength() < 1) {
                std::cout << org->toString() << " has just DIED!\n";
                return true;
            }
            return false;
        });
    organisms.erase(iter, organisms.end());

    turn++;
}

void World::writeWorld(const std::string &fileName)
{
    std::fstream my_file;
    my_file.open(fileName, std::ios::out | std::ios::binary);
    if (my_file.is_open()) {
        my_file.write((char *)&this->worldX, sizeof(int));
        my_file.write((char *)&this->worldY, sizeof(int));
        my_file.write((char *)&this->turn, sizeof(int));
        int orgs_size = static_cast<int>(this->organisms.size());
        my_file.write((char *)&orgs_size, sizeof(int));
        for (int i = 0; i < orgs_size; i++) {
            this->organisms[i]->writeOrganism(my_file);
        }
        my_file.close();
    }
}

void World::readWorld(const std::string &fileName)
{
    this->organisms.clear();
    std::fstream my_file;
    my_file.open(fileName, std::ios::in | std::ios::binary);
    if (my_file.is_open()) {
        int result = 0;
        my_file.read((char *)&result, sizeof(int));
        this->worldX = result;
        my_file.read((char *)&result, sizeof(int));
        this->worldY = result;
        my_file.read((char *)&result, sizeof(int));
        this->turn = result;
        my_file.read((char *)&result, sizeof(int));
        int orgs_size = result;
        std::vector<Organism *> new_organisms;
        for (int i = 0; i < orgs_size; i++) {
            char species = ' ';
            my_file.read((char *)&species, sizeof(char));
            std::string speciesString(1, species);

            int pos_x = 0;
            my_file.read((char *)&pos_x, sizeof(int));
            int pos_y = 0;
            my_file.read((char *)&pos_y, sizeof(int));
            Position pos{pos_x, pos_y};

            auto org = OrganismCreator::createOrganism(speciesString, pos);
            org->setSpecies(speciesString);
            org->readOrganism(my_file);
            new_organisms.push_back(org);
        }
        for (Organism *org : new_organisms) {
            this->addOrganism(org);
        }
        my_file.close();
    }
}

std::string World::toString()
{
    std::string result = "\nturn: " + std::to_string(getTurn()) + '\n';
    std::string spec;

    for (int wY = 0; wY < getWorldY(); ++wY) {
        for (int wX = 0; wX < getWorldX(); ++wX) {
            spec = getOrganismFromPosition(wX, wY);
            if (spec != "") {
                result += spec;
            }
            else {
                result += separator;
            }
        };
        result += '\n';
    }
    return result;
}

std::string World::organismsToString()
{
    std::string result = "All organisms left:\n";

    for (const auto &org : this->organisms) {
        result += org->toString() + ' ' + org->ancestorsToString() + '\n';
    }

    return result;
}
