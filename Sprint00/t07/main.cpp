#include "inv.h"

int main() {
    Inv inv;

    while(1) {
        int cmd_type = -1;

        inv.printPrompt();
        cmd_type = inv.parseCmd();
        if (cmd_type == Cmd_type::EXIT) {
            cout << "Bye." << endl;
            return 0;
        }
        inv.checkCmd(cmd_type);
    }
    return 0;
}
