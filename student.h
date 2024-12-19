//Function definition class for the student class
#pragma once
#include <string>
#include <unordered_map>
#include "degree.h"

using namespace std;

class Student {//create a class Student
private:
    std::string Studentid;
    std::string FirstName;
    std::string LastName;
    std::string Email;
    int Age;
    int DaysinCourse[3];

    DegreeProgram degreeProgram;
    std::unordered_map<std::string, DegreeProgram> programMap;


public:
    // Constructor
    Student(); // default constructor
    Student(string Studentid, string FirstName, string LastName, string Email, int Age, int DaysinCourse[], DegreeProgram DegreeProgram);

    // Getters
    string getStudentid() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int* getDaysinCourse();
    DegreeProgram getDegreeProgram() const;

    // Setters
    void setStudentid(string Studentid);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmail(string Email);
    void setAge(int Age);
    void setDaysinCourse(int DaysinCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Member function
    void print() const;
};
