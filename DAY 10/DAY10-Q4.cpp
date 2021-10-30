//1319. Number of Operations to Make Network Connected
class Solution
{
public:
    int findPar(int x, vector<int> &parent)
    {
        if (parent[x] == x)
            return parent[x];
        return parent[x] = findPar(parent[x], parent);
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int components = 0;

        for (auto it : connections)
        {
            int x = findPar(it[0], parent);
            int y = findPar(it[1], parent);

            if (x == y)
            {
                continue;
            }

            else
            {
                parent[y] = x;
                components++;
            }
        }

        return connections.size() < n - 1 ? -1 : n - 1 - components;
    }
};