#include <iostream>
#include <string>
#include "stringFunctions.h"
using namespace std;
using namespace Read;
using namespace CharsEdit;

// string InvertAllLetterString (string text)
// {
//     for (int i = 0; i <= text.size(); i++)
//     {
//         if (isupper(text[i]))
//         {
//             text[i] = tolower(text[i]);
//         }
//         else 
//         {
//             text[i] = toupper(text[i]);
//         }
//     }
//     return text;
// }

string InvertAllLetterString (string text)
{
    for (int i = 0; i <= text.size(); i++)
    {
        text[i] = InvertCaseChar(text[i]);
    }
    return text;
}

int main ()
{
    string text = ReadString("Please Enter Your Text\n");
    text = InvertAllLetterString(text);
    cout << text << endl;
    return 0;
}