#pragma once

#include "ISpell.h"

namespace Spells {
    class HealingSpell final : public ISpell {
        public:
        bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
            if (spellcaster.getMana() < 15) {
                return false;
            }
            target.setHealth(target.getHealth() + 10);
            spellcaster.setMana(spellcaster.getMana() - 15);
            return true;
        };
        SpellType getType() const {
            return SpellType::Healing;
        };
    };
}