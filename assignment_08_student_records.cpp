// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Student name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Student ID: ";
    cin >> s.id;

    int scoreCount;
    cout << "How many scores? ";
    cin >> scoreCount;
    for (int i = 0; i < scoreCount; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }
    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }
    cout << fixed << setprecision(2);
    cout << "\n----------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" << setw(12) << "ID" << setw(25) << "Scores" << setw(10) << "Average" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for (const auto& s : students) {
        string scoreStr = "";
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoreStr += to_string((int)s.scores[i]) + (i == s.scores.size() - 1 ? "" : ", ");
        }
        double avg = calculateAverage(s.scores);
        cout << left << setw(20) << s.name << setw(12) << s.id << setw(25) << scoreStr << setw(10) << avg << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}

void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;
    for (const auto& s : students) {
        if (s.id == searchId) {
            double avg = calculateAverage(s.scores);
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << avg << endl;
            return;
        }
    }
    cout << "Error: Student ID " << searchId << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Error: Invalid choice. Please enter 1-4." << endl;
                break;
        }
    }

    return 0;
}
