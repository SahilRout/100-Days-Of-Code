//947. Most Stones Removed with Same Row or Column
class Solution
{
public:
    int dfs(vector<vector<int>> &stones, int node, vector<int> &vis, int &n)
    {
        vis[node] = true;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && (stones[i][0] == stones[node][0] || stones[i][1] == stones[node][1]))
                ans += (dfs(stones, i, vis, n) + 1);
        }
        return ans;
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                ans += dfs(stones, i, vis, n);
        }
        return ans;
    }
};