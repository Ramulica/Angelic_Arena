#include "../include/Item.hpp"

Item::Item(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, std::string type)
    : name(name), level(level), health(health), damage(damage), rarity(rarity), id(id) {}
