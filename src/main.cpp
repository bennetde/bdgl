#include <iostream>
#include "BDGL.h"

int main() {
    try {
        std::cout << "Hello World\n";
        BDGL windowding;

        windowding.createWindow("Blah");
        windowding.run();
    } catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

}