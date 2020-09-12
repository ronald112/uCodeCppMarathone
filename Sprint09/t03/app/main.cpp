#include "Worker.h"
#include "ClassWithAtomic.h"
#include <iostream>

static void checkInput(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "usage: classWithAtomic [add] [subtract] [size]" << std::endl;
        exit(EXIT_FAILURE);
    }
    try {
        std::stoi(argv[1]);
        std::stoi(argv[2]);
        std::stoi(argv[3]);
    }
    catch (...) {
        std::cerr << "Incorrect values" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    checkInput(argc, argv);
    int addValue = std::stoi(argv[1]);
    int subtractValue = std::stoi(argv[2]);
    int pushSize = std::stoi(argv[3]);
    Worker worker;

    ClassWithAtomic obj;

    worker.startNewThread(&ClassWithAtomic::addToInt, &obj, addValue);
    worker.startNewThread(&ClassWithAtomic::subtractFromInt, &obj, subtractValue);

    for (auto i = 0; i < pushSize; ++i) {
        worker.startNewThread(&ClassWithAtomic::pushToVector, &obj, i);
    }

    for (auto i = 1; i <= pushSize; ++i) {
        if (i % 2 == 0) {
            worker.startNewThread(&ClassWithAtomic::eraseFromVector, &obj, i);
        }
    }

    worker.joinAllThreads();

    std::cout << "Result: " << obj.getInt() << std::endl;

    auto vec = obj.getVector();

    std::cout << "Size of vector: " << vec.size() << std::endl;

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }
}
