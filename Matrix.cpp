#include "Matrix.h"
#include <iostream>

using namespace std;

template<typename T>
Matrix<T>::Matrix(int x, int y)
    :row(x), col(y)
{
    data = new T*[row];
    for(int i=0; i<row; ++i){
        data[i] = new T[col];

        /// initial values
        for(int k=0; k < col; k++)
            data[i][k] = 0;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m){
    Matrix<T> result(row, col);

    for(int i=0; i < row; i++){
        for(int k=0; k < col; k++){
            result.data[i][k] = data[i][k] + m.data[i][k];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &m){
    Matrix<T> result(row, col);

    for(int i=0; i < row; i++){
        for(int k=0; k < col; k++){
            result.data[i][k] = data[i][k] - m.data[i][k];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m){
    /// take number of rows from mat1 & number of cols from mat2
    Matrix<T> result(row, m.col);

    for(int i=0; i < row; i++){
        for(int j=0; j < m.col; j++){
            for(int k=0; k < col; k++){
                result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    return result;
}

template<typename T>
void Matrix<T>::transpose(){
    Matrix<T> result(col, row);

    for(int i=0; i < row; i++){
        for(int k=0; k < col; k++){
            result.data[k][i] = data[i][k];
        }
    }

    /// to update the new size of the matrix
    swap(row, col);

    data = new T*[row];
    for(int i=0; i<row; ++i){
        data[i] = new T[col];

        /// transfer values
        for(int k=0; k < col; ++k){
            data[i][k] = result.data[i][k];
        }
    }


}

template<typename T>
Matrix<T>::~Matrix()
{
    for(int i=0; i<row; ++i)
        delete[] data[i];

    delete[] data;
}
