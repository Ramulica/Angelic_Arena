#include "../include/Enemy.hpp"
#include "../include/Hero.hpp"

Enemy::Enemy(const std::string& name, int level, int mana)
    : name(name), level(level), health(10 + 10 * level), mana(mana) {}

const std::string& Enemy::get_name() const {
    return name;
}

int Enemy::get_health() const {
    return health;
}

void Enemy::set_health(int value) {
    health = value;

}

int Enemy::get_mana() const {
    return mana;
}

void Enemy::set_mana(int value) {
    mana = value;
}

