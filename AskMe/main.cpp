//
// Created by Saifaldin Elabyad on 23/08/2023.
//

#include "askme.h"
#define acc_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/askme/accounts.txt"
#define qus_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/askme/questions.txt"
#define ans_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/askme/answers.txt"

vector<account> accounts;
account myAccount;
vector<question> questions;
vector<answer> answers;
void loadData() {
  accounts.clear();
  ifstream acc_input(acc_path);
  if (!acc_input) {
    cerr << "Open accounts.txt Failed\n";
    system("pause");
    exit(0);
  }
  int acc_id = 0, allowAnon = 0;
  string user, pass;
  while (acc_input >> acc_id >> allowAnon >> user >> pass) {
    accounts.emplace_back(account(acc_id, allowAnon, user, pass));
  }
  acc_input.close();

  questions.clear();
  ifstream qus_input(qus_path);
  if (!qus_input) {
    cerr << "Open questions.txt Failed\n";
    system("pause");
    exit(0);
  }
  int qus_id = 0, isanon = 0;
  string userfrom, userto, qus;
  while (qus_input >> qus_id >> userfrom >> userto >> isanon) {
    getline(qus_input >> ws, qus);
    questions.emplace_back(question(qus_id, userfrom, userto, isanon, qus));
  }
  qus_input.close();

  answers.clear();
  ifstream ans_input(ans_path);
  if (!ans_input) {
    cerr << "Open answers.txt Failed\n";
    system("pause");
    exit(0);
  }
  int ans_id = 0, aqus_id = 0;
  string ans;
  while (ans_input >> ans_id >> aqus_id) {
    getline(ans_input >> ws, ans);
    answers.emplace_back(answer(ans_id, aqus_id, ans));
  }
  ans_input.close();
}
void loginScreen();
void showMainMenu();

void logoutFunction() {
  accounts.clear();
  myAccount.logout();
  questions.clear();
  answers.clear();

  cout << "You have successfully logged out." << endl;
  cout << endl;
  return loginScreen();
}

void showFeed() {
  cout << "* Feed *" << endl;
  bool isFirst = true;
  for (auto &qs: questions) {
    if (isFirst) {
      isFirst = false;
      continue;
    }
    cout << "\t" << "Question (ID: " << qs.getID() << "): " << qs.getContent() << endl;
    cout << "\t" << "From: " << qs.getUserFrom(true) << ", To: " << qs.getUserTo() << endl;
    string answer;
    for (auto &ans: answers) {
      if (ans.getQuestionID() == qs.getID()) {
        answer = ans.getAnswer();
      }
    }
    cout << "\t" << "Answer: " << answer << endl;
    cout << endl;
  }
  int check = 0;
  bool isGoBack;
  do {
    isGoBack = false;
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      isGoBack = true;
      break;
    }
  } while (check != -1);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
}

void listUsers() {
  cout << "* Users List *" << endl;
  bool isFirst = true;
  for (auto &acc: accounts) {
    if (isFirst) {
      isFirst = false;
      continue;
    }
    cout << "\t" << "ID: " << acc.getAccountID() << ", Username: " << acc.getUsername() << endl;
  }
  cout << endl;
  int check = 0;
  bool isGoBack;
  do {
    isGoBack = false;
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      isGoBack = true;
      break;
    }
  } while (check != -1);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
}

