/*
@Author: mrxhar
@Date:   2023-09-09 09:41:30
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/description/
*/

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

#include <functional>
using std::function;
using std::pair;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递
class Solution {
    int ans = 0;
    void dfs(TreeNode *node, int mn, int mx) {
        if (node == nullptr)
            return;
        mn = std::min(mn, node->val);
        mx = std::max(mx, node->val);
        ans = std::max(ans, std::max(node->val - mn, mx - node->val));
        dfs(node->left, mn, mx);
        dfs(node->right, mn, mx);
    }

public:
    int maxAncestorDiff(TreeNode *root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};

// class Solution {
//     int ans = 0;
//     pair<int, int> dfs(TreeNode *node) {
//         if (node == nullptr) {
//             return {INT_MAX, INT_MIN};
//         }
//         int mn = node->val, mx = mn;
//         auto [lmn, lmx] = dfs(node->left);
//         auto [rmn, rmx] = dfs(node->right);
//         mn = std::min(mn, std::min(lmn, rmn));
//         mx = std::max(mx, std::max(lmx, rmx));
//         ans = std::max(ans, std::max(mx - node->val, node->val - mn));
//         return {mn, mx};
//     }

// public:
//     int maxAncestorDiff(TreeNode *root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         dfs(root);
//         return ans;
//     }
// };

int main() {
    return 0;
}
