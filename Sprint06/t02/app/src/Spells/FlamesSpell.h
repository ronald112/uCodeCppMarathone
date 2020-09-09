#pragma once

#include "ISpell.h"

namespace Spells {
    class FlamesSpell final : public ISpell {
        public:
        bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
            if (spellcaster.getMana() < 8) {
                return false;
            }
            spellcaster.setMana(spellcaster.getMana() - 14);
            target.setHealth(target.getHealth() - 8);
            return true;
        };
        SpellType getType() const {
            return SpellType::Flames;
        };
    };
}