#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

void PrintStringWords(string S1)
{
    cout << "\nYour String Words Are: \n" << endl;
    string delim = " ";                                 // delimiter the space in this case.
    string sword;                                       // temporay string variable to store the words.
    short pos = 0;                                      // identify a varible to save the index of the delimiter.
    while ((pos = S1.find(delim)) != std::string::npos) // get the index of the delimiter and if it not found the loop ends.
    {
        sword = S1.substr(0, pos); // save each word by subtracting the string untill the delimiter postion.
        if (sword != " ")          // make sure that the new word is not empty incase of multiple spaces.
        {
            cout << sword << endl; // printing the temp word.
        }
        S1.erase(0, pos + delim.length()); // delete the word and the delimiter of the string to reset its start pos at 0.
    }
    if (S1 != "")           // making sure that the last word is not empty string.
        cout << S1 << endl; // printing the last word.
}

int main()
{
    string S1 = ReadString("Enter a Text\n");
    PrintStringWords(S1);
    return 0;
}