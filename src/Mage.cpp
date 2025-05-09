#include <iostream>

#include "../include/Mage.hpp"
#include "../include/Enemy.hpp"

Mage::Mage(const std::string& name)
    : Hero(name,5 , 80, 100) {}

void Mage::basic_attack(Enemy& target) {
    int damage = 12; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void Mage::active_skill() {
    std::cout << this->get_name() << " casts Fireball!" << std::endl;
}

void Mage::passive_skill() {
    std::cout << this->get_name() << " regenerates mana over time." << std::endl;
}
