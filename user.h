#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std;

class User {
  // personal data members
  int idx;
  string name;
  string pswd;
  int age;
  char gender;

  // allotment data members
  int center_id;
  int date_alloted;
  bool is_alloted;
  bool is_eligible;

public:
  static deque<User*> users_queue;
  static int obj_count;
  static vector<User*> users_store;

  User(int _) { }
  User() {
    cout << "Kindly enter your details.\n\n";
    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "Create a password: "; cin >> pswd;
    cout << "Gender (m/f): "; cin >> gender;
    // convert gender to downcase, if it is upcase
    if(gender < 97) gender += ('a' - 'A');

    is_alloted = false;
    is_eligible = true;
    idx = ++obj_count;

    cout << "You are registered successfully.\n\n(**) Your VaccineID is: " << idx << "\nKindly remember it. It will be used in login.\n";
  }

  void short_info() {
    cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << '\n';
  }

  void info() {
    cout << "Name: " << name << "\nAge: " << age << "\nGender: " << gender << "\nVaccineID: " << idx << "\nPassword: " << pswd << "\n\n";

    if(is_eligible) {
      if(is_alloted) {
        cout << "Congrats!!! You have been alloted COVID-19 Vaccine shot, at Center " << center_id << ".\nGood luck for vaccination! :)\n";
      } else {
        cout << "Keep in touch with our app, you'll be shortly alloted a shot...\n";
      }
    } else {
      cout << "Sorry dear, you're too young to be given a vaccine dose. Be safe at home! :)\n";
    }
  }

  void edit_details() {
    cout << "Enter your NEW details.\n\n";
    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "Password: "; cin >> pswd;
    cout << "Gender (m/f): "; cin >> gender;
    // convert gender to downcase, if it is upcase
    if(gender < 97) gender += ('a' - 'A');
  }

  bool okay(string p) {
    return pswd == p;
  }

  bool authorize() {
    string p;
    cout << "Enter password: "; cin >> p;
    return pswd == p;
  }

  friend class Admin;
};

deque<User*> User::users_queue;
int User::obj_count;
vector<User*> User::users_store;

#endif