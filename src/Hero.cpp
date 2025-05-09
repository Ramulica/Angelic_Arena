#include "../include/Hero.hpp"
#include <cmath>  // Include for std::round
#include <iostream>
#include "../include/Enemy.hpp"

Hero::Hero(const std::string& name, int level, int base_damage, int mana_max)
    : name(name), level(level), base_damage(base_damage), mana(0), mana_max(mana_max) {
    max_health = calculate_health();  // Set max_health
    this->health = max_health;        // Start full
}

int Hero::get_max_health() const {
    return max_health;
}

const std::string& Hero::get_name() const {
    return name;
}

void Hero::recalculate_max_health() {
    max_health = calculate_health();
    health = max_health;  // Heal to full
}

int Hero::get_health() const {
    return health;
}

void Hero::set_health(int value) {
    health = value;
}
void Hero::set_weapon_damage(int value) {
    weapon_damage = value;
}
void Hero::set_weapon_P_damage(int value) {
    weapon_P_damage = value;
}
void Hero::set_armor_health(int value) {
    armor_health = value;
}
void Hero::set_armor_P_health(int value) {
    armor_P_health = value;
}
void Hero::set_jewele_damage(int value) {
    jewele_damage = value;
}
void Hero::set_boots_health(int value) {
    boots_health = value;
}

int Hero::get_mana() const {
    return mana;
}

void Hero::set_mana(int value) {
    mana = value;
}

void Hero::add_item(std::shared_ptr<Item> item) {
    inventory.push_back(std::move(item));
}

int Hero::get_level() const {
    return level;
}

void Hero::level_up(){
    ++level;
    std::cout << name << " has leveled up! New level: " << level << "\n";
}


int Hero::calculate_attack() const {
    int total_damage = base_damage;  // Hero base damage

    // Add weapon damage and weapon attack percentage
    if (equipped_weapon) {
        total_damage += equipped_weapon->get_damage();
    }

    // Add attack percentage
    float percentage = 0.1f * level;  // Hero level bonus
    if (equipped_weapon) {
        percentage += equipped_weapon->get_attack_percentage();
    }

    // Add jewelry damage if equipped
    if (equipped_jewelry) {
        total_damage += equipped_jewelry->get_damage();
    }

    return std::round(total_damage * (1 + percentage));
}

int Hero::calculate_health() const {
    int base = 100;  // Example base health
    int total_health = base;

    // Add armor health bonuses
    if (equipped_armor) {
        total_health += equipped_armor->get_health();
    }

    // Add boots health bonuses
    if (equipped_boots) {
        total_health += equipped_boots->get_health();
    }

    // Add health percentage
    float percentage = 0.1f * level;
    if (equipped_armor) {
        percentage += equipped_armor->get_health_percentage();
    }

    return std::round(total_health * (1 + percentage));
}


Weapon* Hero::get_equipped_weapon() const {
    return equipped_weapon;
}

BodyArmor* Hero::get_equipped_armor() const {
    return equipped_armor;
}

Boots* Hero::get_equipped_boots() const {
    return equipped_boots;
}

Jewelry* Hero::get_equipped_jewelry() const {
    return equipped_jewelry;
}


void Hero::basic_attack(Enemy& target) {
    int damage = calculate_attack();
    std::cout << name << " attacks " << target.get_name() << " for " << damage << " damage.\n";
    target.set_health(target.get_health() - damage);
}
void Hero::equip_item(std::unique_ptr<Item> item) {
    // Equip the item (weapon, armor, boots, jewelry) as appropriate
    if (auto weapon = dynamic_cast<Weapon*>(item.get())) {
        equipped_weapon = weapon; // Equip the new weapon
    } 
    else if (auto armor = dynamic_cast<BodyArmor*>(item.get())) {
        equipped_armor = armor;  // Equip the new armor
    }
    else if (auto boots = dynamic_cast<Boots*>(item.get())) {
        equipped_boots = boots;  // Equip the new boots
    }
    else if (auto jewelry = dynamic_cast<Jewelry*>(item.get())) {
        equipped_jewelry = jewelry; // Equip the new jewelry
    }

    

}





void Hero::print_equipped_items() const {
    std::cout << this->get_name() << "'s Equipped Items:\n";

    // Check if the hero has a weapon equipped
    if (equipped_weapon) {
        std::cout << "Weapon: " << equipped_weapon->get_name() << "\n";
        std::cout << "  Damage: " << equipped_weapon->get_damage() << "\n";
        std::cout << "  Attack %: " << equipped_weapon->get_attack_percentage() << "%\n";
    } else {
        std::cout << "No weapon equipped.\n";
    }

    // Check if the hero has armor equipped
    if (equipped_armor) {
        std::cout << "Armor: " << equipped_armor->get_name() << "\n";
        std::cout << "  Health: " << equipped_armor->get_health() << "\n";
        std::cout << "  Health %: " << equipped_armor->get_health_percentage() << "%\n";
    } else {
        std::cout << "No armor equipped.\n";
    }

    // Check if the hero has boots equipped
    if (equipped_boots) {
        std::cout << "Boots: " << equipped_boots->get_name() << "\n";
        std::cout << "  Health: " << equipped_boots->get_health() << "\n";
    } else {
        std::cout << "No boots equipped.\n";
    }

    // Check if the hero has jewelry equipped
    if (equipped_jewelry) {
        std::cout << "Jewelry: " << equipped_jewelry->get_name() << "\n";
        std::cout << "  Damage: " << equipped_jewelry->get_damage() << "\n";
    } else {
        std::cout << "No jewelry equipped.\n";
    }
}