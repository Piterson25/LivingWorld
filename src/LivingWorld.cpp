#include "World.h"
#include <iostream>

int main()
{
    // World
    World world;

    // Positions
    Position p1{2, 2};
    Position p2{2, 4};
    Position p3{2, 3};
    Position p4{5, 5};
    Position p5{4, 4};

    world.addOrganism(OrganismCreator::createOrganism("G", p1));
    world.addOrganism(OrganismCreator::createOrganism("D", p2));
    world.addOrganism(OrganismCreator::createOrganism("S", p3));
    world.addOrganism(OrganismCreator::createOrganism("T", p4));
    world.addOrganism(OrganismCreator::createOrganism("W", p5));

    auto positions = world.getVectorOfPositionsAround(Position(5, 5));

    const std::string binFile = "world.bin";

    std::cout << "Start!\n==========\n";
    std::cout << world.toString() << '\n';
    std::cout << "==========\n\n";

    for (int i = 0; i < 10; ++i) {
        if (i == 4) {
            world.writeWorld(binFile);
            std::cout << "Saved world to " << binFile << "\n\n";
        }
        else if (i == 6) {
            world.readWorld(binFile);
            std::cout << "Loaded world from " << binFile << "\n\n";
        }

        world.makeTurn();
        std::cout << world.toString() << '\n';

        std::cout << "==========\n\n";
    }

    std::cout << world.organismsToString();

    return 0;
}
