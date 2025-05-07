#pragma once
#include "Enemy.hpp"


class BloodTroll : public Enemy {
public:
    BloodTroll(int level);
    void basic_attack(Hero& target) override;
    void active_skill() override;
    void passive_skill() override;
};
