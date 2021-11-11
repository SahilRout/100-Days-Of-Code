//980. Unique Paths III
class Solution
{
public:
    int ans = 0, empty = 1;
    void solve(vector<vector<int>> &grid, int x, int y, int count)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1)
            return;

        if (grid[x][y] == 2)
        {
            if (count == empty)
            {
                ans++;
            }
            return;
        }

        grid[x][y] = -1;

        solve(grid, x + 1, y, count + 1);
        solve(grid, x, y + 1, count + 1);
        solve(grid, x - 1, y, count + 1);
        solve(grid, x, y - 1, count + 1);

        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int x = 0, y = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                else if (grid[i][j] == 0)
                {
                    empty++;
                }
            }
        }

        solve(grid, x, y, 0);

        return ans;
    }
};
