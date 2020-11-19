#include "Matrix.h"
#include "Matrix.cpp"
#include <iostream>

using namespace std;

int validateInput();

class MatrixCalculator
{
public:

    /// Menu displa
    void menu(){
        cout << endl;
        cout << "Welcome to (Your Name) Matrix Calculator" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1- Perform Matrix Addition" << endl;
        cout << "2- Perform Matrix Subtraction" << endl;
        cout << "3- Perform Matrix Multiplication" << endl;
        cout << "4- Matrix Transpose" << endl;
        cout << endl;
    }

    /// Adding two matrices of the size row * col
    void add(int row, int col){
        Matrix<int> mat1(row, col);
        Matrix<int> mat2(row, col);

        cout << "Enter the first matrix data: " << endl;
        cin >> mat1;

        cout << endl;

        cout << "Enter the second matrix data: " << endl;
        cin >> mat2;

        cout << endl << "Result: " << endl;
        cout << mat1 + mat2;

    }

    /// Subtracting two matrices of size row * col
    void sub(int row, int col){
        Matrix<int> mat1(row, col);
        Matrix<int> mat2(row, col);

        cout << "Enter the first matrix data: " << endl;
        cin >> mat1;

        cout << endl;

        cout << "Enter the second matrix data: " << endl;
        cin >> mat2;

        cout << endl << "Result: " << endl;
        cout << mat1 - mat2;
    }

    /// Multiplying a matrix of size row1 * col1
    /// with a matrix of size row2 * col2
    void multi(int row1, int col1, int row2, int col2){
        if(col1 == row2){
            Matrix<int> mat1(row1, col1);
            Matrix<int> mat2(row2, col2);

            cout << "Enter the first matrix data: " << endl;
            cin >> mat1;

            cout << endl;

            cout << "Enter the second matrix data: " << endl;
            cin >> mat2;

            cout << endl << "Result: " << endl;
            cout << mat1 * mat2;
        } else {
            cerr << endl;
            cerr << "--------[Math Error!]-------" << endl;
            cerr << "- the number of columns in -" << endl;
            cerr << "- the first matrix  should -" << endl;
            cerr << "- equal the number of rows -" << endl;
            cerr << "-   in the second matrix   -" << endl;
            cerr << "----------------------------" << endl;
        }

    }

    /// Finding the transpose of a matrix of size row * col
    void trans(int row, int col){
        Matrix<int> mat(row, col);

        cout << "Enter the matrix data: " << endl;
        cin >> mat;

        mat.transpose();

        cout << endl << "Result: " << endl;
        cout << mat;
    }

};

int main()
{
    int choice, x=0, y=0;
    MatrixCalculator calc;

    while(true){
        calc.menu();

        choice = validateInput();
        cout << endl;
        if(choice == 1){
            cout << "Enter the two matrices dimensions (ex: 2 4): ";
            cin >> x >> y;

            calc.add(x, y);
        }
        else if (choice == 2){
            cout << "Enter the two matrices dimensions (ex: 2 4): ";
            cin >> x >> y;

            calc.sub(x, y);
        }
        else if (choice == 3){
            int a=0, b=0;

            cout << "Enter the first matrix dimensions (ex: 2 4): ";
            cin >> x >> y;

            cout << "Enter the second matrix dimensions (ex: 2 4): ";
            cin >> a >> b;

            calc.multi(x, y, a, b);

        }
        else if (choice == 4){
            cout << "Enter the matrix dimension (ex: 2 4): ";
            cin >> x >> y;

            calc.trans(x, y);


        } else {
            cerr << endl;
            cerr << "--------------------------" << endl;
            cerr << "- Error, Invalid option! -" << endl;
            cerr << "--------------------------" << endl;
        }

    }

    return 0;
}

/// Input integer validation
int validateInput(){
    int choose;
    cout << "> ";
    cin >> choose;

    // input validation
    while(true){
        if( cin.fail() ){
            cin.clear(); // clear the stream
            cin.ignore(INT_MAX,'\n'); // ignore any thing afterwards

            cout << "\nNot valid choice .. please, try again!\n" << endl;

            cout << "> ";
            cin >> choose;
        }

        if( !cin.fail() ) break;
    }

    return choose;
}
