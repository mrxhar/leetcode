/*
@Author: mrxhar
@Date:   2023-09-06 10:49:08
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/statistics-from-a-large-sample/description/?envType=daily-question&envId=2023-09-06
*/
#include <vector>
using std::vector;
#include <algorithm>
#include <limits>
#include <numeric>

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minium = 256, maximum = 0, n = count.size();
        int total = accumulate(count.begin(), count.end(), 0);
        double mean = 0.0;
        double median = 0.0;

        int mode = 0;
        int maxfreq = 0;

        long long sum = 0;
        int cnt = 0;
        int left = (total + 1) / 2;
        int right = (total + 2) / 2;
        for (int i = 0; i < n; i++) {
            sum += (long long)count[i] * i;
            // 众数
            if (count[i] > maxfreq) {
                maxfreq = count[i];
                mode = i;
            }
            // 最小数
            if (count[i] > 0) {
                if (minium == 256) {
                    minium = i;
                }
                maximum = i;
                cnt += count[i];
            }

            // 中位数
            if (cnt < right && cnt + count[i] >= right) {
                median +=i;
            }
            if (cnt < left && cnt + count[i] >= left) {
                median += i;
            }
            cnt += count[i];
        }
        mean = (double)sum / total;
        median = median / 2.0;
        return {double(minium), (double)maximum, mean, median, (double)mode};
    }
};

int main() {
    return 0;
}
