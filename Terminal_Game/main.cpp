#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "include/Building.hpp"
#include "include/Character.hpp"
#include "include/Currency.hpp"
#include "include/Global.hpp"
#include "include/Item.hpp"
#include "include/Menu.hpp"
#include "include/Town.hpp"

class Building {
 public:
  Building(const int& initialLevel) : level(initialLevel) {}

  void addItem(const Item& item) { items.push_back(item); }

  void printItems() const {
    std::cout << "Items available in this building (level " << level
              << "):" << std::endl;
    for (const Item& item : items) {
      std::cout << "- " << item.getName() << std::endl;
    }
  }

 private:
  int level;
  std::vector<Item> items;
};

class Town {
 public:
  Town(const int& numBuildings) {
    for (int i = 0; i < numBuildings; ++i) {
      buildings.push_back(Building(1));
    }
  }

  Building& getBuilding(const int& index) { return buildings[index]; }

 private:
  std::vector<Building> buildings;
};

int main(int argc, char* argv[]) {
  std::vector<Character> characters;
  Currency playerCurrency;

  while (true) {
    Menu::displayMainMenu();
    int option = getIntegerInput();

    switch (option) {
      case 1: {
        Menu::displayRaidersMenu(characters, playerCurrency);
        break;
      }
      case 2: {
        Menu::displayTownMenu(playerCurrency);
        break;
      }
      case 3: {
        Menu::displayTowerMenu();
        break;
      }
      case 4: {
        Menu::displayInventoryMenu();
        break;
      }
      case 5: {
        Menu::displaySaveLoadMenu();
        break;
      }

      case 6: {
        Menu::displayExitGameMenu();
        break;
      }

      default:
        return 0;  //! Remove at the end
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
  return 0;
}
