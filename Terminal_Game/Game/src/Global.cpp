#include "../include/Global.hpp"

int getIntegerInput() {
  int input;
  while (true) {
    std::cout << "Your Choice: ";
    if (std::cin >> input) {
      break;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number.\n";
    }
  }
  return input;
}

int generateRandomNumber(int minValue, int maxValue) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(minValue, maxValue);

  return distribution(gen);
}
