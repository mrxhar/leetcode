/*
@Author: mrxhar
@Date:   2023-08-30 10:22:55
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/kth-smallest-instructions/
*/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string kthSmallestPath(vector<int> &destination, int k)
    {
        /*
        相当于二分法，其中 为了确定 k 的位置
        其中 第一次分，也就是第一个字符进行确定,第一个字符为 H 的个数的 cob(h - 1,h + v - 1)
        当 k 小于 cob(h - 1,h + v - 1) 则这时候的 第一个元素一定为 H，
        当 k 大于 cob(h - 1,h + v - 1) 则这时候的 第一个元素为 H ，然后我们还需要调整 k 的值，我们不再在 所有元素的顺序字符串序列里面找，而是在 第一个元素确定为 V的元素里面进行寻在，这时候需要找的 k 的字符位置是 k - cob(h -1,h + v -1)。
        例如：
        当  k  = 1;
        ["HHHVV", <3| "HHVHV", "HHVVH",<2| "HVHHV", "HVHVH", "HVVHH", <1| "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
        当 k = 5:
        ["HHHVV", "HHVHV", "HHVVH",|2,k = 5 - 3 =2> "HVHHV",|4,k = 2 - 1 = 1> "HVHVH",<3| "HVVHH",<1| "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
        */
        // 动态规划
        int h = destination[1], v = destination[0];
        vector<vector<int>> comb(h + v, vector<int>(h));
        comb[0][0] = 1;
        for (int i = 1; i < h + v; ++i)
        {
            comb[i][0] = 1;
            for (int j = 1; j <= i && j < h; ++j)
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }

        string ans;
        for (int i = 0, imax = h + v; i < imax; ++i)
        {
            if (h > 0)
            {
                int o = comb[h + v - 1][h - 1];
                if (k > o)
                {
                    ans += 'V';
                    --v;
                    k -= o;
                }
                else
                {
                    ans += 'H';
                    --h;
                }
            }
            else
            {
                ans += 'V';
                --v;
            }
        }
        return ans;
    }
};
