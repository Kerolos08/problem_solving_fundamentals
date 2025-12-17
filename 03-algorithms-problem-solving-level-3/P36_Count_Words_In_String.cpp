#include <iostream>
#include <string>
#include "StringFunctions.h"
using namespace std;
using namespace Read;

short CountStringWords(string text)
{
    short counter = 0;                                    // ** short variable to count words
    string Delim = " ";                                   // ** string variable to store the Delimeter (the space in this case)
    string Sword;                                         // ** string variable to temporary storing every word
    short Pos = 0;                                        // ** short variable to store the index of the delimeter
    while ((Pos = text.find(Delim)) != std::string::npos) // ! while loop and the condition is to not find the delimeter to stop
    {
        Sword = text.substr(0, Pos); // ! extract every word by subtracting from its start to the delimeter
        if (Sword != " ")            // ! condition to make sure the new word is not empty in case of multible spaces before it
        {
            counter++; // ** count the word which is extracted before
        }
        text.erase(0, Pos + Delim.length()); // ! delete the word which is counted before
    }
    if (Sword != "") // ! condition to make sure we get the last word after getting out the loop
    {
        counter++; // ** count the last word
    }
    return counter; // ** return the counter and getting out of the function
}

int main()
{
    string S1 = ReadString("Please Enter A String To Count\n");
    cout << "\n";
    cout << "The Number Of Words In Your String: " << CountStringWords(S1) << endl;
    return 0;
}
