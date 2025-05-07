#include <iostream>

#include "../include/HighOrc.hpp"
#include "../include/Hero.hpp"

HighOrc::HighOrc(int level)
    : Enemy("High Orc", level, 150, 50) {}

void HighOrc::basic_attack(Hero& target) {
    int damage = 20; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void HighOrc::active_skill() {
    std::cout << this->get_name() << " uses Orcish Rage!" << std::endl;
}

void HighOrc::passive_skill() {
    std::cout << this->get_name() << " gains rage and increases attack power!" << std::endl;
}
