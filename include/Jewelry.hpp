#pragma once
#include "Item.hpp"

class Jewelry : public Item {
public:
    int mana;

    Jewelry(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, int mana, std::string type);
    void print_info() const override;
    std::string get_type() const;
    int get_damage() const;
    float get_health_percentage() const override;
    float get_attack_percentage() const override;  // 👈 Needed!



};
