#include <iostream>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int minDepthRecursive(TreeNode* root) {
	if (!root) {
		return 0;
	}
	if (!root->left && !root->right) {
		return 1;
	}

	int leftDepth = minDepthRecursive(root->left);
	int rightDepth = minDepthRecursive(root->right);

	if (leftDepth != 0 && rightDepth != 0) {
		return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	else if (leftDepth == 0) {
		return rightDepth + 1;
	}
	else {
		return leftDepth + 1;
	}
}

int minDepthIterative(TreeNode* root) {
	if (!root) return 0;

	int minDepth = 0;
	std::queue<TreeNode*> q;

	q.push(root);

	while (!q.empty()) {
		int size = q.size();
		minDepth++;

		while (size--) {
			TreeNode* currNode = q.front();
			q.pop();
			if (currNode->left) q.push(currNode->left);
			if (currNode->right) q.push(currNode->right);
			if (!currNode->left && !currNode->right) return minDepth;

		}
	}
	return minDepth;
}

int main() {
	// https://leetcode.com/problems/minimum-depth-of-binary-tree
}