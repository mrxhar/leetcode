/*
@Author: mrxhar
@Date:   2023-09-11 09:51:17
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/?envType=daily-question&envId=2023-09-11
*/
#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;
#include <tuple>
using std::tuple;

// class Solution {
//     bool dfs(vector<vector<int>> &mat, int &left_k, int i, int s) {
//         /// 不超过 s 的数组和
//         /// 终止条件
//         if (i < 0) {
//             return --left_k == 0;  // 递归到第一行，这时候的 left_k 是否用完，如果刚好 == 0 这时候返回 true
//         }
//         for (int x : mat[i]) {
//             if (x - mat[i][0] > s)  // 第一个都大于，后面的元素更大
//             {
//                 break;
//             }
//             if (dfs(mat, left_k, i - 1, s - (x - mat[i][0]))) {
//                 return true;
//             }
//         }
//         return false;
//     }

// public:
//     int kthSmallest(vector<vector<int>> &mat, int k) {
//         int sl = 0, sr = 0;
//         for (auto &row : mat) {
//             sl += row[0];
//             sr += row.back();
//         }

//         int left = sl - 1, right = sr;
//         while (left + 1 < right) {
//             int mid = left + (right - left) / 2;
//             int left_k = k;
//             // 剩余的元素和为 mid - sl,这时候我们需要遍历 dfs(k,m - 1,mid - s1)
//             if (dfs(mat, left_k, mat.size() - 1, mid - sl)) {  // 从最后开始遍历
//                                                                // 这时候 对比 mid - s1 与 left_k 的值的大小
//                 right = mid;
//             } else {
//                 left = mid;
//             }
//         }
//         return right;
//     }
// };

class Solution {
public:
    vector<int> kSamllestPairs(vector<int>& num1, vector<int>& num2, int k) {
        vector<int> ans;
        priority_queue<tuple<int, int, int>> pq;  // 大根堆
        int n = num1.size(), m = num2.size();
        pq.emplace(-num1[0] - num2[0], 0, 0);
        while (!pq.empty() && ans.size() < k) {  // 答案没有满
            auto [_, i, j] = pq.top();
            pq.pop();
            ans.push_back(num1[i] + num2[j]);
            if (j == 0 && i + 1 < n) {
                pq.emplace(-num1[i + 1] - num2[0], i + 1, 0);
            }
            if (j + 1 < m) {
                pq.emplace(-num1[i] - num2[j + 1], i, j + 1);
            }
        }
        return ans;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> a = {0};
        for (auto& row : mat) {
            a = kSamllestPairs(row, a, k);
        }
        return a.back();
    }
};