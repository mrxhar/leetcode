/*
@Author: mrxhar
@Date:   2023-09-11 11:11:00
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/description/?envType=daily-question&envId=2023-09-11
*/
#include <vector>
using std::vector;

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int maxnum = 0, res = 0;
        for (int i = 0; i < flips.size(); i++) {
            maxnum = std::max(flips[i], maxnum);
            if (maxnum == i + 1) {
                res++;
            }
        }
        return res;
    }
};