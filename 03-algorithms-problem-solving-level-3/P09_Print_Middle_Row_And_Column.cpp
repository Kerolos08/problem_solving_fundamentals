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

void PrintMidCol (int nums[3][3], int col, int rows)
{
    short middlecol = col / 2;
    for (short i = 0; i < rows; i++)
    {
        cout << nums[i][middlecol] << "\t";
    }
}

void PrintMidrow (int nums[3][3], int col, int rows)
{
    short middlerow = rows / 2;
    for (short i = 0; i < col; i++)
    {
        cout << nums[middlerow][i] << "\t"; 
    }
}

int main ()
{

    srand((unsigned)time(NULL));

    int matrix1 [3][3];
    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    cout << "Matrix 1: " << endl;
    PrintMatrix(matrix1, 3, 3);

    cout << "Middle column of matrix 1: " << endl;
    PrintMidCol(matrix1, 3, 3);
    cout << "\n";
    cout << "Middle row of matrix 1: " << endl;
    PrintMidrow (matrix1, 3, 3);

    return 0;
}