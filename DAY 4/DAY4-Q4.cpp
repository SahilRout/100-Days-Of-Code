//230. Kth Smallest Element in a BST
class Solution
{
public:
    int ans;
    void solve(TreeNode *root, int &k)
    {
        if (!root)
            return;
        solve(root->left, k);
        k--;
        if (k == 0)
            ans = root->val;
        solve(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        ans = 0;
        solve(root, k);
        return ans;
    }
};