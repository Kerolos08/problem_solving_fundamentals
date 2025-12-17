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

int SumOfMatrix (int matrix [3][3], int col, int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main ()
{

    srand((unsigned)time(NULL));

    int matrix1 [3][3];
    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    cout << "Matrix 1: " << endl;
    PrintMatrix(matrix1, 3, 3);

    cout << "\nSum of the matrix = " << SumOfMatrix(matrix1, 3, 3) << endl;

    return 0;
}