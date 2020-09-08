#include "src/dragonborn.h"
#include "../utils/algorithmUtils.h"
#include "src/misc.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]\n";
        exit(1);
    }
    try {
        Patterns patterns;
        Dragonborn dr;

        readCmd(std::string(argv[1]), patterns, dr);
    }
    catch(...) {
        std::cerr << "Invalid action" << std::endl;
    }
    return 0;
}