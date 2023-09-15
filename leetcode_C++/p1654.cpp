/*
@Author: mrxhar
@Date:   2023-08-30 09:14:03
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/minimum-jumps-to-reach-home/description/
*/
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        // 广度优先遍历
        // 当前位置，往前 a 个
        // 往后 b 个
        // 每一次递归，需要记录 当前位置 x 以及跳跃次数，还有上次状态是否是向前跳跃还是向后跳跃
        // 使用队列进行记录
        queue<tuple<int, int, int>> q;
        unordered_set<int> visited; // 非常有趣的一点是，使用符号区分位置及状态
        q.emplace(0, 1, 0);         // 记录状态  第一次状态一定是向前的
        visited.emplace(0);

        int lower = 0, upper = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) + b; // 最大的禁止地方，肯定不会超过 max(forbidden) + a 以及 x 当然 回退 b 格子，这个也是可能的
        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end()); // 转成set
        while (!q.empty())
        {
            auto [position, direction, step] = q.front();
            q.pop();
            if (position == x)
            {
                return step;
            }

            int nextPosition = position + a;
            int nextDirection = 1;
            if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition))
            {
                visited.emplace(nextPosition * nextDirection);
                q.emplace(nextPosition, nextDirection, step + 1);
            }
            if (direction == 1)
            {
                // 可以向后
                nextPosition = position - b;
                nextDirection = -1;
                if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition))
                {
                    visited.emplace(nextPosition * nextDirection);
                    q.emplace(nextPosition, nextDirection, step + 1);
                }
            }
        }
        return -1;
    }
};
