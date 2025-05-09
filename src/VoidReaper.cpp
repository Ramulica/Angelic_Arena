#include <iostream>

#include "../include/VoidReaper.hpp"
#include "../include/Hero.hpp"

VoidReaper::VoidReaper(int level)
    : Enemy("Void Reaper", level, 60) {}

void VoidReaper::basic_attack(Hero& target) {
    int damage = 15; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void VoidReaper::active_skill() {
    std::cout << this->get_name() << " uses Void Strike!" << std::endl;
}

void VoidReaper::passive_skill() {
    std::cout << this->get_name() << " deals damage over time." << std::endl;
}
