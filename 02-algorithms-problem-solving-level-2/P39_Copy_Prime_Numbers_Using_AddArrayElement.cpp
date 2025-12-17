#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

enum enPrimeOrNot {prime = 1, notprime = 2};

enPrimeOrNot CheckPrimeOrNot (int number)
{
    int M = round(number / 2);
    for (int i = 2; i <= M; i++)
    {
        if(number % i == 0)
        {
            return enPrimeOrNot::notprime;
        }
    }
    return enPrimeOrNot::prime;
}

int RandomNumberFromTo (int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void AddArrayElements (int number, int arr[100], int& arrlength)
{
    arrlength ++;
    arr[arrlength - 1] = number;
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

void CopyPrimeNumbersIntoNewArray (int nums[100], int nums2[100], int arrlength, int& arrlength2)
{
    for (int i = 0; i < arrlength; i++)
    {
        if (CheckPrimeOrNot(nums[i]) == enPrimeOrNot::prime)
        {
        AddArrayElements(nums[i], nums2, arrlength2);
        }
    }
}

int main ()
{
    srand((unsigned)time(NULL));

    int nums[100], length;
    FillArrayWithRandomNumber(nums, length);

    int nums2[100];
    int arrlength2 = 0;
    CopyPrimeNumbersIntoNewArray(nums, nums2, length, arrlength2);

    cout << "Array elements : ";
    PrintArrayElements(nums, length);

    cout << "Array 2 prime numbers : ";
    PrintArrayElements(nums2, arrlength2);
    return 0;
}