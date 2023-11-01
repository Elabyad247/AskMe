//
// Created by Saifaldin Elabyad on 28/10/2023.
//

#include "account.h"

account::account() : id(-1), allowAnon(-1), username(""), password("") {}
account::account(int accID, int accAllowAnon, string &accUser, string &accPass) :
    id(accID), allowAnon(accAllowAnon), username(accUser), password(accPass) {}
account &account::operator=(const account &acc) {
  id = acc.getAccountID();
  allowAnon = acc.getAllowAnon();
  username = acc.getUsername();
  password = acc.getPassword();
  return *this;
}
int account::getAccountID() const {
  return id;
}
int account::getAllowAnon() const {
  return allowAnon;
}
string account::getUsername() const {
  return username;
}
string account::getPassword() const {
  return password;
}
const vector<int> &account::getQuestionsFromMe() const {
  return questionsFromMe;
}
const map<int, vector<int>> &account::getQuestionsThreads() const {
  return questionsThreads;
}
void account::ReloadQuestionsFromMe(const vector<int> &newMyQuestions) {
  questionsFromMe.clear();
  for (auto &i: newMyQuestions) {
    questionsFromMe.emplace_back(i);
  }
}
void account::ReloadQuestionsThreads(const map<int, vector<int>> &newQuestionsThreads) {
  questionsThreads.clear();
  for (auto &x: newQuestionsThreads) {
    for (auto &qID: x.second) {
      questionsThreads[x.first].emplace_back(qID);
    }
  }
}
void account::logout() {
  id = -1;
  allowAnon = -1;
  username = "";
  password = "";
  questionsFromMe.clear();
  questionsThreads.clear();
}