void askQuestion() {
  cout << "* Ask Question *" << endl;
  account askedOne;
  string username = "";
  bool isExist, isGoBack;
  do {
    isExist = false;
    isGoBack = false;
    cout << "\t" << "Enter the username you want ask (or -1 to go back): ";
    cin >> username;
    if (username == "-1") {
      isGoBack = true;
      break;
    }
    for (auto &acc: accounts) {
      if (username == acc.getUsername()) {
        username = acc.getUsername();
        askedOne = acc;
        isExist = true;
        break;
      }
    }
    if (!isExist) {
      cout << "\t" << "Username not found! Try Again." << endl;
    } else {
      if (username == myAccount.getUsername()) {
        cout << "\t" << "You can't ask yourself!" << endl;
        isExist = false;
      }
    }
  } while (!isExist);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
  int isAnon = 0;
  if (askedOne.getAllowAnon() == 0) {
    cout << "\t" << "NOTE: this person does not allow anonymous questions!" << endl;
  } else {
    cout << "\t" << "Anonymous question (1 for yes, 0 for no): ";
    cin >> isAnon;
  }
  cout << "\t" << "Enter question content: ";
  string quest;
  getline(cin >> ws, quest);

  fstream qus_in(qus_path, std::ios::in | std::ios::out);
  if (!qus_in) {
    cerr << "Open questions.txt Failed\n";
    system("pause");
    exit(0);
  }
  qus_in.seekp(0);
  int lastID = questions.front().getID() + 1;
  qus_in << lastID;
  qus_in.close();
  lastID = questions.back().getID() + 1;
  ofstream qus_out(qus_path, ios::app);
  if (!qus_out) {
    cerr << "Open questions.txt Failed\n";
    system("pause");
    exit(0);
  }
  string userfrom = myAccount.getUsername();
  string log = to_string(lastID) + " " + userfrom + " " + username + " " + to_string(isAnon) + " " + quest;
  qus_out << endl << log;
  qus_out.close();

  fstream ans_in(ans_path, std::ios::in | std::ios::out);
  if (!ans_in) {
    cerr << "Open answers.txt Failed\n";
    system("pause");
    exit(0);
  }
  ans_in.seekp(0);
  int lastAnsID = answers.back().getID() + 1;
  ans_in << questions.front().getID() + 1;
  ans_in.close();
  ofstream ans_write(ans_path, ios::app);
  log = to_string(lastAnsID) + " " + to_string(lastID) + " Not Answered Yet";
  ans_write << endl << log;
  ans_write.close();
  questions.emplace_back(question(lastID, userfrom, username, isAnon, quest));
  answers.emplace_back(answer(lastAnsID, lastID, "Not Answered Yet"));
  cout << "Question (ID: " << lastID << ") " << " sent successfully to " << username << "." << endl;
  int check = 0;
  do {
    isGoBack = false;
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      isGoBack = true;
      break;
    }
  } while (check != -1);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
}

void deleteQuestions() {
  cout << "* Delete Question *" << endl;
  int q_id = -1;
  string ques;
  bool isMine, isGoBack;
  do {
    isMine = false;
    isGoBack = false;
    cout << "\t" << "Enter Question ID (or -1 to go back): ";
    cin >> q_id;
    if (q_id == -1) {
      isGoBack = true;
      break;
    }
    int i = 0;
    for (auto &qs: questions) {
      if (qs.getID() == q_id && qs.getUserFrom(false) == myAccount.getUsername()) {
        isMine = true;
        int j = 0;
        for (auto &ans: answers) {
          if (ans.getQuestionID() == q_id) {
            answers.erase(answers.begin() + j);
          }
          j++;
        }
        questions.erase(questions.begin() + i);
        break;
      }
      i++;
    }
    if (!isMine) {
      cout << "Please Enter Question ID Belongs To You!" << endl;
    }
  } while (!isMine);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
  ofstream qus_write(qus_path);
  string log = to_string(questions.front().getID() - 1) + " UserFrom UserTo 0 Content";
  qus_write << log;
  bool isFirst = true;
  for (auto &qus: questions) {
    if (isFirst) {
      isFirst = false;
      continue;
    }
    log = to_string(qus.getID()) + " " + qus.getUserFrom(false) + " " + qus.getUserTo() + " " + to_string(qus.getIsAnon()) + " " + qus.getContent();
    qus_write << endl << log;
  }
  qus_write.close();

  ofstream ans_write(ans_path);
  log = to_string(answers.front().getID() - 1) + " 0 Answers";
  ans_write << log;
  isFirst = true;
  for (auto &ans: answers) {
    if (isFirst) {
      isFirst = false;
      continue;
    }
    log = to_string(ans.getID()) + " " + to_string(ans.getQuestionID()) + " " + ans.getAnswer();
    ans_write << endl << log;
  }
  ans_write.close();
  int check = 0;
  do {
    isGoBack = false;
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      isGoBack = true;
      break;
    }
  } while (check != -1);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
}

