#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumberFromTo (int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

enum enCharType{SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};


char GetCharType (enCharType type)
{
    switch (type)
    {
        case enCharType::SmallLetter:
        return char(RandomNumberFromTo(97, 122));
        break;

        case enCharType::CapitalLetter:
        return char(RandomNumberFromTo(65, 90));
        break;

        case enCharType::SpecialCharacter:
        return char(RandomNumberFromTo(33, 47));
        break;

        default:
        return char(RandomNumberFromTo(48,57));
        break;
    }
}

int ReadNumber (string msg)
{
    int number;
    cout << msg << endl;
    cin >> number;
    return number;
}

string GenerateWord (enCharType type, short length)
{
    string word = "";
    for (int i = 0; i <= length; i++)
    {
        word = word + GetCharType(type);
    }
    return word;
}

string GenerateKey ()
{
    string key = "";
    key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key = key + GenerateWord(enCharType::CapitalLetter, 4);

    return key;
}

void FilArrayWithGeneratedCodes (string arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = GenerateKey();
    }
}


void PrintArrayElements (string arr[100], int arrlength)
{
    cout << "Array elements : \n" << endl;
    for (int i = 0; i < arrlength; i++)
    {
        cout << "Array [ " << i << " ] : " << arr[i] << endl;
    }
}

int main ()
{
    srand((unsigned)time(NULL));

    string arrKeys[100];
    int arrLength = ReadNumber("How many keys do you want to generate?");

    FilArrayWithGeneratedCodes(arrKeys, arrLength);
    cout << endl;
    PrintArrayElements(arrKeys, arrLength);
    return 0;
}