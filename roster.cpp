#include "roster.h"
#include <iostream>
#include <string>
#include "roster.h" // Include the header file for Roster class
#include "degree.h" // Header file present for DegreeProgram enum

using namespace std;

// Constructor
Roster::Roster() {
    // Initialize classRosterArray
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    // Deallocate memory for each student object
    for (int i = 0; i < 5; ++i) {
        delete classRosterArray[i];
    }
}
void Roster::addStudent(string Studentid, string FirstName, string LastName, string Email, int Age, int DaysinCourse1, int DaysinCourse2, int DaysinCourse3, DegreeProgram degreeProgram)
{
    // Find an empty slot in the roster

    int index = -1;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            index = i;
            break;
        }

    }
    // Check if an empty slot is found
    int DaysInCourse[] = { DaysinCourse1, DaysinCourse2,DaysinCourse3 };
    //
    if (index != -1) {
        // Create a new Student object with the provided arguments

        classRosterArray[index] = new Student(Studentid, FirstName, LastName, Email, Age, DaysInCourse, degreeProgram);

    }
    else {
        // Handle the case where no empty slot is found
        cout << "Error: Roster is full. Cannot add more students." << endl;
    }
}
//Add to student
void Roster::addStudent(string studentid, string firstName, string lastName, string emailAddress, int age, int DaysinCourse1, int DaysinCourse2, int DaysinCourse3, string degreeProgram)
{

}

void Roster::remove(string Studentid) {
    bool found = false;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentid() == Studentid) {
            delete classRosterArray[i]; // Deallocate memory for the student object
            classRosterArray[i] = nullptr; // Set the pointer to nullptr
            found = true;
            break; // Exit loop after removing the student
        }
    }
}

void Roster::printAll() const {
    bool rosterEmpty = true; // Flag to check if the roster is empty
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
            rosterEmpty = false; // Roster is not empty if a student is found
        }
    }
}

// Function to calculate and print average days in course for a student identified by studentID
void Roster::printAverageDaysInCourse(string Studentid) const {
    bool found = false;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentid() == Studentid) {
            found = true;
            int* days = classRosterArray[i]->getDaysinCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            cout << "Student ID: " << Studentid << ", " << "average days in course is :"<<average << endl;
            break;
        }
    }
    if (!found) {
        cout << "The student with ID " << Studentid << " was not found." << endl;
    }
}

// Function to print invalid email addresses
void Roster::printInvalidEmails() const {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getEmail();
            if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
                cout << "Invalid email: " << email << endl;
            }
        }
    }
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{

    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
void Roster::printByDegreeProgram(string degreeProgram) const
{
}

Student* Roster::parseStudentData(string studentData)
{
    return nullptr;
}
