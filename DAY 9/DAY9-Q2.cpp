//1376. Time Needed to Inform All Employees
class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < manager.size(); i++)
        {
            adj[manager[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({headID, 0});
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int time = q.front().second;
                int node = q.front().first;
                q.pop();
                int dur = informTime[node] + time;
                ans = max(ans, dur);
                for (auto it : adj[node])
                {
                    q.push({it, dur});
                }
            }
        }

        return ans;
    }
};