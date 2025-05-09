#include "../include/BodyArmor.hpp"
#include <iostream>

BodyArmor::BodyArmor(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, float health_percentage, std::string type)
    : Item(name, level, health, damage, rarity, id, type), health_percentage(health_percentage) {}

std::string BodyArmor::get_type() const {
    return type;
}

int BodyArmor::get_health() const {
    return health;  // Assuming there's a member variable `int health;`
}

float BodyArmor::get_health_percentage() const {
    return health_percentage;
}

float BodyArmor::get_attack_percentage() const {
    return 0.0f;  // Not applicable
}


void BodyArmor::print_info() const {
    std::cout << "Item Type: BodyArmor\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Rarity: " << rarity << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Health %: " << health_percentage * 100 << "%\n";
}
