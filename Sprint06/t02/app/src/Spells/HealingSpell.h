#pragma once

#include "ISpell.h"

namespace Spells {
    class EquilibriumSpell final : public ISpell {
        public:
        bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
            if (spellcaster.getHealth() < 25) {
                return false;
            }
            target.setMana(target.getMana() + 25);
            spellcaster.setHealth(spellcaster.getHealth() - 25);
            return true;
        };
        SpellType getType() const {
            return SpellType::Equilibrium;
        };
    };
}