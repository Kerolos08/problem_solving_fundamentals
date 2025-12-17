#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

enum enWinner {User = 1, Computer = 2, Draw = 3};
enum enGameChoice {Stone = 1, Paper = 2, Scissors = 3};

struct stRoundInfo
{
    short RoundNumber;
    enGameChoice UserChoice;
    enGameChoice ComputerChoice;
    enWinner RoundWinner;
    string WinnerName = "";
};

struct stGameResults
{
    short GameRounds;
    short UserWinTimes;
    short ComputerWinTimes;
    short DrawTimes;
    enWinner GameWinner;
    string WinnerName = "";
};


int RandomNumber (int From, int To)
{ 
//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}

short ReadHowManyRounds ()
{
    short HowManyRounds;
    do{
        cout << "How Many Rounds 1 to 10" <<  endl;
        cin >> HowManyRounds;
    }while(HowManyRounds < 1 || HowManyRounds > 3);
    return HowManyRounds;
}

enGameChoice ReadUsersChoice ()
{
    short choice;
    do{
        cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissors ?";
        cin >> choice;
    }while(choice < 0 || choice > 3);
    return (enGameChoice) choice; 
}

enGameChoice GetComputerChoice ()
{
    return (enGameChoice) RandomNumber(1, 3);
}

enWinner WhoWinTheRound (stRoundInfo RoundInfo)
{
    if (RoundInfo.ComputerChoice == RoundInfo.UserChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.UserChoice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;


    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }
    return enWinner::User;
}

string GetWinnerName (enWinner winner)
{
    string ArrWinnerNames[3] = {"User", "Computer", "No Winner"};
    return ArrWinnerNames[winner - 1];
}

enWinner whoWinTheGame (short UserWinTimes, short ComputerWinTimes)
{
    if (UserWinTimes > ComputerWinTimes)
    return enWinner::User;
    else if (ComputerWinTimes > UserWinTimes)
    return enWinner::Computer;
    else
    enWinner::Draw;
}

stGameResults FillGameResults (short GameRounds, short UserWinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.UserWinTimes = UserWinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = whoWinTheGame(UserWinTimes, ComputerWinTimes);
    GameResults.WinnerName = GetWinnerName (GameResults.GameWinner);

    return GameResults;
}

string GetChoise (enGameChoice Choise)
{
    string ArrStonePaperScissors[3] = {"Stone", "Paper", "Scissors"};
    return ArrStonePaperScissors[Choise - 1];
}

void SetWinnerDisplayColor (enWinner winner)
{
    switch (winner)
    {
    case enWinner::Computer:
    system("color 4F");
    cout << "\a";
    break;

    case enWinner::User:
    system("color 2F");
    break;

    default:
    system("color 6F");
        break;
    }
}

void PrintRoundResults (stRoundInfo RoundInfo)
{
    cout << "____________Round [" << RoundInfo.RoundNumber << "] ____________" << endl;
    cout << "\nUser Choice: " << GetChoise(RoundInfo.UserChoice) << endl;
    cout << "Computer Choice: " << GetChoise(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner: " << RoundInfo.WinnerName << endl;
    cout << "\n__________________________________\n" << endl;
    SetWinnerDisplayColor(RoundInfo.RoundWinner);
}

void ResetScrean ()
{
    system("cls");
    system("color 0F");
}

stGameResults PlayRounds (short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short ComputerWinCounter = 0;
    short UserWinCounter = 0;
    short DrawCounter = 0;

    for  (int RoundNumber = 1; RoundNumber <= HowManyRounds; RoundNumber++)
    {
        cout << "Round [" << RoundNumber << " ] begins :" << endl;
        RoundInfo.RoundNumber = RoundNumber;
        RoundInfo.UserChoice = ReadUsersChoice ();
        RoundInfo.ComputerChoice = GetComputerChoice ();
        RoundInfo.RoundWinner = WhoWinTheRound(RoundInfo);
        RoundInfo.WinnerName = GetWinnerName(RoundInfo.RoundWinner);

        if (RoundInfo.RoundWinner == enWinner::Computer)
            ComputerWinCounter++;
        else if (RoundInfo.RoundWinner == enWinner::User)
            UserWinCounter++;
        else
        DrawCounter++;
        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, UserWinCounter,ComputerWinCounter,DrawCounter);
}

string Tabs (short NumberOfTabs)
{
    string Tab = "";
    for (int i = 0; i < NumberOfTabs; i++)
    {
        Tab = Tab + "\t";
    }
    return Tab;
}

void PrintGameOverScreen ()
{
    cout << Tabs(2) << "________________________________________________\n" << endl;
    cout << Tabs(2) << "             +++ G A M E  O V E R +++             " << endl;
    cout << Tabs(2) << "________________________________________________\n" << endl;
}

void PrintFinalGameResult (stGameResults GameResults)
{
    cout << Tabs(2) << "\n________________________________________________\n" << endl;
    cout << Tabs(2) << "\n________________[ Game Results ]________________\n" << endl;
    cout << Tabs(2) << "Game Rounds : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "User Won Times : " << GameResults.UserWinTimes << endl;
    cout << Tabs(2) << "Computer Won Times : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "\n________________________________________________\n" << endl;
}

void StartGame ()
{
    char PlayAgain = 'Y';
    do{
        ResetScrean ();
        stGameResults Results = PlayRounds(ReadHowManyRounds());
        PrintGameOverScreen ();
        PrintFinalGameResult(Results);
        cout << "Do you want to play again? Y/N?" << endl;
        cin >> PlayAgain;
    }while(PlayAgain != 'Y' || PlayAgain != 'y');
}

int main ()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}