//
// Created by Saifaldin Elabyad on 23/08/2023.
//
#include "system.h"
#define acc_path string("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/AskSystem/accounts.txt").c_str()
#define qus_path string("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/AskSystem/questions.txt").c_str()
#define ans_path string("C:/Users/Saifaldin Elabyad/CLionProjects/OOP/AskSystem/answers.txt").c_str()

vector<string> split(const string &str, const string &delimiter = ";") {
  string s = str;
  vector<string> strings;
  int pos = 0;
  string substr;
  while ((pos = (int) s.find(delimiter)) != -1) {
    substr = s.substr(0, pos);
    strings.push_back(substr);
    s.erase(0, pos + delimiter.length());
  }
  strings.push_back(s);
  return strings;
}
int toInt(const string &str) {
  istringstream iss(str);
  int num;
  iss >> num;
  return num;
}

////////////////// ACCOUNTS SYSTEM //////////////////
_ACCOUNTS_::_ACCOUNTS_() : lastID(-1) {}
void _ACCOUNTS_::loadAccounts() {
  accounts.clear();
  lastID = 0;
  ifstream accountRead(acc_path);
  if (!accountRead) {
    cerr << "Open accounts.txt Failed\n";
    exit(0);
  }
  string line;
  while (getline(accountRead, line)) {
    vector<string> data = split(line);
    accounts[data[2]] = account(toInt(data[0]), toInt(data[1]), data[2], data[3]);
    lastID = max(lastID, toInt(data[0]));
  }
  accountRead.close();
}
void _ACCOUNTS_::updateAccounts() {
  ofstream output(acc_path);
  for (auto &acc: accounts) {
    string log = to_string(acc.second.getAccountID()) + ";" + to_string(acc.second.getAllowAnon()) + ";" + acc.second.getUsername() + ";" + acc.second.getPassword();
    output << log << endl;
  }
  output.close();

}
void _ACCOUNTS_::loginAccount() {
  loadAccounts();
  string username, password;
  bool isCorrect;
  do {
    isCorrect = false;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    if (!accounts.count(username)) {
      cout << "Username does not exist! Try Again." << endl;
    } else {
      if (accounts[username].getPassword() != password) {
        cout << "Password is wrong! Try Again." << endl;
      } else {
        isCorrect = true;
        myAccount = accounts[username];
      }
    }
  } while (!isCorrect);
  cout << "You have successfully logged in." << endl;
}
void _ACCOUNTS_::registerAccount() {
  bool isUsed;
  string username;
  do {
    isUsed = true;
    cout << "Enter your username: ";
    cin >> username;
    if (accounts.count(username)) {
      cout << "Username is used before! Please try another one." << endl;
    } else {
      isUsed = false;
    }
  } while (isUsed);
  string password;
  cout << "Enter your password: ";
  cin >> password;

  int allowAnon = 0;
  do {
    allowAnon = 0;
    cout << "Allow anonymous questions? (0 or 1): ";
    cin >> allowAnon;
    if (allowAnon != 0 && allowAnon != 1) {
      cout << "Please enter 0 for no or 1 for yes!!" << endl;
    }
  } while (allowAnon != 0 && allowAnon != 1);

  lastID++;
  accounts[username] = account(lastID, allowAnon, username, password);
  myAccount = accounts[username];
  cout << "Account with ID: "<< lastID <<" created successfully" << endl;
  updateAccounts();
}
void _ACCOUNTS_::listAccounts() {
  cout << "* Accounts List *" << endl;
  for (auto &acc: accounts) {
    cout << "\t" << "ID: " << acc.second.getAccountID() << ", Username: " << acc.second.getUsername() << endl;
  }
  cout << endl;
  int check = 0;
  do {
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      break;
    }
  } while (check != -1);
}
void _ACCOUNTS_::logoutAccount() {
  myAccount.logout();
  cout << "You have successfully logged out." << endl;
  cout << endl;
  return;
}
void _ACCOUNTS_::ReloadQuestions(const vector<int> &questionsFromMe, const map<int, vector<int>> &questionsToMe) {
  myAccount.ReloadQuestionsFromMe(questionsFromMe);
  myAccount.ReloadQuestionsThreads(questionsToMe);
}
const account &_ACCOUNTS_::getMyAccount() const {
  return myAccount;
}
map<string, account> &_ACCOUNTS_::getAccounts() {
  return accounts;
}
/////////////////////////////////////////////////////

