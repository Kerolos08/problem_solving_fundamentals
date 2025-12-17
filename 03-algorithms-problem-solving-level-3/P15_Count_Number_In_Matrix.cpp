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

int ReadNumber (string msg)
{
    int number;
    
    do {
        cout << msg << endl;
        cin >> number;
    } while(number <= 0);
    return number;
}

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

int main ()
{
    int matrix [3][3] ={{1, 4, 0}, {4, 3, 1}, {2, 4, 5}};


    cout << "Matrix: \n";
    PrintMatrix (matrix, 3, 3);

    int DesiredNumber = ReadNumber("\nEnter the number to count in matrix?"); 
    int counter = dublications (matrix, 3, 3, DesiredNumber);

    cout << "\nNumber " << DesiredNumber << " count in matrix is " << counter << endl;

    return 0;
}