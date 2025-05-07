#pragma once
#include "Hero.hpp"



class Hunter : public Hero {
public:
    Hunter(const std::string& name);
    void basic_attack(Enemy& target) override;
    void active_skill() override;
    void passive_skill() override;
};