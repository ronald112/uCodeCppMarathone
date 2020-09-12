/* app/main.cpp */
#include<iostream>
#include<string>
#include <fstream>

#include "Worker.h"
#include "MultithreadedFileHandler.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        std::ifstream f(argv[1]);
        std::ifstream f1(argv[2]);
        if (!f.is_open() || !f1.is_open()) {
            std::cerr << "error" << std::endl;
            exit(EXIT_FAILURE);
        } else {
            f.close();
            f1.close();
        }
    }
    MultithreadedFileHandler obj;

    Worker worker;

    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, argv[1]);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "-----1 second sleep-----" << std::endl;

    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, argv[2]);

    worker.joinAllThreads();
}

