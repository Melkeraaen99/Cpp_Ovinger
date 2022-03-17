#include "Oppgave2.h"
#include<iostream>
using namespace std;
#include <iomanip> 

Matrix::Matrix(int nRows, int nColumns){
    row = nRows; 
    col= nColumns;
    rows = {new double* [nRows]};
    for (int i = 0; i < row; i++){
        rows[i] = new double [nColumns];
    } 
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            rows[i][j] = 0;
        }
    }
}

Matrix::Matrix(int nRows) : Matrix::Matrix(nRows, nRows){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < row; j++){
            if (j == i){
                rows[i][j] = 1;
            }
        }
    }
}

Matrix::~Matrix(){
    delete[] rows;
    rows = nullptr;
}

double Matrix::get(int row, int col) const{
    return rows[row][col];
}

void Matrix::set(int row, int col, double value){
    rows[row][col] = value;
}

int Matrix::getRows() const{
    return row;
}

int Matrix::getColumns() const{
    return col;
}

ostream& operator<<(ostream& os, const Matrix& mx){
    for (int i = 0; i < mx.getRows(); i++){
        os << "\n";
        for (int j = 0; j < mx.getColumns(); j++){
            os << setw(3)<<mx.get(i,j);
        }
    }
    return os;
}

Matrix &Matrix::operator=(Matrix rhs){
    swap(this->row, rhs.row);
    swap(this->col, rhs.col);
    swap(this->rows, rhs.rows);
    return *this;
}

Matrix::Matrix(const Matrix & rhs) : Matrix {rhs.getRows(), rhs.getColumns()} {
    for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
            this->rows[i][j] = rhs.rows[i][j];
        }
    }
}
