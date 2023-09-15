/*
@Author: mrxhar
@Date:   2023-09-07 09:29:52
@Email:  1337904145@qq.com
@Blog:
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
#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr)
            return carry ? new ListNode(carry) : nullptr;
        if (l1 == nullptr) {
            std::swap(l1, l2);
        }

        carry += l1->val + (l2 ? l2->val : 0);
        l1->val = carry % 10;
        l1->next = merge(l1->next, l2 ? l2->next : nullptr, carry / 10);
        return l1;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        return reverseList(merge(l1, l2));
    }
};

int main() {
    return 0;
}
