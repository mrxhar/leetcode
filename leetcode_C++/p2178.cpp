/*
@Author: mrxhar
@Date:   2023-09-06 09:11:45
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/maximum-split-of-positive-even-integers/description/?envType=daily-question&envId=2023-09-06
*/

#include <vector>
using std::vector;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 != 0)
            return res;
        for (long long i = 2; i <= finalSum; i += 2) {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};

int main() {
    return 0;
}
