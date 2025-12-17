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

void FillArraywithrandomNumbers (int arr[3][3], int colums, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            arr[i][j] = RandomNumber (1, 100);
        }
    }
}


void PrintArray (int arr[3][3], int colums, int rows)
{
    cout << "The following is a 3*3 matrix with random numbers: " << endl;
        for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            cout << setw(2) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main ()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[3][3];
    FillArraywithrandomNumbers(arr, 3, 3);
    PrintArray(arr, 3, 3);
    return 0;
}