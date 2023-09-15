/*
@Author: mrxhar
@Date:   2023-09-05 08:31:54
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/?envType=daily-question&envId=2023-09-05
*/
#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;
#include <cmath>
using std::min;
#include <algorithm>

class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        // 首先肯定是共同有的数
        // 其次就是两个数组最小的数组合
        auto same = [&]() -> int
        {
            unordered_set<int> s(nums1.begin(), nums1.end());
            int x = 10;
            for (auto num : nums2)
            {
                if (s.count(num))
                {
                    x = min(num, x);
                }
            }
            return x == 10 ? -1 : x;
        };

        if (int x = same(); x != -1)
        {
            return x;
        }

        int x = *min_element(nums1.begin(), nums1.end());
        int y = *min_element(nums2.begin(), nums2.end());
        return min(x * 10 + y, y * 10 + x);
    }
};

int main()
{

    return 0;
}
