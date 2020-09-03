#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

enum Cmd_type {
    ADD,
    DELETE,
    READ,
    LIST,
    EXIT,
    ERROR
};

struct Library {
    void printPrompt();
    int parseCmd(stringstream& ss);
    void executeCmd(const int& cmd_type, stringstream& ss);
    void moreArgInCmd(const int& cmd_type, stringstream& ss);
    void addBook(const string& str);
    void deleteBook(const string& str);
    void readBook(const string& str);
    void iterateFile();
    void showLibrary();
    map<string, string> books;
};

string getFileContent(const string &path);
