#pragma once
#include <string>

class Enemy; // forward declaration

class Hero {
    protected:
        std::string name;
        int level;
        int health;
        int mana;
        int mana_max;
    
    public:
        Hero(const std::string& name, int level, int health, int mana_max);
        virtual ~Hero() = default;
    
        virtual void basic_attack(Enemy& target) = 0;
        virtual void active_skill() = 0;
        virtual void passive_skill() = 0;
    
        const std::string& get_name() const;
        int get_health() const;
        void set_health(int value);
    };