/*
@Author: mrxhar
@Date:   2023-09-09 10:35:03
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/fHi6rV/?envType=daily-question&envId=2023-09-09
*/

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <stack>
using std::pair;
using std::stack;
#include <unordered_set>
using std::unordered_set;
#include <unordered_map>
using std::unordered_map;
#include <queue>
using std::queue;

class Solution {
private:
    int n, m;
    const int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    bool judge(const vector<string>& chessboard, int x, int y, int dx, int dy) {
        // 能够保证到达黑棋
        x += dx;
        y += dy;
        while (x >= 0 && x < n && y >= 0 && y < m) {
            if (chessboard[x][y] == 'X') {
                return true;
            } else if (chessboard[x][y] == '.') {
                return false;
            }
            x += dx;
            y += dy;
        }
        return false;
    }

    int bfs(vector<string> chessboard, int px, int py) {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.emplace(px, py);
        chessboard[px][py] = 'X';
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                if (judge(chessboard, cur.first, cur.second, dir[i][0], dir[i][1])) {
                    int x = cur.first + dir[i][0];
                    int y = cur.second + dir[i][1];
                    while (chessboard[x][y] != 'X') {  // 中间的白棋
                        q.emplace(x, y);               // 加入队列 ，将其改为黑棋
                        chessboard[x][y] = 'X';
                        x += dir[i][0];
                        y += dir[i][1];
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }

public:
    int flipChess(vector<string>& chessboard) {
        // 从黑棋出发，八个方向进行遍历，如果遇到白棋则 + 1知道到达空位 这个空位我们暂存起来，并且将白棋个数记录起来，如果遇到空位和黑棋，则代表这个无用，不需要记录，最后返回记录最大的哪个点的位置
        // 第一遍遍历，我们需要记录白棋和黑棋，为了方便查询，我们记为 栈的形式 和数组的形式

        int n = chessboard.size(), m = chessboard[0].size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (chessboard[i][j] == '.') {
                    res = std::max(res, bfs(chessboard, i, j));
                }
            }
        }
        return res;
    }
};

