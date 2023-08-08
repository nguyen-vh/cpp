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
  // Start Menu
  static void displayRPG_GameMenu();
  static void displayStartGameMenu();
  static void displayLoadGameMenu();
  static void displaySettingsMenu();

  //* Main Menu
  static void displayMainMenu();

  // Raiders
  static void displayRaidersMenu(std::vector<Character>& characters,
                                 Currency& playerCurrency);
  static void displayShowRaidersMenu(std::vector<Character>& characters);
  static void displayRecruitRaiderMenu(std::vector<Character>& characters,
                                       Currency& playerCurrency);
  static void displayRecruitRaiderTypeMenu(std::vector<Character>& characters,
                                           Currency& playerCurrency,
                                           Character::CharacterType type);
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
};

#endif
