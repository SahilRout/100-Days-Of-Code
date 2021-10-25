//886. Possible Bipartition
class Solution
{
public:
    bool solve(int node, vector<vector<int>> adj, vector<int> &color)
    {
        if (color[node] == -1)
            color[node] = 1;

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (!solve(it, adj, color))
                    return false;
            }
            else if (color[it] == color[node])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> color(n + 1, -1);
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < dislikes.size(); i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                if (!solve(i, adj, color))
                    return false;
            }
        }

        return true;
    }
};