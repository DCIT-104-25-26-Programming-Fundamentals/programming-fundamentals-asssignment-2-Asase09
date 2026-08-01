// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
int modulus(int a, int b) { return a % b; }
double power(double base, double exp) { return pow(base, exp); }

int main() {
    int choice = 0;
    while (choice != 7) {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please select 1-7." << endl;
            continue;
        }

        if (choice == 5) {
            int num1, num2;
            cout << "Enter first number : "; cin >> num1;
            cout << "Enter second number: "; cin >> num2;
            if (num2 == 0) {
                cout << "Error: Cannot divide/modulus by zero." << endl;
            } else {
                cout << "Result: " << num1 << " % " << num2 << " = " << modulus(num1, num2) << endl;
            }
        } else {
            double num1, num2;
            cout << "Enter first number : "; cin >> num1;
            cout << "Enter second number: "; cin >> num2;
            cout << fixed << setprecision(2);
            switch (choice) {
                case 1:
                    cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                    break;
                case 2:
                    cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                    break;
                case 3:
                    cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                    break;
                case 4:
                    if (num2 == 0) {
                        cout << "Error: Cannot divide by zero." << endl;
                    } else {
                        cout << "Result: " << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                    }
                    break;
                case 6:
                    cout << "Result: " << num1 << " ^ " << num2 << " = " << power(num1, num2) << endl;
                    break;
            }
        }
    }

    return 0;
}
