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

bool Is_Exist(int matrix[3][3], int NumberToSearch, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == NumberToSearch)
            {
                return true;
            }
        }
    }
    return false;
}

void CopyIntersectedItemsToNewMatrix(int matrix1[3][3], int matrix2[3][3], int ResultArray[10], int &Arrlenght, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (Is_Exist(matrix2, matrix1[i][j], 3, 3))
            {
                ResultArray[Arrlenght] = matrix1[i][j];
                Arrlenght++;
            }
        }
    }
}

void Print1D_array(int arr[10], int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int matrix1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};
    int matrix2[3][3] = {{5, 80, 90}, {22, 77, 1}, {10, 8, 33}};
    int ResultArray[10];
    int ResultArrayLength = 0;

    cout << "Matrix: \n";
    PrintMatrix(matrix1, 3, 3);
    cout << "\n";
    cout << "Matrix 2: \n";
    PrintMatrix(matrix2, 3, 3);
    cout << "\n";

    CopyIntersectedItemsToNewMatrix(matrix1, matrix2, ResultArray, ResultArrayLength, 3, 3);

    cout << "Intersected items is: " << endl;
    Print1D_array(ResultArray, ResultArrayLength);

    return 0;
}