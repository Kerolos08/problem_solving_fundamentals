#include <iostream>
using namespace std;

int ReadNumber ()
{
    int N;
    cout << "Enter The Number" << endl;
    cin >> N;
    return N;
}

void PrintInRange1toN_For (int N)
{
    cout << "\nRange Printed Using For Statement" << endl;
    for (int i = N; i >= 1; i--)
    {
        cout << i << endl;
    }
}

void PrintInRange1toN_DoWhile (int N)
{
    cout << "\nRange Printed Using Do While Statement" << endl;
    int counter = N;
    do
    {
    cout << counter << endl;
    counter --;
    } while (counter > 0);
}

void PrintInRange1toN_Do (int N)
{
    cout << "\nRange Printed Using While Statement" << endl;
    int counter = N + 1;
    while (counter > 1)
    {
    counter --;
    cout << counter << endl;
    }
}

int main ()
{
    int N = ReadNumber();
    PrintInRange1toN_Do(N);
    PrintInRange1toN_DoWhile(N);
    PrintInRange1toN_For(N);
    return 0;
}