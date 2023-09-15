/*
@Author: mrxhar
@Date:   2023-09-06 09:17:02
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/dinner-plate-stacks/?envType=daily-question&envId=2023-09-06
*/
#include <vector>
using std::vector;
#include <stack>
using std::stack;
#include <algorithm>
#include <queue>

class DinnerPlates {
private:
    vector<stack<int>> stacks;  // 栈的集合
    int capacity;               // 容量
    // 维护没有满的栈下标
    // 使用小根堆，这样插入的时候就可以直接插入导小根堆堆顶索引的栈位置处
    // 删除的时候也可以将未满的栈加入到小根堆里面进行维护
    std::priority_queue<int, vector<int>, std::greater<int>> idx;  // 没有满的栈下标

public:
    DinnerPlates(int capacity) : capacity(capacity) {}

    void push(int val) {
        if (!idx.empty() && idx.top() >= stacks.size())  // 最大的索引对应着最右的不为空栈
        {
            while (!idx.empty()) {
                // 越界下标，弹出
                idx.pop();
            }
        }
        if (idx.empty()) {
            stack<int> st;
            st.push(val);
            stacks.emplace_back(st);
            if (capacity > 1) {
                idx.push(stacks.size() - 1);  // 入栈
            }
        } else {
            auto& st = stacks[idx.top()];
            st.push(val);
            if (st.size() == capacity) {
                idx.pop();
            }
        }
    }

    int pop() {
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty())
            return -1;
        auto& st = stacks[index];
        if (st.size() == capacity) {
            idx.push(index);  // 变成未满的
        }
        int val = st.top();
        st.pop();
        while (!stacks.empty() && stacks.back().empty()) {
            // 最后一个栈为空，去除掉
            stacks.pop_back();
        }
        return val;
    }
};
