#pragma once

#include "ISpell.h"

namespace Spells {
    class FireballSpell final : public ISpell {
        public:
        bool cast(Creatures::Creature& spellcaster, Creatures::Creature& target) {
            if (spellcaster.getMana() < 50) {
                return false;
            }
            spellcaster.setMana(spellcaster.getMana() - 50);
            target.setHealth(target.getHealth() - 40);
            return true;
        };
        SpellType getType() const {
            return SpellType::Fireball;
        };
    };
}