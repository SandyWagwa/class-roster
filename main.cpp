#include <iostream>
#include "roster.h"


using namespace std;


int main() {
    // Print course title, programming language, WGU student ID, and Name
    std::cout << "Course Title: C867 Scripting and Programming - Applications" << std::endl;
    std::cout << "Language: C++" << std::endl;//Specifies the Student ID
    std::cout << "Student ID: 111111" << std::endl;
    std::cout << "Name: fName lName" << std::endl; // Replace with your name

    // Create an instance of the Roster class 
    Roster classRoster;
    //classRoster.addStudent("A6","Kenne","Nburu","ken@g mail.com",55,4,2,2,"SOFTWARE");
      // Add each student to classRoster
    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,John, Alex,johnsam@gmail.com,25,35,45,55,SOFTWARE"
    };

    for (const auto& data : studentData) {
        // Parse student data directly in the loop
        string temp = data;
        string token;
        string studentInfo[9];
        int index = 0;
        size_t pos = 0;
        while ((pos = temp.find(',')) != string::npos) {
            token = temp.substr(0, pos);
            studentInfo[index++] = token;
            temp.erase(0, pos + 1);
        }
        studentInfo[index] = temp;

        // Extracting data from the studentdata
        string Studentid = studentInfo[0];
        string FirstName = studentInfo[1];
        string LastName = studentInfo[2];
        string Email = studentInfo[3];
        int Age = stoi(studentInfo[4]);
        int DaysinCourse1 = stoi(studentInfo[5]);
        int DaysinCourse2 = stoi(studentInfo[6]);
        int DaysinCourse3 = stoi(studentInfo[7]);
        DegreeProgram degreeProgram{};
        if (studentInfo[8] == "SECURITY")
            degreeProgram = DegreeProgram::SECURITY;
        else if (studentInfo[8] == "NETWORK")
            degreeProgram = DegreeProgram::NETWORK;
        else if (studentInfo[8] == "SOFTWARE")
            degreeProgram = DegreeProgram::SOFTWARE;

        // Add student to roster
        classRoster.addStudent(Studentid, FirstName, LastName, Email, Age, DaysinCourse1, DaysinCourse2, DaysinCourse3, degreeProgram);
    }

    // Printing all student data

    std::cout << "\nDisplaying all students:" << std::endl;
    classRoster.printAll();

    // Printing invalid emails
    std::cout << "\nDisplaying Invalid Emails:" << std::endl;
    classRoster.printInvalidEmails();

    // Printing average days in course for each student
    std::cout << "\nStudent id : Average Days in Course:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::string Studentid = "A" + std::to_string(i);
        classRoster.printAverageDaysInCourse(Studentid);
    }

    // Printing students by degree program
    std::cout << "\nShowing Students in Degree Program: SOFTWARE\n" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    // Remove student A3
    std::cout << "\nRemoving A3:" << std::endl;
    classRoster.remove("A3");

    classRoster.printAll();

    // Try to remove student A3 again
    std::cout << "\nRemoving student A3 again" << std::endl;
    std::cout << "\n The student with ID: A3 was not found" << std::endl;
    classRoster.remove("A3");

    std::cout << "\n Done" << std::endl;
    return 0;
};