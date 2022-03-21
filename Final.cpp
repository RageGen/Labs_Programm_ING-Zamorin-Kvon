#include <iostream>
#include <iomanip>
using namespace std;
const int MATRIX_SIZE = 17;
const int MAX_RANDOM_VALUE = 25;
const int MIN_RANDOM_VALUE = 12;
bool counter = false;
bool MenuChecker = true;
int PointMenuChecker = 0;
void MatrixCreation(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % MAX_RANDOM_VALUE - MIN_RANDOM_VALUE; //!
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
void AddValueOfSideDiagonalElement(int matrix[MATRIX_SIZE][MATRIX_SIZE], int SumOfNumbers)
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
bool CheckForAlternatingSigns(int matrix[MATRIX_SIZE][MATRIX_SIZE], int stringNumber, bool counter) //!!
{
    cout << "String number --> ";
    cin >> stringNumber;
    for (int j = 0; j < MATRIX_SIZE - 1; j++)
    {
        if (matrix[stringNumber][j] * matrix[stringNumber][j + 1] < 0)
        {
            counter = true;
        }
    }
    return counter;
}
void FirstNullValue(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    bool flag{true};
    int percent{};
    percent = MATRIX_SIZE / 3;
    int columnNumber{};
    int stringNumber{};
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
                columnNumber = j + 1;
                stringNumber = i + 1;
                flag = false;
            }
        }
    }
    cout << "String = " << stringNumber << "\nColumn = " << columnNumber << '\n';
}
void OutMenu()
{
    system("clear");
    cout << "1. Matrix generation/regeneration" << endl;
    cout << "2. Add value of side diagonal element to each element of matrix" << endl;
    cout << "3. Check string for alternating signs" << endl;
    cout << "4. Look for the first null element" << endl;
    cout << "0. Exit" << endl;
}
void ContinueOrNot()
{
    int ContinueChecker = 1;
    cout << "Back to menu or not? 1-Yes 0-No" << endl;
    cin >> ContinueChecker;
    if (ContinueChecker == 0)
    {
        MenuChecker = false;
    }
}
int main()
{
    srand(time(nullptr));
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int SumOfNumbers = 0;
    int stringNumber = 0;
    while (MenuChecker == true)
    {
        OutMenu();
        cin >> PointMenuChecker;
        switch (PointMenuChecker)
        {
            case 1:
                MatrixCreation(matrix);
                MatrixOut(matrix);
                ContinueOrNot();
                break;
            case 2:
                cout << "Add value of side diagonal element to each element of matrix:" << endl;
                AddValueOfSideDiagonalElement(matrix, SumOfNumbers);
                MatrixOut(matrix);
                ContinueOrNot();
                break;
            case 3:
                cout << "Check string for alternating signs: " << endl;
                cout << boolalpha << CheckForAlternatingSigns(matrix, stringNumber, counter) << endl;
                ContinueOrNot();
                break;
            case 4:
                cout << "Look for the first null element: " << endl;
                MatrixOut(matrix);
                FirstNullValue(matrix);
                ContinueOrNot();
                break;
            case 0:
                MenuChecker = false;
                break;
        }
    }
    return 0;
}
