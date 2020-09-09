#pragma once

#include "../Wizard/MightyWizard.h"

class HoneyNut final : public FoodItem {
    public:
    FoodType getFoodType() const {
        return FoodType::HoneyNut;
    };
};