#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
    private:
        T** data;
        int row, col;

    public:
        Matrix(int x, int y); /// initialize matrix

        Matrix<T> operator+(const Matrix<T> &m);
        Matrix<T> operator-(const Matrix<T> &m);
        Matrix<T> operator*(const Matrix<T> &m);
        void transpose();

        /// I/O operators overloading
        friend istream& operator >>(istream &in, const Matrix<T> &m){
            for(int i=0; i < m.row; i++){
                for(int k=0; k < m.col; k++){
                    in >> m.data[i][k];
                }
            }

            return in;
        }

        friend ostream& operator <<(ostream &out, const Matrix<T> &m){
            for(int i=0; i < m.row; i++){
                for(int k=0; k < m.col; k++){
                    out << m.data[i][k] << " ";
                }
                out << endl;
            }

            return out;
        }

        ~Matrix(); /// free space

    protected:
};

#endif // MATRIX_H
