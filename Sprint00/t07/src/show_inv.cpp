#include "inv.h"

void Inv::showInventory() {
    cout << "Inventory {";
    for (const auto& i : my_inv) {
        if (i == Item_type::WEAPON) {
            cout << " w";
        }
        else if (i == Item_type::FOOD) {
            cout << " f";
        }
        else if (i == Item_type::ARMOR) {
            cout << " a";
        }
        else if (i == Item_type::POTION) {
            cout << " p";
        }
        else if (i == Item_type::NO_ITEM) {
            cout << " -";
        }
    }
    cout << " }" << endl;
}
