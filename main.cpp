#include <iostream>
#include <memory>
#include "../include/Knight.hpp"
#include "../include/BloodTroll.hpp"
#include "../include/Game.hpp"

int main() {
    std::unique_ptr<Hero> hero = std::make_unique<Knight>("Arthas");
    std::cout << "Hero created: " << hero->get_name() << "\n";

    for (int i = 1; i <= 5; ++i) {
        std::cout << "\n--- Level " << i << " ---\n";

        std::unique_ptr<Enemy> enemy = std::make_unique<BloodTroll>(i);
        Game game(std::move(hero), std::move(enemy));
        game.start_battle();

        // Retrieve back the hero after battle
        hero = std::move(game.get_hero());  // <-- You need to implement this method in `Game`

        // Optional milestone
        if (hero->get_level() >= 5) {
            std::cout << hero->get_name() << " reached level 5 and became a Knight!\n";
        }
    }

    std::cout << "\nGame completed.\n";
    return 0;
}
