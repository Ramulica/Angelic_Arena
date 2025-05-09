#pragma once

#include <memory>
#include <string>
#include <random>
#include "Item.hpp"
#include "Weapon.hpp"
#include "Boots.hpp"
#include "BodyArmor.hpp"
#include "Jewelry.hpp"

class ItemFactory {
public:
    static std::unique_ptr<Item> generate_random_item(int hero_level);
};
