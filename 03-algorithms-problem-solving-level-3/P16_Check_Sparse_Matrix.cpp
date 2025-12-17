#include <iostream>
#include <cmath>
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

// bool Is_Sparce (int matrix[3][3], int rows, int cols)
// {
//     short zeroscount = 0;
//     short numberscount = 0;
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (matrix [i][j] == 0)
//             {
//                 zeroscount++;
//             }
//             else
//             {
//                 numberscount++;
//             }
//         }
//     }
//     return (zeroscount > numberscount);
// }

int dublications (int nums[3][3], int rows, int cols, int DesiredNumber)
{
    int Counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (nums[i][j] == DesiredNumber)
            {
                Counter ++;
            }
        }
    }
    return Counter;
}

bool Is_Exist (int matrix[3][3], int rows, int cols)
{
    float matrixsize = rows * cols;
    return (dublications(matrix, 3, 3, 0) >= ceil(matrixsize / 2));
}

void PrintResult (bool quest)
{
    if (quest)
    {
        cout << "\nYes, It is sparce" << endl;
    }
    else
    {
        cout << "\nNo, It is not sparce" << endl;
    }
}

int main ()
{
    int matrix [3][3] ={{1, 5, 0}, {4, 0, 3}, {0, 0, 5}};


    cout << "Matrix: \n";
    PrintMatrix (matrix, 3, 3);


    PrintResult (Is_Exist(matrix, 3, 3));

    return 0;
}