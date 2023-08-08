#include "../include/Character.hpp"

Character::Character(const std::string& name) : name(name) {
  characterStats[Stat::LUK] = 0;
  characterStats[Stat::CHA] = 0;
  characterStats[Stat::WIS] = 0;
  characterStats[Stat::INT] = 0;
  characterStats[Stat::END] = 0;
  characterStats[Stat::DEX] = 0;
  characterStats[Stat::AGI] = 0;
  characterStats[Stat::STR] = 0;
  characterStats[Stat::LVL] = 0;
}

std::string Character::getName() const { return name; }

Character Character::createRaider(CharacterType type, const std::string& name) {
  Character character(name);
  std::unordered_map<Stat, int> typeStats = getStatsForType(type);

  for (const auto& entry : typeStats) {
    character.characterStats[entry.first] = entry.second;
  }

  return character;
}

std::unordered_map<Character::Stat, int> Character::getStatsForType(
    CharacterType type) {
  std::unordered_map<Stat, int> stats;

  switch (type) {
    case CharacterType::Weak: {
      stats[Stat::LUK] = generateRandomNumber(3, 14);
      stats[Stat::CHA] = generateRandomNumber(3, 14);
      stats[Stat::WIS] = generateRandomNumber(3, 14);
      stats[Stat::INT] = generateRandomNumber(3, 14);
      stats[Stat::END] = generateRandomNumber(3, 14);
      stats[Stat::DEX] = generateRandomNumber(3, 14);
      stats[Stat::AGI] = generateRandomNumber(3, 14);
      stats[Stat::STR] = generateRandomNumber(3, 14);
      stats[Stat::LVL] = 0;
      break;
    }
    case CharacterType::Average: {
      stats[Stat::LUK] = generateRandomNumber(5, 16);
      stats[Stat::CHA] = generateRandomNumber(5, 16);
      stats[Stat::WIS] = generateRandomNumber(5, 16);
      stats[Stat::INT] = generateRandomNumber(5, 16);
      stats[Stat::END] = generateRandomNumber(5, 16);
      stats[Stat::DEX] = generateRandomNumber(5, 16);
      stats[Stat::AGI] = generateRandomNumber(5, 16);
      stats[Stat::STR] = generateRandomNumber(5, 16);
      stats[Stat::LVL] = 0;
      break;
    }
    case CharacterType::Strong: {
      stats[Stat::LUK] = generateRandomNumber(8, 19);
      stats[Stat::CHA] = generateRandomNumber(8, 19);
      stats[Stat::WIS] = generateRandomNumber(8, 19);
      stats[Stat::INT] = generateRandomNumber(8, 19);
      stats[Stat::END] = generateRandomNumber(8, 19);
      stats[Stat::DEX] = generateRandomNumber(8, 19);
      stats[Stat::AGI] = generateRandomNumber(8, 19);
      stats[Stat::STR] = generateRandomNumber(8, 19);
      stats[Stat::LVL] = 0;
      break;
    }
    default: {
      break;
    }
  }

  return stats;
}

void Character::applyItemStats(const Item& item) {
  const std::unordered_map<Item::Stat, int>& itemStats = item.getStats();
  for (const auto& entry : itemStats) {
    if (characterStats.find(static_cast<Stat>(entry.first)) !=
        characterStats.end()) {
      characterStats[static_cast<Stat>(entry.first)] += entry.second;
    }
  }
}

void Character::setCharacterStat(Stat stat, int Value) {
  if (characterStats.find(stat) != characterStats.end()) {
    characterStats[stat] = Value;
  } else {
    std::cout << "Stat not found." << std::endl;
  }
}

std::string Character::statToString(Character::Stat stat) const {
  switch (stat) {
    case Character::Stat::LUK: {
      return "LUK";
    }
    case Character::Stat::CHA: {
      return "CHA";
    }
    case Character::Stat::WIS: {
      return "WIS";
    }
    case Character::Stat::INT: {
      return "INT";
    }
    case Character::Stat::END: {
      return "END";
    }
    case Character::Stat::DEX: {
      return "DEX";
    }
    case Character::Stat::AGI: {
      return "AGI";
    }
    case Character::Stat::STR: {
      return "STR";
    }
    case Character::Stat::LVL: {
      return "LVL";
    }
    default: {
      return "UNKNOWN";
    }
  }
}

void Character::showCharacter() const {
  std::cout << "===== Lv." << characterStats.at(Stat::LVL) << " " << name
            << " =====" << std::endl;

  bool firstLine = true;
  for (const auto& entry : characterStats) {
    if (!firstLine) {
      std::cout << " " << statToString(entry.first) << ": " << entry.second
                << std::endl;
    }
    firstLine = false;
  }
  std::cout << std::endl;
}

void Character::addEXP(int amount) {
  expPoints += amount;
  while (expPoints >= expThreshold) {
    levelUp();
  }
}

int Character::getEXP() const { return expPoints; }

void Character::levelUp() {
  characterStats[Stat::LVL] += 1;
  expThreshold = calculateEXPThreshold();
  skillPointsAll += 3;
}

int Character::calculateEXPThreshold() {
  int level = characterStats[Stat::LVL];
  int baseEXPThreshold = 100;
  int scaleEXP = std::log(level) * 100;
  int decimalscaleEXP = (level / 10) * 250;

  return baseEXPThreshold + scaleEXP + decimalscaleEXP;
}

int Character::addSkillPoints(int amount) {
  skillPointsAll += amount;
  return skillPointsAll;
}

int Character::getSkillPoints() const {
  int skillPointsLeft = skillPointsAll - skillPointsUsed;

  return skillPointsLeft;
}

void Character::useSkillPoint(Stat stat) {
  if (getSkillPoints() > 0) {
    characterStats[stat] += 1;
    skillPointsUsed += 1;
  }
}