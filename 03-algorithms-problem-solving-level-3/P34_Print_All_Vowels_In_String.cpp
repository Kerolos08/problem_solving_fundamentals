#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

bool Is_Vowel(char Letter)
{
    Letter = tolower(Letter);
    return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}

void Print_Vowels (string Text)
{
    short Counter = 0;
    for (int i = 0; i < Text.length(); i++)
    {
        if (Is_Vowel(Text[i]))
        {
            cout << Text[i] << "    ";
        }
    }
    cout << "\n";
}

int main()
{
    string S1 = ReadString("Please Enter Your String\n");
    cout << "\nNumber Of Vowels is: ";
    Print_Vowels(S1);
    return 0;
}
