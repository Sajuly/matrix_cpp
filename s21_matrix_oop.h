#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class S21Matrix {
private:
int rows_, cols_;
double **matrix_;  //  указатель на память, где будет размещена матрица

void AllocateMemory_();
void CopyValue_(const S21Matrix& other);
void CleanMemory_();
double Det_(int n);
S21Matrix MiniMatrix_(int n, int c);

public:
// constructors
S21Matrix();                        // Базовый конструктор
S21Matrix(int rows, int cols);      // Параметризированный конструктор
S21Matrix(const S21Matrix& other);  // Конструктор копирования
S21Matrix(S21Matrix&& other);       // Конструктор переноса
~S21Matrix();                       // Деструктор

// accessors and mutators
int GetRows() const;
int GetCols() const;
void SetRows(int rows);
void SetCols(int cols);
double** GetMatrix() const;

// public methods
bool EqMatrix(const S21Matrix& other) const;
void SumMatrix(const S21Matrix& other);
void SubMatrix(const S21Matrix& other);
void MulNumber(const double num);
void MulMatrix(const S21Matrix& other);
S21Matrix Transpose();
S21Matrix CalcComplements();
double Determinant();
S21Matrix InverseMatrix();

// operators overloads
S21Matrix operator+(const S21Matrix& other) const;
S21Matrix operator-(const S21Matrix& other) const;
S21Matrix operator*(const double& num) const;
S21Matrix operator*(const S21Matrix& other) const;
bool operator==(const S21Matrix& other) const;
S21Matrix& operator=(const S21Matrix& other);
S21Matrix& operator+=(const S21Matrix& other);
S21Matrix& operator-=(const S21Matrix& other);
S21Matrix& operator*=(const double& num);
S21Matrix& operator*=(const S21Matrix& other);
double& operator()(int row, int col);
double& operator()(int row, int col) const;

// fill matrix & print
void Fill(double n);
void Fill(double n, double add);
void FillRev(double n, double sub);


void print_matrix() const;


};

#endif
