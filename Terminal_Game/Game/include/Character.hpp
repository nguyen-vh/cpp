#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>

#include "Global.hpp"
#include "Item.hpp"

class Character {
 public:
  Character(const std::string& name);

  enum class Stat { LVL, STR, AGI, DEX, END, INT, WIS, CHA, LUK };

  enum class SecondaryStats {
    HP,
    MP,
    ATK,
    DEF,
    MATK,
    MDEF,
    SPD,
    ACC,
    INIT,
    DR,
    CRIT,
    CRITdmg,
    HPregen,
    MPregen,
    MRES,
    StatusRES,
    StatusDur,
    LootBonus,
    GoldBonus
  };

  enum class CharacterType { Weak, Average, Strong };

  static Character createRaider(CharacterType type, const std::string& name);

  std::string getName() const;

  void applyItemStats(const Item& item);

  void setCharacterStat(Stat stat, int Value);

  void showCharacter() const;

  void showSecondaryStats() const;

  void addEXP(int amount);

  int getEXP() const;

  void levelUp();

  int calculateEXPThreshold();

  int addSkillPoints(int amount);

  int getSkillPoints() const;

  void useSkillPoint(Stat stat);

  std::map<SecondaryStats, double> updateSecondaryStats();

  std::string secondaryStatToString(SecondaryStats stat) const;

 private:
  std::string name{};

  std::unordered_map<Stat, int> characterStats;

  std::map<SecondaryStats, double> secondarycharacterStats;

  static std::unordered_map<Stat, int> getStatsForType(CharacterType type);

  std::string statToString(Stat stat) const;

  int expPoints{0};

  int expThreshold{};

  int skillPointsAll{5};

  int skillPointsUsed{0};
};

#endif