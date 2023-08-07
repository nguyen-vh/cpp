#include "../include/Menu.hpp"

#include "../include/Global.hpp"

//! Main Menu
void Menu::displayMainMenu() {
  std::cout << std::endl;
  std::cout << "===== Menu =====\n";
  std::cout << "1. Raiders\n";
  std::cout << "2. Town\n";
  std::cout << "3. Tower\n";
  std::cout << "4. Inventory\n";
  std::cout << "5. Save/Load\n";
  std::cout << "6. Exit Game\n";
}

//! Raiders
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
        if (!characters.empty()) {
          for (const Character& character : characters) {
            character.showCharacter();
          }
        } else {
          std::cout << std::endl;
          std::cout << "You currently have no Raider." << std::endl;
        }
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

void Menu::displayRecruitRaiderMenu(std::vector<Character>& characters,
                                    Currency& playerCurrency) {
  while (true) {
    std::cout << std::endl;
    std::cout << "===== Recruit Raider =====" << std::endl;
    std::cout << "Balance: " << playerCurrency.GetGold() << " Gold "
              << playerCurrency.GetSilver() << " Silver "
              << playerCurrency.GetBronze() << " Bronze\n"
              << std::endl;
    std::cout << "0. Go Back\n";
    std::cout << "1. Raider (weak) for 10 Gold\n";
    std::cout << "2. Raider (normal) for 35 Gold\n";
    std::cout << "3. Raider (strong) for 100 Gold\n";

    int option = getIntegerInput();

    switch (option) {
      case 0: {
        return;
      }
      case 1: {
        return;
      }
      case 2: {
        return;
      }
      case 3: {
        return;
      }

      default:
        std::cout << std::endl;
        std::cout << "Invalid number. Please try again.\n";
        break;
    }
  }
}

//! Town
void Menu::displayTownMenu(const Currency& playerCurrency) {
  while (true) {
    std::cout << std::endl;
    std::cout << "===== Town =====" << std::endl;
    std::cout << "Balance: " << playerCurrency.GetGold() << " Gold "
              << playerCurrency.GetSilver() << " Silver "
              << playerCurrency.GetBronze() << " Bronze\n"
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

//! Tower
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

//! Inventory
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

//! Save/Load
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

//! Exit Game
void Menu::displayExitGameMenu() {
  std::cout << std::endl;
  std::cout << "===== Exit Game =====\n" << std::endl;
  std::cout << "Are you sure you want to leave?\n" << std::endl;
  std::cout << "             y / n             \n";

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
