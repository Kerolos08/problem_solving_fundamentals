#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel {EasyLevel = 1, MidLevel = 2, HardLevel = 3, MixedLevel = 5};
enum enOperatorType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixedOP = 5};

struct stQuestion
{
    int number1 = 0;
    int number2 = 0;
    enQuestionsLevel Difficulty;
    enOperatorType OperationType;
    int UserAnswer = 0;
    int RightAnswer = 0;
    bool IsTrue = false;
};

struct stFullQuiez
{
    stQuestion QuestionsList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionLevels;
    enOperatorType OpType;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool IsPass = false;
};

short RandomNumber (int From, int To)
{ 
//Function to generate a random number
short randNum = rand() % (To - From + 1) + From;
return randNum;
}

enQuestionsLevel ReadQuestionLevel ()
{
    short QuestionLevel;
    do{
        cout << "Enter Question Level [1] Easy, [2] Mid, [3] Hard, [4] Mix ";
        cin >> QuestionLevel;
    }while (QuestionLevel < 0 || QuestionLevel > 4);
    return (enQuestionsLevel)QuestionLevel;
}

enOperatorType ReadOperatorType ()
{
    short OpType;
    do{
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ";
        cin >> OpType;
    }while (OpType < 0 || OpType > 5);
    return (enOperatorType)OpType;
}

short ReadHowManyQuestions ()
{
    short HowManyQuestions;
    do{
        cout << "How Many Questions Do You Want To Answar ? ";
        cin >> HowManyQuestions;
    }while (HowManyQuestions < 0 || HowManyQuestions > 10);
    return HowManyQuestions;
}

string ReturnStringOperator (enOperatorType OP)
{
    switch (OP)
    {
        case enOperatorType::Add:
        return "+";
        case enOperatorType::Sub:
        return "-";
        case enOperatorType::Mul:
        return "*";
        case enOperatorType::Div:
        return "/";
        default:
        return "Mix";
    }
}

void SetScreenColor (bool right)
{
    if (right)
    {
        system("color 2F");
    }
    else
    {
    system("color 4F");
    system("\a");
    }

}

string GetLevelName (enQuestionsLevel Level)
{
    string Levels[4] = {"Easy", "Mid", "Hard", "Mix"};
    return Levels[Level - 1];
}

enOperatorType GetRandomOperator (enOperatorType OPtype)
{
    int op = RandomNumber(1,4);
    return enOperatorType(op);
}

int SimpleCalculator (int number1, int number2, enOperatorType OpType)
{
    switch (OpType)
    {
        case enOperatorType::Add:
        return number1 + number2;

        case enOperatorType::Sub:
        return number1 - number2;

        case enOperatorType::Mul:
        return number1 * number2;

        case enOperatorType::Div:
        return number1 / number2;

        default:
        return number1 + number2;
    }
}

enOperatorType GetRandomOperationType()
{
    int Op = RandomNumber(1, 4);
    return (enOperatorType)Op;
} 


stQuestion GenerateQuestion (enQuestionsLevel Level, enOperatorType OPtype)
{
    stQuestion Question;

    if (Level == enQuestionsLevel::MixedLevel)
    {
        Level = (enQuestionsLevel) RandomNumber(1, 3);
    }
    if (OPtype == enOperatorType::MixedOP)
    {
        OPtype = GetRandomOperationType();
    }
    Question.OperationType = OPtype;

    switch (Level)
    {
        case enQuestionsLevel::EasyLevel:
        Question.number1 = RandomNumber(0, 10);
        Question.number2 = RandomNumber(0, 10);
        Question.RightAnswer = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
        return Question;

        case enQuestionsLevel::MidLevel:
        Question.number1 = RandomNumber(10, 50);
        Question.number2 = RandomNumber(10, 50);
        Question.RightAnswer = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
        return Question;

        case enQuestionsLevel::HardLevel:
        Question.number1 = RandomNumber(50, 100);
        Question.number2 = RandomNumber(50, 100);
        Question.RightAnswer = SimpleCalculator(Question.number1, Question.number2, Question.OperationType);
        return Question;
    }
    return Question;
}

