#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void PrintMatrix (int matrix[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf(" %02d ", matrix[i][j]);
        }
        cout << "\n";
    }
}

void FillMatrixWithRandomNumbers (int matrix[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
        matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

void MatrixMulResult (int matrix1[3][3], int matrix2[3][3], int matrix3[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
        matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

int main ()
{

    srand((unsigned)time(NULL));

    int matrix1 [3][3];
    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    cout << "Matrix 1: " << endl;
    PrintMatrix(matrix1, 3, 3);

    int matrix2 [3][3];
    FillMatrixWithRandomNumbers(matrix2, 3, 3);
    cout << "\nMatrix 2: " << endl;
    PrintMatrix(matrix2, 3, 3);

    int resMatrix[3][3];
    MatrixMulResult(matrix1, matrix2, resMatrix, 3, 3);
    cout << "\nResults : " << endl;
    PrintMatrix(resMatrix, 3, 3);

    return 0;
}