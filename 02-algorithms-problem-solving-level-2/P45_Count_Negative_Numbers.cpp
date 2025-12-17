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

void FillArrayWithRandomNumbers (int nums[100], int arrlength)
{

    for (int i = 0; i < arrlength; i++)
    {
        nums[i] = RandomNumberFromTo(-100, 100);
    }
}

int CountNegativeNumbersInArray (int nums[100], int length)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] < 0)
        {
            counter ++;
        }
    }
    return counter;
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
    FillArrayWithRandomNumbers(nums, arrLength);

    cout << "\nArray 1 elements :" << endl;
    PrintArrayElements(nums, arrLength);

    cout << "Negative numbers count is: ";
    cout << CountNegativeNumbersInArray(nums, arrLength) << endl;

    return 0;
}