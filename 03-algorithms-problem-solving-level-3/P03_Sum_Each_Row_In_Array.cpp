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

void FillArraywithrandomNumbers (int arr[3][3], int columns, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = RandomNumber (1, 100);
        }
    }
}


void PrintArrayTwoDimArr (int arr[3][3], int columns, int rows)
{
    cout << "\nThe following is a 3*3 matrix with random numbers: " << endl;

        for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(2) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int SumOfRows (int arr[3][3], int ColumnNumber, int RowNumber)
{
    int sum = 0;
    for (int j = 0; j < ColumnNumber; j++)
    {
        sum += arr[RowNumber][j];
    }
    return sum;
}


void SaveSumOfEachRowInArray (int OneDimArr[3], int TwoDimArr[3][3], int columns, int rows)
{
    for (int i = 0; i < rows; i++)
    {
    OneDimArr[i] = SumOfRows(TwoDimArr, columns, i);
    }
}

void PrintOneDimArr (int arr[3], int arrlength)
{
    cout << "\nThe following are the sum of each row in the matrix :\n";
    for (int i = 0; i < arrlength; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main ()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int TwoDimArr[3][3];
    FillArraywithrandomNumbers(TwoDimArr, 3, 3);
    PrintArrayTwoDimArr(TwoDimArr, 3, 3);
    int OneDimArr[3];
    SaveSumOfEachRowInArray(OneDimArr, TwoDimArr, 3, 3);
    PrintOneDimArr(OneDimArr, 3);

    return 0;
}