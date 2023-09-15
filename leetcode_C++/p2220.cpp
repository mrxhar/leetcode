/*
@Author: mrxhar
@Date:   2023-09-01 10:43:02
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2023-09-01
*/

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        // 位不同的个数
        int res = 0;
        int tmp = start ^ goal;
        while (tmp)
        {
            res += tmp & 1; // 尾部是否是 1 也可以进行判断奇偶性
            tmp >>= 1;
        }
        return res;
    }
};
