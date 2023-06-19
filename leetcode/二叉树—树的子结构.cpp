#include "TreeNode.h"
class Solution {
public:
    bool isSameTree(TreeNode* A, TreeNode* B)
    {
        if (!B)
            return true; //说明B树已经遍历完成
        if (!A)
            return false; //说明越过了A的叶子节点  ,A为空不能说明A包含B
        return (A->val == B->val) && isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
    /*这里是自己调用自己
        isSameTree(A和B是否是相同的树)
        isSubStructure(A->left, B) || isSubStructure(A->right, B);
        B是不是和A的子树是子结构 */
    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        if (!A || !B)
            return false;
        if (isSameTree(A, B))
            return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    /*
        镜像二叉树
        1. 函数的功能是，给出一个root结点，返回一个镜像的二叉树
        2. 因此，先让左子树变成镜像二叉树，赋值给left; 再让右子树变成镜像二叉树，赋值给right
        3. 此时，让root的左边应该是右子树的镜像，root的右边应该是左子树的镜像
     */
    TreeNode* mirrorTree(TreeNode* root)
    {
        if (nullptr == root)
            return nullptr;
        TreeNode* left = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};