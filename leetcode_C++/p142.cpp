/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 快慢指针
        // 当快慢指针相等时候，或者快指针到顶点时候结束
        // 指针相等时候，fast在圈里走了slow同样的步数，则
        ListNode *fast = head;
        ListNode *slow = head;
        while (true)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }

        fast = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};