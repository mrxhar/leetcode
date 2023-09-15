/*
@Author: mrxhar
@Date:   2023-09-13 09:53:47
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/?envType=daily-question&envId=2023-09-13
*/
#include <vector>
using namespace std;

// class Solution {
// public:
//     int maxAbsoluteSum(vector<int>& nums) {
//         // 更新两个值
//         // 最大和最小
//         int res = 0;
//         int maxcur = 0;
//         int mincur = 0;
//         // 前面有
//         for (auto& num : nums) {
//             maxcur += num;
//             mincur -= num;

//             if (maxcur < 0) {
//                 maxcur = num;
//             }
//             if (mincur < 0) {
//                 mincur = -num;
//             }

//             res = max(res, max(maxcur, mincur));
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s = 0, mx = 0, mn = 0;
        for (int x : nums) {
            s += x;
            mx = max(mx, s);
            mn = min(mn, s);
        }

        return mx - mn;
    }
};