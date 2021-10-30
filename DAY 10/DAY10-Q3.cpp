//547. Number of Provinces
class Solution
{
public:
    int findPar(vector<int> &parent, int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findPar(parent, parent[u]);
    }
    void unionn(vector<int> &parent, int u, int v)
    {
        u = findPar(parent, u);
        v = findPar(parent, v);
        if (u == v)
            return;
        else
            parent[v] = u;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j])
                {
                    unionn(parent, i + 1, j + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (parent[i] == i)
                ans++;
        }

        return ans;
    }
};