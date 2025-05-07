#include "../include/Enemy.hpp"
#include "../include/Hero.hpp"

Enemy::Enemy(const std::string& name, int level, int health, int mana)
    : name(name), level(level), health(health), mana(mana) {}

const std::string& Enemy::get_name() const {
    return name;
}

int Enemy::get_health() const {
    return health;
}

void Enemy::set_health(int value) {
    health = value;
}
