#include <iostream>
using namespace std;

int ReadNumber ()
{
    int number;
    cout << "Enter A Number ?" << endl;
    cin >> number;
    return number;
}

void PrintResults (int number)
{
    int a, b, c;
    a = number * number;
    b = number * number * number;
    c = number * number * number * number;

    cout << a << " " << b << " " << c << endl;
}

int main ()
{
    PrintResults(ReadNumber());
    return 0;
}