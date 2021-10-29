//103. Binary Tree Zigzag Level Order Traversal
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                int ind = (flag) ? i : (size - 1 - i);
                row[ind] = curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            flag = !flag;
            ans.push_back(row);
        }

        return ans;
    }
};