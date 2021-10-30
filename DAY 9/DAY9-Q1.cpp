//1219. Path with Maximum Gold

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int x, int y, int m, int n)
    {
        int ans = 0;
        int temp = 0;
        if (x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == 0)
            return 0;

        temp = grid[x][y];
        grid[x][y] = 0;
        ans = max(ans, dfs(grid, x - 1, y, m, n));
        ans = max(ans, dfs(grid, x, y - 1, m, n));
        ans = max(ans, dfs(grid, x + 1, y, m, n));
        ans = max(ans, dfs(grid, x, y + 1, m, n));

        grid[x][y] = temp;
        return ans + temp;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    ans = max(ans, dfs(grid, i, j, m, n));
                }
            }
        }

        return ans;
    }
};