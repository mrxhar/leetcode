/*
@Author: mrxhar
@Date:   2023-08-29 09:37:52
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/can-place-flowers/
*/
#include <vector>

using std::vector;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        // 每个地块有两种选择，种、不种
        // 种：需要检查之前一块地和后一块地状态
        // 不种：随时可以不种
        // 遍历所有地块，种花，种花后更新前后地块状态
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; ++i)
        {
            if (flowerbed[i] == 1)
            {
                // 已经种了地
                if (prev < 0)
                {
                    count += i / 2; // 最初的点到目前位置都没有种过花
                }
                else
                {
                    count += (i - prev - 2) / 2; // 上一块有花的地到 i 点没有种过花
                }
                if (count >= n)
                {
                    return true;
                }

                prev = i;
            }
        }
        if (prev < 0)
        {
            count += (m + 1) / 2;
        }
        else
        {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};