void CreateQiezQuestionList (stFullQuiez& Qiezz)
{
    for (short CurrentQuestion = 0; CurrentQuestion < Qiezz.NumberOfQuestions; CurrentQuestion++)
    {
        Qiezz.QuestionsList[CurrentQuestion] = GenerateQuestion(Qiezz.QuestionLevels, Qiezz.OpType);
    }
}

void PrintQuestion (stFullQuiez& Quiezz, short QuestionNumber)
{
    cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quiezz.NumberOfQuestions << "]" << endl;
    cout << Quiezz.QuestionsList[QuestionNumber].number1 << endl;
    cout << ReturnStringOperator(Quiezz.QuestionsList[QuestionNumber].OperationType) << endl;
    cout << Quiezz.QuestionsList[QuestionNumber].number2;
    cout << "\n_________________\n";
}

int ReadUsersAnswer ()
{
    int number;
    cin >> number;
    return number;
}

void CheckAndCorrectUsersAnswers (stFullQuiez& Quiezz, short NumberOfTheRound)
{
    if (Quiezz.QuestionsList[NumberOfTheRound].UserAnswer != Quiezz.QuestionsList[NumberOfTheRound].RightAnswer)
    {
        Quiezz.QuestionsList[NumberOfTheRound].IsTrue = false;
        Quiezz.NumberOfWrongAnswers++;
        cout << "Wrong Answer" << endl;
        cout << "The right answer is : " << Quiezz.QuestionsList[NumberOfTheRound].RightAnswer << endl;
    }
    else
    Quiezz.QuestionsList[NumberOfTheRound].IsTrue = true;
    Quiezz.NumberOfRightAnswers++;
    cout << "Right Answer" << endl;

    SetScreenColor(Quiezz.QuestionsList[NumberOfTheRound].IsTrue);
}

void AskAndCorrectTheQuestionList (stFullQuiez& Quiezz)
{
    for (short CurrentQuestion = 0; CurrentQuestion < Quiezz.NumberOfQuestions; CurrentQuestion++)
    {
        PrintQuestion(Quiezz, CurrentQuestion);
        Quiezz.QuestionsList[CurrentQuestion].UserAnswer = ReadUsersAnswer();
        CheckAndCorrectUsersAnswers(Quiezz, CurrentQuestion);
        Quiezz.IsPass = (Quiezz.NumberOfRightAnswers >= Quiezz.NumberOfWrongAnswers);
    }
}

string PrintPassorFail (bool pass)
{
    if(pass)
        return "You Passed :)";
    else
        return "You Failled :(";
}

void PrintAllQuiezResults (stFullQuiez Queiezz)
{
    {
    cout << "\n_________________________________\n" << endl;
    cout <<PrintPassorFail (Queiezz.IsPass);
    cout << "\n_________________________________" << endl;
    cout  << "\nNumber of Questions : " << Queiezz.NumberOfQuestions << endl;
    cout << "Question Level : " << GetLevelName(Queiezz.QuestionLevels) << endl;
    cout << "OP Type : " << ReturnStringOperator(Queiezz.OpType) << endl;
    cout << "Number Of right answers : " << Queiezz.NumberOfRightAnswers << endl;
    cout << "Number oF Wrong answers : " << Queiezz.NumberOfWrongAnswers << endl;
}
}

void PlayMathGame ()
{
    stFullQuiez Quiezz;
    Quiezz.NumberOfQuestions = ReadHowManyQuestions();
    Quiezz.QuestionLevels = ReadQuestionLevel();
    Quiezz.OpType = ReadOperatorType();

        CreateQiezQuestionList(Quiezz);
        AskAndCorrectTheQuestionList(Quiezz);
        PrintAllQuiezResults(Quiezz);
}

void ResetScreen ()
{
    system ("cls");
    system ("color 0F");
}

void StartGame ()
{
    char PlayAgain = 'Y';
    do{
        PlayMathGame();
        cout << "Do you want to play again? Y/N?" << endl;
        cin >> PlayAgain;
    }while(PlayAgain == 'Y' || PlayAgain == 'y');
}

int main ()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}
