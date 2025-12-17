#include <iostream>
using namespace std;

char ReadCharacter (string msg)
{
    char c;
    cout << msg;
    cin >> c;
    return c;
}

char InvertCaseChar (char c)
{
return (isupper(c) ? tolower(c) : toupper(c));
}

int main ()
{
    char c = ReadCharacter("Please enter a character\n");
    cout << "Char After Inverting Case\n";
    cout << InvertCaseChar(c);
    return 0;
}