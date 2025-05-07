#pragma once
#include "Hero.hpp"

class Knight : public Hero {
public:
    Knight(const std::string& name);
    void basic_attack(Enemy& target) override;
    void active_skill() override;
    void passive_skill() override;
};

