#include <iostream>
#include <string>
using namespace std;

enum enWhatToCount {All = 0, CapitalLetters = 1, SmallLetters = 2};

namespace Read
{
    string ReadString (string msg)
    {
        string s1;
        cout << msg;
        getline(cin, s1);
        return s1;
    }

    char ReadCharacter (string msg)
    {
        char c;
        cout << msg;
        cin >> c;
        return c;
    }
}

namespace CharsEdit
{

    char InvertCaseChar (char c)
    {
        return (isupper(c) ? tolower(c) : toupper(c));
    }

    
}

namespace StringCount
{

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

    
}

namespace StringsEdit
{
    string UpperAllString(string text)
{
    for (int i = 0; i <= text.size(); i++)
    {
        if (islower(text[i]))
        {
            text[i] = toupper(text[i]);
        }
        else
        {
            continue;
        }
    }
    return text;
}

string LowerAllString(string text)
{
    for (int i = 0; i <= text.size(); i++)
    {
        if (isupper(text[i]))
        {
        text[i] = tolower(text[i]);
        }
        else
        {
            continue;
        }
    }
    return text;
}

string FormatName (string text)
{
    bool Is_FirstLetter = true;
    for (int i = 0; i <= text.size(); i++)
    {
        if (text[i] != ' ' && Is_FirstLetter)
        {
            text[i] = toupper(text[i]);
        }
        Is_FirstLetter = (text[i] == ' ' ? true : false);
    }
    return text;
}

string InvertAllLetterString (string text)
{
    for (int i = 0; i <= text.size(); i++)
    {
        if (isupper(text[i]))
        {
            text[i] = tolower(text[i]);
        }
        else 
        {
            text[i] = toupper(text[i]);
        }
    }
    return text;
}

}