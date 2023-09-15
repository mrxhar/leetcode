#include <vector>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>> &logs) {
        // 记录上一个任务结束
        int pre = 0;
        int maxid = -1;
        int maxtime = -1;
        for (auto &log : logs) {
            if (log[1] - pre > maxtime || (log[1] - pre == maxtime && log[0] < maxid)) { // 只有严格大于才算，为沙不幸
                maxid = log[0];
                maxtime = log[1] - pre;
            }
            pre = log[1];
        }
        return maxid;
    }
};