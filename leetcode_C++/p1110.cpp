
#include <vector>
#include <deque>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
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
    vector<TreeNode *> ans;
    unordered_set<int> s;

    TreeNode *dfs(TreeNode *node) {
        if (node == nullptr) return nullptr;
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        if (!s.count(node->val)) {
            return node; // 该节点不需要删除可以返回，如果该节点需要删除
        }
        if (node->left) {
            ans.push_back(node->left);
        }
        if (node->right) {
            ans.push_back(node->right);
        }
        // 需要删除
        return nullptr;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        for (int i : to_delete) s.insert(i);
        if (dfs(root)) ans.push_back(root);
        return ans;

        // 宽度有向遍历
    }
};
