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

int ReadNumber (string msg)
{
    int number;
    
    do {
        cout << msg << endl;
        cin >> number;
    } while(number <= 0);
    return number;
}

bool Is_Exist (int matrix[3][3], int rows, int cols)
{

    int NumberToSearch = ReadNumber("\nEnter a Number to search for?");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix [i][j] == NumberToSearch)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintResult (bool quest)
{
    if (quest)
    {
        cout << "\nIt is there" << endl;
    }
    else
    {
        cout << "\nIt is not there" << endl;
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