#pragma once

#include "Item.hpp"

class Weapon : public Item {
public:
    float attack_percentage;  // attack percentage for Weapon

    // Constructor
    Weapon(const std::string& name, int health, int damage, const std::string& rarity, int id, float attack_percentage)
        : Item(name, health, damage, rarity, id), attack_percentage(attack_percentage) {}
};
