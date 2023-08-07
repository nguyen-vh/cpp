#include "../include/Currency.hpp"

Currency::Currency(int Gold, int Silver, int Bronze)
    : gold(Gold), silver(Silver), bronze(Bronze) {
  ConvertBronzeToSilver();
  ConvertSilverToGold();
}

int Currency::GetGold() const { return gold; }
int Currency::GetSilver() const { return silver; }
int Currency::GetBronze() const { return bronze; }

void Currency::AddGold(int newGold) {
  gold += newGold;
  ConvertSilverToGold();
}

void Currency::AddSilver(int newSilver) {
  silver += newSilver;
  ConvertBronzeToSilver();
  ConvertSilverToGold();
}

void Currency::AddBronze(int newBronze) {
  bronze += newBronze;
  ConvertBronzeToSilver();
  ConvertSilverToGold();
}

void Currency::ConvertBronzeToSilver() {
  while (bronze >= 100) {
    silver += 1;
    bronze -= 100;
  }
}

void Currency::ConvertSilverToGold() {
  while (silver >= 100) {
    gold += 1;
    silver -= 100;
  }
}
