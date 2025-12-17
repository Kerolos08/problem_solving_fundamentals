#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

short CountSpacificLetterInString(string text, char Dchar)
{
    short counter = 0;
    for (int i = 0; i <= text.length(); i++)
    {
        if (text[i] == Dchar)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    string s1 = ReadString("Please Enter A String\n");
    char Dchar = ReadCharacter("\nPlease Enter A Character \n");
    cout << "\nLetter '" << Dchar << "' Count = ";
    cout << CountSpacificLetterInString(s1, Dchar) << endl;

    return 0;
}
