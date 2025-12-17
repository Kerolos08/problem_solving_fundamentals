#include <iostream>
#include <string>
#include <vector>
#include "StringFunctions.h"
using namespace std;
using namespace Read;



vector<string> SplitFunction(string text)
{
    vector<string> FinalString;
    string Delimiter = " ";
    string Sword;
    short Pos = 0;
    while ((Pos = text.find(Delimiter)) != std::string::npos)
    {
        Sword = text.substr(0, Pos);
        if (Sword != " ")
        {
            FinalString.push_back(Sword);
        }
        text.erase(0, Pos + Delimiter.length());
    }
    if (text != "")
    {
        FinalString.push_back(text);
    }
    return FinalString;
}

string JoinString (vector <string> vWords, string Delimiter)
{
    string S1 = "";
    for (string &s : vWords)
    {
        S1 = S1 + s + Delimiter;
    }
    return (S1.substr(0, S1.length() - Delimiter.length()));
}


string ReplaceWordInString (string Text, string StringToReplace, string ReplaceTo, bool MatchCase = false)
{
    vector <string> vText;
    vText = SplitFunction(Text);
    vector <string> :: iterator it = vText.begin();
    if(MatchCase)
    {
        while (it != vText.end())
        {
        if (*it == StringToReplace)
        {
        *it = ReplaceTo;
        }
        it++;
        }
    }
    else
    {
        while (it != vText.end())
        {
        if (StringsEdit::LowerAllString(*it) == StringsEdit::LowerAllString(StringToReplace))
        {
        *it = ReplaceTo;
        }
        it++;
        }
    }
    return (JoinString(vText, " "));
}



// string ReplaceWordInString (string Text, string StringToReplace, string ReplaceTo, bool MatchCase = false)
// {
//     vector <string> vWords = SplitFunction(Text);
//     if (MatchCase)
//     {
//         for (string &s : vWords)
//         {
//             if (s == StringToReplace)
//             {
//                 s = ReplaceTo;
//             }
//         }
//     }
//     else
//     {
//         for (string &s : vWords)
//         {
//         if (StringsEdit::To_Low(s) == StringsEdit::To_Low(StringToReplace))
//         {
//             s = ReplaceTo;
//         }
//         }
//     }
//     return JoinString(vWords, " ");
// }


int main ()
{
    cout << "Original string: " << endl;
    string Text = "Hello, my name is Kerolos . I am from Egypt . Egypt is a nice country";
    cout << Text << endl;

    cout << "\n";

    string WordToReplace = "egypt";
    string ReplaceTo = "USA";

    cout << "The new text after replacing the word with match case\n";
    cout << ReplaceWordInString(Text, WordToReplace, ReplaceTo, true) << endl;
    cout << "\n";

    cout << "The new text after replacing the word without match case\n";
    cout << ReplaceWordInString(Text, WordToReplace, ReplaceTo) << endl; 

    return 0;
}