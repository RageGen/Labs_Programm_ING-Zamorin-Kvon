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
int main()
{
    srand(time(nullptr));
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int SumOfNumbers = 0;
    MatrixCreation(matrix);
    MatrixOut(matrix);
    SideDiagonal(matrix, SumOfNumbers);
    cout << "Point a:" << endl;
    MatrixOut(matrix);
    return 0;
}