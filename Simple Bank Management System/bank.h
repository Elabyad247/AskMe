//
// Created by Saifaldin Elabyad on 27/08/2023.
//

#ifndef OOP_BANK_H_
#define OOP_BANK_H_

#include <bits/stdc++.h>
using namespace std;

class customer {
 private:
  int uID;
  string uName;
  string uPhone;
  string uAddress;
  int uAccountNumber;
 public:
  static int customerCounter;
  customer();
  customer(int id, string name, string phone, string address, int accountNumber);
  int getID() const;
  string getName() const;
  string getPhone() const;
  string getAddress() const;
  int getAccountNumber() const;
  void setAccountNumber(int accountNumber);
};

class account {
 private:
  int aID;
  int cID;
  int aNumber;
  int aBalance;
  string aType;
 public:
  static int accountCounter;
  account();
  account(int id, int customerID, int number, int balance, string type);
  int getID() const;
  int getCustomerID() const ;
  int getAccountNumber() const;
  int getBalance() const;
  string getType() const;
  void deposit(int amount);
  void withdraw(int amount);
};

#endif //OOP_BANK_H_
