#pragma once
#include "Item.hpp"

class BodyArmor : public Item {
public:
    float health_percentage;  // health percentage bonus for BodyArmor

    // Constructor
    BodyArmor(const std::string& name, int health, int damage, const std::string& rarity, int id, float health_percentage)
        : Item(name, health, damage, rarity, id), health_percentage(health_percentage) {}
};
