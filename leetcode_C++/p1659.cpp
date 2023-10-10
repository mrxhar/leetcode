#include <cmath>
#include <cstring>
using namespace std;
class Solution {
    static constexpr int T = 243, N = 5, M = 6;
    // // 三进制状态压缩+动态规划
    // int n, m, tot;
    // int mask_bit[T][N]; // 记录 每个mask 对应的  bit 状态，这个bit 状态为 5 因为一行只有五个位置
    // int iv_count[T], ev_count[T];
    // int inner_score[T], inter_score[T][T];
    // int d[N][T][M + 1][M + 1]; // dfs 记忆化搜索的结果

    // 轮廓线进行转移
    int n, m, tot;
    int p[N];
    int d[N * N][T][M + 1][M + 1];
    // ；邻居间的分数
    static constexpr int score[3][3] = {
        {0, 0, 0},
        {0, -60, -10},
        {0, -10, 40}};

public:
    // void init_data() {
    //     for (int mask = 0; mask < tot; mask++) {
    //         int mask_tmp = mask;
    //         for (int i = 0; i < n; i++) {
    //             int x = mask_tmp % 3;
    //             mask_bit[mask][i] = x;
    //             mask_tmp /= 3;
    //             if (x == 1) // 内向
    //             {
    //                 iv_count[mask]++; // 内向的人
    //                 inner_score[mask] += 120;
    //             } else if (x == 2) {
    //                 ev_count[mask]++;
    //                 inner_score[mask] += 40;
    //             }
    //             if (i > 0) {
    //                 inner_score[mask] += score[x][mask_bit[mask][i - 1]];
    //             }
    //         }
    //     }
    //     // 计算行间分数
    //     for (int i = 0; i < tot; i++) {
    //         for (int j = 0; j < tot; j++) {
    //             inter_score[i][j] = 0;
    //             for (int k = 0; k < N; k++) {
    //                 inter_score[i][j] += score[mask_bit[i][k]][mask_bit[j][k]];
    //             }
    //         }
    //     }
    // }

    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->n = n;
        this->m = m;
        this->tot = pow(3, n); // 所有状态
        // // 预先处理出一行的所有状态的 行间分数与行内分数。
        // // 然后放在 dfs 里面，只需要枚举每一个 行状态即可，判断是否符合条件。
        // init_data();
        // memset(d, -1, sizeof d);
        // return dfs(0, 0, introvertsCount, extrovertsCount);

        // 按 轮廓线 进行转移
        p[0] = 1; //
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * 3; // 状态数
        }
        memset(d, -1, sizeof(d));
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    int dfs(int pos, int mask, int iv, int ev) {
        //     if (row == m || (iv == 0 && ev == 0)) {
        //         return 0;
        //     }
        //     if (d[row][premask][iv][ev] != -1) {
        //         return d[row][premask][iv][ev];
        //     }

        //     int &res = d[row][premask][iv][ev];
        //     res = 0;

        //     for (int mask = 0; mask < tot; mask++) {
        //         if (iv_count[mask] > iv || ev_count[mask] > ev) {
        //             // mask 状态存在的 iv 和 ev 不符合要求
        //             continue;
        //         }
        //         res = max(res,
        //                   dfs(row + 1, mask, iv - iv_count[mask], ev - ev_count[mask]) + inner_score[mask] + inter_score[premask][mask]);
        //     }
        //     return res;
        // }
        // 按位置进行转移
        if (pos == n * m || (iv == 0 && ev == 0)) {
            // 结束了
            return 0;
        }
        int &res = d[pos][mask][iv][ev];
        if (res != -1) {
            return res;
        }
        // mask / p[n - 1]
        // 左边的状态 ： mask % 3
        // up 为 pos 上面的状态
        // left 为 pos 左边的状态
        int up = mask / p[n - 1], left = mask % 3;
        // 第一列，左侧没有元素
        if (pos % n == 0) {
            left = 0;
        }
        // 枚举当前位置的状态
        for (int i = 0; i < 3; i++) {
            if ((i == 1 && iv == 0) || (i == 2 && ev == 0)) {
                // 当不够时候不能是某些状态
                continue;
            }
            int next_mask = mask % p[n - 1] * 3 + i; // 更新状态，这个mask 是 这条轮廓线的状态
            int score_sum = dfs(pos + 1, next_mask, iv - (i == 1), ev - (i == 2)) + score[up][i] + score[left][i];
            if (i == 1) {
                score_sum += 120;
            } else if (i == 2) {
                score_sum += 40;
            }
            res = max(res, score_sum);
        }
        return res;
    }
};