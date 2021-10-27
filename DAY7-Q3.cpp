//Implementing Dijkstra Algorithm
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, INT_MAX);

        dis[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis[v] > dis[node] + w)
                {
                    dis[v] = dis[node] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis;
    }
};