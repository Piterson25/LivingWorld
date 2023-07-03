# LivingWorld

🌍 Living world simulation

LivingWorld is a C++ project that simulates a two-dimensional world where various organisms, such as Dandelion, Grass, Sheep, Toadstool, and Wolf, coexist. This simulation aims to model the interactions, dynamics among these organisms within their environment and focuses on determining which organisms are stronger than others.

## 🚀 Getting Started
To use the LivingWorld simulation, follow these steps:
1. Ensure you have a C++17-compatible compiler installed on your system.
2. Configure the project using CMake:

```sh
mkdir build
cd build
cmake ..
```

3. Build the project:

```sh
cmake --build .
```

4. Run the generated executable to start the simulation:

```sh
./LivingWorld
```


## 🎉 Features
### Organism Strength Comparison
The simulation allows for the comparison of the relative strength of different organisms, enabling analysis and observation of their interactions.

### Ancestral History
Each organism in the simulation stores a history of its ancestors, providing insights into their lineage and evolutionary path.

### SOLID Principles
The simulation incorporates the SOLID principles, ensuring modular and maintainable code design.

### Serialization/Deserialization
The simulation implements a robust mechanism for the serialization and deserialization of the world, enabling efficient storage and retrieval of simulation data. The serialized data is saved to [world.bin](https://github.com/Piterson25/LivingWorld/blob/main/src/world.bin)

## License
LivingWorld is licensed under the MIT License. See [LICENSE](https://github.com/Piterson25/LivingWorld/blob/main/LICENSE) for more information.