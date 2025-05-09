#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string name, int level, int health, int damage,
               std::string rarity, int id, float attack_percentage, std::string type)
    : Item(std::move(name), level, health, damage, rarity, id, type),
      damage(damage), attack_percentage(attack_percentage) {}

      
std::string Weapon::get_type() const {
    return type;
}

int Weapon::get_damage() const {
    return damage;
}

float Weapon::get_attack_percentage() const {
    return attack_percentage;
}

float Weapon::get_health_percentage() const {
    return 0.0f;  // Weapon doesn't use this
}

void Weapon::print_info() const {
    std::cout << "Item Type: Weapon\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Rarity: " << rarity << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Damage: " << damage << "\n";
    std::cout << "Attack %: " << attack_percentage * 100 << "%\n";
}
