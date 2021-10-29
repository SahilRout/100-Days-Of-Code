//129. Sum Root to Leaf Numbers
class Solution
{
public:
    int ans = 0;
    void Solve(TreeNode *root, int val)
    {
        if (!root)
            return;
        val *= 10;
        val += root->val;
        if (!root->left && !root->right)
        {
            ans += val;
            return;
        }
        Solve(root->left, val);
        Solve(root->right, val);
    }
    int sumNumbers(TreeNode *root)
    {
        Solve(root, 0);
        return ans;
    }
};