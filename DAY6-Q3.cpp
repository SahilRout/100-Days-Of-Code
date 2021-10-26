//332. Reconstruct Itinerary
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> adj;
        vector<string> ans;
        int n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> s;
        s.push("JFK");
        while (!s.empty())
        {
            string src = s.top();
            if (adj[src].size() == 0)
            {
                ans.push_back(src);
                s.pop();
            }
            else
            {
                auto it = adj[src].begin();
                s.push(*it);
                adj[src].erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};