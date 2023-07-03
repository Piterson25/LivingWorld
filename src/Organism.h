#pragma once

#include "Position.h"
#include <fstream>
#include <list>
#include <string>

class Organism {
protected:
    int power;
    int initiative;
    Position position;
    int liveLength;
    int powerToReproduce;
    std::string species;
    std::list<std::pair<int, int>> ancestors;
    int birth;

public:
    Organism(int power, int initiative, int liveLength, int powerToReproduce,
             Position position);
    Organism(Position position);
    Organism(const Organism &other);
    Organism(Organism *other);
    virtual ~Organism();

    std::string ancestorsToString() const;
    void addAncestor(int t_birth, int t_death);
    bool isKilledBy(Organism *organism) const;
    void writeOrganism(std::fstream &stream);
    void readOrganism(std::fstream &stream);
    bool operator==(Organism &other) const;

    int getPower() const;
    int getInitiative() const;
    Position getPosition() const;
    int getPositionX() const;
    int getPositionY() const;
    int getLiveLength() const;
    int getPowerToReproduce() const;
    std::string getSpecies() const;
    int getBirth() const;
    std::list<std::pair<int, int>> getAncestors();
    bool isReproduce() const;

    void setPower(int t_power);
    void setInitiative(int t_initiative);
    void setPosition(Position t_position);
    void setLiveLength(int t_liveLength);
    void setPowerToReproduce(int t_powerToReproduce);
    void setSpecies(const std::string &t_spec);
    void setBirth(int t_birth);
    void setAncestors(const std::list<std::pair<int, int>> &t_ancestors);

    virtual Organism *reproduce() const = 0;
    virtual void move(int dx, int dy) = 0;
    virtual std::string toString() const = 0;
};
