/*
@Author: mrxhar
@Date:   2023-09-02 10:24:48
@Email:  1337904145@qq.com
@Blog:
*/
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        // 使用栈 记录 值和位置,

        vector<int> ans;
        stack<pair<int, int>> vis;
        ListNode *cur = head;
        int idx = -1;
        while (cur)
        {
            ++idx;
            ans.push_back(0);
            // 这样依次扩展内存，就可以保证我们的元素都可以进行插入
            // 循环判断顶点的值
            while (!vis.empty() && vis.top().first < cur->val)
            {
                // 当前值大于栈顶点值
                ans[vis.top().second] = cur->val;
                vis.pop();
            }

            vis.emplace(cur->val, idx);
            cur = cur->next;
        }
        return ans;
    }
};