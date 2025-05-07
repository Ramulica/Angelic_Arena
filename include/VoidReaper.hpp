#pragma once

#include "Enemy.hpp"


class VoidReaper : public Enemy {
public:
    VoidReaper(int level);
    void basic_attack(Hero& target) override;
    void active_skill() override;
    void passive_skill() override;
};