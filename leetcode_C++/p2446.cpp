
/*
@Author: mrxhar
@Date:   2023-09-07 10:19:52
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/determine-if-two-events-have-conflict/?envType=daily-question&envId=2023-09-07
*/

#include <vector>
using std::vector;
#include <string>
using std::stoi;
using std::string;

int main() {
    return 0;
}

// class Solution {
// public:
//     int compare(string& time1, string& time2) {
//         int hour1 = stoi(time1.substr(0, 2));
//         int hour2 = stoi(time2.substr(0, 2));
//         int minute1 = stoi(time1.substr(3));
//         int minute2 = stoi(time2.substr(3));
//         if (hour1 < hour2) {
//             return -1;
//         } else if (hour1 == hour2 && minute1 < minute2) {
//             return -1;
//         } else if (hour1 == hour2 && minute1 == minute2) {
//             return 0;
//         } else {
//             return 1;
//         }
//     }
//     // 转成分钟也可以

//     bool haveConflict(vector<string>& event1, vector<string>& event2) {
//         // 比较时间，交集
//         // 包含时刻 1 包含 2
//         // 这时候 1开始要小于等于 2 的开始时刻,1 结束要大于2结束
//         if (compare(event1[0], event2[0]) <= 0 && compare(event1[1], event2[1]) >= 0) {
//             return true;
//         }
//         // 2 包含 1
//         else if (compare(event1[0], event2[0]) >= 0 && compare(event1[1], event2[1]) <= 0) {
//             return true;
//         }

//         // 交集
//         if (compare(event1[0], event2[0]) <= 0 && compare(event2[0], event1[1]) <= 0 && compare(event1[1], event2[1]) <= 0) {
//             return true;
//         }
//         if (compare(event2[0], event1[0]) <= 0 && compare(event1[0], event2[1]) <= 0 && compare(event2[1], event1[1]) <= 0) {
//             return true;
//         };

//         return false;
//     }
// };

class Solution {
public:
    int convertint(string& time) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3));
        return hour * 60 + minute;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // 包含关系
        int start1 = convertint(event1[0]);
        int start2 = convertint(event2[0]);
        int end1 = convertint(event1[1]);
        int end2 = convertint(event2[1]);

        if ((start1 <= start2 && end1 >= start2) || (start2 <= start1 && end2 >= end1)) {
            return true;
        }

        if (start1 <= start2 && start2 <= end1 && end1 <= end2) {
            return true;
        }
        if (start2 <= start1 && start1 <= end2 && end2 <= end1) {
            return true;
        }
        return false;
    }
};