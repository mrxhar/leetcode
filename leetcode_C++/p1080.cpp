/*
@file: name
@description:
@author: mrxhar
@date: 2023-10-08 10:49:08
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

//  Definition for a binary tree node.
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
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit) {
        limit -= root->val;                                               // 限制值进一步减少
        if (root->left == root->right) return limit > 0 ? nullptr : root; // 返回空
        if (root->left) root->left = sufficientSubset(root->left, limit);
        if (root->right) {
            root->right = sufficientSubset(root->right, limit);
        }
        return root->left || root->right ? root : nullptr; // 如果左右数存在一个则返回root 如果都不存在 返回空节点
    }
};