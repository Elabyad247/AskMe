//
// Created by Saifaldin Elabyad on 28/10/2023.
//

#include "question.h"

question::question() : ID(-1), userFrom(""), userTo(""), isAnon(-1), threadID(-1), question_content("") {}
question::question(int qID, string &qUserFrom, string &qUserTo, int qIsAnon, int qThreadID, string &qContent) :
    ID(qID), userFrom(qUserFrom), userTo(qUserTo), isAnon(qIsAnon), threadID(qThreadID), question_content(qContent) {}
int question::getID() const {
  return ID;
}
string question::getUserFrom(bool checkAnon) const {
  if (checkAnon && getIsAnon() == 1) {
    return "Anonymous";
  }
  return userFrom;
}
string question::getUserTo() const {
  return userTo;
}
int question::getIsAnon() const {
  return isAnon;
}
int question::getThreadID() const {
  return threadID;
}
string question::getQuestionContent() const {
  return question_content;
}
void question::setQuestionID(int newID) {
  ID = newID;
}
void question::setUserFrom(string &newUserFrom) {
  userFrom = newUserFrom;
}
void question::setUserTo(string &newUserTo) {
  userTo = newUserTo;
}
void question::setIsAnon(int newIsAnon) {
  isAnon = newIsAnon;
}
void question::setThreadID(int newThreadID) {
  threadID = newThreadID;
}
void question::setQuestionContent(string &newContent) {
  question_content = newContent;
}