void answerQuestions() {
  cout << "* Answer Question *" << endl;
  int q_id = -1;
  string ques, from, ansr;
  bool isMine, isGoBack;
  do {
    isMine = false;
    isGoBack = false;
    cout << "\t" << "Enter question id (or -1 to go back): ";
    cin >> q_id;
    if (q_id == -1) {
      isGoBack = true;
      break;
    }
    for (auto &qs: questions) {
      if (qs.getID() == q_id && qs.getUserTo() == myAccount.getUsername()) {
        ques = qs.getContent();
        from = qs.getUserFrom(true);
        isMine = true;
        break;
      }
    }
    if (!isMine) {
      cout << "Please enter question id belongs to you!" << endl;
    } else {
      for (auto &ans: answers) {
        if (ans.getQuestionID() == q_id) {
          ansr = ans.getAnswer();
          break;
        }
      }
    }
  } while (!isMine);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
  cout << "\t" << "Question (ID: " << q_id << "): " << ques << endl;
  cout << "\t" << "From: " << from << endl;
  cout << "\t" << "Answer: " << ansr << endl;
  cout << endl;
  string new_ans;
  cout << "Enter your answer (answer will be overwrote or -1 to go back): ";
  getline(cin >> ws, new_ans);
  if (new_ans == "-1") {
    isGoBack = true;
  }
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
  for (auto &ans: answers) {
    if (ans.getQuestionID() == q_id) {
      ans.setAnswer(new_ans);
      break;
    }
  }
  ofstream ans_write(ans_path);
  string log = to_string(answers.front().getID()) + " 0 Answers";
  ans_write << log;
  bool isFirst = true;
  for (auto &ans: answers) {
    if (isFirst) {
      isFirst = false;
      continue;
    }
    log = to_string(ans.getID()) + " " + to_string(ans.getQuestionID()) + " " + ans.getAnswer();
    ans_write << endl << log;
  }
  ans_write.close();
  int check = 0;
  do {
    isGoBack = false;
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      isGoBack = true;
      break;
    }
  } while (check != -1);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
}

void showMyQuestions() {
  cout << "* My Questions *" << endl;
  for (auto &qs: questions) {
    if (qs.getUserFrom(false) == myAccount.getUsername()) {
      cout << "\t" << "Question (ID: " << qs.getID() << "): " << qs.getContent() << endl;
      cout << "\t" << "To: " << qs.getUserTo() << endl;
      string answer;
      for (auto &ans: answers) {
        if (ans.getQuestionID() == qs.getID()) {
          answer = ans.getAnswer();
        }
      }
      cout << "\t" << "Answer: " << answer << endl;
      cout << endl;
    }
  }
  int check = 0;
  bool isGoBack;
  do {
    isGoBack = false;
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      isGoBack = true;
      break;
    }
  } while (check != -1);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
}

void showQuestionsToMe() {
  cout << "* Question Sent To Me *" << endl;
  for (auto &qs: questions) {
    if (qs.getUserTo() == myAccount.getUsername()) {
      cout << "\t" << "Question (ID: " << qs.getID() << "): " << qs.getContent() << endl;
      cout << "\t" << "From: " << qs.getUserFrom(true) << endl;
      string answer;
      for (auto &ans: answers) {
        if (ans.getQuestionID() == qs.getID()) {
          answer = ans.getAnswer();
        }
      }
      cout << "\t" << "Answer: " << answer << endl;
      cout << endl;
    }
  }
  int check = 0;
  bool isGoBack;
  do {
    isGoBack = false;
    cout << "Enter -1 to go back: ";
    cin >> check;
    if (check == -1) {
      isGoBack = true;
      break;
    }
  } while (check != -1);
  if (isGoBack) {
    cout << endl;
    return showMainMenu();
  }
}

