#include "bookSaver.h"

int main() {
    Library lybrary;

    while(1) {
        try {
            int cmd_type = -1;
            stringstream ss;

            lybrary.printPrompt();
            cmd_type = lybrary.parseCmd(ss);
            if (cmd_type == Cmd_type::EXIT) {
                cout << "bye" << endl;
                return 0;
            }
            lybrary.executeCmd(cmd_type, ss);
        }
        catch (string& ex) {
            cerr << ex << endl;
        }
    }
    return 0;
}
