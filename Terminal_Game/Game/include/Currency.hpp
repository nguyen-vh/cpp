#ifndef CURRENCY_HPP
#define CURRENCY_HPP

class Currency {
 public:
  // 100 Silber = 1 Gold
  Currency(int Gold = 140, int Silver = 0);

  int GetGold() const;
  int GetSilver() const;

  void AddGold(int newGold);
  void AddSilver(int newSilver);

 private:
  int gold;
  int silver;

  void ConvertGoldtoSilver();
  void ConvertSilvertoGold();
};

#endif
