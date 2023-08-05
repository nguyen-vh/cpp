// "currency_conversion.hpp"
// Header for inclusion

#ifndef CURRENCY_CONVERSION_HPP
#define CURRENCY_CONVERSION_HPP

#include <string>
#include <unordered_map>

// Add more by looking for 1000000 (Currency adding) converted to USD
// ex. 1000000 EUR -> 1121675.00 USD

std::unordered_map<std::string, double> currencyER = {
    {"USD", 1000000},  {"EUR", 1121675.00}, {"CNY", 139363.10},
    {"CUP", 41680.94}, {"HKD", 127966.70},  {"INR", 12190.48},
    {"JPY", 7178.80},  {"KRW", 788.30},     {"SEK", 97401.14},
    {"TRY", 37945.34}, {"VND", 42.30}};

inline double conversion(const double& amount, const std::string& currencyIN,
                         const std::string& currencyOUT) {
  return (amount * (currencyER[currencyIN]) / (currencyER[currencyOUT]));
}

#endif