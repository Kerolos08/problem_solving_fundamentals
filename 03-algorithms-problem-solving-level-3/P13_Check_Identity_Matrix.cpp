#include <iostream>
using namespace std;


void PrintMatrix (int matrix[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}


bool IsIdentity (int matrix1[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // check for diagonals elements
            if (i == j && matrix1 [i][j] != 1)
            {
                return false;
            }
            // check the rest 
            else if (i != j && matrix1 [i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main ()
{
    srand((unsigned)time(NULL));

    int matrix1 [3][3] =   {{1, 0, 0},
                            {0, 1, 0},
                            {0, 0, 1}};


    cout << "Matrix 1: " << endl;
    PrintMatrix(matrix1, 3, 3);


    (IsIdentity(matrix1, 3, 3) ? cout << "\nYes, matrix is Identity.\n" : cout << "\nNo, matrix is not Identity.\n");
    return 0;
}