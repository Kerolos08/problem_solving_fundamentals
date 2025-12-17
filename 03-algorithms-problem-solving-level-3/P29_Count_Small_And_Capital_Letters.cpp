#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

enum enWhatToCount {All = 0, CapitalLetters = 1, SmallLetters = 2};

short CountLetters (string text, enWhatToCount WhatToCount = enWhatToCount :: All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return text.length();
    }
    short counter = 0;
    for (short i = 0; i <= text.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(text[i]))
        {
            counter ++;
        }

        if (WhatToCount == enWhatToCount::SmallLetters && islower(text[i]))
        {
            counter ++;
        }
    }
    return counter;
}

int GetStringLength (string text)
{
    return text.size();
}

int CountCapitalLetters (string text)
{
    int counter = 0;
    for (int i = 0; i <= text.size(); i++)
    {
        if (isupper(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int CountSmallLetters (string text)
{
    int counter = 0;
    for (int i = 0; i <= text.size(); i++)
    {
        if (islower(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int main ()
{
    string s1 = ReadString("Please Enter The String ?\n");
    cout << "Method #1\n" << endl;
    cout << "\nString Length = ";
    cout  << GetStringLength(s1) << endl;
    cout << "Capital Letters Count = ";
    cout << CountCapitalLetters(s1) << endl;
    cout << "Small Letters Count = ";
    cout << CountSmallLetters(s1) << endl;
    cout << "Method #2\n" << endl;
    cout << "\nString Length = ";
    cout  << CountLetters(s1) << endl;
    cout << "Capital Letters Count = ";
    cout << CountLetters(s1, enWhatToCount::CapitalLetters) << endl;
    cout << "Small Letters Count = ";
    cout << CountLetters(s1, enWhatToCount::SmallLetters) << endl;
    return 0;
}
