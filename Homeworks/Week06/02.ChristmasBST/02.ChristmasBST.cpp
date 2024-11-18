#include <iostream>
#include <vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

bool validateTree(TreeNode* root, int min = 1, int max = 300000000) {
	if (!root) return true;
    if (root->val < min || root->val > max)  return false;
    return validateTree(root->left, min, root->val - 1) && validateTree(root->right, root->val + 1, max);
}

int main()
{
    int T = 0, N = 0;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> N;
        std::vector<TreeNode> nodes(N);
        for (int j = 0; j < N; j++) {
            int value, left, right;
			std::cin >> value >> left >> right; 

            nodes[j].val = value;
            nodes[j].left = (left != -1) ? &nodes[left] : nullptr;
            nodes[j].right = (right != -1) ? &nodes[right] : nullptr;
        }

        validateTree(&nodes[0]) ? std::cout << 1 : std::cout << 0;
        std::cout << std::endl;
    }
}
