/*
@Author: mrxhar
@Date:   2023-08-31 10:56:51
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/kth-largest-element-in-an-array/solutions/2361969/215-shu-zu-zhong-de-di-k-ge-zui-da-yuan-d786p/
*/
#include <vector>
#include <random>

using namespace std;

// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         return quict_sort(nums, k);
//     }
//     int quict_sort(vector<int> &nums, int k)
//     {
//         vector<int> big, small;
//         int pivot = nums[rand() % nums.size()];
//         for (auto num : nums)
//         {
//             if (num > pivot)
//             {
//                 big.emplace_back(num);
//             }
//             else if (num < pivot)
//             {
//                 small.emplace_back(num);
//             }
//         }
//         if (k <= big.size())
//         {
//             return quict_sort(big, k);
//         }
//         if (nums.size() - small.size() < k)
//         {
//             return quict_sort(small, k - (nums.size() - small.size()));
//         }
//         return pivot;
//     }
// };
#include <queue>
class Solution
{
public:
    // 构造最小堆；
    struct cmp
    {
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, cmp> heap;
        for (int i = 0; i < nums.size(); i++)
        {
            heap.push(nums[i]);
            if (heap.size() > k)
            {
                heap.pop();
            }
        }
        return heap.top();
    }
};