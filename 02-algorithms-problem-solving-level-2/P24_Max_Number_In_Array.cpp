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

int FindMaxRandomNumberInArray (int nums[100], int length)
{
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}

int main ()
{
    srand((unsigned)time(NULL));
    int nums[100], length;
    FillArrayWithRandomNumber(nums, length);
    cout << "Array elements : ";
    PrintArrayElements(nums, length);
    cout << "\nMax number is : " << FindMaxRandomNumberInArray(nums, length) << endl;
    return 0;
}