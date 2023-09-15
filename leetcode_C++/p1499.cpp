/*
@Author: mrxhar
@Date:   2023-09-09 10:23:30
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/max-value-of-equation/description/?envType=daily-question&envId=2023-09-09
*/
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <climits>
using std::pair;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        deque<pair<int, int>> dq;  // 存储两个值 一个是 y - x ,一个是 x
        for (auto& p : points) {
            // 弹出不符合条件的值
            while (!dq.empty() && dq.front().second <= p[0] - k)
                dq.pop_front();
            // 符合条件的值
            if (!dq.empty()) {
                ans = std::max(ans, p[1] + dq.front().first + p[0]);
            }
            while (!dq.empty() && dq.back().first <= p[1] - p[0]) {
                dq.pop_back();
            }
            dq.push_back({p[1] - p[0], p[0]});
        }
        return ans;
    }
};
int main() {
    return 0;
}
