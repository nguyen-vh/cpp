#include "include/Character.hpp"
#include "include/Currency.hpp"
#include "include/Global.hpp"
#include "include/Item.hpp"
#include "include/Menu.hpp"
#include "include/Town.hpp"

//*  ___________                          ____________________  ________
//*  \__    ___/_____  _  __ ___________  \______   \______   \/  _____/
//*    |    | /  _ \ \/ \/ // __ \_  __ \  |       _/|     ___/   \  ___
//*    |    |(  <_> )     /\  ___/|  | \/  |    |   \|    |   \    \_\  \
//*    |____| \____/ \/\_/  \___  >__|     |____|_  /|____|    \______  /
//*                             \/                \/                  \/

int main(int argc, char* argv[]) {
  Menu::GameLoop();

  return 0;
}
