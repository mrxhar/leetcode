
#include <climits>
//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :
        val(0),
        left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x),
        left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x),
        left(left), right(right) {
    }
};
class Solution {
    // int ans = 0;

public:
    int goodNodes(TreeNode *root, int mx = INT_MIN) {
        // 获取好节点
        if (root == nullptr) {
            return 0;
        }
        int left = goodNodes(root->left, max(mx, root->val));
        int right = goodNodes(root->right, max(mx, root->val));
        return left + right + (mx <= root->val);
    }
};