#include "../include/Currency.hpp"

Currency::Currency(int Gold, int Silver) : gold(Gold), silver(Silver) {
  ConvertSilvertoGold();
}

int Currency::GetGold() const { return gold; }
int Currency::GetSilver() const { return silver; }

void Currency::AddGold(int newGold) {
  gold += newGold;
  ConvertSilvertoGold();
}

void Currency::AddSilver(int newSilver) {
  silver += newSilver;
  if (silver < 0) {
    ConvertGoldtoSilver();
  }
  ConvertSilvertoGold();
}

void Currency::ConvertGoldtoSilver() {
  int totalSilver = gold * 100 + silver;

  if (totalSilver < 0) {
    int deficitGold = (-totalSilver + 99) / 100;
    gold -= deficitGold;
    silver = 100 * deficitGold + totalSilver;
  } else {
    gold = 0;
    silver = totalSilver;
  }
}

void Currency::ConvertSilvertoGold() {
  if (silver >= 100) {
    gold += silver / 100;
    silver = silver % 100;
  }
}
