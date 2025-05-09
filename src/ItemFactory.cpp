#include "../include/ItemFactory.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>

namespace {
    // Random engine
    std::mt19937 rng(static_cast<unsigned>(time(nullptr)));

    std::string random_rarity() {
        int roll = std::uniform_int_distribution<>(1, 100)(rng);
        if (roll <= 60) return "Common";
        else if (roll <= 90) return "Rare";
        else if (roll <= 98) return "Epic";
        return "Legendary";
    }

    std::string random_name(const std::string& rarity, int type) {
        static std::vector<std::string> adjectives = {
            "Ancient", "Blazing", "Brutal", "Cursed", "Divine", "Elegant", "Fierce", "Frozen", "Glorious", "Holden",
            "Heavy", "Infernal", "Iron", "Luminous", "Mystic", "Nightmare", "Radiant", "Ruthless", "Sacred", "Savage",
            "Shadow", "Shimmering", "Silent", "Stormforged", "Vicious"
        };

        static std::vector<std::string> weapon_nouns = {"Sword", "Axe", "Spear", "Mace", "Dagger"};
        static std::vector<std::string> armor_nouns = {"Chestplate", "Cuirass", "Mail", "Vest", "Plate"};
        static std::vector<std::string> boots_nouns = {"Boots", "Sandals", "Greaves", "Stompers", "Footguards"};
        static std::vector<std::string> jewelry_nouns = {"Amulet", "Pendant", "Ring", "Talisman", "Charm"};

        std::string noun;

        switch (type) {
            case 0: noun = weapon_nouns[rand() % weapon_nouns.size()]; break;
            case 1: noun = armor_nouns[rand() % armor_nouns.size()]; break;
            case 2: noun = boots_nouns[rand() % boots_nouns.size()]; break;
            case 3: noun = jewelry_nouns[rand() % jewelry_nouns.size()]; break;
            default: noun = "Item"; break;
        }

        std::string adj = adjectives[rand() % adjectives.size()];
        return rarity + " " + adj + " " + noun;
    }

    int get_stat_range(const std::string& rarity, int& stat_min, int& stat_max) {
        if (rarity == "Common") { stat_min = 5; stat_max = 10; }
        else if (rarity == "Rare") { stat_min = 20; stat_max = 40; }
        else if (rarity == "Epic") { stat_min = 100; stat_max = 150; }
        else { stat_min = 500; stat_max = 1000; }
        return std::uniform_int_distribution<>(stat_min, stat_max)(rng);
    }

    float get_percentage_stat(const std::string& rarity) {
        if (rarity == "Common") return 0.10f;
        if (rarity == "Rare") return 0.20f;
        if (rarity == "Epic") return 0.50f;
        return 1.00f;
    }
}

std::unique_ptr<Item> ItemFactory::generate_random_item(int hero_level) {
    std::string rarity = random_rarity();
    int id = rand();

    // Choose a random item type: 0 = Weapon, 1 = Armor, 2 = Boots, 3 = Jewelry
    int type = std::uniform_int_distribution<>(0, 3)(rng);
    std::string name = random_name(rarity, type);

    int base_stat_min, base_stat_max;
    int health = 0, damage = 0, speed = 0;
    float attack_pct = 0.0f;
    float health_pct = 0.0f;
    int mana = 0;

    float level_multiplier = 1.0f + 0.2f * hero_level;

    switch (type) {
        case 0: { // Weapon
            damage = std::round(get_stat_range(rarity, base_stat_min, base_stat_max) * level_multiplier);
            attack_pct = get_percentage_stat(rarity);
            return std::make_unique<Weapon>(name, hero_level, 0, damage, rarity, id, attack_pct, "Weapon");
        }
        case 1: { // BodyArmor
            health = std::round(get_stat_range(rarity, base_stat_min, base_stat_max) * level_multiplier);
            health_pct = get_percentage_stat(rarity);
            return std::make_unique<BodyArmor>(name, hero_level, health, 0, rarity, id, health_pct, "BodyArmor");
        }
        case 2: { // Boots
            health = std::round(get_stat_range(rarity, base_stat_min, base_stat_max) * level_multiplier);
            speed = std::round(get_stat_range(rarity, base_stat_min, base_stat_max) * level_multiplier);
            return std::make_unique<Boots>(name, hero_level, health, 0, rarity, id, speed, "Boots");
        }
        case 3: { // Jewelry
            damage = std::round(get_stat_range(rarity, base_stat_min, base_stat_max) * level_multiplier);
            mana = std::round(get_stat_range(rarity, base_stat_min, base_stat_max) * level_multiplier);
            return std::make_unique<Jewelry>(name, hero_level, 0, damage, rarity, id, mana, "Jewelry");
        }
        default:
            return nullptr;
    }
}
