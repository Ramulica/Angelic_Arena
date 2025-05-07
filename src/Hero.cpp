#include "../include/Hero.hpp"
#include "../include/Enemy.hpp"

Hero::Hero(const std::string& name, int level, int health, int mana_max)
    : name(name), level(level), health(health), mana(0), mana_max(mana_max) {}

const std::string& Hero::get_name() const {
    return name;
}

int Hero::get_health() const {
    return health;
}

void Hero::set_health(int value) {
    health = value;
}
