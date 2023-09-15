/*
@Author: mrxhar
@Date:   2023-09-09 08:51:37
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/course-schedule/?envType=daily-question&envId=2023-09-09
*/

#include <vector>
using std::vector;
#include <queue>
using std::queue;

// class Solution {
// private:
//     vector<vector<int>> graph;
//     vector<int> inDegree;

// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         // 需要从一个没有入度得点出发，遍历所有能够到达得点
//         // 建图，有向图
//         // 入度表
//         graph.resize(numCourses);
//         inDegree.resize(numCourses);
//         for (const auto& info : prerequisites) {
//             graph[info[1]].push_back(info[0]);
//             ++inDegree[info[0]];  // 记录入度和图
//         }

//         queue<int> q;
//         for (int i = 0; i < numCourses; i++) {
//             if (inDegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         int visited = 0;
//         while (!q.empty()) {
//             ++visited;
//             int u = q.front();
//             q.pop();
//             for (int v : graph[u]) {
//                 --inDegree[v];
//                 if (inDegree[v] == 0) {
//                     q.push(v);
//                 }
//             }
//         }
//         return visited == numCourses;
//     }
// };

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;  // 记录状态
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;  // 在搜索中
        for (int v : edges[u]) {
            if (visited[v] == 0) {  // 没有搜索过
                dfs(v);             // 搜索它
                if (!valid)
                    return;
            } else if (visited[v] == 1) {
                valid = false;  // 搜索中，闭环，代表这个深度路径不可行
                return;
            }
        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};