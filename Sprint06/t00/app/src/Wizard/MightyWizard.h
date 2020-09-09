#pragma once

#include <iostream>
#include <string>

using namespace std;

enum class FoodType {
    ApplePie,
    HoneyNut,
    SweetRoll,
    PoisonedFood,
    Invalid
};

class FoodItem {
    public:
    virtual FoodType getFoodType() const = 0;
    virtual ~FoodItem() = default;
};

class AbstractWizard {
    protected:
    FoodType deductFoodType(FoodItem &item) {
        return item.getFoodType();
    };
    public:
    virtual ~AbstractWizard() = default;
};

class MightyWizard final : public AbstractWizard {
    public:
    MightyWizard(const string& name) : m_name(name) {};
    void checkFood(const FoodItem& fooditem) {
        switch (fooditem.getFoodType()) {
        case FoodType::ApplePie: cout << "Apple pie. Ugh, not again!" << endl; break;
        case FoodType::HoneyNut: cout << "Honey nut. Mmm, tasty!" << endl; break;
        case FoodType::SweetRoll: cout << "SweetRoll. Mmm, tasty!" << endl; break;
        case FoodType::PoisonedFood: cout << "Poison. Ugh, not again!" << endl; break;
        default: cout << "<unknown>. Ugh, not again!" << endl; break;
        }
    }
    void checkFood(const FoodItem* fooditem) {
        if (fooditem == nullptr) {
            cout << "<unknown>. Ugh, not again!" << endl;
        }
        else {
            checkFood(*fooditem);
        }
    }
    private:
    const string m_name;
};