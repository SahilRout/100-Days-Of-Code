//743. Network Delay Time
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> dis(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        dis[k] = 0;
        pq.push({0, k});
        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                if (dis[it.first] > dis[node] + it.second)
                {
                    dis[it.first] = dis[node] + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ans < dis[i])
            {
                ans = dis[i];
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};