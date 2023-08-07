#include "../include/Item.hpp"

Item::Item(const std::string& name) : name(name) {}

std::string Item::getName() const { return name; }

void Item::addStat(const std::string& statName, int value) {
  stats[statName] = value;
}

const std::unordered_map<std::string, int>& Item::getStats() const {
  return stats;
}
