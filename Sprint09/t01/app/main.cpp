/* app/main.cpp */
#include<iostream>
#include<string>

#include "Worker.h"
#include "MultithreadedClass.h"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]" << std::endl;
    }
    else {
        try {
            int count = std::stoi(argv[3]);
            int addValue = std::stoi(argv[1]);
            int subtractValue = std::stoi(argv[2]);

            if (addValue < -2000 || addValue > 2000
                || subtractValue < -2000 || subtractValue > 2000
                || count < 5 || count > 10) {
                std::cerr << "Incorrect values" << std::endl;
                exit(EXIT_FAILURE);
            }
            std::cout << addValue << " " << subtractValue << " " << addValue << std::endl;

            MultithreadedClass obj;

            Worker worker;

            for (auto i = 0; i < count; ++i) {
                worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
            }

            for (auto i = 0; i < count; ++i) {
                worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
            }

            worker.joinAllThreads();

            std::cout << obj.getInt() << std::endl;
        }
        catch(...) {
            std::cerr << "Incorrect values" << std::endl;
        }
    }
}    
