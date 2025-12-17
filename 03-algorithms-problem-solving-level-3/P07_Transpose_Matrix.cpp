#include <iostream>
using namespace std;

void FillMatrixWithOrderedNumbers (int arr[3][3], int rows, int columns)
{
    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = ++counter;
        }
    }
}

void PrintTwoDimArr (int arr[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

void TransposeMatrix (int arr[3][3], int transposedarr[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j ++)
        {
            transposedarr[i][j] = arr[j][i];
        }
    }
}

int main ()
{
    int arr[3][3];
    int transarr[3][3];
    FillMatrixWithOrderedNumbers(arr, 3, 3);
    cout << "\nRegular Matrix\n";
    PrintTwoDimArr(arr, 3, 3);
    TransposeMatrix(arr, transarr, 3, 3);
    cout << "\nTransversed Matrix\n";
    PrintTwoDimArr(transarr, 3, 3);
    return 0;
}