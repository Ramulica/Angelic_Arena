#pragma once
#include "Item.hpp"

class Jewelry : public Item {
public:
    int mana;  // mana attribute for Jewelry

    // Constructor
    Jewelry(const std::string& name, int health, int damage, const std::string& rarity, int id, int mana)
        : Item(name, health, damage, rarity, id), mana(mana) {}
};
