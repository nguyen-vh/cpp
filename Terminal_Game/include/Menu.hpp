#ifndef MENU_HPP
#define MENU_HPP

// #include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include "Character.hpp"
#include "Currency.hpp"

class Menu {
 public:
  // Raiders
  static void displayRaidersMenu(std::vector<Character>& characters,
                                 Currency& playerCurrency);
  static void displayRecruitRaiderMenu(std::vector<Character>& characters,
                                       Currency& playerCurrency);
  // Town
  static void displayTownMenu(const Currency& playerCurrency);

  // Tower
  static void displayTowerMenu();

  // Inventory
  static void displayInventoryMenu();

  // Save/Load
  static void displaySaveLoadMenu();

  // Exit Game
  static void displayExitGameMenu();

  // Main Menu
  static void displayMainMenu();
};

#endif
