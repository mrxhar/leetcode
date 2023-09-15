/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <climits>
#include <tuple>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {
    }
};

class Solution {
    int ans = 0;
    tuple<int, int, bool> dfs(TreeNode *node) {
        if (node == nullptr) {
            return {INT_MAX, INT_MIN, 0};
        }
        auto [l_min, l_max, l_sum] = dfs(node->left);
        auto [r_min, r_max, r_sum] = dfs(node->right);
        int x = node->val;
        if (x <= l_max || x >= r_min) { // 判断是否是搜索二叉树
            return {INT_MIN, INT_MAX, 0};
        }
        int s = l_sum + r_sum + node->val;
        ans = max(ans, s);
        return {min(l_min, x), max(r_max, x), s};
    };

public:
    int maxSumBST(TreeNode *root) {
        dfs(root);
        return ans;
    }
};