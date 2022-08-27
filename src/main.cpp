#include <iostream>
#include <filesystem>
#include "BDGL.h"
#include "core/mesh.hpp"
#include "core/mesh_generator.hpp"
int main() {
    try {
        std::cout << "Executing runBDGL\n";
        BDGL windowding;

        windowding.createWindow("Blah");
        windowding.run();
    } catch (std::exception ex) {
        std::cout << "Crashed" << std::endl;
        std::cout << ex.what() << std::endl;
    }
}