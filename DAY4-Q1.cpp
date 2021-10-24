//98. Validate Binary Search Tree
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *prev = NULL;
        return Solve(root, prev);
    }
    bool Solve(TreeNode *node, TreeNode *&prev)
    {
        if (node == NULL)
            return true;
        if (!Solve(node->left, prev))
            return false;
        if (prev != NULL && prev->val >= node->val)
            return false;
        prev = node;
        return Solve(node->right, prev);
    }
};