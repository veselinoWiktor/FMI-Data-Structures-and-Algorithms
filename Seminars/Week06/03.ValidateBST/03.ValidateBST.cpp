#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isValidBSTRec(const TreeNode* root, long min, long max) {
    if (root == nullptr)
        return true;

    if (root->val <= min || root->val >= max)
        return false;

    return isValidBSTRec(root->left, min, root->val)
        && isValidBSTRec(root->right, root->val, max);
}

bool isValidBST(const TreeNode* root) {
    return isValidBSTRec(root, LONG_MIN, LONG_MAX);
}

int main()
{
    // https://leetcode.com/problems/validate-binary-search-tree/
}