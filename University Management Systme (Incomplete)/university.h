//
// Created by Saifaldin Elabyad on 31/08/2023.
//

#ifndef OOP_UNIVERSITY_H_
#define OOP_UNIVERSITY_H_

#include <bits/stdc++.h>
using namespace std;

class Account {
 private:
  int accountID;
  string username;
  string password;
  string accountType;
 public:
  Account() : accountID(-1) {}
  Account(int accID, string &accUser, string &accPass, string &accType) {
    accountID = accID;
    username = accUser;
    password = accPass;
    accountType = accType;
  }
  int getAccountID() const {
    return accountID;
  }
  string getUsername() const {
    return username;
  }
  string getPassword() const {
    return password;
  }
  string getAccountType() const {
    return accountType;
  }
  bool isAdmin() const {
    return accountType == "Admin";
  }
  bool isStudent() const {
    return accountType == "Student";
  }
  bool isEmployee() const {
    return accountType == "Employee";
  }

  void setAccountType(string &accType) {
    accountType = accType;
  }
};

class Course {
 private:
  string courseCode;
  string courseName;
  int hours;
  int grade;
  int fullGrade;
  string letterGrade;

 public:
  Course() : hours(-1), grade(-1), fullGrade(-1) {}
  Course(string &cCode, string &cName, int cHours, int cGrade, int cFullGrade, string &cLetterGrade) {
    courseCode = cCode;
    courseName = cName;
    hours = cHours;
    grade = cGrade;
    fullGrade = cFullGrade;
    letterGrade = cLetterGrade;
  }

  string getCourseCode() {
    return courseCode;
  }
  string getCourseName() {
    return courseName;
  }
  int getHours() {
    return hours;
  }
  int getGrade() {
    return grade;
  }
  int getFullGrade() {
    return fullGrade;
  }
  double getPercentage() {
    return (grade * 100.0) / fullGrade;
  }

  void setHours(int cHours) {
    hours = cHours;
  }
  void setGrade(int cGrade) {
    grade = cGrade;
  }
  void setLetterGrade(string &cLetterGrade) {
    letterGrade = cLetterGrade;
  }

};

class Person {
 private:
  int nationalID;
  string firstName;
  string lastName;
  int age;
  string gender;

 public:
  Person() : nationalID(-1), age(-1) {}
  Person(int pID, string &pFirstName, string &pLastName, int pAge, string &pGender) {
    nationalID = pID;
    firstName = pFirstName;
    lastName = pLastName;
    age = pAge;
    gender = pGender;
  }

  int getNationalID() {
    return nationalID;
  }
  string getFirstName() {
    return firstName;
  }
  string getLastName() {
    return lastName;
  }
  string getFullName() {
    return firstName + " " + lastName;
  }
  int getAge() {
    return age;
  }
  string getGender() {
    return gender;
  }

  void increaseAge() {
    age += 1;
  }
};

class Student : public Person {
 private:
  int studentCode;
  double GPA;
  int currentLevel;
  int enrolledYear;
  string email;
  vector<Course> courses;

 public:
  Student() : studentCode(-1), GPA(-1), currentLevel(-1), enrolledYear(-1) {}
  Student(int sNationalID, string &sFirstName, string &sLastName, int sAge, string &sGender, int sCode, double sGPA, int sCurLevel, int sEnYear, string &sEmail, vector<Course> &sCourses)
  : Person(sNationalID, sFirstName, sLastName, sAge, sGender) {
    studentCode = sCode;
    GPA = sGPA;
    currentLevel = sCurLevel;
    enrolledYear = sEnYear;
    email = sEmail;
    courses = sCourses;
  }

  int getStudentCode() {
    return studentCode;
  }
  double getGPA() {
    return GPA;
  }
  int getCurrentLevel() {
    return currentLevel;
  }
  int getEnrolledYear() {
    return enrolledYear;
  }
  string getEmail() {
    return email;
  }
  vector<Course> getCourses() {
    return courses;
  }

  void setGPA(double nGPA) {
    GPA = nGPA;
  }
  void passLevel() {
    currentLevel += 1;
  }
  void setCourses(vector<Course> &sCourses) {
    courses = sCourses;
  }
};

class Employee : public Person {
 private:
    int employeeCode;
    double salary;
    int hiredYear;
    string phoneNumber;
    string email;
    string position;
    string department;
    string qualification;

 public:
  Employee() : employeeCode(-1), salary(-1), hiredYear(-1) {}
  Employee(int eNationalID, string &eFirstName, string &eLastName, int eAge, string &eGender, int eCode, double eSalary, int eHiredYear, string &ePhoneNumber,
           string &eEmail, string &ePosition, string &eDepartment, string &eQualification) : Person(eNationalID, eFirstName, eLastName, eAge, eGender) {
    employeeCode = eCode;
    salary = eSalary;
    hiredYear = eHiredYear;
    phoneNumber = ePhoneNumber;
    email = eEmail;
    position = ePosition;
    department = eDepartment;
    qualification = eQualification;
  }

  int getEmployeeCode() {
    return employeeCode;
  }
  double getSalary() {
    return salary;
  }
  int getHiredYear() {
    return hiredYear;
  }
  string getPhoneNumber() {
    return phoneNumber;
  }
  string getEmail() {
    return email;
  }
  string getPosition() {
    return position;
  }
  string getDepartment() {
    return department;
  }
  string getQualification() {
    return qualification;
  }

  void setSalary(double nSalary) {
    salary = nSalary;
  }
  void setPosition(string &nPosition) {
    position = nPosition;
  }
  void setDepartment(string &nDepartment) {
    department = nDepartment;
  }
  void setQualification(string &nQualification) {
    qualification = nQualification;
  }
};

#endif //OOP_UNIVERSITY_H_
