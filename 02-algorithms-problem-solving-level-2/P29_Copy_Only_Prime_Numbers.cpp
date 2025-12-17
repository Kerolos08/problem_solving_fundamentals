#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

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

void FillArrayWithRandomNumbers (int arr[100], int& arrlength)
{
    cout << "Enter the length of the array" << endl;
    cin >> arrlength;

    for (int i = 0; i < arrlength; i++)
    {
        arr[i] = RandomNumberFromTo(1, 100);
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

void CopyPrimeNumbersInNewArray (int arr[100], int arr2[100], int arrlength, int& arr2length)
{
    int primecounter = 0;
    for (int i = 0; i < arrlength; i++)
    {
        if (CheckPrimeOrNot(arr[i]) == enPrimeOrNot::prime)
        {
            arr2[primecounter] = arr[i];
            primecounter++;
        }
    }
    arr2length = primecounter;
}


int main ()
{
    srand((unsigned)time(NULL));


    int arr[100];
    int arrlength;
    FillArrayWithRandomNumbers(arr, arrlength);
    cout << "Array 1 elements: ";
    PrintArrayElements(arr, arrlength);

    int arr2[100];
    int arr2length;
    CopyPrimeNumbersInNewArray(arr, arr2, arrlength, arr2length);

    cout << "Prime numbers in array 2 : ";
    PrintArrayElements (arr2, arr2length);

    return 0;
}