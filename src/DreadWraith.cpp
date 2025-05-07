#include <iostream>

#include "../include/DreadWraith.hpp"
#include "../include/Hero.hpp"

DreadWraith::DreadWraith(int level)
    : Enemy("Dread Wraith", level, 120, 60) {}

void DreadWraith::basic_attack(Hero& target) {
    int damage = 12; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void DreadWraith::active_skill() {
    std::cout << this->get_name() << " uses Wraith's Curse!" << std::endl;
}

void DreadWraith::passive_skill() {
    std::cout << this->get_name() << " regenerates health over time." << std::endl;
}
