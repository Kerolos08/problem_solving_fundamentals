#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumberFromTo (int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void FillArrayWithRandomNumber (int nums[100], int& length)
{
    cout << "Please enter the lengh of the array" << endl;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        nums[i] = RandomNumberFromTo(0, 100);
    }
}

void PrintArrayElements (int nums[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int SumOfArrayMembers (int nums[100], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum = sum + nums[i];
    }
    return sum;
}

float AvgOfArrayNumbers (int nums[100], int length)
{
    return (float)SumOfArrayMembers(nums, length) / length;
}

int main ()
{
    srand((unsigned)time(NULL));
    int nums[100], length;
    FillArrayWithRandomNumber(nums, length);
    cout << "Array elements : ";
    PrintArrayElements(nums, length);
    cout << "Average of all numbers : " << AvgOfArrayNumbers(nums, length) << endl;
    return 0;
}