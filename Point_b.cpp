#include <iostream>
#include <iomanip>
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
void CheckForAlternatingSigns(int matrix[MATRIX_SIZE][MATRIX_SIZE], int stringNumber, int counter)
{
    cout << "String number --> ";
    cin >> stringNumber;
    for (int j = 0; j < MATRIX_SIZE - 1; j++)
    {
        if (matrix[stringNumber][j] * matrix[stringNumber][j + 1] < 0)
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
int main()
{
    srand(time(nullptr));
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int stringNumber = 0;
    int counter = 0;
    MatrixCreation(matrix);
    MatrixOut(matrix);
    CheckForAlternatingSigns(matrix, stringNumber, counter);
    return 0;
}
