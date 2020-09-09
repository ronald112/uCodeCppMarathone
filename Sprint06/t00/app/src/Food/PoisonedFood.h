#pragma once

#include "../Wizard/MightyWizard.h"

class PoisonedFood final : public FoodItem {
    public:
    FoodType getFoodType() const {
        return FoodType::PoisonedFood;
    };
};