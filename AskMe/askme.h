//
// Created by Saifaldin Elabyad on 23/08/2023.
//

#include <bits/stdc++.h>
using namespace std;
#ifndef OOP_ASKME_account_H_
#define OOP_ASKME_account_H_

class account {
 private:
  int id;
  int allowAnon;
  string username;
  string password;
 public:
  account(){

  }
  account(int accID, int accAllowAnon, string &accUser, string &accPass) {
    id = accID;
    allowAnon = accAllowAnon;
    username = accUser;
    password = accPass;
  }
  account& operator=(const account& acc) {
    id = acc.getAccountID();
    allowAnon = acc.getAllowAnon();
    username = acc.getUsername();
    password = acc.getPassword();
    return *this;
  }
  int getAccountID() const {
    return id;
  }
  int getAllowAnon() const {
    return allowAnon;
  }
  string getUsername() const {
    return username;
  }
  string getPassword() const {
    return password;
  }
  void setAccountID(int accID) {
    id = accID;
  }
  void setAllowAnon(int accAllowAnon) {
    allowAnon = accAllowAnon;
  }
  void setUsername(string &accUser) {
    username = accUser;
  }
  void setPasswrod(string &accPass) {
    password = accPass;
  }
  void logout() {
    id = 0;
    allowAnon = 0;
    username = "";
    password = "";
  }
};

class question {
 private:
  int ID;
  string userFrom;
  string userTo;
  int isAnon;
  //int threadID;
  string content;
  //string answer;
 public:
  question() {

  }
  question(int qID, string &qUserFrom, string &qUserTo, int qIsAnon, string &qContent) {
    ID = qID;
    userFrom = qUserFrom;
    userTo = qUserTo;
    isAnon = qIsAnon;
    content = qContent;
  }
  int getID() const {
    return ID;
  }
  string getUserFrom(bool checkAnon) const {
    if (checkAnon && getIsAnon() == 1) {
      return "Anonymous";
    }
    return userFrom;
  }
  string getUserTo() const {
    return userTo;
  }
  string getContent() const {
    return content;
  }
  int getIsAnon() const {
    return isAnon;
  }
  void setContent(string &qContent) {
    content = qContent;
  }
};

class answer {
 private:
  int ID;
  int questionID;
  string ans;
 public:
  answer() {

  }
  answer(int aID, int aQID, string aAnswer) {
    ID = aID;
    questionID = aQID;
    ans = aAnswer;
  }
  int getID() const {
    return ID;
  }
  int getQuestionID() const {
    return questionID;
  }
  string getAnswer() const {
    return ans;
  }
  void setAnswer(string &aAnswer) {
    ans = aAnswer;
  }
};


#endif //OOP_ASKME_account_H_
