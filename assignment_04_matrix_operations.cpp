// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

void displayMatrix(const int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl;
    }
}

void inputMatrix(int mat[MAX][MAX], int rows, int cols, const string& name = "Matrix") {
    cout << "Enter elements for " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void transposeMatrix(const int src[MAX][MAX], int rows, int cols, int dest[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int rows, int cols, int C[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX][MAX], int rA, int cA, const int B[MAX][MAX], int rB, int cB, int C[MAX][MAX]) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "=== MATRIX OPERATIONS ===" << endl;
    cout << "1. Transpose Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    if (!(cin >> choice)) return 0;

    if (choice == 1) {
        int r, c;
        cout << "Enter number of rows: "; cin >> r;
        cout << "Enter number of columns: "; cin >> c;
        if (r <= 0 || r > MAX || c <= 0 || c > MAX) {
            cout << "Invalid dimensions." << endl;
            return 0;
        }
        int mat[MAX][MAX], res[MAX][MAX];
        inputMatrix(mat, r, c);
        transposeMatrix(mat, r, c, res);
        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(mat, r, c);
        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(res, c, r);
    } else if (choice == 2) {
        int r, c;
        cout << "Enter number of rows: "; cin >> r;
        cout << "Enter number of columns: "; cin >> c;
        if (r <= 0 || r > MAX || c <= 0 || c > MAX) {
            cout << "Invalid dimensions." << endl;
            return 0;
        }
        int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
        inputMatrix(A, r, c, "Matrix A");
        inputMatrix(B, r, c, "Matrix B");
        addMatrices(A, B, r, c, C);
        cout << "\nMatrix Sum (A + B):" << endl;
        displayMatrix(C, r, c);
    } else if (choice == 3) {
        int rA, cA, rB, cB;
        cout << "Enter rows for Matrix A: "; cin >> rA;
        cout << "Enter columns for Matrix A: "; cin >> cA;
        cout << "Enter rows for Matrix B: "; cin >> rB;
        cout << "Enter columns for Matrix B: "; cin >> cB;
        if (cA != rB) {
            cout << "Error: Number of columns in A must equal number of rows in B." << endl;
            return 0;
        }
        if (rA <= 0 || rA > MAX || cA <= 0 || cA > MAX || cB <= 0 || cB > MAX) {
            cout << "Invalid dimensions." << endl;
            return 0;
        }
        int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
        inputMatrix(A, rA, cA, "Matrix A");
        inputMatrix(B, rB, cB, "Matrix B");
        multiplyMatrices(A, rA, cA, B, rB, cB, C);
        cout << "\nMatrix Product (A x B):" << endl;
        displayMatrix(C, rA, cB);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
