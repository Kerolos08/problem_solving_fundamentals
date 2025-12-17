#include <iostream>
using namespace std;

void PrintMatrix(int matrix[3][3], int cols, int rows)
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

int Get_Min(int matrix[3][3], int rows, int cols)
{
    int Min_number = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < Min_number)
            {
                Min_number = matrix[i][j];
            }
        }
    }
    return Min_number;
}

int Get_Max(int matrix[3][3], int rows, int cols)
{
    int Max_number = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > Max_number)
            {
                Max_number = matrix[i][j];
            }
        }
    }
    return Max_number;
}

int main()
{
    int matrix[3][3] = {{77, 5, 12}, {22, 20, 6}, {14, 3, 9}};

    cout << "Matrix: \n";
    PrintMatrix(matrix, 3, 3);

    cout << "\nMinimum Number in matrix is: " << Get_Min(matrix, 3, 3) << endl;
    cout << "\nMaximum Number in matrix is: " << Get_Max(matrix, 3, 3) << endl;

    return 0;
}