#pragma once
#include <iostream>
#include <utility>
using namespace std;

class Matrix{
private: 
    int row;
    int col;
    double** rows;

public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const;
    int getColumns() const;
    friend ostream& operator<<(ostream& os, const Matrix& mx);
    Matrix(const Matrix & rhs);
    Matrix& operator = (Matrix rhs);
    Matrix& operator+=(const Matrix& rhs){
        for (int i = 0; i<row; i++){
            for (int j = 0; j<col; j++){
                this->rows[i][j] += rhs.rows[i][j];
            }
        }
        return *this;
    }
    Matrix& operator+(const Matrix& rhs){
        for (int i = 0; i<row; i++){
            for (int j = 0; j<col; j++){
                this->rows[i][j] = rhs.rows[i][j] + rows[i][j];
            }
        }
        return *this;
    }
};