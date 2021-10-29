//733. Flood Fill
class Solution
{
public:
    void solve(vector<vector<int>> &grid, int x, int y, int r, int c, int newColor, int orignalColor)
    {
        if (x < 0 || y < 0 || x >= r || y >= c || grid[x][y] != orignalColor)
            return;

        if (grid[x][y] == orignalColor)
            grid[x][y] = newColor;

        solve(grid, x + 1, y, r, c, newColor, orignalColor);
        solve(grid, x, y + 1, r, c, newColor, orignalColor);
        solve(grid, x - 1, y, r, c, newColor, orignalColor);
        solve(grid, x, y - 1, r, c, newColor, orignalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        if (m <= 0)
            return image;
        int n = image[0].size();
        int orignalColor = image[sr][sc];
        if (orignalColor == newColor)
            return image;
        solve(image, sr, sc, m, n, newColor, orignalColor);
        return image;
    }
};