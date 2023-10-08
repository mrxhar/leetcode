#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time) {
        stable_sort(time.begin(), time.end(), [](auto &a, auto &b) {
            return a[0] + a[2] < b[0] + b[2];
        });

        priority_queue<pair<int, int>> waitL, waitR;                                    // 两边的队伍等待
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> workL, workR; // 工作的队伍 他们是时间 t 然后 是工号

        for (int i = k - 1; i >= 0; --i) {
            waitL.emplace(i, 0); // 进入都是时间0
        }

        int cur = 0; // 当前时间
        while (n) {
            // 每次我们都让工人从小去工作并且排队，如果他的时间小于当前时间，这时候他应该以及去排队了，工人除了排队需要等待，其他时刻不需要进行等待，可以直接进行
            while (!workL.empty() && workL.top().first <= cur) {
                auto [t, i] = workL.top();
                workL.pop();         // 弹出，他要去工作
                waitL.emplace(i, t); // 他放箱,回到岸边，也是重新出来工作
            }

            while (!workR.empty() && workR.top().first <= cur) {
                auto [t, i] = workR.top();
                workR.pop();
                waitR.emplace(i, t);
            }
            // 过桥运动，每次只操作一个工人，因为过桥不允许一起。
            if (!waitR.empty()) {
                auto [i, t] = waitR.top(); // 获得等待的工人的 工号 和 时间
                waitR.pop();
                cur += time[i][2]; // 第 i 个 工人的时间
                workL.emplace(cur + time[i][3], i);
            } else if (!waitL.empty()) {
                // 左边开始过桥
                auto [i, t] = waitL.top();
                waitL.pop();
                cur += time[i][0];
                workR.emplace(cur + time[i][1], i); // 过桥就直接去搬运箱子
                --n;                                // 如果可以运动到这，代表waitR 为空
            } else if (workL.empty()) {
                // 没有人等待过桥，这时候我们等待右边的工人国卡u
                cur = workR.top().first;
            } else if (workR.empty()) {
                cur = workL.top().first;
            } else {
                cur = min(workL.top().first, workR.top().first);
            }
        }
        while (!workR.empty()) {
            auto [t, i] = workR.top();
            workR.pop();
            cur = max(t, cur) + time[i][2];
        }
        return cur;
    }
};