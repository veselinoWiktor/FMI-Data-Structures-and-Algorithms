#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


int maxDepth(TreeNode* root) {
	if (!root) return 0;

	int maxDepthLeft = maxDepth(root->left);
	int maxDepthRight = maxDepth(root->right);

	return std::max(maxDepthLeft, maxDepthRight) + 1;
}

int main() {
	// https://leetcode.com/problems/maximum-depth-of-binary-tree
}