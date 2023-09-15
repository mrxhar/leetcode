/*
@Author: mrxhar
@Date:   2023-09-07 08:45:50
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2023-09-07
*/
#include <vector>

using std::vector;
#include <algorithm>
#include <cmath>
#include <numeric>
using std::min;
using std::sqrt;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // 二分查找
        // 最长的时间是 能力最强的一直
        int min_r = ranks[0], cnt[101]{};
        for (auto r : ranks) {
            min_r = min(min_r, r);
            cnt[r]++;
        }
        long long left = 0, right = 1ll * (min_r * cars * cars);
        while (left + 1 < right) {
            long long mid = (left + right) / 2, s = 0;
            for (int r = 1; r <= 100; r++) {
                s += (long long)(sqrt(mid / r)) * cnt[r];
            }
            (s >= cars ? right : left) = mid;
        }
        return right;
    }
};

int main() {
    return 0;
}