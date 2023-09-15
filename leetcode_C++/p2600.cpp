/*
@Author: mrxhar
@Date:   2023-09-09 09:50:22
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/k-items-with-the-maximum-sum/?envType=daily-question&envId=2023-09-09
*/

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int n = numOnes + numZeros + numNegOnes;

        if (k < numOnes) {
            return k;
        } else if (k < numOnes + numZeros) {
            return numOnes;
        } else {
            return 2 * numOnes - k + numZeros;
        }
    }
};

int main() {
    return 0;
}
