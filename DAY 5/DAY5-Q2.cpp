//841. Keys and Rooms
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto x : rooms[node])
            {
                if (!vis[x])
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }

        for (auto it : vis)
        {
            if (!it)
                return false;
        }

        return true;
    }
};