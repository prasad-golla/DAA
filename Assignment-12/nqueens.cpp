


#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n)
{
    for (int j = 0; j < col; j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }

    int r = row, c = col;

    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;

        r--;
        c--;
    }

    r = row;
    c = col;

    while (r < n && c >= 0)
    {
        if (board[r][c] == 'Q')
            return false;

        r++;
        c--;
    }

    return true;
}

void solve(int col, vector<string>& board, int n)
{
    if (col == n)
    {
        for (auto row : board)
            cout << row << endl;

        cout << endl;
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';

            solve(col + 1, board, n);

            board[row][col] = '.';
        }
    }
}

int main()
{
    int n = 4;

    vector<string> board(n, string(n, '.'));

    solve(0, board, n);

    return 0;
}
