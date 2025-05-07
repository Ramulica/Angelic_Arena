#pragma once
#include "Enemy.hpp"

class DreadWraith : public Enemy {
public:
    DreadWraith(int level);
    void basic_attack(Hero& target) override;
    void active_skill() override;
    void passive_skill() override;
};
