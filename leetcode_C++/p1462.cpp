/*
@Author: mrxhar
@Date:   2023-09-12 09:05:30
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/course-schedule-iv/?envType=daily-question&envId=2023-09-12
*/

#include <vector>
using std::vector;
#include <cstring>
#include <queue>
using namespace std;
// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         // 是否是前一个节点的
//         bool f[numCourses][numCourses];

//         memset(f, false, sizeof(f));

//         for (auto& p : prerequisites) {
//             f[p[0]][p[1]] = true;
//         }

//         for (int k = 0; k < numCourses; k++) {
//             for (int i = 0; i < numCourses; i++) {
//                 for (int j = 0; j < numCourses; j++) {
//                     f[i][j] |= (f[i][k] && f[k][j]);
//                 }
//             }
//         }

//         vector<bool> ans;
//         for (auto& q : queries) {
//             ans.push_back(f[q[0]][q[1]]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 拓扑排序
        bool f[numCourses][numCourses];

        memset(f, false, sizeof(f));

        vector<int> g[numCourses];
        vector<int> indeg(numCourses);

        for (auto& p : prerequisites) {
            g[p[0]].push_back(p[1]);
            ++indeg[p[1]];
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();

            q.pop();

            for (int j : g[i]) {
                f[i][j] = true;
                for (int h = 0; h < numCourses; h++) {
                    f[h][j] |= f[h][i];  // 更新其他节点, h 节点是否能够到达 j 取决于 h 是否到达 i，i —> j ,然后就建立起， h 和 j 的关系。
                }
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(f[q[0]][q[1]]);
        }
        return ans;
    }
};