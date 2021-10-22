//652. Find Duplicate Subtrees
class Solution
{
public:
    unordered_map<string, int> mp;
    vector<TreeNode *> ans;
    string solve(TreeNode *root)
    {
        if (!root)
            return "";

        string str = "(";
        str += solve(root->left);
        str += to_string(root->val);
        str += solve(root->right);
        str += ")";

        if (mp[str] == 1)
            ans.push_back(root);

        mp[str]++;

        return str;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        if (!root)
            return ans;
        solve(root);
        return ans;
    }
};