////////////////// QUESTIONS SYSTEM //////////////////
_QUESTIONS_::_QUESTIONS_() : lastID(-1) {}
void _QUESTIONS_::loadQuestions() {
  questions.clear();
  lastID = 0;
  ifstream questionRead(qus_path);
  if (!questionRead) {
    cerr << "Open questions.txt Failed\n";
    exit(0);
  }
  string line;
  while (getline(questionRead, line)) {
    vector<string> data = split(line);
    questions[toInt(data[0])] = question(toInt(data[0]), data[1], data[2], toInt(data[3]), toInt(data[4]), data[5]);
    if (toInt(data[4]) == -1) {
      questionsThreads[toInt(data[0])].push_back(toInt(data[0]));
    } else {
      questionsThreads[toInt(data[4])].push_back(toInt(data[0]));
    }
    lastID = max(lastID, toInt(data[0]));
  }
  questionRead.close();
}
void _QUESTIONS_::updateQuestions() {
  ofstream output(qus_path);
  for (auto &qus: questions) {
    string log = to_string(qus.second.getID()) + ";" + qus.second.getUserFrom(false) + ";" + qus.second.getUserTo() + ";" + to_string(qus.second.getIsAnon()) + ";" + to_string(qus.second.getThreadID()) + ";" + qus.second.getQuestionContent();
    output << log << endl;
  }
  output.close();
}
void _QUESTIONS_::showQuestionToUser(const account &acc, const map<int, answer> &answers) const {
  cout << "* Questions Sent To "<< acc.getUsername() << " *" << endl;
  for (auto &qs: questions) {
    if (qs.second.getUserTo() == acc.getUsername()) {
      cout << "\t" << "Question (ID: " << qs.second.getID() << "): " << qs.second.getQuestionContent() << endl;
      cout << "\t" << "From: " << qs.second.getUserFrom(true) << endl;
      string answerContent;
      for (auto &ans: answers) {
        if (ans.second.getQuestionID() == qs.second.getID()) {
          answerContent = ans.second.getAnswerContent();
        }
      }
      cout << "\t" << "Answer: " << answerContent << endl;
      cout << endl;
    }
  }
  int check = 0;
  do {
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      break;
    }
  } while (check != -1);
}
void _QUESTIONS_::showQuestionsFromUser(const account &acc, const map<int, answer> &answers) const {
  cout << "* Questions Sent by "<< acc.getUsername() << " *" << endl;
  for (auto &qs: questions) {
    if (qs.second.getUserFrom(false) == acc.getUsername()) {
      cout << "\t" << "Question (ID: " << qs.second.getID() << "): " << qs.second.getQuestionContent() << endl;
      cout << "\t" << "To: " << qs.second.getUserTo() << endl;
      string answerContent;
      for (auto &ans: answers) {
        if (ans.second.getQuestionID() == qs.second.getID()) {
          answerContent = ans.second.getAnswerContent();
        }
      }
      cout << "\t" << "Answer: " << answerContent << endl;
      cout << endl;
    }
  }
  int check = 0;
  do {
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      break;
    }
  } while (check != -1);
}
void _QUESTIONS_::askQuestion(const account &acc, map<string, account> &accounts) {
  cout << "* Ask Question *" << endl;
  string username = "";
  bool isExist;
  do {
    isExist = false;
    cout << "\t" << "Enter the username you want ask (or -1 to go back): ";
    cin >> username;
    if (username == "-1") {
      break;
    }
    if (accounts.count(username)) {
      isExist = true;
    }
    if (!isExist) {
      cout << "\t" << "Username not found! Try Again." << endl;
    } else {
      if (username == acc.getUsername()) {
        cout << "\t" << "You can't ask yourself!" << endl;
        isExist = false;
      }
    }
  } while (!isExist);
  if (!accounts.count(username)) {
    cout << endl;
    return;
  }
  int isAnon = 0;
  if (accounts[username].getAllowAnon() == 0) {
    cout << "\t" << "NOTE: this person does not allow anonymous questions!" << endl;
  } else {
    cout << "\t" << "Anonymous question (1 for yes, 0 for no): ";
    cin >> isAnon;
  }
  int threadID = -1;
  do {
    cout << "For thread question: Enter Question id or -1 for new question: ";
    cin >> threadID;
    if (threadID == -1) {
      break;
    }
    if (!questionsThreads.count(threadID)) {
      cout << "No thread question with such ID. Try again!" << endl;
      threadID = -1;
    }
  } while (threadID == -1);

  question newQuestion;
  lastID++;
  newQuestion.setQuestionID(lastID);
  newQuestion.setThreadID(threadID);
  string userFrom = acc.getUsername();
  newQuestion.setUserFrom(userFrom);
  newQuestion.setUserTo(username);
  newQuestion.setIsAnon(isAnon);
  cout << "\t" << "Enter question content: ";
  string questionContent;
  getline(cin >> ws, questionContent);
  newQuestion.setQuestionContent(questionContent);
  questions[lastID] = newQuestion;
  if (newQuestion.getThreadID() == -1) {
    questionsThreads[lastID].push_back(lastID);
  } else {
    questionsThreads[newQuestion.getThreadID()].push_back(lastID);
  }
  cout << "Question (ID: " << lastID << ") " << " sent successfully to " << username << "." << endl;
  int check = 0;
  do {
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      break;
    }
  } while (check != -1);
}
void _QUESTIONS_::answerQuestion(const account &acc, map<int, answer> &answers, int lastAnswerID) {
  cout << "* Answer Question *" << endl;
  int questionID = -1;
  bool isExist;
  string answerContent;
  do {
    isExist = false;
    cout << "\t" << "Enter question id (or -1 to go back): ";
    cin >> questionID;
    if (questionID == -1) {
      break;
    }
    if (!questions.count(questionID)) {
      cout << "Wrong question id. Try Again" << endl;
      isExist = false;
    } else {
      if (questions[questionID].getUserTo() != acc.getUsername()) {
        cout << "Please enter question id belongs to you!" << endl;
        isExist = false;
      } else {
        isExist = true;
        answerContent = answers[questionID].getAnswerContent();
      }
    }
  } while (!isExist);
  if (questionID == -1) {
    cout << endl;
    return;
  }
  cout << "\t" << "Question (ID: " << questionID << "): " << questions[questionID].getQuestionContent() << endl;
  cout << "\t" << "From: " << questions[questionID].getUserFrom(true) << endl;
  cout << "\t" << "Answer: " << answerContent << endl;
  cout << endl;
  string newAnswerContent;
  cout << "Enter your answer (answer will be overwrote or -1 to go back): ";
  getline(cin >> ws, newAnswerContent);
  if (newAnswerContent == "-1") {
    cout << endl;
    return;
  }
  answers[questionID].setAnswerID(lastAnswerID + 1);
  answers[questionID].setQuestionID(questionID);
  answers[questionID].setAnswerContent(newAnswerContent);
  int check = 0;
  do {
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      break;
    }
  } while (check != -1);
}
void _QUESTIONS_::deleteQuestion(const account &acc, map<int, answer> &answers) {
  cout << "* Delete Question *" << endl;
  int questionID = -1;
  bool isMine;
  do {
    isMine = false;
    cout << "\t" << "Enter Question ID (or -1 to go back): ";
    cin >> questionID;
    if (questionID == -1) {
      break;
    }
    for (auto &qs: questions) {
      if (qs.second.getID() == questionID && qs.second.getUserFrom(false) == acc.getUsername()) {
        isMine = true;
        break;
      }
    }
    if (!isMine) {
      cout << "Please enter question ID belongs to you!" << endl;
    }
  } while (!isMine);
  if (questionID == -1) {
    return;
  }
  vector<int> deletedIDs;
  if (questionsThreads.count(questionID)) {
    deletedIDs = questionsThreads[questionID];
    questionsThreads.erase(questionID);
  } else {
    deletedIDs.push_back(questionID);
    for (auto &x: questionsThreads) {
      vector<int> &v = x.second;
      for (int i = 0; i < (int) v.size(); ++i) {
        if (questionID == v[i]) {
          answers.erase(questionID);
          v.erase(v.begin() + i);
          break;
        }
      }
    }
    for (const auto &x : deletedIDs) {
      answers.erase(x);
      questions.erase(x);
    }
  }
  int check = 0;
  do {
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      break;
    }
  } while (check != -1);
}
void _QUESTIONS_::showFeed(map<int, answer> &answers) const {
  cout << "* Feed *" << endl;
  for (auto &qs: questions) {
    if (qs.second.getThreadID() != -1) {
      cout << "Thread ID (" << qs.second.getThreadID() << ")";
    }
    cout << "\t" << "Question (ID: " << qs.second.getID() << "): " << qs.second.getQuestionContent() << endl;
    cout << "\t" << "From: " << qs.second.getUserFrom(true) << ", To: " << qs.second.getUserTo() << endl;
    string answerContent;
    for (auto &ans: answers) {
      if (ans.second.getQuestionID() == qs.second.getID()) {
        answerContent = ans.second.getAnswerContent();
      }
    }
    cout << "\t" << "Answer: " << answerContent << endl;
    cout << endl;
  }
  int check = 0;
  do {
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      break;
    }
  } while (check != -1);
}
//////////////////////////////////////////////////

