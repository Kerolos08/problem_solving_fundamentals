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

void CopyArray (int nums[100], int nums2[100], int length)
{
    for (int i = 0; i < length; i++)
    {
    nums2[i] = nums[i];
    }
}

int main ()
{
    srand((unsigned)time(NULL));

    int nums[100], length;
    FillArrayWithRandomNumber(nums, length);

    int nums2[100];
    CopyArray(nums, nums2, length);

    cout << "Array elements : ";
    PrintArrayElements(nums, length);

    cout << "Array 2 elements after copy : ";
    PrintArrayElements(nums2, length);
    return 0;
}