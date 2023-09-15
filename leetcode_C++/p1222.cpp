/*
@Author: mrxhar
@Date:   2023-09-14 09:02:46
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/queens-that-can-attack-the-king/description/?envType=daily-question&envId=2023-09-14
*/
#include <unordered_map>
#include <vector>
using namespace std;

// class Solution {
//     vector<pair<int, int>> ds{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// public:
//     vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
//         // 往八个方向遍历
//         unordered_set<int> qset;
//         for (const auto& queen : queens) {
//             int x = queen[0], y = queen[1];
//             qset.insert(x * 8 + y);
//         }

//         vector<vector<int>> ans;
//         for (auto& d : ds) {
//             int dx = d.first, dy = d.second;

//             auto x0 = king[0], y0 = king[1];
//             while (0 <= x0 && x0 < 8 && 0 <= y0 && y0 < 8) {
//                 int pos = x0 * 8 + y0;
//                 if (qset.count(pos)) {
//                     ans.push_back({x0, y0});
//                     break;
//                 }
//                 x0 += dx, y0 += dy;
//             }
//         }
//         return ans;
//     }
// };
// 枚举皇后
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        auto sgn = [](int x) -> int {
            return x > 0 ? 1 : (x == 0 ? 0 : -1);
        };

        unordered_map<int, pair<vector<int>, int>> candidates;
        int kx = king[0], ky = king[1];
        for (const auto& queen : queens) {
            int qx = queen[0], qy = queen[1];
            int x = qx - kx, y = qy - ky;
            if (x == 0 || y == 0 || abs(x) == abs(y)) {
                int dx = sgn(x), dy = sgn(y);
                int key = dx * 10 + dy;
                if (!candidates.count(key) || candidates[key].second > (abs(x) + abs(y))) {
                    // 没有这个方向
                    candidates[key] = {queen, abs(x) + abs(y)};
                }
            }
        }

        vector<vector<int>> ans;
        for (const auto& [_, value] : candidates) {
            ans.push_back(value.first);
        }
        return ans;
    }
};