//Bridge edge in a graph
class Solution
{
    bool ans = false;
    void dfs(int c, int d, int node, int parent, vector<int> &vis, vector<int> &tim, vector<int> &low, int &timer, vector<int> adj[])
    {
        vis[node] = 1;
        tim[node] = low[node] = timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(c, d, it, node, vis, tim, low, timer, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] > tim[node])
                {
                    if (it == c && node == d || node == c && it == d)
                        ans = true;
                }
            }
            else
            {
                low[node] = min(low[node], tim[it]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        vector<int> vis(V, 0);
        vector<int> tim(V, -1);
        vector<int> low(V, -1);
        int timer = 1;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(c, d, i, -1, vis, tim, low, timer, adj);
            }
        }

        return ans;
    }
};