#ifndef ADMIN_H
#define ADMIN_H

#include <bits/stdc++.h>
using namespace std;

int today = 1;

class Admin {
  string pswd;
  int center_id;

public:  
  static int min_age;
  Admin() {
    pswd = "go_corona_go";
    center_id = 1031;
  }

  void execute_allotment(int shots) {
    int t = shots;
    while(shots > 0 && !User::users_queue.empty()) {
      User* u = User::users_queue.top();
      // checking if the user is eligible?
      if(u->age >= min_age) {
        u->center_id = center_id;
        u->date_alloted = (today + 1) % 31;
        u->is_alloted = true;
        shots--; // vaccine booked for user
      } else {
        u->is_eligible = false;
      }
      User::users_queue.pop();
    }

    cout << "Success: " << t-shots << "Vaccine shots are confirmed for allotment at the specified medical center. There are remaining " << shots << " shots unalloted.\n";
  }

  void display_registrations() {
    cout << "Registrations list:\n\n";
    priority_queue<User*, vector<User*>, C> temp;

    while(!User::users_queue.empty()) {
      User* u = User::users_queue.top();
      u->short_info();
      temp.push( User::users_queue.top() );
      User::users_queue.pop();
    }

    while(!temp.empty()) {
      User::users_queue.push( temp.top() );
      temp.pop();
    }
  }

  void edit_min_age(int new_min) {
    min_age = new_min;
    priority_queue<User*, vector<User*>, C> temp;

    while(!User::users_queue.empty()) {
      if(User::users_queue.top()->age >= min_age) {
        temp.push( User::users_queue.top() );
      }
      User::users_queue.pop();
    }

    while(!temp.empty()) {
      User::users_queue.push( temp.top() );
      temp.pop();
    }
  }

  bool authorize() {
    string p;
    cout << "Enter password: "; cin >> p;
    return p == pswd;
  }
};

int Admin::min_age = 16;

#endif