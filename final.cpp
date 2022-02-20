#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int MATRIX_SIZE = 17;
void MatrixCreation(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % 25 - 12;
        }
    }
}
void MatrixOut(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}
void SideDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE], int SumOfNumbers)
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (i + j == MATRIX_SIZE - 1)
            {
                SumOfNumbers = 0;
                SumOfNumbers += (abs(matrix[i][j] / 10) + abs(matrix[i][j] % 10));
            }
        }
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] += SumOfNumbers;
        }
    }
}
void Alternation(int matrix[MATRIX_SIZE][MATRIX_SIZE], int StrNum, int counter)
{
    cout << "String number --> ";
    cin >> StrNum;
    for (int j = 0; j < MATRIX_SIZE - 1; j++)
    {
        if (matrix[StrNum][j] * matrix[StrNum][j + 1] < 0)
        {
            counter = 1;
        }
    }
    if (counter == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}
void BlackElements(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    bool flag{true};
    int percent{};
    percent = MATRIX_SIZE / 3;
    int coln{};
    int str{};
    for (int i{percent}; i < MATRIX_SIZE; i++)
    {
        if (!flag)
            break;
        for (int j{}; j < MATRIX_SIZE; j++)
        {
            if (!flag)
                break;
            if (matrix[i][j] == 0)
            {
                coln = j + 1;
                str = i + 1;
                flag = false;
            }
        }
    }
    cout << "String = " << str << "\nColumn = " << coln << endl;
}
int main()
{
    srand(time(nullptr));
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int SumOfNumbers = 0;
    int StrNum = 0;
    int counter = 0;
    MatrixCreation(matrix);
    MatrixOut(matrix);
    SideDiagonal(matrix, SumOfNumbers);
    cout << "Point a:" << endl;
    MatrixOut(matrix);
    cout << "Point c: " << endl;
    BlackElements(matrix);
    cout << "Point b: " << endl;
    Alternation(matrix, StrNum, counter);
    return 0;
}