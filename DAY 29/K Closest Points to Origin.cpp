//973. K Closest Points to Origin
typedef pair<int, pair<int, int>> pd;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pd> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (pq.size() < k)
                pq.push({dist, {points[i][0], points[i][1]}});
            else
            {
                if (pq.top().first > dist)
                {
                    pq.pop();
                    pq.push({dist, {points[i][0], points[i][1]}});
                }
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};