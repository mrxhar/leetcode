/*
@Author: mrxhar
@Date:   2023-09-08 10:47:49
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/minimum-incompatibility/?envType=daily-question&envId=2023-09-08
*/
#include <vector>
using std::vector;
#include <limits>
#include <unordered_map>
using std::unordered_map;
#include <set>
using std::max;
using std::min;
using std::set;
#include <string.h>

#include <algorithm>

int dp[(1 << 16) * 16];
class Solution {
public:
    int n, per, maxv = 1e9;
    vector<int> nums;
    int lowbit(int x) { return x & (-x); }  // lowbit 函数：求出当前数字最低位的 1。
    int f(int mask, int pre) {
        // mask 当前可以能够使用的数状态，可用为1
        // pre 上次选择的 num 中的第 pre个
        if (mask == 0) {  // 数组全利用了，不需要答案
            return 0;
        }
        if (dp[mask * n + pre] != -1) {
            return dp[mask * n + pre];
        }
        // cnt 当前还有多少可以使用的数
        // per 子集的大小
        // res 返回值
        int cnt = __builtin_popcount(mask), rem = cnt % per, res = maxv;
        //
        if (rem == 0) {                                         // 当前要为新子集分配数字
            res = f(mask ^ lowbit(mask), __builtin_ctz(mask));  // 剪枝：我们不妨从第一个可用的数字开始为新子集分配数字。
            for (int pre = 0; pre < n; ++pre) {
                dp[mask * n + pre] = res;  // 此时 pre 的数值不重要
            }
        } else {                                                 // 当前子集已经有了数字 nums[pre]，继续分配
            if (__builtin_popcount(mask >> (pre + 1)) >= rem) {  // 剪枝：剩余可用数字的个数必须足够填充当前子集
                for (int p = pre + 1; p < n; ++p) {
                    if ((mask & (1 << p)) && nums[p] > nums[pre]) {
                        res = min(res, f(mask ^ (1 << p), p) + nums[p] - nums[pre]);
                    }
                }
            }
            dp[mask * n + pre] = res;
        }
        return res;
    }

    int minimumIncompatibility(vector<int>& nums, int k) {
        n = nums.size(), per = n / k;
        if (k == 1) {
            set<int> s(nums.begin(), nums.end());
            if (s.size() < nums.size()) {
                return -1;
            }
            return (*s.rbegin()) - (*s.begin());
        }
        if (k == n) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        this->nums = nums;
        memset(dp, -1, (1 << n) * n * sizeof(int));

        int res = f((1 << n) - 1, 0);
        if (res >= 10000) {
            return -1;
        }
        return res;
    }
};

int main() {
    return 0;
}
