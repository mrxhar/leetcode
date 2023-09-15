/*
@Author: mrxhar
@Date:   2023-09-03 09:19:11
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/?envType=daily-question&envId=2023-09-03
*/
class Solution
{
public:
    int numberOfCuts(int n)
    {
        if (n <= 1)
        {
            return 0;
        }
        // 偶数 均分
        if (n % 2 == 0)
        {
            return n / 2;
        }
        else
        {
            return n;
        }
    }
};