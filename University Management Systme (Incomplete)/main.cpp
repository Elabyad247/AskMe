#include "university.h"

#define accounts_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/University/accounts.txt"
#define courses_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/University/courses.txt"
#define employees_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/University/employees.txt"
#define students_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/University/students.txt"

vector<Account> accounts;
vector<Course> courses;
vector<Student> students;
vector<Employee> employees;
Account currentAccount;

vector<string> stringSplitter(const string &str, const string &delimiter = ";") {
  string s = str;
  vector<string> strings;
  int pos;
  string sub;
  while ((pos = (int)s.find(delimiter)) != -1) {
    sub = s.substr(0, pos);
    strings.push_back(sub);
    s.erase(0, pos + delimiter.length());
  }
  strings.push_back(s);
  return strings;
}
int strToInt(const string &str) {
  istringstream iss(str);
  int num;
  iss >> num;
  return num;
}
void appendFile(string &path, string &log) {
  ofstream output(path, ios::app);
  output << log << endl;
  output.close();
}

void showLoginMenu();

void Login(string accountType) {

  cout << "< " << accountType << " Login >" << endl;
  string username, password;
  bool isCorrect, userExist, isGoBack;
  do {
    isCorrect = false;
    userExist = false;
    isGoBack = false;
    cout << "\t" << "Enter your username (or -1 to go back): ";
    cin >> username;
    if (username == "-1") {
      isGoBack = true;
      break;
    }
    cout << "\t" << "Enter your password: ";
    cin >> password;
    for (auto &acc: accounts) {
      if (username == acc.getUsername() && accountType == acc.getAccountType()) {
        userExist = true;
        if (password == acc.getPassword()) {
          isCorrect = true;
          currentAccount = acc;
          break;
        }
      }
    }
    if (userExist) {
      if (!isCorrect) {
        cout << "\t" << "Password is wrong! Try Again." << endl;
      }
    } else {
      cout << "\t" << "Username does not exist! Try Again." << endl;
    }
  } while (!isCorrect);
  if (isGoBack) {
    cout << endl;
    return showLoginMenu();
  }
  cout << "\t" << "You have successfully logged in." << endl << endl;
}

void showLoginMenu() {
  cout << "< UNIVERSITY SYSTEM >" << endl;
  cout << "\t" << "1: Student" << endl;
  cout << "\t" << "2: Employee" << endl;
  cout << "\t" << "3: Admin" << endl;

  string operationMsg = "Enter operation number: ";
  int operationNumber;
  do {
    cout << operationMsg;
    cin >> operationNumber;
    if (operationNumber > 3 || operationNumber < 1) {
      cout << "Invalid operation number!" << endl;
    }
  } while (operationNumber > 3 || operationNumber < 1);
  cout << endl;
  if (operationNumber == 1) {
    Login("Student");
  } else if (operationNumber == 2) {
    Login("Employee");
  } else if (operationNumber == 3) {
    Login("Admin");
  }
}

int main() {

  showLoginMenu();
  return 0;
}
