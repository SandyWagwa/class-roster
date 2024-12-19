#pragma once
#include <string>
#include "student.h"

class Roster {
private:
    static const int MAX_STUDENTS = 5;
    int lastIndex; // index of the last student in classRosterArray
    Student* classRosterArray[5];

public:
    // Constructor
    Roster(); 

    // Destructor
    ~Roster(); // destructor to release memory allocated for student objects

    void addStudent(string Studentid, string FirstName, string LastName, string Email, int Age, int DaysinCourse1, int DaysinCourse2, int DaysinCourse3, DegreeProgram degreeProgram);

    //Defining functions to be use in the implementation in the roster class
    void addStudent(string Studentid, string FirstName, string LastName, string Email, int age, int DaysinCourse1, int DaysinCourse2, int DaysinCourse3, string degreeProgram);
    void remove(string Studentid);
    void printAll() const;
    void printAverageDaysInCourse(string Studentid) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    void printByDegreeProgram(string degreeProgram) const;

   
    Student* parseStudentData(string studentData);//parsing student data 
};


