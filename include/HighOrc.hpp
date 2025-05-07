#pragma once
#include "Enemy.hpp"

class HighOrc : public Enemy {
public:
    HighOrc(int level);
    void basic_attack(Hero& target) override;
    void active_skill() override;
    void passive_skill() override;
};
