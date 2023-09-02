#include "bank.h"
#define customers_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Bank/customers.txt"
#define accounts_path "C:/Users/Saifaldin Elabyad/CLionProjects/OOP/Bank/accounts.txt"

vector<string> SplitString(const string &str, const string &delimiter = ";") {
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
int ToInt(const string &str) {
  istringstream iss(str);
  int num;
  iss >> num;

  return num;
}
void appendFile(string path, string log) {
  ofstream output(path, ios::app);
  output << log << endl;
  output.close();
}
template<typename T>
T random(set<T> const &st) {
  auto it = st.cbegin();
  int random = rand() % st.size();
  advance(it, random);
  return *it;
}
set<int> randomNumbers;
void numberGenerator(int low, int high) {
  for (int i = low; i <= high; i++) {
    randomNumbers.insert(i);
  }
}

int customer::customerCounter = 0;
int account::accountCounter = 0;
vector<customer> customers;
vector<account> accounts;

void showMainMenu();
void loadData() {
  numberGenerator(10000, 99999);
  customers.clear();
  ifstream customers_input(customers_path);
  if (!customers_input) {
    cerr << "Open customers.txt Failed\n";
    system("pause");
    exit(0);
  }
  string line;
  while (getline(customers_input, line)) {
    vector<string> data = SplitString(line);
    int uID = ToInt(data[0]);
    string uName = data[1];
    string uPhone = data[2];
    string uAddress = data[3];
    int uAccountNumber = ToInt(data[4]);
    customers.emplace_back(customer(uID, uName, uPhone, uAddress, uAccountNumber));
  }
  customers_input.close();
  customer::customerCounter = customers.size();

  accounts.clear();
  ifstream accounts_input(accounts_path);
  if (!accounts_input) {
    cerr << "Open accounts.txt Failed\n";
    system("pause");
    exit(0);
  }
  while (getline(accounts_input, line)) {
    vector<string> data = SplitString(line);
    int aID = ToInt(data[0]);
    int cID = ToInt(data[1]);
    int accountNumber = ToInt(data[2]);
    randomNumbers.erase(accountNumber);
    int aBalance = ToInt(data[3]);
    string aType = data[4];
    accounts.emplace_back(account(aID, cID, accountNumber, aBalance, aType));
  }
  accounts_input.close();
  account::accountCounter = accounts.size();
}
void updateDatabase() {
  ofstream cust_write(customers_path);
  for (auto &cust: customers) {
    string log = to_string(cust.getID()) + ";" + cust.getName() + ";" + cust.getPhone() + ";" + cust.getAddress() + ";" + to_string(cust.getAccountNumber());
    cust_write << log << endl;
  }
  cust_write.close();

  ofstream acc_write(accounts_path);
  for (auto &acc: accounts) {
    string log = to_string(acc.getID()) + ";" + to_string(acc.getCustomerID()) + ";" + to_string(acc.getAccountNumber()) + ";" + to_string(acc.getBalance()) + ";" + acc.getType();
    acc_write << log << endl;
  }
  acc_write.close();
}
void addCustomer() {
  cout << "< Add Customer >" << endl;
  string name;
  cout << "\t" << "Enter customer's name (or -1 to go back): ";
  getline(cin >> ws, name);
  if (name == "-1") {
    cout << endl;
    return showMainMenu();
  }
  string phone;
  cout << "\t" << "Enter customer's phone: ";
  getline(cin >> ws, phone);
  string address;
  cout << "\t" << "Enter customer's address: ";
  getline(cin >> ws, address);

  int newID = (!customers.empty()) ? (customers.back().getID() + 1) : 1;
  string log = to_string(newID) + ";" + name + ";" + phone + ";" + address + ";0";
  appendFile(customers_path, log);

  customers.emplace_back(customer(newID, name, phone, address, 0));
  cout << "\t" <<  "Customer with ID: "<< newID <<" added successfully, Total number of customers: " << customer::customerCounter << endl;
  cout << endl;

  showMainMenu();
}
void createAccount() {
  cout << "< Create Account >" << endl;
  int cID = -1;
  bool custExist, hasAccount;
  do {
    custExist = false;
    hasAccount = false;
    cout << "\t" << "Enter customer's id (or -1 to go back): ";
    cin >> cID;
    if (cID == -1) {
      cout << endl;
      return showMainMenu();
    }
    for (auto &cust: customers) {
      if (cID == cust.getID()) {
        custExist = true;
        if (cust.getAccountNumber() != 0) {
          hasAccount = true;
          break;
        }
        break;
      }
    }
    if (!custExist) {
      cout << "\t" << "Customer does not exist! Try Again." << endl;
    } else {
      if (hasAccount) {
        cout << "\t" << "This customer already has an account!" << endl;
      }
    }
  } while (!custExist || hasAccount);
  string aType;
  cout << "\t" << "Enter type of account: ";
  getline(cin >> ws, aType);
  int aBalance = 0;
  do {
    cout << "\t" << "Enter account's initial balance: ";
    cin >> aBalance;
    if (aBalance < 0) {
      cout << "\t" << "You cannot enter a negative balance!" << endl;
    }
  } while (aBalance < 0);
  int accountNumber = random(randomNumbers);
  randomNumbers.erase(accountNumber);

  int newID = (!accounts.empty()) ? (accounts.back().getID() + 1) : 1;
  string log = to_string(newID) + ";" + to_string(cID) + ";" + to_string(accountNumber) + ";" + to_string(aBalance) + ";" + aType;
  appendFile(accounts_path, log);
  accounts.emplace_back(account(newID, cID, accountNumber, aBalance, aType));
  for (auto &cust: customers) {
    if (cust.getID() == cID) {
      cust.setAccountNumber(accountNumber);
      break;
    }
  }
  cout << "\t" << "Account with ID: "<< newID <<" added successfully, Total number of accounts: " << account::accountCounter << endl;
  cout << endl;

  updateDatabase();

  showMainMenu();
}
void depositToAccount() {
  cout << "< Deposit To Account >" << endl;
  int accountNumber = 0;
  bool accountExist;
  do {
    accountExist = false;
    cout << "\t" << "Enter account number (or -1 to go back): ";
    cin >> accountNumber;
    if (accountNumber == -1) {
      cout << endl;
      return showMainMenu();
    }
    for (auto &acc: accounts) {
      if (accountNumber == acc.getAccountNumber()) {
        accountExist = true;
        break;
      }
    }
    if (!accountExist) {
      cout << "\t" << "Account does not exist! Try Again." << endl;
    }
  } while (!accountExist);
  int amount = 0;
  do {
    cout << "\t" << "Enter the amount you want to deposit: ";
    cin >> amount;
    if (amount <= 0) {
      cout << "\t" << "You cannot deposit a negative (or zero) amount!" << endl;
    }
  } while (amount <= 0);
  for (auto &acc: accounts) {
    if (accountNumber == acc.getAccountNumber()) {
      acc.deposit(amount);
      break;
    }
  }

  updateDatabase();

  showMainMenu();
}
void withdrawFromAccount() {
  cout << "< Withdraw From Account >" << endl;
  int accountNumber = 0;
  bool accountExist;
  do {
    accountExist = false;
    cout << "\t" << "Enter account number (or -1 to go back): ";
    cin >> accountNumber;
    if (accountNumber == -1) {
      cout << endl;
      return showMainMenu();
    }
    for (auto &acc: accounts) {
      if (accountNumber == acc.getAccountNumber()) {
        accountExist = true;
        break;
      }
    }
    if (!accountExist) {
      cout << "\t" << "Account does not exist! Try Again." << endl;
    }
  } while (!accountExist);
  int amount = 0;
  do {
    cout << "\t" << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount <= 0) {
      cout << "\t" << "You cannot withdraw a negative (or zero) amount!" << endl;
    }
  } while (amount <= 0);

  for (auto &acc: accounts) {
    if (accountNumber == acc.getAccountNumber()) {
      acc.withdraw(amount);
      break;
    }
  }

  updateDatabase();

  showMainMenu();
}
void displayAccounts() {
  cout << "< Display Accounts >" << endl;
  for (auto &acc: accounts) {
    cout << "-------------------------------------------" << endl;
    cout << "\t" << "Account ID: " << acc.getID() << endl;
    cout << "\t" << "Customer ID: " << acc.getCustomerID() << endl;
    cout << "\t" << "Account Number: " << acc.getAccountNumber() << endl;
    cout << "\t" << "Account Balance: " << acc.getBalance() << endl;
    cout << "\t" << "Account Type: " << acc.getType() << endl;
  }
  cout << "-------------------------------------------" << endl << endl;

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
void exitProgram() {
  updateDatabase();
  customers.clear();
  accounts.clear();
  randomNumbers.clear();
  customer::customerCounter = 0;
  account::accountCounter = 0;
  cout << "-------------------EXIT-------------------";
  return;
}

void showMainMenu() {
  cout << "< BANK MANAGEMENT SYSTEM >" << endl;
  cout << "\t" << "1: Add Customer" << endl;
  cout << "\t" << "2: Create Account" << endl;
  cout << "\t" << "3: Deposit" << endl;
  cout << "\t" << "4: Withdraw" << endl;
  cout << "\t" << "5: Display Accounts" << endl;
  cout << "\t" << "0: Exit" << endl;

  string operationMsg = "Enter operation number: ";
  int operationNumber;
  do {
    cout << operationMsg;
    cin >> operationNumber;
    if (operationNumber > 5 || operationNumber < 0) {
      cout << "Invalid operation number!" << endl;
    }
  } while (operationNumber > 5 || operationNumber < 0);
  cout << endl;
  if (operationNumber == 1) {
    addCustomer();
  } else if (operationNumber == 2) {
    createAccount();
  } else if (operationNumber == 3) {
    depositToAccount();
  } else if (operationNumber == 4) {
    withdrawFromAccount();
  } else if (operationNumber == 5) {
    displayAccounts();
  } else if (operationNumber == 0) {
    exitProgram();
  }
}

int main() {
  loadData();
  showMainMenu();
  return 0;
}
