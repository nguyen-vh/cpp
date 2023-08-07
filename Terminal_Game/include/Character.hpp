#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <unordered_map>

#include "Item.hpp"

class Character {
 public:
  Character(const std::string& name);

  void applyItemStats(const Item& item);

  void changeStatBoost(int boostValue);

  void changeCharacterStat(const std::string& statName, double newValue);

  void showCharacter() const;

 private:
  std::string name;
  int statBoost;
  std::unordered_map<std::string, int> stats;
};

#endif