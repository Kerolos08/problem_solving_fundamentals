#include <iostream>
using namespace std;

void PrintHeader ()
{
    cout << "\n\t\t\t\tMultiplication Table From 1 To 10\n\n" << endl;
    cout <<"\t";

    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n___________________________________________________________________________________________\n";
}

string PrintcolumSeparator(int i)
{
    if (i < 10)
    return "    |";
    else
    return "   |";
}

void PrintMultiplicationTable ()
{
    PrintHeader();
    for (int i = 1; i <= 10; i++)
    {
        cout << i << PrintcolumSeparator(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << j * i << "\t";
        }
        cout << "\n";
    }
}


int main()
{
    PrintMultiplicationTable();
    return 0;
}