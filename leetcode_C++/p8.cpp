/*
@Author: mrxhar
@Date:   2023-08-29 09:57:29
@Email:  1337904145@qq.com
@Blog:   https://leetcode.cn/problems/string-to-integer-atoi/description/
*/

#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

using std::min;
using std::string;
using std::unordered_map;
using std::vector;

class Automaton
{
private:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;
    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
        {
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution
{
public:
    int myAtoi(string s)
    {
        // 自动机概念
        Automaton automaton;
        for(char c : s)
        {
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
};