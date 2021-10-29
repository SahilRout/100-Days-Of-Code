//938. Range Sum of BST
class Solution
{
public:
    int ans;
    void solve(TreeNode *root, int low, int high)
    {
        if (!root)
            return;
        solve(root->left, low, high);
        if (root->val >= low && root->val <= high)
            ans = ans + root->val;
        solve(root->right, low, high);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        ans = 0;
        solve(root, low, high);
        return ans;
    }
};