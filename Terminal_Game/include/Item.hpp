#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>

class Item {
 public:
  Item(const std::string& name);

  std::string getName() const;

  void addStat(const std::string& statName, int value);

  const std::unordered_map<std::string, int>& getStats() const;

 private:
  std::string name;
  std::unordered_map<std::string, int> stats;
};

#endif