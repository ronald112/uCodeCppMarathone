#include "MultithreadedFileHandler.h"
#include <fstream>
#include <iostream>

void MultithreadedFileHandler::processFile() {
    std::unique_lock<std::mutex> l(m_mutex);
    m_condVar.wait(l);
    std::cout << m_file << std::endl;
    m_fileLoaded = false;
}

void MultithreadedFileHandler::loadFile(const std::string& fileName) {
    std::ifstream f(fileName);

    if (f.is_open()) {
        std::getline(f, m_file, '\0');
        f.close();
        m_fileLoaded = true;
        m_condVar.notify_one();
    }
}
