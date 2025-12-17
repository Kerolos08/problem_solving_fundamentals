#include <iostream>
#include <string>
#include <vector>
#include "StringFunctions.h"
using namespace std;
using namespace Read;


string ReplaceWordInString (string Text, string WordToReplace, string NewWord)
{
    short pos = Text.find(WordToReplace);
    while (pos != std :: string :: npos)
    {
        Text.replace(pos, WordToReplace.length(), NewWord);
        pos = Text.find(WordToReplace);
    }
    return Text;
}

int main ()
{
    cout << "Original string: " << endl;
    string Text = "Hello, my name is Kerolos . I am from Egypt . Egypt is a nice country";
    cout << Text << endl;
    cout << "\n";
    string WordToReplace = "Egypt";
    string ReplaceTo = "USA";
    cout << "The new text after replacing the word\n";
    cout << ReplaceWordInString(Text, WordToReplace, ReplaceTo);


    return 0;
}