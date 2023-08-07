#ifndef CURRENCY_HPP
#define CURRENCY_HPP

class Currency {
 public:
  Currency(int Gold = 1500, int Silver = 0, int Bronze = 0);

  int GetGold() const;
  int GetSilver() const;
  int GetBronze() const;

  void AddGold(int newGold);
  void AddSilver(int newSilver);
  void AddBronze(int newBronze);

 private:
  int gold;
  int silver;
  int bronze;

  void ConvertBronzeToSilver();
  void ConvertSilverToGold();
};

#endif
