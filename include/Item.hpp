#pragma once

#include <string>

class Item {
protected:
    std::string name;
    int level;
    std::string type;
    int health;
    int damage;
    std::string rarity;
    int id;

public:
    Item(const std::string& name, int level, int health, int damage, const std::string& rarity, int id, std::string type);
    virtual ~Item() = default;

    // Getters
    const std::string& get_name() const { return name; }
    int get_level() const { return level; }
    int get_health() const { return health; }
    int get_damage() const { return damage; }
    const std::string& get_rarity() const { return rarity; }
    const std::string& get_type() const { return type; }
    int get_id() const { return id; }
    virtual void print_info() const = 0;
    virtual float get_attack_percentage() const = 0;
    virtual float get_health_percentage() const = 0;


    // Optional: add a virtual print or description method if needed
};
