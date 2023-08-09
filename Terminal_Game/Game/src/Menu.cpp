#include "../include/Menu.hpp"

#include "../include/Character.hpp"
#include "../include/Global.hpp"

//* Game Loop
void Menu::GameLoop() { displayLoadingScreen(); }

//* >Loading Screen
void Menu::displayLoadingScreen() {
  clearScreen();
  showImage("Tower RPG");

  std::string message =
      "                             Press Enter to continue... ";

  for (char c : message) {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(70));
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  displayRPG_GameMenu();
}

//* >Starting Menu
void Menu::displayRPG_GameMenu() {
  while (true) {
    clearScreen();
    std::cout << "===== Tower RPG =====\n";
    std::cout << "[1] Start Game\n";
    std::cout << "[2] Load Game\n";
    std::cout << "[3] Settings\n";
    std::cout << "[4] Quit\n";

    int option = getIntegerInput();

    switch (option) {
      case 1: {
        displayStartGameMenu();
        break;
      }
      case 2: {
        displayLoadGameMenu();
        break;
      }
      case 3: {
        displaySettingsMenu();
        break;
      }
      case 4: {
        exit(0);
        break;
      }
      default: {
        std::cout << std::endl;
        std::cout << "Invalid option. Please try again.\n";
        break;
      }
    }
  }
}

//  >Start Game
void Menu::displayStartGameMenu() {
  clearScreen();
  std::cout << "===== Start Game =====\n" << std::endl;
  std::cout << "Enter Chiefname: \n";
  std::string chiefname{};
  std::cin >> chiefname;
  displayMainMenu();
}

//  >Load Game
void Menu::displayLoadGameMenu() {
  clearScreen();
  std::cout << "===== Load Game =====\n" << std::endl;
  std::cout << "Enter Savefile: \n";
  std::string savefile{};
  std::cin >> savefile;
  displayMainMenu();
}

//  >Settings
void Menu::displaySettingsMenu() {
  while (true) {
    clearScreen();
    std::cout << "===== Settings =====\n";
    std::cout << "[0] Go Back\n";
    std::cout << "[1] Set Easy\n";
    std::cout << "[2] Set Normal\n";
    std::cout << "[3] Set Hard\n";
    std::cout << "[4] Set Hardcode\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        break;
      }
      case 2: {
        break;
      }
      case 3: {
        break;
      }
      case 4: {
        break;
      }

      default: {
        std::cout << std::endl;
        std::cout << "Invalid option. Please try again.\n";
        break;
      }
    }
  }
}

//! >Main Menu
void Menu::displayMainMenu() {
  std::vector<Character> characters;
  Currency playerCurrency;

  while (true) {
    clearScreen();
    std::cout << "===== Menu =====\n";
    std::cout << "[1] Raiders\n";
    std::cout << "[2] Town\n";
    std::cout << "[3] Tower\n";
    std::cout << "[4] Inventory\n";
    std::cout << "[5] Save/Load\n";
    std::cout << "[6] Exit Game\n";

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
        exit(0);  //! Remove at the end
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
}

//* >Raiders
void Menu::displayRaidersMenu(std::vector<Character>& characters,
                              Currency& playerCurrency) {
  while (true) {
    clearScreen();
    std::cout << "===== Raiders =====" << std::endl;
    std::cout << "[0] Go Back\n";
    std::cout << "[1] Show Raiders\n";
    std::cout << "[2] Recruit Raider\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        displayShowRaidersMenu(characters);
        break;
      }
      case 2: {
        displayRecruitRaiderMenu(characters, playerCurrency);
        break;
      }

      default: {
        std::cout << std::endl;
        std::cout << "Invalid option. Please try again.\n";
        break;
      }
    }
  }
}

