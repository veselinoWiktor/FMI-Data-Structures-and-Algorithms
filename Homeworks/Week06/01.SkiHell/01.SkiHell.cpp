#include <iostream>
#include <vector>
#include <map>
#include <queue>

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode treeNodes[1000000]{ 0 };
long long colsSums[20000000]{ 0 };

int maxIdx = INT32_MIN;
int minIdx = INT32_MAX;

void sumCols(TreeNode* root, int index = 0) {
    if (!root)
        return;

    colsSums[index + 10000000] += root->val; // Offset index to handle negative indices

    if (index < minIdx) minIdx = index;
    if (index > maxIdx) maxIdx = index;

    sumCols(root->left, index - 1);
    sumCols(root->right, index + 1);
}

int main() {
    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int value, left, right;
        std::cin >> value >> left >> right;
        treeNodes[i].val = value;
        treeNodes[i].left = (left != -1) ? &treeNodes[left] : nullptr;
        treeNodes[i].right = (right != -1) ? &treeNodes[right] : nullptr;
    }

    sumCols(&treeNodes[0], 0);

    for (int i = minIdx; i <= maxIdx; ++i) {
        if (colsSums[i + 10000000] != 0) {
            std::cout << colsSums[i + 10000000] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
