#include <iostream>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

bool Is_Vowel(char Letter)
{
    Letter = tolower(Letter);
    return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}

int main()
{
    char Letter = ReadCharacter("Please Enter A Character? \n");
    if (Is_Vowel(Letter))
    {
        cout << "Yes, Letter '" << Letter << "' is Vowel" << endl;
    }
    else
    {
        cout << "No, Letter '" << Letter << "' is Not Vowel" << endl;
    }
    return 0;
}