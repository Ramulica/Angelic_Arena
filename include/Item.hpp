#pragma once
#include <string>

class Item {
protected:
    std::string name;
    int health;
    int damage;
    std::string rarity;
    int id;

public:
    Item(const std::string& name, int health, int damage, const std::string& rarity, int id);
    virtual ~Item() = default;

    // Getter functions or other member functions can be added here
};
