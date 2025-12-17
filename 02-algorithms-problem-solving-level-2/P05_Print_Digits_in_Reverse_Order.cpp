#include <iostream>
#include <string>
using namespace std;

string ReadNumber ()
{
    string number;
    cout << "Please Enter The Number" << endl;
    cin >> number;
    return number;
}

// int ReadNumber ()
// {
//     int number;
//     cout << "Please Enter The Number" << endl;
//     cin >> number;
//     return number;
// }

void PrintDigits (string number)
{
    int length = number.size();
    for (int i = length - 1; i >= 0; i--)
    {
        cout << number[i] << endl;
    }
}


// void PrintDigits (int number)
// {
//     int remainder = 0;
//     while (number > 0)
//     {
//         remainder = number % 10;
//         number = number / 10;
//         cout << remainder << endl;
//     }
// }


int main ()
{
    PrintDigits(ReadNumber());
    return 0;
}