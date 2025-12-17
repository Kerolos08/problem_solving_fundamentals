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
    for (int i = 1; i <= N; i++)
    {
        cout << i << endl;
    }
}

void PrintInRange1toN_DoWhile (int N)
{
    cout << "\nRange Printed Using Do While Statement" << endl;
    int counter = 0;
    do
    {
    counter ++;
    cout << counter << endl;
    } while (counter < N);
}

void PrintInRange1toN_Do (int N)
{
    cout << "\nRange Printed Using While Statement" << endl;
    int counter = 0;
    while (counter < N)
    {
    counter ++;
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