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

void PrintReversedLetterPattern (int number)
{
    for (int i = 1 ; i <= number; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << char(i + 64);
        }
        cout << endl;
    }
}

int main()
{
    PrintReversedLetterPattern(ReadNumber("Type a Number"));
    return 0;
}