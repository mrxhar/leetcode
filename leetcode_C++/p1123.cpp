/*
@Author: mrxhar
@Date:   2023-09-06 08:26:06
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/?envType=daily-question&envId=2023-09-06
*/
#include <bits/stdc++.h>
using std::pair;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<TreeNode *, int> dfs(TreeNode *root) {
        if (!root)
            return {nullptr, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (left.second > right.second) {
            return {left.first, left.second + 1};  // 左树更深
        } else if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        return {root, left.second + 1};
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        return dfs(root).first;
    }
};