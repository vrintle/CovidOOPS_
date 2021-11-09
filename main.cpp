#include <iostream>
#include "./user.h"
#include "./admin.h"
#include "./menu.h"
using namespace std;

int main() {
  cout << "\nWelcome to COVID-19 Vaccine registration App!\n";
  MainMenu main_menu;
  
  do {
    main_menu.choose();
  } while(main_menu.running());

  cout << "\nThanks for using App!\n";
  return 0;
}