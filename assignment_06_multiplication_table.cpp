// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//

#include <iostream>
using namespace std;

void printSingleTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << i << "  =  " << num * i << endl;
    }
}

void printMultipleTables(int n) {
    for (int i = 1; i <= n; i++) {
        printSingleTable(i);
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    cout << "1. Single Multiplication Table" << endl;
    cout << "2. Multiplication Tables from 1 to N" << endl;
    cout << "Select option (1-2): ";
    if (!(cin >> choice)) return 0;

    if (choice == 1) {
        int num;
        cout << "Enter a number: ";
        if (cin >> num && num > 0) {
            printSingleTable(num);
        } else {
            cout << "Error: Input must be a positive integer." << endl;
        }
    } else if (choice == 2) {
        int n;
        cout << "Enter N: ";
        if (cin >> n && n > 0) {
            printMultipleTables(n);
        } else {
            cout << "Error: Input must be a positive integer." << endl;
        }
    } else {
        cout << "Invalid option." << endl;
    }

    return 0;
}
