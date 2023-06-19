#include "TreeNode.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder, int k, int l, int r)
    {
        if (l > r)
            return nullptr;
        int temp = preorder[k];
        TreeNode* root = new TreeNode(temp);
        int index = l;
        while (inorder[index] != temp)
            index++;
        root->left = buildTree(preorder, inorder, k + 1, l, index - 1);
        root->right = buildTree(preorder, inorder, k + (index - l + 1), index + 1, r);
        return root;
    }
};