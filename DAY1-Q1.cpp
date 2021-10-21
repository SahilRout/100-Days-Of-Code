//105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution
{
public:
    int preInd = 0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int len = inorder.size();
        return Solve(preorder, inorder, 0, len - 1);
    }
    TreeNode *Solve(vector<int> &preorder, vector<int> &inorder, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[preInd++]);
        int ind;
        for (int i = start; i <= end; i++)
        {
            if (inorder[i] == node->val)
            {
                ind = i;
                break;
            }
        }
        node->left = Solve(preorder, inorder, start, ind - 1);
        node->right = Solve(preorder, inorder, ind + 1, end);
        return node;
    }
};