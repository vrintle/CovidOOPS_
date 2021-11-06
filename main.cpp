#include <iostream>
#include "./user.h"
#include "./admin.h"
#include "./menu.h"
using namespace std;

int main() {
  MainMenu main_menu;
  
  do {
    main_menu.choose();
  } while(main_menu.running());

  return 0;
}