//124. Binary Tree Maximum Path Sum
class Solution
{
public:
    int maxSum = 0;
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = max(solve(root->left), 0);
        int r = max(solve(root->right), 0);
        maxSum = max(maxSum, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        maxSum = root->val;
        solve(root);
        return maxSum;
    }
};