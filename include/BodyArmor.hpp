#pragma once
#include "Item.hpp"

class BodyArmor : public Item {
public:
    float health_percentage;
    int get_health() const;
    std::string get_type() const;

    float get_health_percentage() const override;
    float get_attack_percentage() const override; 

    BodyArmor(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, float health_percentage, std::string type);
    void print_info() const override;

};