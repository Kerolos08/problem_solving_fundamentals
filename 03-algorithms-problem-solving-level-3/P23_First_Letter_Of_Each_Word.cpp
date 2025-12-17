#include <iostream>
#include <string>
using namespace std;

string ReadText(string msg)
{
    string text;
    cout << msg << endl;
    getline(cin, text);
    return text;
}

void ReturnFristLetterFromEachWord(string text)
{
    cout << "\nThe First Letter Of Each Word\n";
    int StringLength = size(text);
    bool Is_FirstLetter = true;
    for (int i = 0; i <= StringLength; i++)
    {
        if (text[i] != ' ' && Is_FirstLetter)
        {
            cout << text[i] << endl;
        }
        Is_FirstLetter = (text[i] == ' ' ? true : false);
    }
}

int main()
{
    ReturnFristLetterFromEachWord(ReadText("Please Enter Your Text\n"));
    return 0;
}