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

void PrintOrderAndPosition (int number)
{
if (number == -1)
{
    cout << "\nThe number is not found :-(" << endl;
}
    else
{
    cout << "\nThe number found at position: " << number << endl;
    cout << "\nThe number found at order   : " << number + 1 << endl;
}
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
    PrintOrderAndPosition(SearchForANumber(arr, arrLegth, numbertosearchfor));

    return 0;
}