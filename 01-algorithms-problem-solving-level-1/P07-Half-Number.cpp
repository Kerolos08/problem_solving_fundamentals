#include <iostream>
using namespace std;

int ReadNumber ()
{
    int number;
    cout << "Type A Number" << endl;
    cin >> number;
    
    return number;
}

float HalfNumber (int number)
{
    return (float)number / 2;
}

void PrintResult (int number)
{
    string result;
    result = "\nHalf Of " + to_string(number) + " Is " + to_string(HalfNumber(number));
    cout << result << endl;
}

int main ()
{
    PrintResult(ReadNumber());
    return 0;
}