#include <iostream>
using namespace std;

int ReadNumber (string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}

void ReadArrayOfNumbers (int nums[100], int& length)
{
    cout << "\nEnter number of elements:\n";
    cin >> length;

    cout << "\nEnter array elements: \n";
    for (int i = 0; i <= length - 1; i++)
    {
        cout << "Element [ " << (i + 1) << " ] : " ;
        cin >> nums[i];
    }
    cout << endl;
}

void PrintArray (int nums[], int length)
{
    for (int i = 0; i <= length - 1; i++)
    {
        cout << nums[i];
    }
    cout << endl;
}

int TimesRepeted (int nums[], int checknum, int length)
{
    int counter = 0;
    for (int i = 0; i <= length - 1; i++)
    {
        if (checknum == nums[i])
        {
            counter ++;
        }
    }
    return counter;
}

int main()
{
    int length;
    int nums[100];
    int numbertocheck;
    ReadArrayOfNumbers(nums, length);
    numbertocheck = ReadNumber("Enter the number you want to check: ");
    cout << "\nOriginal Array : ";
    PrintArray(nums, length);
    cout << "\nNumber" << numbertocheck << " is repeated " << TimesRepeted(nums, numbertocheck, length) << " time(s)" << endl;
    return 0;
}