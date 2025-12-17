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
        nums[i] = RandomNumberFromTo(1, 100);
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


int SearchForANumber (int arr[100], int arrLength, int numbertosearchfor)
{
    cout << "\nNumber you are looking for is: " << numbertosearchfor << endl;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == numbertosearchfor)
        {
            return i;
        }
    }
    return -1;
}

bool ExistedOrNot (int arr[100], int arrLength, int numbertosearchfor)
{
return SearchForANumber (arr, arrLength, numbertosearchfor) == -1;
}

int main ()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLegth = ReadPossitiveNumber("Enter the length of the array");

    FillArrayWithRandomNumbers(arr, arrLegth);
    cout << "\nArray 1 elements : ";
    PrintArrayElements(arr, arrLegth);
    cout << endl;

    int numbertosearchfor = ReadPossitiveNumber("Please enter a number to search for?");

    if(!ExistedOrNot(arr, arrLegth, numbertosearchfor))
    cout << "\nYes, The number is found :-(" << endl;
    else
    cout << "\nNo, The number is not found :-)" << endl;

    return 0;
}