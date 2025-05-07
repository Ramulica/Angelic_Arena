#include <iostream>

#include "../include/Knight.hpp"
#include "../include/Enemy.hpp"

Knight::Knight(const std::string& name)
    : Hero(name, 1, 100, 100) {}

void Knight::basic_attack(Enemy& target) {
    int damage = 10; // example damage
    target.set_health(target.get_health() - damage);
    std::cout << this->get_name() << " attacks " << target.get_name() << " for " << damage << " damage." << std::endl;
}

void Knight::active_skill() {
    std::cout << this->get_name() << " uses Shield Slam!" << std::endl;
}

void Knight::passive_skill() {
    std::cout << this->get_name() << " gains a defensive buff!" << std::endl;
}
