#include <iostream>
#include "BDGL.h"

int main() {
    try {
        std::cout << "Executing runBDGL\n";
        BDGL windowding;

        windowding.createWindow("Blah");
        windowding.run();
    } catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

}