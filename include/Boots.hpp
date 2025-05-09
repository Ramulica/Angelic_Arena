#pragma once
#include "Item.hpp"

class Boots : public Item {
public:
    int speed;

    
    Boots(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, int speed, std::string type);
    void print_info() const override;
    std::string get_type() const;
    int get_health() const;
    float get_health_percentage() const override;
    float get_attack_percentage() const override;  


};
