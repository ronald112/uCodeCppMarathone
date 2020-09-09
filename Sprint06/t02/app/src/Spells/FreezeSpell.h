#pragma once

#include "ISpell.h"

namespace Spells {
    class FreezeSpell final : public ISpell {
        public:
        bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
            if (spellcaster.getMana() < 30) {
                return false;
            }
            spellcaster.setMana(spellcaster.getMana() - 30);
            target.setHealth(target.getHealth() - 20);
            return true;
        };
        SpellType getType() const {
            return SpellType::Freeze;
        };
    };
}