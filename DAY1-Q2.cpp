//106. Construct Binary Tree from Inorder and Postorder Traversal
class Solution
{
public:
    TreeNode *Solve(vector<int> &inorder, int x, int y, vector<int> &postorder, int a, int b)
    {
        if (x > y || a > b)
            return NULL;
        TreeNode *node = new TreeNode(postorder[b]);
        int SI = x;
        while (node->val != inorder[SI])
            SI++;
        node->left = Solve(inorder, x, SI - 1, postorder, a, a + SI - x - 1);
        node->right = Solve(inorder, SI + 1, y, postorder, a + SI - x, b - 1);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return Solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};