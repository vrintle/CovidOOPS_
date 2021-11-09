#ifndef MENU_H
#define MENU_H

#include <bits/stdc++.h>
using namespace std;

// abstract class
class Menu {
protected:
  vector<string> options;
  int exitCode;
  int choice;

public:
  Menu() {
    exitCode = 0; // code to exit view-loop
  }
  void virtual choose() = 0; // pure virtual method, must be defined in derived classes, else they'll become abstract
};

class UserMenu : protected Menu {
public:
  UserMenu() {
    options = {
      "Check registration status.",
      "Edit details."
    };
  }

  void choose() {
    int id;
    cout << "Enter VaccineID: "; cin >> id;
    string pswd;
    cout << "Enter password: "; cin >> pswd;

    if(id <= User::obj_count && id > 0 && User::users_store[id - 1]->okay(pswd)) {
      User* user = User::users_store[id - 1];      
      cout << "\nUSER MENU\n---------\n\n";
      for(int i = 0; i < options.size(); i++) {
        cout << i+1 << ". " << options[i] << "\n";
      }

      cout << "\nEnter your choice (" << exitCode << " to exit): ";
      cin >> choice;

      if(choice == 1) {
        user->info();
      } else if(choice == 2) {
        user->edit_details();
      }
    } else {
      cout << "Sorry, the password doesn't matches with the VaccineID. Please try again!\n";
    }
  }
};

class AdminMenu : protected Menu {
public:
  AdminMenu() {
    options = {
      "Execute vaccine allotment.",
      "Show registrations list.",
      "Change minimum eligible age."
    };
  }

  void choose() {
    Admin adm;
    if(adm.authorize()) {
      cout << "\nADMIN MENU\n----------\n\n";
      for(int i = 0; i < options.size(); i++) {
        cout << i+1 << ". " << options[i] << "\n";
      }

      cout << "\nEnter your choice (" << exitCode << " to exit): ";
      cin >> choice;

      if(choice == 1) {
        cout << "Enter amount of shots available: ";
        int shots; cin >> shots;
        adm.execute_allotment(shots);
      } else if(choice == 2) {
        adm.display_registrations();
      } else if(choice == 3) {
        int new_min;
        cout << "Enter new min-age: ";
        cin >> new_min;
        adm.edit_min_age(new_min);
      }
    }
  }
};

class MainMenu : protected Menu {
public:
  MainMenu() {
    options = {
      "Register for vaccine.",
      "Login as user.",
      "Login as Admin."
    };
  }

  void choose() {
    cout << "\nMAIN MENU\n---------\n\n";
    for(int i = 0; i < options.size(); i++) {
      cout << i+1 << ". " << options[i] << "\n";
    }

    cout << "\nEnter your choice (" << exitCode << " to exit): ";
    cin >> choice;

    if(choice == 1) {
      cout << "Are you sure to register? (y/n): ";
      char c; cin >> c;
      if(c == 'y' || c == 'Y') {
        User u;
        User::users_store.push_back(&u);
        User::users_queue.push(&u);
            
        // for(int i = 0; i < User::users_store.size(); i++) {
        //   (*User::users_store[i]).short_info();
        // }
      }
    } else if(choice == 2) {
      UserMenu user_menu;
      user_menu.choose();
    } else if(choice == 3) {
      AdminMenu adm_menu;
      adm_menu.choose();
    }
  }

  bool running() {
    return choice != exitCode;
  }
};

#endif