////////////////// ANSWERS SYSTEM //////////////////
_ANSWERS_::_ANSWERS_() : lastID(-1) {}
void _ANSWERS_::loadAnswers() {
  answers.clear();
  lastID = 0;
  ifstream answerRead(ans_path);
  if (!answerRead) {
    cerr << "Open answers.txt Failed\n";
    exit(0);
  }
  string line;
  while (getline(answerRead, line)) {
    vector<string> data = split(line);
    answers[toInt(data[1])] = answer(toInt(data[0]), toInt(data[1]), data[2]);
    lastID = max(lastID, toInt(data[0]));
  }
  answerRead.close();
}
void _ANSWERS_::updateAnswers() {
  ofstream output(ans_path);
  for (auto &ans: answers) {
    string log = to_string(ans.second.getAnswerID()) + ";" + to_string(ans.second.getQuestionID()) + ";"  + ans.second.getAnswerContent();
    output << log << endl;
  }
  output.close();
}
map<int, answer> &_ANSWERS_::getAnswers() {
  return answers;
}
int _ANSWERS_::getLastID() {
  return lastID;
}
//////////////////////////////////////////////////

////////////////// MAIN SYSTEM //////////////////
void _SYSTEM_::loadData(bool resetUsersQuestions = false) {
  accountsSystem.loadAccounts();
  questionsSystem.loadQuestions();
  answersSystem.loadAnswers();
  if (resetUsersQuestions) {
    resetQuestions();
  }
}
void _SYSTEM_::updateData() {
  accountsSystem.updateAccounts();
  questionsSystem.updateQuestions();
  answersSystem.updateAnswers();
}
void _SYSTEM_::resetQuestions() {
  const auto &questionsFromMe = accountsSystem.getMyAccount().getQuestionsFromMe();
  const auto &questionsToMe = accountsSystem.getMyAccount().getQuestionsThreads();
  accountsSystem.ReloadQuestions(questionsFromMe, questionsToMe);
}
void _SYSTEM_::startMenu() {
  cout << "Menu:" << endl;
  cout << "\t" << "1: Login" << endl;
  cout << "\t" << "2: Register" << endl;
  string operationMsg = "Please enter operation number: ";
  int operationNumber = -1;
  do {
    cout << operationMsg;
    cin >> operationNumber;
    if (operationNumber != 1 && operationNumber != 2) {
      cout << "Invalid operation number!" << endl;
    }
  } while (operationNumber != 1 && operationNumber != 2);
  cout << endl;
  if (operationNumber == 1) {
    accountsSystem.loginAccount();
  } else if (operationNumber == 2) {
    accountsSystem.registerAccount();
  }
}
void _SYSTEM_::run() {
  loadData(false);
  startMenu();
  resetQuestions();
  while (true) {
    updateData();
    loadData(true);
    cout << "Menu:" << endl;
    cout << "\t" << "1: Show questions to me" << endl;
    cout << "\t" << "2: Show questions from me" << endl;
    cout << "\t" << "3: Answer question" << endl;
    cout << "\t" << "4: Delete question" << endl;
    cout << "\t" << "5: Ask question" << endl;
    cout << "\t" << "6: List users" << endl;
    cout << "\t" << "7: Feed" << endl;
    cout << "\t" << "8: Logout" << endl;

    string operationMsg = "Please enter operation number: ";
    int operationNumber;
    do {
      cout << operationMsg;
      cin >> operationNumber;
      if (operationNumber > 8 || operationNumber < 1) {
        cout << "Invalid operation number!" << endl;
      }
    } while (operationNumber > 8 || operationNumber < 1);
    cout << endl;
    if (operationNumber == 1) {
      questionsSystem.showQuestionToUser(accountsSystem.getMyAccount(), answersSystem.getAnswers());
    } else if (operationNumber == 2) {
      questionsSystem.showQuestionsFromUser(accountsSystem.getMyAccount(), answersSystem.getAnswers());
    } else if (operationNumber == 3) {
      questionsSystem.answerQuestion(accountsSystem.getMyAccount(), answersSystem.getAnswers(), answersSystem.getLastID());
      updateData();
    } else if (operationNumber == 4) {
      questionsSystem.deleteQuestion(accountsSystem.getMyAccount(), answersSystem.getAnswers());
      resetQuestions();
      updateData();
    } else if (operationNumber == 5) {
      questionsSystem.askQuestion(accountsSystem.getMyAccount(), accountsSystem.getAccounts());
      updateData();
    } else if (operationNumber == 6) {
      accountsSystem.listAccounts();
    } else if (operationNumber == 7) {
      questionsSystem.showFeed(answersSystem.getAnswers());
    } else if (operationNumber == 8) {
      accountsSystem.logoutAccount();
      break;
    }
  }
  run();
}
//////////////////////////////////////////////////