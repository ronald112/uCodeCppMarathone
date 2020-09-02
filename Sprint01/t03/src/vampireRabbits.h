#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <random>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #include <Windows.h>
    #define SLEEP(sec) Sleep(sec * 1000)
#elif __APPLE__
    #include <chrono>
    #include <thread>
    #define SLEEP(sec) this_thread::sleep_for(chrono::seconds(sec))
#elif __linux__
    #include <unistd.h>
    #define SLEEP(sec) sleep(sec * 1000)
#elif __unix__ // all unices not caught above
    #include <chrono>
    #include <thread>
    #define SLEEP(sec) this_thread::sleep_for(chrono::seconds(sec))
#else
#   error "Unknown compiler"
#endif

using namespace std;

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

struct MyRabbits {
    MyRabbits(); //
    Rabbit m_createRabbit(); //
    void changeAge(); //
    void deleteOld(); //
    void createVampires(); //
    void createRabbits(); //
    void print();
    list<Rabbit> m_rabbits;
    int males = 0;
    int females = 0;
    int vampires = 0;
    int zombies = 0;
    unsigned sum = 0;
};
