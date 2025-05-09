#pragma once
#include "Item.hpp"

class Weapon : public Item {
public:
    Weapon(std::string name, int level, int health, int damage,
           std::string rarity, int id, float attack_percentage, std::string type);

    int get_damage() const;
    std::string get_type() const;
    float get_attack_percentage() const override;
    float get_health_percentage() const override;  

    void print_info() const override;

private:
    int damage;
    float attack_percentage;
};
