//685. Redundant Connection II
class Solution
{
public:
    vector<int> ans;
    int findPar(vector<int> &parent, int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findPar(parent, parent[u]);
    }
    void unionn(vector<int> &parent, vector<int> &rank, int u, int v)
    {
        u = findPar(parent, u);
        v = findPar(parent, v);
        if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else if (rank[v] > rank[u])
        {
            parent[u] = v;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    bool cycleDSU(vector<vector<int>> &adj, int n, vector<int> edge)
    {
        vector<int> parent(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        vector<int> rank(n + 1, 0);

        for (auto it : adj)
        {
            if (edge.size() > 0 && it == edge)
                continue;

            if (findPar(parent, it[0]) == findPar(parent, it[1]))
            {
                ans = it;
                return true;
            }
            else
                unionn(parent, rank, it[0], it[1]);
        }

        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> indegree(n + 1, -1);
        int i = 0;
        for (auto it : edges)
        {
            if (indegree[it[1]] != -1)
            {
                if (cycleDSU(edges, n, it))
                    return edges[indegree[it[1]]];
                else
                    return it;
            }
            else
            {
                indegree[it[1]] = i;
            }
            i++;
        }

        vector<int> temp;
        cycleDSU(edges, n, temp);
        return ans;
    }
};