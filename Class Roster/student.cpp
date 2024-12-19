#include "student.h"//header file
#include <iostream>
#include <string>

//identifies the degreeProgramToString variable
std::string degreeProgramToString(DegreeProgram degreeProgram) {
    switch (degreeProgram) {
    case SECURITY:
        return "SECURITY";
    case NETWORK:
        return "NETWORK";
    case SOFTWARE:
        return "SOFTWARE";
    default:
        return "UNKNOWN";
    }
}

// Constructors
Student::Student() {}
Student::Student(string Studentid, string FirstName, string LastName, string Email, int Age, int DaysinCourse[], DegreeProgram degreeProgram) {
    setStudentid(Studentid);
    setFirstName(FirstName);
    setLastName(LastName);
    setEmail(Email);
    setAge(Age);
    setDaysinCourse(DaysinCourse);
    setDegreeProgram(degreeProgram);

}

// Accessors (getters)
string Student::getStudentid() const {
    return Studentid;
}
string Student::getFirstName() const {
    return FirstName;
}
string Student::getLastName() const {
    return LastName;
}
string Student::getEmail() const {
    return Email;
}
int Student::getAge() const {
    return Age;
}
int* Student::getDaysinCourse() {
    return DaysinCourse;
}
DegreeProgram Student::getDegreeProgram()const {
    return degreeProgram;
}

// Mutators (setters)
void Student::setStudentid(string Studentid) {
    this->Studentid = Studentid;
}
void Student::setFirstName(string FirstName) {
    this->FirstName = FirstName;
}
void Student::setLastName(string LastName) {
    this->LastName = LastName;
}
void Student::setEmail(string Email) {
    this->Email = Email;
}
void Student::setAge(int Age) {
    this->Age = Age;
}
void Student::setDaysinCourse(int DaysinCourse[]) {
    for (int i = 0; i < 3; ++i) {
        this->DaysinCourse[i] = DaysinCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;

}

// Printing values in the student data
void Student::print() const {

    cout  << Studentid << "\t";
    cout  << FirstName << "\t";
    cout  << LastName << "\t";
    cout  << Email << "\t";
    cout  << Age << "\t";
    cout  << "{";
    for (int i = 0; i < 3; ++i) {
        cout << DaysinCourse[i];
        if (i < 2) {
            cout << ", ";
        }
    }
    cout << "}" << "\t";

    // Printing DegreeProgram
    cout << degreeProgramToString(degreeProgram) << endl;
}

