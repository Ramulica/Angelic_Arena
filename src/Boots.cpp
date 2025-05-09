#include "../include/Boots.hpp"
#include <iostream>

Boots::Boots(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, int speed, std::string type)
    : Item(name, level, health, damage, rarity, id, type), speed(speed) {}

int Boots::get_health() const {
    return health;  // Assuming there's a member variable `int health;`
}

std::string Boots::get_type() const {
    return type;
}
float Boots::get_attack_percentage() const {
    return 0.0f;
}

float Boots::get_health_percentage() const {
    return 0.0f;
}

void Boots::print_info() const {
    std::cout << "Item Type: Boots\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Rarity: " << rarity << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Speed: " << speed << "\n";
}
    