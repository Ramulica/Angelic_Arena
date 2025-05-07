#pragma once
#include "Hero.hpp"


class Assassin : public Hero {
public:
    Assassin(const std::string& name);
    void basic_attack(Enemy& target) override;
    void active_skill() override;
    void passive_skill() override;
};

