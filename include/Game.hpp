#pragma once
#include <memory>
#include <vector>
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Item.hpp"  // Adaugă include pentru Item (dacă nu ai făcut-o deja)

class Game {
private:
    std::unique_ptr<Hero> hero;
    std::unique_ptr<Enemy> enemy;
    std::vector<std::unique_ptr<Item>> inventory; // Folosește unique_ptr pentru Item


public:
    Game(std::unique_ptr<Hero> hero, std::unique_ptr<Enemy> enemy);
    void start_battle();
    std::unique_ptr<Hero> get_hero();  // Add this method

};
