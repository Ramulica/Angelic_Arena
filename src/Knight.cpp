#include <iostream>
#include "../include/Knight.hpp"
#include "../include/Enemy.hpp"
#include <cmath> 

Knight::Knight(const std::string& name)
    : Hero(name, 1, 10, 100) {}

void Knight::basic_attack(Enemy& target) {
    int damage = calculate_attack(); // Use calculate_attack specific to Knight
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void Knight::active_skill() {
    std::cout << this->get_name() << " uses Shield Slam!" << std::endl;
}

void Knight::passive_skill() {
    std::cout << this->get_name() << " gains a defensive buff!" << std::endl;
}

int Knight::calculate_attack() const {
    int total_damage = base_damage;  // Start with base damage

    // Add Knight-specific bonuses (e.g., +5 damage for Knight class)

    // Level scaling
    float percentage = 0.1f * level;
    
    // Add weapon damage and weapon attack percentage
    if (weapon_damage) {
        total_damage += weapon_damage;
        percentage += weapon_P_damage;
    }

    // Add jewelry damage
    if (jewele_damage) {
        total_damage += jewele_damage;
    }

    return std::round(total_damage * (1 + percentage));
}

int Knight::calculate_health() const {
    int base_health = 100;  // Knight has a higher base health

    // Add Knight-specific health bonuses (e.g., +20 base health for Knight class)
    base_health += 20; 

    // Now use the Hero's calculate_health logic
    int total_health = base_health;

    if (armor_health) {
        total_health += armor_health;
    }
    if (boots_health) {
        total_health += boots_health;
    }

    float percentage = 0.1f * level;
    if (armor_P_health) {
        percentage += armor_P_health;
    }

    // Use Hero's calculation for percentage scaling
    return std::round(total_health * (1 + percentage));
}

