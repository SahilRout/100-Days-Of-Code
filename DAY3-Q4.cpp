//116. Populating Next Right Pointers in Each Node
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (i != n)
                {
                    Node *next = q.front();
                    temp->next = next;
                }
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return root;
    }
};