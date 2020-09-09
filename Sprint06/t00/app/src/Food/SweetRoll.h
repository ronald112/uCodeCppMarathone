#pragma once

#include "../Wizard/MightyWizard.h"

class SweetRoll final : public FoodItem {
    public:
    FoodType getFoodType() const {
        return FoodType::SweetRoll;
    };
};