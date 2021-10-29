//207. Course Schedule
class Solution
{
public:
    bool Solve(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis)
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (Solve(it, adj, vis, dfsVis))
                    return true;
            }
            else if (dfsVis[it])
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (Solve(i, adj, vis, dfsVis))
                    return false;
            }
        }

        return true;
    }
};