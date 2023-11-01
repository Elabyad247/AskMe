//
// Created by Saifaldin Elabyad on 23/08/2023.
//

#include <bits/stdc++.h>
using namespace std;

#ifndef OOP_ASK_SYSTEM_H_
#define OOP_ASK_SYSTEM_H_
#include "account.h"
#include "question.h"
#include "answer.h"

class _ACCOUNTS_ {
 private:
  account myAccount;
  map<string, account> accounts;
  int lastID;
 public:
  _ACCOUNTS_();
  void loadAccounts();
  void updateAccounts();
  void loginAccount();
  void registerAccount();
  void listAccounts();
  void logoutAccount();
  void ReloadQuestions(const vector<int> &questionsFromMe, const map<int, vector<int>> &questionsToMe);
  const account &getMyAccount() const;
  map<string, account> &getAccounts();
};

class _QUESTIONS_ {
 private:
  map<int, vector<int>> questionsThreads;
  map<int, question> questions;
  int lastID;
 public:
  _QUESTIONS_();
  void loadQuestions();
  void updateQuestions();
  void showQuestionToUser(const account &acc, const map<int, answer> &answers) const;
  void showQuestionsFromUser(const account &acc, const map<int, answer> &answers) const;
  void askQuestion(const account &acc, map<string, account> &accounts);
  void answerQuestion(const account &acc, map<int, answer> &answers, int lastAnswerID);
  void deleteQuestion(const account &acc, map<int, answer> &answers);
  void showFeed(map<int, answer> &answers) const;
};

class _ANSWERS_ {
 protected:
  map<int, answer> answers;
  int lastID;
 public:
  _ANSWERS_();
  void loadAnswers();
  void updateAnswers();
  map<int, answer> &getAnswers();
  int getLastID();
};

class _SYSTEM_ {
 private:
  _ACCOUNTS_ accountsSystem;
  _QUESTIONS_ questionsSystem;
  _ANSWERS_ answersSystem;

  void loadData(bool resetUsersQuestions);
  void updateData();
  void resetQuestions();
  void startMenu();
 public:
  void run();
};

#endif //OOP_ASK_SYSTEM_H_