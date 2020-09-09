#include "ISpell.h"

bool operator==(Spells::ISpell& lhs, Spells::ISpell& rhs) {
    return lhs.getType() == rhs.getType();
}