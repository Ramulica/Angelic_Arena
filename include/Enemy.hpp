#pragma once
#include <string>

class Hero; // forward declaration

class Enemy {
protected:
    std::string name;
    int level;
    int health;
    int mana;

public:
    Enemy(const std::string& name, int level, int health, int mana);
    virtual ~Enemy() = default;

    virtual void basic_attack(Hero& target) = 0;
    virtual void active_skill() = 0;
    virtual void passive_skill() = 0;

    const std::string& get_name() const;
    int get_health() const;
    void set_health(int value);
};