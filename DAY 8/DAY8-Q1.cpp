//787. Cheapest Flights Within K Stops
class Solution
{
    void solve(int src, int dst, vector<vector<pair<int, int>>> &adj, vector<int> &vis, int cost, int k, int &fare)
    {
        if (k < -1)
            return;
        if (src == dst)
        {
            fare = min(fare, cost);
            return;
        }
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it.first] && cost + it.second <= fare)
                solve(it.first, dst, adj, vis, cost + it.second, k - 1, fare);
        }

        vis[src] = 0;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> vis(n, 0);
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int fare = INT_MAX;
        solve(src, dst, adj, vis, 0, k, fare);

        if (fare == INT_MAX)
            return -1;

        return fare;
    }
};