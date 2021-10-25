//200. Number of Islands
class Solution
{
public:
    void solveDFS(vector<vector<char>> &grid, int x, int y, int m, int n)
    {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1')
            return;

        grid[x][y] = '2';

        solveDFS(grid, x + 1, y, m, n);
        solveDFS(grid, x, y + 1, m, n);
        solveDFS(grid, x - 1, y, m, n);
        solveDFS(grid, x, y - 1, m, n);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    solveDFS(grid, i, j, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
};