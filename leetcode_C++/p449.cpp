/*
@Author: mrxhar
@Date:   2023-09-04 09:04:44
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/serialize-and-deserialize-bst/?envType=daily-question&envId=2023-09-04
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
using std::stoi;
using std::string;
using std::to_string;
#include <vector>
using std::vector;
#include <stack>
using std::stack;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // 二叉搜索树
        string res;
        vector<int> arr;
        // 转成 数组类型
        beforeOrder(root, arr);
        if (arr.size() == 0)
        {
            return res;
        }
        for (int i = 0; i < arr.size() - 1; i++)
        {
            res.append(to_string(arr[i]) + ",");
        }
        // 最后一个节点没有 ，
        res.append(to_string(arr.back()));
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return nullptr;
        }
        vector<string> arr = split(data, ',');
        stack<int> st;
        for (auto &str : arr)
        {
            // 压入栈中
            st.emplace(stoi(str));
        }
        return construct(INT_MIN, INT_MAX, st);
    }

    TreeNode *construct(int lower, int upper, stack<int> &st)
    {
        if (st.size() == 0 || st.top() < lower || st.top() > upper)
        {
            // 终止条件
            return nullptr;
        }
        int val = st.top();
        st.pop();
        TreeNode *root = new TreeNode(val);
        // 二叉搜索树特征，右树大于根节点，左数小于根节点
        root->right = construct(val, upper, st);
        root->left = construct(lower, val, st);
        return root;
    }

    /// @brief 后序遍历
    /// @param root
    /// @param arr
    void postOrder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrder(root->left, arr);
        postOrder(root->right, arr);
        arr.emplace_back(root->val);
    }

    /// @brief 后序遍历
    /// @param root
    /// @param arr
    void beforeOrder(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }
        arr.emplace_back(root->val);
        postOrder(root->left, arr);
        postOrder(root->right, arr);
    }

    /// @brief 分割字符串
    /// @param str
    /// @param dec
    /// @return
    vector<string> split(string &str, char dec)
    {
        int pos = 0;
        int start = 0;
        vector<string> res;
        while (pos < str.size())
        {
            while (pos < str.size() && str[pos] == dec)
            {
                // 跳过dec
                pos++;
            }
            start = pos; // 到达下一个string的起点
            while (pos < str.size() && str[pos] != dec)
            {
                // 跳过 这个string 到达尾部的 分隔符
                pos++;
            }
            if (start < str.size())
            {
                // 添加进去
                res.emplace_back(str.substr(start, pos - start));
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;