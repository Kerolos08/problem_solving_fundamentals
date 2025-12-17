#include <iostream>
#include <string>

using namespace std;

int ReadNumber (string msg)
{
    int number;
        cout << msg << endl;
        cin >> number;
    return number;
}

int ReadZeroOrOne (string msg)
{
    int number;
    do{
    cout << msg << endl;
    cin >> number;
    }while(number != 0 && number != 1);
    return number;
}

void AddArrayElements (int number, int arr[100], int& arrlength)
{
    arrlength ++;
    arr[arrlength - 1] = number;
}

void AddNumberToArray (int arr[100], int& arrlength)
{
    bool AddMore = true;;
    do{
        AddArrayElements(ReadNumber("Please enter a number"), arr, arrlength);
        AddMore = ReadZeroOrOne("Do you want to add more numbers? [0]:No,[1]:Yes");
    }while (AddMore);
}

void PrintArrayElements (int arr[100], int arrlength)
{
    for(int i = 0; i < arrlength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main ()
{
    int arr[100];
    int arrlength = 0;
    AddNumberToArray(arr, arrlength);
    cout << "\nArray length : " << arrlength << endl;
    cout << "Array elements : ";
    PrintArrayElements(arr, arrlength);
    return 0;
}