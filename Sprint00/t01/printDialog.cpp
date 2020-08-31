#include "printDialog.h"

void printDialog(const std::string& name, const std::string& sentence) {
    std::cout << name << " says: " << "\"" << sentence << "\"" << std::endl;
}

// Guard says: "I used to be an adventurer like you. Then I took an arrow in the knee..."$
int main() {
    printDialog("Guard", "I used to be an adventurer like you. "
        "Then I took an arrow in the knee...");
    return 0;
}