void showMainMenu() {
  cout << "Menu:" << endl;
  cout << "\t" << "1: Show questions sent to me" << endl;
  cout << "\t" << "2: Show my questions" << endl;
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
    if (operationNumber != 1 && operationNumber != 2 && operationNumber != 3 && operationNumber != 4 && operationNumber != 5 && operationNumber != 6 && operationNumber != 7 && operationNumber != 8) {
      cout << "Invalid operation number!" << endl;
    }
  } while (operationNumber != 1 && operationNumber != 2 && operationNumber != 3 && operationNumber != 4 && operationNumber != 5 && operationNumber != 6 && operationNumber != 7 && operationNumber != 8);
  cout << endl;
  if (operationNumber == 1) {
    showQuestionsToMe();
  } else if (operationNumber == 2) {
    showMyQuestions();
  } else if (operationNumber == 3) {
    answerQuestions();
  } else if (operationNumber == 4) {
    deleteQuestions();
  } else if (operationNumber == 5) {
    askQuestion();
  } else if (operationNumber == 6) {
    listUsers();
  } else if (operationNumber == 7) {
    showFeed();
  } else if (operationNumber == 8) {
    logoutFunction();
  }
}

void loginFunction() {
  string username, password;
  bool isCorrect, userExist, isGoBack;
  do {
    isCorrect = false;
    userExist = false;
    isGoBack = false;
    cout << "Enter your username (or -1 to go back): ";
    cin >> username;
    if (username == "-1") {
      isGoBack = true;
      break;
    }
    cout << "Enter your password: ";
    cin >> password;
    for (auto &acc: accounts) {
      if (username == acc.getUsername()) {
        userExist = true;
        if (password == acc.getPassword()) {
          isCorrect = true;
          myAccount = acc;
          break;
        }
      }
    }
    if (userExist) {
      if (!isCorrect) {
        cout << "Password is wrong! Try Again." << endl;
      }
    } else {
      cout << "Username does not exist! Try Again." << endl;
    }
  } while (!isCorrect);
  if (isGoBack) {
    cout << endl;
    return loginScreen();
  }
  cout << "You have successfully logged in." << endl;
  showMainMenu();
}

void registerFunction() {
  bool isUsed, isGoBack;
  string username;
  do {
    isUsed = false;
    isGoBack = false;
    cout << "Enter your username (or -1 to go back): ";
    cin >> username;
    if (username == "-1") {
      isGoBack = true;
      break;
    }
    for (auto &acc: accounts) {
      if (acc.getUsername() == username) {
        isUsed = true;
        cout << "Username is used before! Please try another one." << endl;
        break;
      }
    }
  } while (isUsed);
  if (isGoBack) {
    cout << endl;
    return loginScreen();
  }
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

  fstream acc_in(acc_path, std::ios::in | std::ios::out);
  acc_in.seekp(0);
  int lastID = accounts[0].getAccountID() + 1;
  acc_in << lastID;
  acc_in.close();
  lastID = accounts.back().getAccountID() + 1;
  ofstream acc_out(acc_path, ios::app);
  string log = to_string(lastID) + " " + to_string(allowAnon) + " " + username + " " + password;
  acc_out << endl << log;
  acc_out.close();
  cout << "Account with ID: "<< lastID <<" created successfully" << endl << endl;
  myAccount = account(lastID, allowAnon, username, password);
  accounts.emplace_back(myAccount);
  showMainMenu();
}

void loginScreen() {
  loadData();
  cout << "Menu:" << endl;
  cout << "\t" << "1: Login" << endl;
  cout << "\t" << "2: Register" << endl;

  string operationMsg = "Please enter operation number: ";
  int operationNumber;
  do {
    cout << operationMsg;
    cin >> operationNumber;
    if (operationNumber != 1 && operationNumber != 2) {
      cout << "Invalid operation number!" << endl;
    }
  } while (operationNumber != 1 && operationNumber != 2);
  cout << endl;

  if (operationNumber == 1) {
    loginFunction();
  } else if (operationNumber == 2) {
    registerFunction();
  }
}

int main() {
  loginScreen();
  return 0;
}
