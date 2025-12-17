#include <iostream>
using namespace std;

bool Is_PalindromeMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == matrix[i][cols - j - 1])
            {
                return true;
            }
        }
    }
    return false;
}

void PrintMatrix(int matrix[3][3], int cols, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}


int main()
{
    int Matrix1[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};

    cout << "Matrix: \n";
    PrintMatrix(Matrix1, 3, 3);
    cout << "\n";

    if (Is_PalindromeMatrix)
    cout << "Yes, Matrix is Palindrome" << endl;
    else
    cout << "No, Matrix is not Palindrome" << endl;

    return 0;
}
