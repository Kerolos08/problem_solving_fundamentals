#include <iostream>
using namespace std;

bool isscalar (int arr[3][3], int cols, int rows)
{
    int * felementP = &arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && arr[i][j] != *felementP)
            {
                return false;
            }
            else if (i != j && arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}


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


int main ()
{
    int matrix [3][3] ={{3, 0, 0},
                        {0, 3, 0},
                        {0, 0, 5}};

    PrintMatrix (matrix, 3, 3);

    ((isscalar(matrix, 3, 3)) ? cout << "\nYes, The matrix is scalar\n" : cout << "\nNo, The matrix is not scalar\n");
    return 0;
}