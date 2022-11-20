#include "s21_matrix_oop.h"

void S21Matrix::AllocateMemory_() {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
    }
}

void S21Matrix::CopyValue_(const S21Matrix& another) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = another.matrix_[i][j];
    }
  }
}

void S21Matrix::CleanMemory_() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

//----------------------------------------constructors

// default constructor
S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  AllocateMemory_();
}

// parameterized constructor
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::out_of_range("Incorrect input: size less ");
  }
  AllocateMemory_();
}

// copy constructor
S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  AllocateMemory_();
  CopyValue_(other);
}

// move constructor
S21Matrix::S21Matrix(S21Matrix&& other) : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = other.matrix_;  // CopyValue_(other);
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

// destructor
S21Matrix::~S21Matrix() {
  if (matrix_) {
    CleanMemory_();
  }
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

//---------------------------------accessors and mutators




//---------------------------------public methods



//---------------------------------operators overloads



//---------------------------------fill matrix & print

void S21Matrix::print_matrix() const {
    for (int i = 0; i < rows_; i++) {
        for (int j=0; j < cols_; j++) {
            // cout << matrix_[i, j];
            cout << setw(3) << setprecision(2) << matrix_[i][j];  // ширина между и точность
        }
        cout << endl;
    }
}

int main () {
    
    S21Matrix test;
    test.print_matrix();

    return 0;
}