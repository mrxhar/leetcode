/*
@Author: mrxhar
@Date:   2023-09-08 09:58:45
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/calculate-delayed-arrival-time/?envType=daily-question&envId=2023-09-08
*/

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};

int main() {
    return 0;
}
