//Negative weight cycle
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto it : edges)
            {
                if (dist[it[0] == INT_MAX])
                    continue;
                if (dist[it[0]] + it[2] < dist[it[1]])
                {
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }
        for (auto it : edges)
        {
            if (dist[it[0]] + it[2] < dist[it[1]])
            {
                return 1;
            }
        }

        return 0;
    }
};