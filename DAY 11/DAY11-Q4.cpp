class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j])
            return;

        grid[i][j] = 1;
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
            dfs(grid, i, 0, m, n), dfs(grid, i, m - 1, m, n);
        for (int i = 0; i < m; i++)
            dfs(grid, 0, i, m, n), dfs(grid, n - 1, i, m, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!grid[i][j])
                {
                    dfs(grid, i, j, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
};