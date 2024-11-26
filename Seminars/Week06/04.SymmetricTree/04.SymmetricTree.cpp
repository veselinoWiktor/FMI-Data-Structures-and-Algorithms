#include <iostream>
#include <deque>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int depth = 0;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool areSymetric(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (!left || !right) return false;

    if (left->val != right->val) {
        return false;
    }
    else {
        return areSymetric(left->left, right->right)
            && areSymetric(left->right, right->left);
    }
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    return areSymetric(left, right);
}

void printBFS(TreeNode* root) {
    if (!root) return;

    std::deque<TreeNode*> deq;
    deq.push_back(root);
    int counter = 0;
    
    while (!deq.empty())
    {
        int size = deq.size();
        while (size > 0)
        {
            TreeNode* curr;
            if (counter % 2 == 0) {
                curr = deq.back();
                if (curr->right) deq.push_front(curr->right);
                if (curr->left) deq.push_front(curr->left);
                std::cout << curr->val << " ";
                deq.pop_back();
            }
            else
            {
                curr = deq.front();
                if (curr->left) deq.push_back(curr->left);
                if (curr->right)deq.push_back(curr->right);
                std::cout << curr->val << " ";
                deq.pop_front();
            }

            size--;
        }
        counter++;
    }
}
int highest(int i,int j,int k)
{
    if (i > j && i > k)
    {
        return i;
    }
    else if (j > k)
    {
        return j;
    }
    else
    {
        return k;
    }
}


int maxDepth(TreeNode* root, int depth = 0) {
    if (!root) return -1;

    if (!root->left && !root->right) {
        std::cout << depth << " ";
        return depth;
    }

    int leftDepth = 0, rightDepth = 0;
    if (root->left) leftDepth = maxDepth(root->left, depth + 1);
    if (root->right) rightDepth = maxDepth(root->right, depth + 1);

    leftDepth -= depth;
    rightDepth -= depth;
    int max = depth;
    if (root->left && leftDepth > max) {
        max = leftDepth;
    }
    if (root->right && rightDepth > max) {
        max = rightDepth;
    }
    std::cout << max << " ";

    return leftDepth < rightDepth ? rightDepth + depth : leftDepth + depth;
}

int main()
{
    TreeNode* one = new TreeNode(1);

    TreeNode* four = new TreeNode(4);
    TreeNode* seven = new TreeNode(7);

    TreeNode* thithteen = new TreeNode(13);

    TreeNode* six = new TreeNode(6, four, seven);
    TreeNode* fourteen = new TreeNode(14, thithteen, nullptr);

    TreeNode* three = new TreeNode(3, one, six);
    TreeNode* ten = new TreeNode(10, nullptr, fourteen);

    TreeNode* root = new TreeNode(8, three, ten);

    maxDepth(root);

    // https://leetcode.com/problems/symmetric-tree
}