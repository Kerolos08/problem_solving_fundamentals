#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumberFromTo (int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

int ReadPossitiveNumber (string msg)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while(number < 0);
    return number;
}

void Swap(int& A, int& B)
{
    int Temp;
    Temp = A;
    A = B;
    B = Temp; 
}

void FillArrayWith1ToN (int nums[100], int arrlength)
{

    for (int i = 0; i < arrlength; i++)
    {
        nums[i] = i + 1;
    }
}

void ShuffleArray(int arr[100], int arrLength)
{ 
    for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[i], arr[RandomNumberFromTo(1, arrLength) - 1]);
        }
} 

void PrintArrayElements (int arr[100], int arrlength)
{
    for(int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main ()
{
srand((unsigned)time(NULL));

    int arrLength = ReadPossitiveNumber("Enter the length of the array");
    int nums[100];
    FillArrayWith1ToN(nums, arrLength);

    cout << "Array elements before shuffle : ";
    PrintArrayElements(nums, arrLength);

    ShuffleArray(nums, arrLength);

    cout << "Array elements after shuffle : ";
    PrintArrayElements(nums, arrLength);

    return 0;
}

// 1 2 3 4 5 6 7
// 3 1 4 6 5 2 7 
// 7 4 6 5 1 3 2 
// 2 5 1 7 3 6 4 