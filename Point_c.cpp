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
void BlackElements (int matrix[MATRIX_SIZE][MATRIX_SIZE]){
    bool flag {true};
    int percent {};
    percent = MATRIX_SIZE / 3;
    int coln{};
    int str{};
    for (int i{percent}; i < MATRIX_SIZE; i++){
        if (!flag) break;
        for(int j{}; j < MATRIX_SIZE; j++){
            if (!flag) break;
            if (matrix[i][j] == 0){
                coln = j+1;
                str = i+1;
                flag = false;
            }
        }
    }
    cout << "\nString = "<<str<< "\nColumn = "<<coln;
}
int main() {
    srand(time(nullptr));
    int matrix [MATRIX_SIZE][MATRIX_SIZE];
    MatrixCreation(matrix);
    MatrixOut(matrix);
    BlackElements(matrix);
    return 0;
}
