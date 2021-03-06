//1351. Count Negative Numbers in a Sorted Matrix
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int i = m - 1;
        int j = 0;
        int count = 0;
        while (i >= 0 && j < n)
        {
            if (grid[i][j] < 0)
            {
                count = count + (n - j);
                i--;
            }
            else
            {
                j++;
            }
        }

        return count;
    }
};