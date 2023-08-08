#include "../include/Item.hpp"

Item::Item(const std::string& name) : name(name) {}

std::string Item::getName() const { return name; }

void Item::addStat(Item::Stat stat, int value) { itemStats[stat] = value; }

const std::unordered_map<Item::Stat, int>& Item::getStats() const {
  return itemStats;
}
