#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

// short CountSpacificLetterInString(string text, char Dchar)
// {
//     short counter = 0;
//     for (int i = 0; i <= text.length(); i++)
//     {
//         if (text[i] == Dchar)
//         {
//             counter++;
//         }
//     }
//     return counter;
// }

// short CountLetterInString(string text, char Dchar)
// {
//     short counter = 0;
//     for (int i = 0; i <= text.length(); i++)
//     {
//         if (text[i] == Dchar || text[i] == toupper(Dchar))
//         {
//             counter++;
//         }
//     }
//     return counter;
// }

short CountLetterInString(string text, char Dchar, bool MatchCase = true)
{
    short counter = 0;
    for (int i = 0; i <= text.length(); i++)
    {
        if (MatchCase)
        {
            if (text[i] == Dchar)
            counter ++;
        }
        else
        {
            if (tolower(text[i]) == tolower(text[i]));
            counter ++;
        }
    }
    return counter;
}

int main()
{
    string s1 = ReadString("Please Enter A String\n");
    char Dchar = ReadCharacter("\nPlease Enter A Character \n");
    cout << "\nLetter '" << Dchar << "' Count = ";
    cout << CountLetterInString(s1, Dchar) << endl;
    cout << "\nLetter '" << Dchar << "' Or '" << char(toupper(Dchar)) << "' Count = ";
    cout << CountLetterInString(s1, Dchar, false) << endl;

    return 0;
}
