//
// Created by Saifaldin Elabyad on 28/10/2023.
//

#ifndef OOP_ASK_ANSWER_H_
#define OOP_ASK_ANSWER_H_
#include <bits/stdc++.h>
using namespace std;

class answer {
 private:
  int answerID;
  int questionID;
  string answerContent;
 public:
  answer();
  answer(int aID, int aQID, string aAnswer);
  int getAnswerID() const;
  int getQuestionID() const;
  string getAnswerContent() const;
  void setAnswerContent(string &aAnswer);
  void setAnswerID(int newAnsID);
  void setQuestionID(int newQuestionID);
};

#endif //OOP_ASK_ANSWER_H_