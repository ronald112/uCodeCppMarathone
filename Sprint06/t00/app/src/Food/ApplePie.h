#pragma once

#include "../Wizard/MightyWizard.h"

class ApplePie final : public FoodItem {
    public:
    FoodType getFoodType() const {
        return FoodType::ApplePie;
    };
};