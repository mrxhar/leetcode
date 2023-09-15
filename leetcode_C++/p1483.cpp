/*
@Author: mrxhar
@Date:   2023-09-05 09:13:00
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/description/?envType=daily-question&envId=2023-09-05
*/

#include <vector>
using std::vector;

class TreeAncestor
{
    const int log = 16;
    vector<vector<int>> ancestors;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        ancestors = vector<vector<int>>(n, vector<int>(log, -1));
        for (int i = 0; i < n; i++)
        {
            ancestors[i][0] = parent[i];
        }
        // 表示 node\textit{node}node 向祖先方向移动了 2^j
        for (int j = 1; j < log; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (ancestors[i][j - 1] != -1)
                {
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        // k 可以分解为若干不同的 222 的幂（
        for (int j = 0; j < log; j++)
        {
            // 这时候容易出现问题
            if ((k >> j) & 1) // 移动 j 位，判断是否为奇数，移动j位是奇数的话，
            {
                node = ancestors[node][j];
                if (node == -1)
                {
                    return -1;
                }
            }
        }
        return node;
    }
};

int main()
{

    return 0;
}
