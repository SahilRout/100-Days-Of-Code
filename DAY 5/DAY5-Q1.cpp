//785. Is Graph Bipartite?
class Solution
{
public:
    bool solveBFS(int node, vector<vector<int>> &graph, int color[])
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto it : graph[x])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[x];
                    q.push(it);
                }
                else if (color[it] == color[x])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int color[n];
        memset(color, -1, sizeof color);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!solveBFS(i, graph, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};