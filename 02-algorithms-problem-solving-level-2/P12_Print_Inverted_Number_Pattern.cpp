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

void PrintPattern (int number)
{
    for (int i = number; i >= 1; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    PrintPattern(ReadNumber("Type a Number"));
    return 0;
}