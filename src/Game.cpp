#include <iostream>
#include <memory>
#include <vector>

#include "../include/Game.hpp"
#include "../include/Knight.hpp"
#include "../include/BloodTroll.hpp"
#include "../include/ItemFactory.hpp"

Game::Game(std::unique_ptr<Hero> hero, std::unique_ptr<Enemy> enemy)
    : hero(std::move(hero)), enemy(std::move(enemy)) {}

std::unique_ptr<Hero> Game::get_hero() {
    return std::move(hero);  // Transfer ownership back
}

void Game::start_battle() {
    int turn_count = 0;

    std::cout << "=== Battle: " << hero->get_name() << " vs " << enemy->get_name() << " ===" << std::endl;
    std::cout << "Start of the game" << (turn_count + 1) << ":\n";
    std::cout << hero->get_name() << " HP: " << hero->get_health() << "\n";
    std::cout << enemy->get_name() << " HP: " << enemy->get_health() << "\n";
    while (hero->get_health() > 0 && enemy->get_health() > 0 && turn_count < 10) {
        // Hero turn
        if (hero->get_mana() == 100) {
            hero->active_skill();
            hero->set_mana(0);
        } else {
            hero->basic_attack(*enemy);
            hero->set_mana(hero->get_mana() + 50);
        }

        if (enemy->get_health() <= 0) break;

        // Enemy turn
        if (enemy->get_mana() == 100) {
            enemy->active_skill();
            enemy->set_mana(0);
        } else {
            enemy->basic_attack(*hero);
            enemy->set_mana(enemy->get_mana() + 50);
        }

        std::cout << "After turn " << (turn_count + 1) << ":\n";
        std::cout << hero->get_name() << " HP: " << hero->get_health() << "\n";
        std::cout << enemy->get_name() << " HP: " << enemy->get_health() << "\n";

        ++turn_count;
    }

    // Battle result
    if (hero->get_health() > 0 && enemy->get_health() <= 0) {
        std::cout << hero->get_name() << " wins the battle!\n";

        // 🎁 Generate an item
        auto item = ItemFactory::generate_random_item(hero->get_level());
        std::cout << "You received an item!\n";
        item->print_info();

        if (item->get_type() == "Weapon"){
            hero->set_weapon_damage(item->get_damage());
            hero->set_weapon_P_damage(item->get_attack_percentage());

        } else if (item->get_type() == "BodyArmor"){
            hero->set_armor_health(item->get_health());
            hero->set_armor_P_health(item->get_health_percentage());
            
        } else if (item->get_type() == "Boots"){
            hero->set_boots_health(item->get_health());
            
        } else {
            hero->set_jewele_damage(item->get_damage());
            
        }
        

        // Recalculate hero stats after equipping the item
        hero->recalculate_max_health();  // Recalculate health based on equipped items
        hero->calculate_attack();        // Recalculate attack (if necessary)
        hero->calculate_health();        // Recalculate health (if necessary)

        // Ensure stats are correctly reflected after leveling up
        hero->level_up();  // Level up after winning


        std::cout << "Updated Stats after leveling up and equipping item:\n";
    } else if (enemy->get_health() > 0 && hero->get_health() <= 0) {
        std::cout << enemy->get_name() << " wins the battle!\n";
    } else {
        std::cout << "The battle ends in a draw.\n";
    }
}
