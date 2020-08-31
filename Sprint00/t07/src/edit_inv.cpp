#include "inv.h"

Inv::Inv() {
    my_inv.fill(NO_ITEM);
}

void Inv::insertItem(const int& i_type) {
    if (index < 12) {
        my_inv[index] = i_type;
        index++;
    }
    else {
        cerr << "Inventory is full." << endl;
    }
}

static array<int, 12> reFillArray(const array<int, 12>& arr) {
    array<int, 12> n_arr;
    int j = 0;

    n_arr.fill(Item_type::NO_ITEM);
    for (const auto& i : arr) {
        if (i != Item_type::NO_ITEM) {
            n_arr[j] = i;
            j++;
        }
    }
    return n_arr;
}

static string getItemByType(const int& item) {
    if (item == Item_type::ARMOR)
        return "a";
    else if (item == Item_type::WEAPON)
        return "w";
    else if (item == Item_type::FOOD)
        return "f";
    else if (item == Item_type::POTION)
        return "p";
    else
        return "-";
}

void Inv::removeItem(const int& i_type) {
    bool success = false;
    for (auto& i : my_inv) {
        if (i == i_type) {
            i = Item_type::NO_ITEM;
            index--;
            success = true;
            break;
        }
    }
    if (!success) {
        cerr << "Invalid item." << endl;
    }
    else {
        my_inv = reFillArray(my_inv);
        cout << getItemByType(i_type) + " was removed." << endl;
    }
}

// insert w
// insert a
// insert p
// insert w
// insert f
// insert w
// insert a
// insert a
// insert p
// insert p
// insert w
// insert p
// insert a
