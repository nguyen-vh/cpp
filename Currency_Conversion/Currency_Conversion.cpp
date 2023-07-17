#include <iomanip>
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, double> currencyER;

double convertion(const double& amount, const std::string& currencyIN,
                  const std::string& currencyOUT) {
  return (amount * (currencyER[currencyIN]) / (currencyER[currencyOUT]));
}

int main() {
  currencyER["USD"] = 1000000;
  currencyER["EUR"] = 1121675.00;
  currencyER["CNY"] = 139363.10;
  currencyER["CUP"] = 41680.94;
  currencyER["HKD"] = 127966.70;
  currencyER["INR"] = 12190.48;
  currencyER["JPY"] = 7178.80;
  currencyER["KRW"] = 788.30;
  currencyER["SEK"] = 97401.14;
  currencyER["TRY"] = 37945.34;
  currencyER["VND"] = 42.30;

  double amount{};
  std::string currencyIN{}, currencyOUT{}, possibleConversions{};

  std::cout << "Possible Conversions: " << std::endl;

  for (const auto& pair : currencyER) {
    if (!possibleConversions.empty()) {
      possibleConversions += ", ";
    }
    possibleConversions += pair.first;
  }

  std::cout << possibleConversions << std::endl;

  std::cout << "Amount > Currency IN > Currency OUT" << std::endl;

  std::cin >> amount >> currencyIN >> currencyOUT;

  std::cout << amount << " " << currencyIN << " converts to " << std::fixed
            << std::setprecision(2)
            << convertion(amount, currencyIN, currencyOUT) << " " << currencyOUT
            << std::endl;
}