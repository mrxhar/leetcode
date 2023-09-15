/*
@Author: mrxhar
@Date:   2023-08-29 08:30:47
@Email:  1337904145@qq.com
@Blog:
*/
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cmath>

using std::min;
using std::queue;
using std::tuple;
using std::vector;

class Solution
{
private:
    static constexpr int dx[4] = {1, 0, -1, 0}; // constexpr 尽量放在编译阶段
    static constexpr int dy[4] = {0, 1, 0, -1};

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        vector<tuple<int, int, int, int>> items; // 距离，价格，坐标 x,y
        queue<tuple<int, int, int>> q;
        q.emplace(start[0], start[1], 0);
        if (pricing[0] <= grid[start[0]][start[1]] && grid[start[0]][start[1]] <= pricing[1])
        {
            // 起点的 价格符合我们的预期，加入到items。
            items.emplace_back(0, grid[start[0]][start[1]], start[0], start[1]); // 直接在容器尾部创建元素，不同于push_back 要进行拷贝移动销毁。
        }
        grid[start[0]][start[1]] = 0; // 标记为无法穿越，以防重复遍历
        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty())
        {
            auto [x, y, d] = q.front(); // c++ 17
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0)
                {
                    if (pricing[0] <= grid[nx][ny] && grid[nx][ny] <= pricing[1])
                    {
                        items.emplace_back(d + 1, grid[nx][ny], nx, ny);
                    }
                    q.emplace(nx, ny, d + 1);
                    grid[nx][ny] = 0; // 标记为无法穿越，以防重复遍历
                }
            }
        }
        sort(items.begin(), items.end());
        vector<vector<int>> res;
        int cnt = min(k, static_cast<int>(items.size()));
        for (int i = 0; i < cnt; ++i)
        {
            auto [d, price, x, y] = items[i];
            res.push_back({x, y}); // 初始化列表
        }
        return res;
    }
};
