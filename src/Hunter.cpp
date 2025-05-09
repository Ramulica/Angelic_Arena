#include <iostream>

#include "../include/Hunter.hpp"
#include "../include/Enemy.hpp"

Hunter::Hunter(const std::string& name)
    : Hero(name,5 , 100, 100) {}

void Hunter::basic_attack(Enemy& target) {
    int damage = 10; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void Hunter::active_skill() {
    std::cout << this->get_name() << " uses Arrow Barrage!" << std::endl;
}

void Hunter::passive_skill() {
    std::cout << this->get_name() << " gains increased range!" << std::endl;
}
