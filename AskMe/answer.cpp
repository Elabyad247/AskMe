//
// Created by Saifaldin Elabyad on 28/10/2023.
//

#include "answer.h"

answer::answer() : answerID(-1), questionID(-1), answerContent("") {}
answer::answer(int aID, int aQID, string aAnswer) : answerID(aID), questionID(aQID), answerContent(aAnswer) {}
int answer::getAnswerID() const {
  return answerID;
}
int answer::getQuestionID() const {
  return questionID;
}
string answer::getAnswerContent() const {
  return answerContent;
}
void answer::setAnswerID(int newAnsID) {
  answerID = newAnsID;
}
void answer::setQuestionID(int newQuestionID) {
  questionID = newQuestionID;
}
void answer::setAnswerContent(string &aAnswer) {
  answerContent = aAnswer;
}