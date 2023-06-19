#include "TreeNode.h"
const int null = INT_MIN;

TreeNode* getTreeByVector(const std::vector<int>& nums)
{
    std::vector<TreeNode*> raw_datas;
    for (const auto& s : nums) {
        TreeNode* temp = s == null ? nullptr : new TreeNode(s);
        raw_datas.emplace_back(temp);
    }

    auto n = raw_datas.size();
    for (int i = 0; i < n; i++) {
        if (raw_datas[i]) {
            raw_datas[i]->left = (2 * i + 1 < n) ? raw_datas[2 * i + 1] : nullptr;
            raw_datas[i]->right = (2 * i + 2 < n) ? raw_datas[2 * i + 2] : nullptr;
        }
    }

    return raw_datas[0];
}
void dfs(TreeNode* root, int p, vector<TreeNode*>& v, bool& isFind)
{
    if (root == nullptr || isFind)
        return;
    v.push_back(root);
    if (p == root->val) {
        isFind = true;
        return;
    }
    if (root->left && isFind == false) {
        dfs(root->left, p, v, isFind);
        if (!isFind)
            v.pop_back();
    }
    if (root->right && isFind == false) {
        dfs(root->right, p, v, isFind);
        if (!isFind)
            v.pop_back();
    }
}
int lowestCommonAncestor(TreeNode* root, int p, int q)
{
    vector<TreeNode*> vector_p;
    vector<TreeNode*> vector_q;
    bool isFind = false;
    dfs(root, p, vector_p, isFind);
    isFind = false;
    dfs(root, q, vector_q, isFind);
    int i = 0, j = 0;
    while (i < vector_p.size() && vector_p[i]->val != p)
        i++;
    while (j < vector_q.size() && vector_q[j]->val != q)
        j++;
    while (i >= 0) {
        for (int k = j; k >= 0; k--) {
            if (vector_q[k]->val == vector_p[i]->val)
                return vector_p[i]->val;
        }
        i--;
    }
    return -1;
}

void dfs(TreeNode* root)
{
    if (root) {
        dfs(root->left);
        cout << root->val << " ";
        dfs(root->right);
    }
}

int main()
{
    std::vector<int> nums { 6, 2, 8, 0, 4, 7, 9, null, null, 3, 5 };
    TreeNode* root = getTreeByVector(nums);
    // vector<TreeNode*> vector_p;
    // vector<TreeNode*> vector_q;
    // int p = 2, q = 4;
    // std::cout << lowestCommonAncestor(root, p, q) << endl;
    dfs(root);
}