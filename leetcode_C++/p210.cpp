/*
@Author: mrxhar
@Date:   2023-09-10 09:06:55
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/course-schedule-ii/?envType=daily-question&envId=2023-09-10
*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;  // 邻接表
    vector<int> indegree;       // 入度数组

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 返回顺序
        vector<int> res;
        // 初始化入度数组
        graph.resize(numCourses);
        indegree.resize(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++indegree[prerequisites[i][0]];
        }
        // 这时候我们需要知道 我们需要构建的课程
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // q 中都是不需要入度的课程
            int u = q.front();  // 目前节点 u
            q.pop();
            res.push_back(u);
            for (auto v : graph[u]) {
                // 到达 v 课程
                --indegree[v];
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return (res.size() == numCourses) ? res : vector<int>();
    }
};
