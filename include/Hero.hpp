#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Item.hpp"
#include "Weapon.hpp"
#include "BodyArmor.hpp"
#include "Boots.hpp"
#include "Jewelry.hpp"

// Forward declaration
class Enemy;

class Hero {
public:
    Hero(const std::string& name, int level, int base_damage, int mana_max);

    // Basic Info
    const std::string& get_name() const;
    int get_health() const;
    void set_health(int value);
    int get_mana() const;
    void set_mana(int value);
    void level_up();
    int get_level() const;  // Added getter
    int get_max_health() const;       // ADD
    void recalculate_max_health();

    void set_weapon_damage(int value) ;
    void set_weapon_P_damage(int value) ;
    void set_armor_health(int value) ;
    void set_armor_P_health(int value) ;
    void set_jewele_damage(int value) ;
    void set_boots_health(int value) ;

    // Inventory
    void add_item(std::shared_ptr<Item> item);
    void equip_item(std::unique_ptr<Item> item);

    // Combat
    virtual void basic_attack(Enemy& target);   // Added
    virtual void active_skill() = 0;            // Pure virtual
    virtual void passive_skill() = 0;           // Pure virtual
    void print_equipped_items() const;
    // Calculation Methods
    int calculate_attack() const;
    int calculate_health() const;

    // Accessors for equipped items
    Weapon* get_equipped_weapon() const;
    BodyArmor* get_equipped_armor() const;
    Boots* get_equipped_boots() const;
    Jewelry* get_equipped_jewelry() const;

protected:
    int max_health; 
    std::string name;
    int level;
    int health;
    int base_damage;
    int mana;
    int mana_max;
    int weapon_damage;
    int weapon_P_damage;
    int armor_health;
    int armor_P_health;
    int jewele_damage;
    int boots_health;

    std::vector<std::shared_ptr<Item>> inventory;

    Weapon* equipped_weapon = nullptr;
    BodyArmor* equipped_armor = nullptr;
    Boots* equipped_boots = nullptr;
    Jewelry* equipped_jewelry = nullptr;
};
