/*
@Author: mrxhar
@Date:   2023-09-05 09:34:45
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/reorder-list/?envType=daily-question&envId=2023-09-05
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }

        // 1.中点
        ListNode *mid = midnode(head);
        // 2.翻转后半部分
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        // 3.合并
        merge(l1, l2);
    }

    ListNode *midnode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        // 当前
        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void merge(ListNode *l1, ListNode *l2)
    {
        ListNode *l1_tmp;
        ListNode *l2_tmp;
        while (l1 != nullptr && l2 != nullptr)
        {
            l1_tmp = l1->next;
            l2_tmp = l2->next;
            l1->next = l2;
            l1 = l1_tmp;
            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};

int main()
{

    return 0;
}
