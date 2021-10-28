//684. Redundant Connection
class Solution
{
public:
    bool cycle(vector<vector<int>> &adj, vector<int> &vis, int node, int parent = -1)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (cycle(adj, vis, it, node))
                    return true;
            }
            else if (it != parent)
                return true;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = size(edges);
        vector<int> vis(n + 1);
        vector<vector<int>> adj(n + 1);
        for (auto it : edges)
        {
            fill(begin(vis), end(vis), 0);
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            if (cycle(adj, vis, it[0]))
                return it;
        }

        return {};
    }
};