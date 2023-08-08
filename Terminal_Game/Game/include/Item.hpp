#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>

class Item {
 public:
  Item(const std::string& name);

  enum class Stat { LVL, STR, AGI, DEX, END, INT, WIS, CHA, LUK };

  std::string getName() const;

  void addStat(Stat stat, int value);

  const std::unordered_map<Stat, int>& getStats() const;

 private:
  std::string name;
  std::unordered_map<Stat, int> itemStats;
};

#endif
