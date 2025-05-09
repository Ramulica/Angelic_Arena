#include <iostream>

#include "../include/BloodTroll.hpp"
#include "../include/Hero.hpp"

BloodTroll::BloodTroll(int level)
    : Enemy("Blood Troll", level, 50) {}

void BloodTroll::basic_attack(Hero& target) {
    int damage = 10; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void BloodTroll::active_skill() {
    std::cout << this->get_name() << " uses Bloodlust!" << std::endl;
}

void BloodTroll::passive_skill() {
    std::cout << this->get_name() << " heals when dealing damage!" << std::endl;
}
