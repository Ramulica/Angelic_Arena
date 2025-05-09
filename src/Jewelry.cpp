#include "../include/Jewelry.hpp"
#include <iostream>

Jewelry::Jewelry(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, int mana, std::string type)
    : Item(name, level, health, damage, rarity, id, type), mana(mana) {}


int Jewelry::get_damage() const {
    return damage;
}
    
float Jewelry::get_attack_percentage() const {
    return 0.0f;
}

float Jewelry::get_health_percentage() const {
    return 0.0f;
}

void Jewelry::print_info() const {
    std::cout << "Item Type: Jewelry\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Rarity: " << rarity << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Damage: " << damage << "\n";
    std::cout << "Armor: " << mana << "\n";
}

std::string Jewelry::get_type() const {
    return type;
}
