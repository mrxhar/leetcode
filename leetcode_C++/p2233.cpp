/*
@Author: mrxhar
@Date:   2023-09-01 10:48:35
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-product-after-k-increments/?envType=daily-question&envId=2023-09-01
*/
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {

        // // 平均分配可能最大，每次都加最小的数，因为增加的数最大，所有的数和 - 最小的数
        // // 最小堆
        // int mod = 1000000007;
        // make_heap(nums.begin(), nums.end(), greater<int>());
        // while (k--)
        // {
        //     pop_heap(nums.begin(), nums.end(), greater<int>());
        //     ++nums.back();
        //     push_heap(nums.begin(), nums.end(), greater<int>());
        // }
        // int res = 1;
        // for (auto num : nums)
        // {
        //     res = (long long)num * res % mod;
        // }
        // return res;
        int mod = 1000000007;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        nums.push_back(INT_MAX);
        for (int i = 0; i < n; i++)
        {
            long long tmp = (long long)(i + 1) * (nums[i + 1] - nums[i]);
            if (k >= tmp) // 最关键一步，进行判断，可以增加到的 i 值，使得前面所有的数都是相等的
            {
                k -= tmp;
                continue;
            }
            // 进行剩余数的判断，剩余数使得前面 剩余个数的数 这样均衡，使得乘积最大
            int d = k / (i + 1); // 剩余数可以分配的个数
            int m = k % (i + 1);
            for (int j = 0; j <= i; ++j)
            {
                nums[j] = nums[i] + d;
                if (j < m)
                {
                    ++nums[j];
                }
            }
            break;
        }
        nums.pop_back();
        int res = 1;
        for (int num : nums)
        {
            res = (long long)num * res % mod;
        }
        return res;
    }
};