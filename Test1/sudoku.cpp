
#include <iostream>
using namespace std;

int board[9][9];

// Function to print Sudoku
void printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check whether number is valid
bool isValid(int row, int col, int num)
{
    // Check row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    // Find starting position of 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    // Check 3x3 subgrid
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

// Function to solve Sudoku
bool solveSudoku()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // Find empty cell
            if (board[row][col] == 0)
            {
                // Try numbers from 1 to 9
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(row, col, num))
                    {
                        board[row][col] = num;

                        if (solveSudoku())
                            return true;

                        // Backtracking
                        board[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main()
{
    cout << "Enter Sudoku (use 0 for empty cells):" << endl;

    // Take input from user
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];

            if (board[i][j] < 0 || board[i][j] > 9)
            {
                cout << "Invalid input!" << endl;
                return 0;
            }
        }
    }

    // Check initial Sudoku for duplicates
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int num = board[i][j];

            if (num != 0)
            {
                board[i][j] = 0;

                if (!isValid(i, j, num))
                {
                    cout << "Invalid Sudoku!" << endl;
                    return 0;
                }

                board[i][j] = num;
            }
        }
    }

    if (solveSudoku())
    {
        cout << "\nSolved Sudoku:" << endl;
        printBoard();
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}
