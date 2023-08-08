#include "../include/Menu.hpp"

#include "../include/Character.hpp"
#include "../include/Global.hpp"

//* >Starting Menu
void Menu::displayRPG_GameMenu() {
  while (true) {
    std::cout << std::endl;
    std::cout << "===== RPG Game =====\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Load Game\n";
    std::cout << "3. Settings\n";
    std::cout << "4. Quit\n";

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
  std::cout << std::endl;
  std::cout << "===== Start Game =====\n" << std::endl;
  std::cout << "Enter Chiefname: \n";
  std::string chiefname{};
  std::cin >> chiefname;
  displayMainMenu();
}

//  >Load Game
void Menu::displayLoadGameMenu() {
  std::cout << std::endl;
  std::cout << "===== Load Game =====\n" << std::endl;
  std::cout << "Enter Savefile: \n";
  std::string savefile{};
  std::cin >> savefile;
  displayMainMenu();
}

//  >Settings
void Menu::displaySettingsMenu() {
  while (true) {
    std::cout << std::endl;
    std::cout << "===== Settings =====\n";
    std::cout << "0. Go Back\n";
    std::cout << "1. Set Easy\n";
    std::cout << "2. Set Normal\n";
    std::cout << "3. Set Hard\n";
    std::cout << "4. Set Hardcode\n";

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
    std::cout << std::endl;
    std::cout << "===== Menu =====\n";
    std::cout << "1. Raiders\n";
    std::cout << "2. Town\n";
    std::cout << "3. Tower\n";
    std::cout << "4. Inventory\n";
    std::cout << "5. Save/Load\n";
    std::cout << "6. Exit Game\n";

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
    std::cout << std::endl;
    std::cout << "===== Raiders =====" << std::endl;
    std::cout << "0. Go Back\n";
    std::cout << "1. Show Raiders\n";
    std::cout << "2. Recruit Raider\n";

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
    std::cout << std::endl;
    std::cout << "===== Show Raiders =====\n";
    std::cout << "0. Go Back\n";

    if (!characters.empty()) {
      int index = 1;
      for (const Character& character : characters) {
        std::cout << index << ". " << character.getName() << std::endl;
        index++;
      }
    } else {
      std::cout << std::endl;
      std::cout << "You currently have no Raiders.\n";
      std::cout << std::endl;
      std::cout << "0. Go Back\n";
    }

    int characterNum = getIntegerInput();

    if (characterNum == 0) {
      return;
    }

    if (characterNum > 0) {
      while (true) {
        characters[characterNum - 1].showCharacter();
        std::cout << "Skill Points: "
                  << characters[characterNum - 1].getSkillPoints() << "\n";
        std::cout << std::endl;
        std::cout << "0. Go Back\n";
        std::cout << "1. +1 STR\n";
        std::cout << "2. +1 AGI\n";
        std::cout << "3. +1 DEX\n";
        std::cout << "4. +1 END\n";
        std::cout << "5. +1 INT\n";
        std::cout << "6. +1 WIS\n";
        std::cout << "7. +1 CHA\n";
        std::cout << "8. +1 LUK\n";
        std::cout << "9. Open Stats\n";

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
    std::cout << std::endl;
    std::cout << "===== Recruit Raider =====" << std::endl;
    std::cout << "Balance: " << playerCurrency.GetGold() << " Gold "
              << playerCurrency.GetSilver() << " Silver\n"
              << std::endl;
    std::cout << "0. Go Back\n";
    std::cout << "1. Raider (weak) for 10 Gold\n";
    std::cout << "2. Raider (average) for 35 Gold\n";
    std::cout << "3. Raider (strong) for 100 Gold\n";

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
          std::cout << "0. Go Back\n";
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
          std::cout << "0. Go Back\n";
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
          std::cout << "0. Go Back\n";
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
    std::cout << std::endl;
    std::cout << "===== Town =====" << std::endl;
    std::cout << "Balance: " << playerCurrency.GetGold() << " Gold "
              << playerCurrency.GetSilver() << " Silver\n"
              << std::endl;
    std::cout << "0. Go Back\n";
    std::cout << "1. Shop\n";
    std::cout << "2. Upgrade Town\n";

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
    std::cout << std::endl;
    std::cout << "===== Tower =====" << std::endl;
    std::cout << "0. Go Back\n";
    std::cout << "1. -\n";
    std::cout << "2. -\n";

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
    std::cout << std::endl;
    std::cout << "===== Inventory =====" << std::endl;
    std::cout << "0. Go Back\n";
    std::cout << "1. -\n";
    std::cout << "2. -\n";

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
    std::cout << std::endl;
    std::cout << "===== Save/Load =====" << std::endl;
    std::cout << "0. Go Back\n";
    std::cout << "1. -\n";
    std::cout << "2. -\n";

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
  std::cout << std::endl;
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
