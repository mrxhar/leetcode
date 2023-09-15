/*
@Author: mrxhar
@Date:   2023-09-07 09:38:48
@Email:  1337904145@qq.com
@Blog:lid-clock-times/?envType=daily-question&envId=2023-09-07

*/
#include <string>
using std::string;

class Solution {
public:
    int countTime(string time) {
        // 小时和分钟是分开来计算的，小时不影响分钟
        int hour = 1, minute = 1;
        // 问号
        // 先计算 hour
        if (time[0] == '?' && time[1] == '?')
            hour = 24;
        else if (time[0] == '?')
            hour = (time[1] - '0') <= 3 ? 3 : 2;
        else
            hour = (time[0] - '0') < 2 ? 10 : 4;
        
        // 计算minute
        minute = (time[3] == '?' ? 6 : 1) * (time[4] == '?' ? 10 : 1);
        return hour * minute;
    }
};

int main() {
    return 0;
}