//  -Raiders >Show Raiders
void Menu::displayShowRaidersMenu(std::vector<Character>& characters) {
  while (true) {
    clearScreen();
    std::cout << "===== Show Raiders =====\n";
    if (!characters.empty()) {
      int index = 1;
      std::cout << "[0] Go Back\n";
      for (const Character& character : characters) {
        std::cout << "[" << index << "] " << character.getName() << std::endl;
        index++;
      }
    } else {
      std::cout << std::endl;
      std::cout << "You currently have no Raiders.\n";
      std::cout << std::endl;
      std::cout << "[0] Go Back\n";
    }

    int option = getIntegerInput();
    int characterNum = option;

    if (option == 0) {
      return;
    }

    if (option > 0) {
      while (true) {
        clearScreen();
        characters[characterNum - 1].showCharacter();
        std::cout << "Skill Points: "
                  << characters[characterNum - 1].getSkillPoints() << "\n";
        std::cout << std::endl;
        std::cout << "[0] Go Back\n";
        std::cout << "[1] +1 STR\n";
        std::cout << "[2] +1 AGI\n";
        std::cout << "[3] +1 DEX\n";
        std::cout << "[4] +1 END\n";
        std::cout << "[5] +1 INT\n";
        std::cout << "[6] +1 WIS\n";
        std::cout << "[7] +1 CHA\n";
        std::cout << "[8] +1 LUK\n";
        std::cout << "[9] 2nd Page\n";

        int option = getIntegerInput();

        switch (option) {
          case 0: {
            return;
          }
          case 1: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::STR);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 2: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::AGI);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 3: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::DEX);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 4: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::END);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 5: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::INT);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 6: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::WIS);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 7: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::CHA);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 8: {
            if (characters[characterNum - 1].getSkillPoints() > 0) {
              characters[characterNum - 1].useSkillPoint(Character::Stat::LUK);
            } else {
              std::cout << std::endl;
              std::cout << "Not enough Skill Points" << std::endl;
              return;
            }
            break;
          }
          case 9: {
            while (true) {
              clearScreen();
              std::cout << "===== Secondary Stats =====\n";
              characters[characterNum - 1].updateSecondaryStats();
              characters[characterNum - 1].showSecondaryStats();

              std::cout << "[0] Go Back\n";

              int option = getIntegerInput();

              if (option == 0) {
                return;
              }
            }
            break;
          }

          default: {
            std::cout << std::endl;
            std::cout << "Invalid option. Please try again.\n";
            break;
          }
        }
      }
    }
  }
}

// -Raiders >Recruit Raider
void Menu::displayRecruitRaiderMenu(std::vector<Character>& characters,
                                    Currency& playerCurrency) {
  while (true) {
    clearScreen();
    std::cout << "===== Recruit Raider =====" << std::endl;
    std::cout << "Balance: " << playerCurrency.GetGold() << " Gold "
              << playerCurrency.GetSilver() << " Silver\n"
              << std::endl;
    std::cout << "[0] Go Back\n";
    std::cout << "[1] Weak Raider for 10 Gold\n";
    std::cout << "[2] Average Raider for 35 Gold\n";
    std::cout << "[3] Strong Raider for 100 Gold\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        Character::CharacterType type = Character::CharacterType::Weak;
        displayRecruitRaiderTypeMenu(characters, playerCurrency, type);
        return;
      }
      case 2: {
        Character::CharacterType type = Character::CharacterType::Average;
        displayRecruitRaiderTypeMenu(characters, playerCurrency, type);
        return;
      }
      case 3: {
        Character::CharacterType type = Character::CharacterType::Strong;
        displayRecruitRaiderTypeMenu(characters, playerCurrency, type);
        return;
      }

      default:
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
}

