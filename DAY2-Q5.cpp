//987. Vertical Order Traversal of a Binary Tree
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *curr = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(curr->val);
            if (curr->left)
                q.push({curr->left, {x - 1, y + 1}});
            if (curr->right)
                q.push({curr->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto p : mp)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};