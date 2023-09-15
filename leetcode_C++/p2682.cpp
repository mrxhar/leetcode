/*
@Author: mrxhar
@Date:   2023-09-05 10:03:23
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/find-the-losers-of-the-circular-game/?envType=daily-question&envId=2023-09-05
*/
#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        // 模拟
        // 模拟的话，记录访问过的节点，这个节点可以记录在二进制里面
        // 然后每次从二进制里面取出来，然后每次取出来之后，就从后面开始遍历，
        vector<bool> visited(n, false);
        for (int i = k, j = 0; !visited[j]; i += k)
        {
            visited[j] = true;
            j = (j + i) % n; // j 的值，下一个访问道德位置，j + i 累和
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}
