/*
@file: name
@description:
@author: mrxhar
@date: 2023-10-09 08:32:53
@version: 1.0
@email: mrxhar@163.com
@copyright: Copyright (c) 2023 mrxhar
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        /*
        排列：判断num的位数是否为奇数或者偶数
        奇数：一个较大位数的值，优先填充较小值，同位数的值分别填充较小的两个值
        偶数：同时填充较小的两个值
        */
        string record = to_string(num);

        sort(record.begin(), record.end());
        int num1 = 0, num2 = 0;
        for (int i = 0; i < record.size(); i++) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + (record[i] - '0');
            } else {
                num2 = num2 * 10 + (record[i] - '0');
            }
        }
        return num1 + num2;
    }
};