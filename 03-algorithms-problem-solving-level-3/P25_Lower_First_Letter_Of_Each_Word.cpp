#include <iostream>
#include <string>
using namespace std;

string ReadString (string msg)
{
    string text;
    cout << msg;
    getline (cin, text);
    return text;
}

string LowerFristLetterOfEachWord (string text)
{
    bool Is_FirstLetter = true;                    // ! to get the frist letter of the frist word
    for (int i = 0; i <= text.size(); i++)              // ! for loop
    {
        if (text[i] != ' ' && Is_FirstLetter)              // ! condition to get the frist letter after the ' ' 
        {
            text[i] = tolower(text[i]);                       // ! modify the frist letter
        }
        Is_FirstLetter = (text[i] == ' ' ? true : false);      /* ! update the value of the variable to make the it true
        to make if condition true for the next element "same technique like the first letter of the tect"*/
    }
    return text;
}

int main ()
{
    string s1 = ReadString("Please Enter Your String\n");
    cout << "\nString After Conversion\n";
    s1 = LowerFristLetterOfEachWord(s1);
    cout << s1 << endl;
    return 0;;
}