#pragma once
#include <memory>
#include "Hero.hpp"
#include "Enemy.hpp"

class Game {
private:
    std::unique_ptr<Hero> hero;
    std::unique_ptr<Enemy> enemy;

public:
    Game(std::unique_ptr<Hero> hero, std::unique_ptr<Enemy> enemy);
    void start_battle();
};
