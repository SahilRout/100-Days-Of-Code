//37. Sudoku Solve
class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num)
                return false;
        }
        for (int j = 0; j < 9; j++)
        {
            if (board[j][col] == num)
                return false;
        }
        int boxRow = row - row % 3;
        int boxCol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + boxRow][j + boxCol] == num)
                    return false;
            }
        }

        return true;
    }
    bool Solve(vector<vector<char>> &board)
    {
        int row = 0, col = 0;
        bool isEmpty = false;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    row = i;
                    col = j;
                    isEmpty = true;
                    break;
                }
            }
        }
        if (isEmpty == false)
            return true;
        for (char c = '1'; c <= '9'; c++)
        {
            if (isSafe(board, row, col, c))
            {
                board[row][col] = c;
                if (Solve(board))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        Solve(board);
    }
};