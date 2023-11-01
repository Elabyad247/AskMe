//
// Created by Saifaldin Elabyad on 28/10/2023.
//

#ifndef OOP_ASK_ACCOUNT_H_
#define OOP_ASK_ACCOUNT_H_
#include <bits/stdc++.h>
using namespace std;

class account {
 private:
  int id;
  int allowAnon;
  string username;
  string password;
  vector<int> questionsFromMe;
  map<int, vector<int>> questionsThreads;
 public:
  account();
  account(int accID, int accAllowAnon, string &accUser, string &accPass);
  account& operator = (const account& acc);
  int getAccountID() const;
  int getAllowAnon() const;
  string getUsername() const;
  string getPassword() const;
  const vector<int> &getQuestionsFromMe() const;
  const map<int, vector<int>> &getQuestionsThreads() const;
  void ReloadQuestionsFromMe(const vector<int> &newMyQuestions);
  void ReloadQuestionsThreads(const map<int, vector<int>> &newQuestionsThreads);
  void logout();
};

#endif //OOP_ASK_ACCOUNT_H_