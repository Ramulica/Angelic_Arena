#include <iostream>

#include "../include/Assassin.hpp"
#include "../include/Enemy.hpp"

Assassin::Assassin(const std::string& name)
    : Hero(name, 1, 90, 100) {}

void Assassin::basic_attack(Enemy& target) {
    int damage = 15; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void Assassin::active_skill() {
    std::cout << this->get_name() << " uses Stealth!" << std::endl;
}

void Assassin::passive_skill() {
    std::cout << this->get_name() << " has increased critical hit chance." << std::endl;
}
