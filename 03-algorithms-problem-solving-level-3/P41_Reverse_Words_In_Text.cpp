#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string msg)
{
    string s1;
    cout << msg;
    getline(cin, s1);
    return s1;
}

vector<string> SplitFunction(string text)
{
    vector<string> FinalString;                               // ** declaring a vector string.
    string Delimiter = " ";                                   // ** declaring a string variable that storing the delimiter which is space in this case.
    string Sword;                                             // ** string variable that temorarlly stores each word.
    short Pos = 0;                                            // ** short variable that stores the position of the delimiter.
    while ((Pos = text.find(Delimiter)) != std::string::npos) // ! while loop and its condition to stop when we not having the delimite positon.
    {
        Sword = text.substr(0, Pos); // ! saving the each word temporarlly by subtracting from the begining of string to the pos. of delimiter.
        if (Sword != " ")            // ! condition to prevent saving an empty word due to having multiple delimiters in the text.
        {
            FinalString.push_back(Sword); // ! pushing the word stored in the variable to the vector.
        }
        text.erase(0, Pos + Delimiter.length()); // ! deleting the saved word from the string as it is allready pushed to the vector.
    }
    if (text != "") // ! condition that allaw getting the last word in the string.
    {
        FinalString.push_back(text); // ! pushing last word in the string to the vector.
    }
    return FinalString; // ** returning the completed vector.
}

string ReverseString(string text)
{
    string NewString = "";                     // ** string variable that will store the reversed string
    vector<string> vText;                      // ** declaring vector to sebarate string words so we have the full control on their order.
    vText = SplitFunction(text);               // ! using the split function to get a fill vector with words.
    vector<string>::iterator it = vText.end(); // ! declaring an iterator that pointing to the last element of the vector.
    while (it != vText.begin())                // ! while loop and its condition that if we reached the first element it will end the loop.
    {
        it--;                   // ! iterator - 1 to get the actual last element as the end() not getting the last element decrement it to get the next words.
        NewString += *it + " "; // ! saving the new string with the reversed order.
    }
    NewString = (NewString.substr(0, NewString.length() - 1)); // ! deleting the last space in the text.
    return NewString;                                          // ** returning the new reversed string.
}

int main()
{
    string Text = ReadString("Please Enter Your Text\n");
    cout << "The Text After Reversing\n";
    cout << ReverseString(Text);
    return 0;
}
