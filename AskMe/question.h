//
// Created by Saifaldin Elabyad on 28/10/2023.
//

#ifndef OOP_ASK_QUESTION_H_
#define OOP_ASK_QUESTION_H_
#include <bits/stdc++.h>
using namespace std;

class question {
 private:
  int ID;
  string userFrom;
  string userTo;
  int isAnon;
  int threadID;
  string question_content;
 public:
  question();
  question(int qID, string &qUserFrom, string &qUserTo, int qIsAnon, int qThreadID, string &qContent);
  int getID() const;
  string getUserFrom(bool checkAnon) const;
  string getUserTo() const;
  int getIsAnon() const;
  int getThreadID() const;
  string getQuestionContent() const;
  void setQuestionID(int newID);
  void setUserFrom(string &newUserFrom);
  void setUserTo(string &newUserTo);
  void setIsAnon(int newIsAnon);
  void setThreadID(int newThreadID);
  void setQuestionContent(string &newContent);
};

#endif //OOP_ASK_QUESTION_H_