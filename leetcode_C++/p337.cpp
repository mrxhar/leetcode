/*
@file:
@description:
@author: mrxhar
@date: 2023-09-18 08:39:11
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

//   Definition for a binary tree node.
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
private:
    pair<int, int> rob_traverse(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }
        auto left = rob_traverse(node->left);
        auto right = rob_traverse(node->right);

        int money = node->val + left.first + right.first;

        int ammoney = max(left.first, left.second) + max(right.first, right.second);
        return {ammoney, money}; // first no robed ,second robed
    }

public:
    int rob(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        auto res = rob_traverse(root);
        return max(res.first, res.second);
        // dpsdsadsasad    dsasa dsada}
    }
};