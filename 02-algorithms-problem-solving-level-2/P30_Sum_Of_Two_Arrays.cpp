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

void SumOf2RandomArraiesIn3rdOne (int arr[100], int arr2[100], int arr3[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr3[i] = arr[i] + arr2[i]; 
    }
}

int main ()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLegth = ReadPossitiveNumber("Enter the length of the array");

    FillArrayWithRandomNumbers(arr, arrLegth);
    cout << "Array 1 elements : ";
    PrintArrayElements(arr, arrLegth);

    int arr2[100];
    FillArrayWithRandomNumbers(arr2, arrLegth);
    cout << "\nArray 2 elements : ";
    PrintArrayElements(arr2,arrLegth);



    int arr3[100];
    SumOf2RandomArraiesIn3rdOne(arr, arr2, arr3, arrLegth);
    cout << "\nSum of array1 and array2 elements : ";
    PrintArrayElements(arr3, arrLegth);

    return 0;
}