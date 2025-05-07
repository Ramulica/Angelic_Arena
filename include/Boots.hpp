#pragma once
#include "Item.hpp"

class Boots : public Item {
public:
    int speed;  // speed attribute for Boots

    // Constructor
    Boots(const std::string& name, int health, int damage, const std::string& rarity, int id, int speed)
        : Item(name, health, damage, rarity, id), speed(speed) {}
};
