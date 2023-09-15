/*
@Author: mrxhar
@Date:   2023-09-06 08:53:29
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/swap-nodes-in-pairs/?envType=daily-question&envId=2023-09-06
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 两两交换，这时候我们需要一个 虚拟的头节点，保存头位置
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head && head->next) {
            // 确保交换的节点不为空
            // 保存需要跳到的下一个接待你位置
            ListNode* next = head->next->next;
            // 交换
            prev->next = head->next;
            head->next->next = head;
            head->next = next;
            head = next;
            prev = prev->next->next;
        }
        return dummy->next;
    }
};

int main() {
    return 0;
}
