#include <iostream>
#include <cstdlib>
using namespace std;

// int ReadNumber (string msg)
// {
//     int number;
//     cout << msg << endl;
//     cin >> number;
//     return number;
// }

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

int FindMinRandomNumberInArray (int nums[100], int length)
{
    int min = 0;
    min = nums[0];
    for (int i = 0; i < length; i++)
    {
        if(nums[i] < min)
        {
            min = nums[i];
        }
    }
    return min;
}

int main ()
{
    srand((unsigned)time(NULL));
    int nums[100], length;
    FillArrayWithRandomNumber(nums, length);
    cout << "Array elements : ";
    PrintArrayElements(nums, length);
    cout << "\nMax number is : " << FindMinRandomNumberInArray(nums, length) << endl;
    return 0;
}