
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() :
        val(0), next(nullptr) {
    }
    ListNode(int x) :
        val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) :
        val(x), next(next) {
    }
};

class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator<(const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // 每个重新记录和组织
        // 所有的node进优先队列
        for (auto &node : lists) {
            if (node) q.push({node->val, node});
        }

        ListNode head, *tail = &head; // 都是空的
        while (!q.empty()) {
            // 弹出一个最小的接上数组，并将其下一个压入队列
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) {
                q.push({f.ptr->next->val, f.ptr->next});
            }
        }
        return head.next;
    }
};