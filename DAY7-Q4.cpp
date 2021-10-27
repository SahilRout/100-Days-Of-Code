//Shortest Path DAG
void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int src, int N, vector<pair<int,int>> adj[])
{
    vector<int> vis(N,0);
    stack<int> st;
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        findTopoSort(i,vis,st,adj);
    }
    for(int i=0;i<N;i++)
    {
        dis[i]=INT_MAX;
    }
    dis[src]=0;
    while(!st.empt())
    {
        int node=st.top();
        st.pop();
        if(dis[node]!=INT_MAX)
        {
            for(auto it : adj[node])
            {
                if(dis[node]+it.second<dis[it.first])
                {
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
    }

    return dis;
}