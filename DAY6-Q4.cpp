//133. Clone Graph
class Solution
{
    void dfs(Node *ele, Node *node, vector<Node *> &vis)
    {
        //Node* copy = new Node(node->val);
        vis[node->val] = node;
        for (auto it : ele->neighbors)
        {
            if (vis[it->val] == NULL)
            {
                Node *newnode = new Node(it->val);
                (node->neighbors).push_back(newnode);
                dfs(it, newnode, vis);
            }
            else
                (node->neighbors).push_back(vis[it->val]);
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        vector<Node *> vis(1000, NULL);
        Node *copy = new Node(node->val);
        vis[node->val] = copy;
        //Iterate for all neighbors
        for (auto ele : node->neighbors)
        {
            if (vis[ele->val] == NULL)
            {
                Node *newnode = new Node(ele->val);
                (copy->neighbors).push_back(newnode);
                dfs(ele, newnode, vis);
            }
            else
                (copy->neighbors).push_back(vis[ele->val]);
        }
        return copy;
    }
};
