// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//

#include <iostream>
using namespace std;

void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }
    cout << "Fibonacci sequence: ";
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << (i == n - 1 ? "" : " ");
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isFibonacci(long long num) {
    if (num < 0) return false;
    long long a = 0, b = 1;
    while (a < num) {
        long long next = a + b;
        a = b;
        b = next;
    }
    return (a == num);
}

int main() {
    int terms;
    cout << "How many terms? ";
    if (cin >> terms) {
        if (terms <= 0) {
            cout << "Error: N must be a positive integer." << endl;
        } else {
            printFibonacci(terms);
        }
    }

    long long numToCheck;
    cout << "\nEnter a number to check: ";
    if (cin >> numToCheck) {
        if (isFibonacci(numToCheck)) {
            cout << numToCheck << " is a Fibonacci number." << endl;
        } else {
            cout << numToCheck << " is NOT a Fibonacci number." << endl;
        }
    }

    return 0;
}
