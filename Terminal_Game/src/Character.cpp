#include "../include/Character.hpp"

Character::Character(const std::string& name) : name(name), statBoost(0) {
  stats["Luck"] = 0;
  stats["Magic Def"] = 0;
  stats["Magic Atk"] = 0;
  stats["Defense%"] = 0;
  stats["Defense"] = 0;
  stats["Attack%"] = 0;
  stats["Attack"] = 2;
  stats["Mana"] = 5;
  stats["Health"] = 100;
  stats["Level"] = 1;
}

void Character::applyItemStats(const Item& item) {
  const std::unordered_map<std::string, int>& itemStats = item.getStats();
  for (const auto& entry : itemStats) {
    if (stats.find(entry.first) != stats.end()) {
      stats[entry.first] += entry.second + statBoost;
    }
  }
}

void Character::changeStatBoost(int boostValue) { statBoost = boostValue; }

void Character::changeCharacterStat(const std::string& statName,
                                    double newValue) {
  if (stats.find(statName) != stats.end()) {
    stats[statName] = newValue;
  } else {
    std::cout << "Stat '" << statName << "' not found." << std::endl;
  }
}

void Character::showCharacter() const {
  std::cout << "===== Lv." << std::to_string(stats.at("Level")) << " " << name
            << " =====" << std::endl;

  bool firstLine = true;
  for (const auto& entry : stats) {
    if (!firstLine) {
      std::cout << entry.first << ": " << entry.second << std::endl;
    }
    firstLine = false;
  }
  std::cout << std::endl;
}