//  -Raiders -Recruit Raider >Recruit Raider(Type)
void Menu::displayRecruitRaiderTypeMenu(std::vector<Character>& characters,
                                        Currency& playerCurrency,
                                        Character::CharacterType type) {
  while (true) {
    std::cout << std::endl;
    switch (type) {
      case Character::CharacterType::Weak: {
        clearScreen();
        std::cout << "===== Recruit Raider(Weak) =====\n";

        if (playerCurrency.GetGold() >= 10) {
          std::string raidername{};
          std::cout << "Enter Raider name: ";
          std::cin >> raidername;
          Character Raider = Character::createRaider(
              Character::CharacterType::Weak, raidername);
          characters.push_back(Raider);
          playerCurrency.AddGold(-10);
        } else {
          std::cout << std::endl;
          std::cout << "Not enough Gold!\n" << std::endl;
          std::cout << "[0] Go Back\n";
          int option = getIntegerInput();

          if (option == 0) {
            return;
          } else {
            return;
          }
        }
        return;
      }

      case Character::CharacterType::Average: {
        clearScreen();
        std::cout << "===== Recruit Raider(Average) =====\n";

        if (playerCurrency.GetGold() >= 35) {
          std::string raidername{};
          std::cout << "Enter Raider name: ";
          std::cin >> raidername;
          Character Raider = Character::createRaider(
              Character::CharacterType::Average, raidername);
          characters.push_back(Raider);
          playerCurrency.AddGold(-35);
        } else {
          std::cout << std::endl;
          std::cout << "Not enough Gold!\n" << std::endl;
          std::cout << "[0] Go Back\n";
          int option = getIntegerInput();

          if (option == 0) {
            return;
          } else {
            return;
          }
        }
        return;
      }

      case Character::CharacterType::Strong: {
        clearScreen();
        std::cout << "===== Recruit Raider(Strong) =====\n";

        if (playerCurrency.GetGold() >= 100) {
          std::string raidername{};
          std::cout << "Enter Raider name: ";
          std::cin >> raidername;
          Character Raider = Character::createRaider(
              Character::CharacterType::Strong, raidername);
          characters.push_back(Raider);
          playerCurrency.AddGold(-100);
        } else {
          std::cout << std::endl;
          std::cout << "Not enough Gold!\n" << std::endl;
          std::cout << "[0] Go Back\n";
          int option = getIntegerInput();

          if (option == 0) {
            return;
          } else {
            return;
          }
        }
        return;
      }
      default: {
        return;
      }
    }
  }
}

//* >Town
void Menu::displayTownMenu(const Currency& playerCurrency) {
  while (true) {
    clearScreen();
    std::cout << "===== Town =====" << std::endl;
    std::cout << "Balance: " << playerCurrency.GetGold() << " Gold "
              << playerCurrency.GetSilver() << " Silver\n"
              << std::endl;
    std::cout << "[0] Go Back\n";
    std::cout << "[1] Shop\n";
    std::cout << "[2] Upgrade Town\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        break;
      }
      case 2: {
        break;
      }
      default:
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
}

//* >Tower
void Menu::displayTowerMenu() {
  while (true) {
    clearScreen();
    std::cout << "===== Tower =====" << std::endl;
    std::cout << "[0] Go Back\n";
    std::cout << "[1] -\n";
    std::cout << "[2] -\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        break;
      }
      case 2: {
        break;
      }
      default:
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
}

//* >Inventory
void Menu::displayInventoryMenu() {
  while (true) {
    clearScreen();
    std::cout << "===== Inventory =====" << std::endl;
    std::cout << "[0] Go Back\n";
    std::cout << "[1] -\n";
    std::cout << "[2] -\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        break;
      }
      case 2: {
        break;
      }
      default:
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
}

//* >Save/Load
void Menu::displaySaveLoadMenu() {
  while (true) {
    clearScreen();
    std::cout << "===== Save/Load =====" << std::endl;
    std::cout << "[0] Go Back\n";
    std::cout << "[1] -\n";
    std::cout << "[2] -\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        break;
      }
      case 2: {
        break;
      }
      default:
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
}

//* >Exit Game
void Menu::displayExitGameMenu() {
  clearScreen();
  std::cout << "===== Exit Game =====\n" << std::endl;
  std::cout << "Are you sure you want to leave?\n" << std::endl;
  std::cout << "       y / n         \n";

  std::string option;
  std::cout << std::endl;
  std::cout << "Your Choice: ";
  std::cin >> option;

  if (option == "y" || option == "Y") {
    std::cout << "Exiting the game. Goodbye!" << std::endl;
    exit(0);
  } else {
    return;
  }
}
