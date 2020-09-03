#include "bookSaver.h"

void Library::moreArgInCmd(const int& cmd_type, stringstream& ss) {
    string arg;
    ss >> arg;

    if (ss.fail() || ss.peek() != EOF) {
        getline(ss, arg);
        throw string("invalid command");
    }
    else if (cmd_type == Cmd_type::ADD) {
        addBook(arg);
    }
    else if (cmd_type == Cmd_type::DELETE) {
        deleteBook(arg);
    }
    else if (cmd_type == Cmd_type::READ) {
        readBook(arg);
    }
}

void Library::executeCmd(const int& cmd_type, stringstream& ss) {
    if (cmd_type == Cmd_type::ADD
        || cmd_type == Cmd_type::DELETE
        || cmd_type == Cmd_type::READ) {
        moreArgInCmd(cmd_type, ss);
    }
    else if (cmd_type == Cmd_type::LIST) {
        showLibrary();
    }
    else if (cmd_type == Cmd_type::ERROR) {
        cerr << "invalid command" << endl;
    }
}

int Library::parseCmd(stringstream& ss) {
    string cmd;
    getline(cin, cmd);
    ss.str(cmd);
    ss >> cmd;

    if (cmd.size() == 0)
        return -1;
    if (cmd == "add")
        return Cmd_type::ADD;
    else if (cmd == "delete")
        return Cmd_type::DELETE;
    else if (cmd == "read")
        return Cmd_type::READ;
    else if (cmd == "list")
        return Cmd_type::LIST;
    else if (cmd == "quit")
        return Cmd_type::EXIT;
    else
        return Cmd_type::ERROR;
}
