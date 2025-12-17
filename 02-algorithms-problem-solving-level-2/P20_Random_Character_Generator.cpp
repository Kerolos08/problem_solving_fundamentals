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

int main ()
{
    srand((unsigned)time(NULL));
    cout << GetCharType(enCharType::CapitalLetter) << endl;
    cout << GetCharType(enCharType::SmallLetter) << endl;
    cout << GetCharType(enCharType::SpecialCharacter) << endl;
    cout << GetCharType(enCharType::Digit) << endl;
    return 0;
}